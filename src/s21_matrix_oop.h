#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>
#define E 1e-7
class S21Matrix {
 public:
    S21Matrix();
    ~S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);

    bool eq_matrix(const S21Matrix& other);
    void sum_matrix(const S21Matrix& other);
    void sub_matrix(const S21Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);

    double& operator()(int row, int col);
    bool operator==(const S21Matrix& other);
    friend S21Matrix operator*(const double num, const S21Matrix& other);
    S21Matrix operator+(const S21Matrix& other);
    S21Matrix operator-(const S21Matrix& other);
    S21Matrix operator*(const S21Matrix& other);
    S21Matrix operator*(const double num);
    S21Matrix& operator=(const S21Matrix& other);
    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix& operator-=(const S21Matrix& other);
    S21Matrix& operator*=(const S21Matrix& other);
    S21Matrix& operator*=(const double num);

    S21Matrix transpose();
    S21Matrix calc_complements();
    S21Matrix inverse_matrix();
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
    void copy_matrix(const S21Matrix& other);
    S21Matrix minor_matrix(const S21Matrix& other, int i_rows, int j_cols);
};

S21Matrix operator*(const double num, const S21Matrix& other);

#endif  // SRC_S21_MATRIX_OOP_H_
