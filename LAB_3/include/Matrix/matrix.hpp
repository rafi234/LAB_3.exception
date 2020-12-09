#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Matrix
{
private:
    double **mat = nullptr;
    int x, y;

public:
    Matrix(int n, int m);
    Matrix(int n);
    Matrix(string filename, string path);
    void CreateMatrix_1();
    void CreateMatrix_2();
    Matrix substract(Matrix &m2);
    Matrix add(Matrix &m2);
    Matrix multiply(Matrix &m2);
    int cols();
    int rows();
    void set(int n, int m, double val);
    double get(int n, int m);
    void print();
    void store(string filename, string path);
};
