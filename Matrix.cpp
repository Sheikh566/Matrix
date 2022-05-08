#include <iostream>
using namespace std;

class Matrix
{
private:
    // double height,width;
public:
    double virtual getElem(int i, int j) const = 0;
    void virtual setElem(int i, int j, double value) = 0;
    Matrix virtual *add(const Matrix &other) = 0;
    Matrix virtual *multiply(const Matrix &other) = 0;
    void virtual toString() const = 0;
    // Matrix virtual *delinearize(int rows, int cols) const = 0;
};