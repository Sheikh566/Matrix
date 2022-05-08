#include <iostream>
#include "Matrix2DArray.cpp"
using namespace std;

class MatrixLin : public Matrix
{
protected:
    double* data;
    int height = 1;
    int totalElems;

public:
    MatrixLin(int w): data( new double[w] ) {
        totalElems=w;
    }
    void setElem(int i, int j, double value)
    {
        if (i < totalElems)
        {
            data[i] = value;
        }
        else
        {
            cout << "Error 404";
        }
    }
    double getElem(int i, int j) const
    {
        return data[i];
    }

    MatrixLin *add(const Matrix &other)
    {
        MatrixLin* K = new MatrixLin(totalElems);
        for (int i = 0; i < totalElems; i++)
        {
            double value = this->data[i] + other.getElem(i,0);
            K->setElem(i, 0, value);
            
        }
        return K;
    }
    MatrixLin* multiply(const Matrix &other)
    {
        int j=0;
        MatrixLin *L = new MatrixLin(totalElems);
        for (int i = 0; i < height; i++)
        {       
                double value = this->data[i] * other.getElem(i, j);
                L->setElem(i, j, value);            
        }
        return L;
    }

    // Converts MatrixLin to Matrix2DArray
    Matrix2DArray delinearize(int rows, int cols) const {
        Matrix2DArray mat(rows, cols);
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat.setElem(i, j, this->data[k]);
                k++;
            }
        }
        return mat;
    }
    void toString() const {
      for (int i = 0; i < totalElems; i++) {
        cout << this->getElem(i, 0) << " ";
      }
      cout << endl;
    }

    // Cleanup
    ~MatrixLin() {
        delete[] data;
    }
};