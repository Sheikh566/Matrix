#include <iostream>
#include "Matrix.cpp"
using namespace std;

class Matrix2DArray : public Matrix
{
  double **data;

public:
  int h, w;
  // Creates Truly Dynamic 2D Array
  Matrix2DArray(int height, int width) : data(new double *[height])
  {
    for (int i = 0; i < height; ++i)
    {
      data[i] = new double[width];
    }
    h = height;
    w = width;
  }

  void setElem(int i, int j, double value)
  {
    if (i < h && j < w) data[i][j] = value;
    else cout << "Error: Invalid Index";
  }
  
  double getElem(int i, int j) const
  {
    return this->data[i][j];
  }

  Matrix2DArray *add(const Matrix &other)
  {
    Matrix2DArray *M = new Matrix2DArray(h, w);
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        double value = this->data[i][j] + other.getElem(i, j);
        M->setElem(i, j, value);
      }
    }
    return M;
  }

  // Overloads '+' operator
  Matrix2DArray *operator+(const Matrix &other)
  {
    return this->add(other);
  }

  Matrix2DArray *multiply(const Matrix &other)
  {
    Matrix2DArray *N = new Matrix2DArray(h, w);
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        double total = 0;
        for (int k = 0; k < h; k++)
        {
          double mul = this->data[i][k] * other.getElem(k, j);
          total = total + mul;
        }
        N->setElem(i, j, total);
      }
    }
    return N;
  }

  // Overloads '*' operator
  Matrix2DArray *operator*(const Matrix &other)
  {
    return this->multiply(other);
  }

  Matrix2DArray transpose() {
    Matrix2DArray transposed(w, h);
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        transposed.setElem(j, i, this->getElem(i, j));
      }
    }
    return transposed;
  }
  void toString() const
  {
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        cout << this->getElem(i, j) << " ";
      }
      cout << endl;
    }
  }

  // Cleanup
  ~Matrix2DArray()
  {
    for (int i = 0; i < h; ++i)
    {
      delete[] data[i];
    }
    delete[] data;
  }
};