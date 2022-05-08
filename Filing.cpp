#include <iostream>
#include <fstream>
#include "MatrixLin.cpp"
using namespace std;

class Filing
{
public:
  // Assumes that the CSV file is valid
  static Matrix2DArray readCSV(string filePath)
  {
    ifstream file(filePath);
    // Determining rows, cols from given CSV to create correct 2d matrix
    int m = countRows(filePath);
    int n = countCols(filePath);
    Matrix2DArray mat2D(m, n);
    string line;
    int row = 0;
    while (true)
    {
      file >> line;
      if (file.eof())
        break;
      string num;
      int col = 0;
      for (int i = 0; i < line.length(); i++)
      {
        if (line[i] == ',')
        {
          mat2D.setElem(row, col, stod(num));
          num = "";
          col++;
        }
        else
        {
          num += line[i];
        }
      }
      mat2D.setElem(row, col, stod(num));
      num = "";
      row++;
    }
    file.close();
    return mat2D;
  }
  
  static void writeCSV(const Matrix2DArray &mat, string fileName) {
    ofstream file(fileName+".csv");
    string text = "";
    for (int i = 0; i < mat.h; i++) {
      for (int j = 0; j < mat.w; j++) {
        // avoids comma before first elem of a row
        if (j != 0) text += ",";
        text += to_string(mat.getElem(i, j));
      }
      text += "\n";
    }
    file << text;
    file.close();
  }
  private:
  // checks no. of lines to count rows
    static int countRows(string filePath) {
      ifstream file(filePath);
      int count = 0;
      string line;
      while (getline(file, line)) {
        ++count;
      }
      file.close();
      return count;
    }

    // checks no. of commas to count columns
    static int countCols(string filePath) {
      ifstream file(filePath);
      int count = 0;
      string line;
      file >> line;
      for (int i = 0; i < line.length(); i++) {
        if (line[i] == ',') ++count;
      }
      file.close();
      return count + 1;
    }
};