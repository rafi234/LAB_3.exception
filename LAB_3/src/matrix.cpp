
#include "Matrix/matrix.hpp"

Matrix::Matrix(int n, int m)
{
    if (n < 1 || m < 1)
    {
        cout << "Warning: Liczba kolumn i wierszy musi byc wieksza od 0\n";
        int i = 1;
        while (i)
        {
            cout << "Podaj nowa liczbe kolumn i wierszy.\n";
            cin >> m >> n;
            if (n > 0 && m > 0)
                i = 0;
            else
                cout << "Warning: Zostala podana zla ilosc kolumn i wierszy. Sprobuj ponownie.\n";
        }
    }
    x = n;
    y = m;
    mat = new double *[n];
    if (!mat)
    {
        throw -3;
    }
    memset(mat, 0, sizeof(double) * n);
    for (int i = 0; i < n; ++i)
    {
        mat[i] = new double[m];
        if (!mat[i])
        {
            throw -3;
        }
        memset(mat[i], 0, sizeof(double) * m);
    }
}

Matrix::Matrix(int n)
{
    if (n < 1)
    {
        cout << "Warning: Liczba kolumn i wierszy musi byc wieksza od 0!\n";

        int i = 1;
        while (i)
        {
            cout << "Podaj nowa liczbe kolumn i wierszy.\n";
            cin >> n;
            if (n > 0)
                i = 0;
            else
                cout << "Warning: Zostala podana zla ilosc kolumn i wierszy. Sprobuj ponownie.\n";
        }
    }
    y = n;
    x = n;
    mat = new double *[n];
    if (!mat)
    {
        throw -3;
    }
    memset(mat, 0, sizeof(double) * n);
    for (int i = 0; i < n; ++i)
    {
        mat[i] = new double[n];

        if (!mat[i])
        {
            throw -3;
        }
        memset(mat[i], 0, sizeof(double) * n);
    }
}

Matrix::Matrix(string filename, string path)
{
    ifstream plik(path);
    plik.open(filename);

    if (plik.good() == false)
    {
        throw -4;
    }

    plik >> x >> y;

    mat = new double *[x];
    if (!mat)
    {
        throw -3;
    }
    for (int i = 0; i < x; ++i)
    {
        mat[i] = new double[y];
        if (!mat[i])
        {
            throw -3;
        }
    }
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
            plik >> mat[i][j];
    }

    plik.close();
}

int Matrix::cols()
{
    return x;
}

int Matrix::rows()
{
    return y;
}

double Matrix::get(int n, int m)
{
    if ((0 > n || n >= x) || (0 > m || m >= y))
        throw -2;

    return mat[n][m];
}

void Matrix::set(int n, int m, double val)
{
    if (0 > n >= x || 0 > m >= y)
        throw -2;

    mat[n][m] = val;
}

void Matrix::print()
{
    for (int i = 0; i < x; ++i)
    {
        cout << endl;
        for (int j = 0; j < y; ++j)
        {
            cout.width(8);
            cout << mat[i][j] << "  ";
        }
    }
}

Matrix Matrix::substract(Matrix &m2)
{
    if (x != m2.x || y != m2.y)
    {
        throw -1;
    }

    Matrix temp(m2.x, m2.y);
    for (int i = 0; i < m2.x; ++i)
    {
        for (int j = 0; j < m2.y; ++j)
        {
            temp.mat[i][j] = m2.mat[i][j] - mat[i][j];
        }
    }
    return temp;
}

Matrix Matrix::add(Matrix &m2)
{
    if (x != m2.x || y != m2.y)
    {
        throw -1;
    }

    Matrix temp(m2.x, m2.y);

    for (int i = 0; i < m2.x; ++i)
    {
        for (int j = 0; j < m2.y; ++j)
        {
            temp.mat[i][j] = m2.mat[i][j] + mat[i][j];
        }
    }
    return temp;
}

Matrix Matrix::multiply(Matrix &m2)
{
    if (x != m2.y)
    {
        throw -1;
    }
  
    Matrix temp(x, m2.y);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < m2.y; ++j)
        {
            temp.mat[i][j] = 0.0;
            for (int k = 0; k < x; ++k)
                temp.mat[i][j] += mat[i][k] * m2.mat[k][j];
        }
    }
    return temp;
}

void Matrix::CreateMatrix_1()
{
    for (int i = 0; i < x; ++i)
    {
        cout << endl;
        double temp_i = i;
        for (int j = 0; j < y; ++j)
        {
            double temp_j = j;
            mat[i][j] = ((temp_i + 1) * (temp_j + 4)) / 3;
        }
    }
}

void Matrix::CreateMatrix_2()
{
    for (int i = 0; i < x; ++i)
    {
        cout << endl;
        double temp_i = i;
        for (int j = 0; j < y; ++j)
        {
            double temp_j = j;
            mat[i][j] = ((temp_i + 3) * (temp_j + 4)) / 5;
        }
    }
}

void Matrix::store(string filename, string path)
{
    ofstream plik(path);
    plik.open(filename);

    if (plik.good() == false)
    {
        throw -4;
    }
    plik << x << " " << y << endl;

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            plik << get(i, j) << " ";
        }
        plik << endl;
    }
    plik.close();
}