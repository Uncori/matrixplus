#ifndef SRC_MATRIX_OOP_H_
#define SRC_MATRIX_OOP_H_

#include <cmath>
#include <iostream>
#define E 1e-7

class Matrix {
 public:
    Matrix();
    ~Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);

    bool eq_matrix(const Matrix& other);
    void sum_matrix(const Matrix& other);
    void sub_matrix(const Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const Matrix& other);

    double& operator()(int row, int col);
    bool operator==(const Matrix& other);
    friend Matrix operator*(const double num, const Matrix& other);
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator*(const Matrix& other);
    Matrix operator*(const double num);
    Matrix& operator=(const Matrix& other);
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix& operator*=(const double num);

    Matrix transpose();
    Matrix calc_complements();
    Matrix inverse_matrix();
    double determinant();
    void set_rows(int rows);
    void set_cols(int cols);
    int get_rows();
    int get_cols();

 private:
    int _rows, _cols;
    double** _matrix;
    void destroy_matrix();
    void memory_allocation();
    void copy_matrix(const Matrix& other);
    Matrix minor_matrix(const Matrix& other, int i_rows, int j_cols);
};

Matrix operator*(const double num, const Matrix& other);

#endif  // SRC_MATRIX_OOP_H_
