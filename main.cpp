#include <iostream>
#include "Filing.cpp"
using namespace std;

int main()
{
  // ============ Transposing ==============
  // mat1.toString();
  // cout << "After Transpose: " << endl;
  // mat1.transpose().toString();

  // ========== MatLin to Mat2D (delinearization) ===========
  // MatrixLin MatLinear_1(6);
  // MatrixLin MatLinear_2(6);
  // MatLinear_2.setElem(0, 0, 9);
  // MatLinear_2.setElem(1, 0, 3);
  // MatLinear_2.setElem(2, 0, 5);
  // MatLinear_2.setElem(3, 0, 7);
  // MatLinear_2.setElem(4, 0, 4);
  // MatLinear_2.setElem(5, 0, 9);

  // Matrix2DArray Mat2D_1 = MatLinear_1.delinearize(2, 3);
  // Matrix2DArray Mat2D_2 = MatLinear_2.delinearize(2, 3);
  // Matrix2DArray *resAdd = Mat2D_1 + Mat2D_2;
  // Matrix2DArray *resMul = Mat2D_1 * Mat2D_2;

  // ============ Read/Write with CSV File  =============
  Matrix2DArray mat1 = Filing::readCSV("matrix1.csv");
  Matrix2DArray mat2 = Filing::readCSV("matrix2.csv");
  Matrix2DArray *res = mat1 * mat2;
  Filing::writeCSV(*res, "res");

  Matrix2DArray resFile = Filing::readCSV("res.csv");
  cout << "Result: " << endl; 
  resFile.toString();
  
  return 0;
}
