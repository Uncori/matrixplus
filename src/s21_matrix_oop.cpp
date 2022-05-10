
#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : _rows(0), _cols(0), _matrix(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
    if (this->_rows <= 0 || this->_cols <= 0) {
        throw std::out_of_range("Error: out of range");
    }
    this->memory_allocation();
}

S21Matrix::~S21Matrix() { this->destroy_matrix(); }

void S21Matrix::destroy_matrix() {
    if (this->_matrix != nullptr) {
        for (int i = 0; i < this->_rows; ++i) {
            delete[] this->_matrix[i];
        }
        delete[] this->_matrix;
    }
    this->_matrix = nullptr;
    this->_cols = 0;
    this->_rows = 0;
}
void S21Matrix::memory_allocation() {
    if (this->_rows <= 0 || this->_cols <= 0) {
        throw std::out_of_range("Error: out of range");
    }
    this->_matrix = new double*[this->_rows]();
    for (int i = 0; i < this->_rows; ++i) {
        this->_matrix[i] = new double[this->_cols]();
    }
}
void S21Matrix::copy_matrix(const S21Matrix& other) {
    if (this->_rows != other._rows || this->_cols != other._cols) {
        throw std::out_of_range("Error: Matrix have different dimensions");
    }
    for (int i = 0; i < this->_rows; ++i) {
        for (int j = 0; j < this->_cols; ++j) {
            this->_matrix[i][j] = other._matrix[i][j];
        }
    }
}
void S21Matrix::set_rows(int rows) {
    S21Matrix temp(*this);
    this->destroy_matrix();
    _rows = rows;
    _cols = temp._cols;
    this->memory_allocation();
    for (int i = 0; i < this->_rows; ++i) {
        for (int j = 0; j < this->_cols; ++j) {
            this->_matrix[i][j] = temp._matrix[i][j];
        }
    }
}
void S21Matrix::set_cols(int cols) {
    S21Matrix temp(*this);
    this->destroy_matrix();
    _rows = temp._rows;
    _cols = cols;
    this->memory_allocation();
    for (int i = 0; i < this->_rows; ++i) {
        for (int j = 0; j < this->_cols; ++j) {
            this->_matrix[i][j] = temp._matrix[i][j];
        }
    }
}
S21Matrix::S21Matrix(const S21Matrix& other) : _rows(other._rows), _cols(other._cols) {
    this->memory_allocation();
    this->copy_matrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) : _rows(other._rows), _cols(other._cols) {
    this->copy_matrix(other);
    other.destroy_matrix();
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
    S21Matrix neo(*this);
    neo.sum_matrix(other);
    return neo;
}
S21Matrix S21Matrix::operator-(const S21Matrix& other) {
    S21Matrix neo(*this);
    neo.sub_matrix(other);
    return neo;
}
S21Matrix S21Matrix::operator*(const S21Matrix& other) {
    S21Matrix neo(*this);
    neo.mul_matrix(other);
    return neo;
}
S21Matrix S21Matrix::operator*(const double num) {
    S21Matrix neo(*this);
    neo.mul_number(num);
    return neo;
}
bool S21Matrix::operator==(const S21Matrix& other) { return this->eq_matrix(other); }
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    this->destroy_matrix();
    this->_rows = other._rows;
    this->_cols = other._cols;
    this->memory_allocation();
    this->copy_matrix(other);
    return *this;
}
S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
    sum_matrix(other);
    return *this;
}
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
    sub_matrix(other);
    return *this;
}
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
    mul_matrix(other);
    return *this;
}
S21Matrix& S21Matrix::operator*=(const double num) {
    mul_number(num);
    return *this;
}

double& S21Matrix::operator()(int row, int col) {
    if (row >= this->_rows || col >= this->_cols || row < 0 || col < 0) {
        throw std::out_of_range("Error: out of range");
    }
    return this->_matrix[row][col];
}

int S21Matrix::get_rows() { return this->_rows; }
int S21Matrix::get_cols() { return this->_cols; }

bool S21Matrix::eq_matrix(const S21Matrix& other) {
    bool res = true;
    if (other._cols == this->_cols && other._rows == this->_rows) {
        for (int i = 0; i < other._rows && res; ++i) {
            for (int j = 0; j < other._cols && res; ++j) {
                if (fabs(other._matrix[i][j] - this->_matrix[i][j]) >= E) {
                    res = false;
                }
            }
        }
    } else {
        res = false;
    }
    return res;
}
void S21Matrix::sum_matrix(const S21Matrix& other) {
    if (this->_rows != other._rows || this->_cols != other._cols) {
        throw std::out_of_range("Error: Matrix have different dimensions");
    }
    for (int i = 0; i < other._rows; ++i) {
        for (int j = 0; j < other._cols; ++j) {
            this->_matrix[i][j] += other._matrix[i][j];
        }
    }
}
void S21Matrix::sub_matrix(const S21Matrix& other) {
    if (this->_rows != other._rows || this->_cols != other._cols) {
        throw std::out_of_range("Error: Matrix have different dimensions");
    }
    for (int i = 0; i < other._rows; ++i) {
        for (int j = 0; j < other._cols; ++j) {
            this->_matrix[i][j] -= other._matrix[i][j];
        }
    }
}
void S21Matrix::mul_number(const double num) {
    for (int i = 0; i < this->_rows; ++i) {
        for (int j = 0; j < this->_cols; ++j) {
            this->_matrix[i][j] *= num;
        }
    }
}
void S21Matrix::mul_matrix(const S21Matrix& other) {
    if (this->_cols != other._rows) {
        throw std::out_of_range("Error: Matrix have different dimensions");
    }
    S21Matrix res(this->_rows, other._cols);
    for (int i = 0; i < this->_rows; ++i) {
        for (int j = 0; j < other._cols; ++j) {
            for (int k = 0; k < this->_cols; ++k) {
                res._matrix[i][j] += this->_matrix[i][k] * other._matrix[k][j];
            }
        }
    }
    *this = res;
}

S21Matrix S21Matrix::transpose() {
    S21Matrix neo(this->_cols, this->_rows);
    for (int i = 0; i < neo._rows; ++i) {
        for (int j = 0; j < neo._cols; ++j) {
            neo._matrix[i][j] = _matrix[j][i];
        }
    }
    return neo;
}

S21Matrix S21Matrix::inverse_matrix() {
    double det = determinant();
    if (det == 0 || this->_rows != _cols) {
        throw std::out_of_range("Error: determinant = 0");
    }
    S21Matrix neo(this->_rows, this->_cols);
    S21Matrix temp = this->calc_complements();
    S21Matrix second_temp = temp.transpose();
    neo = second_temp;
    neo.mul_number(1 / det);

    return neo;
}

S21Matrix S21Matrix::calc_complements() {
    if (this->_rows != this->_cols) {
        throw std::out_of_range("Error: Matrix have different dimensions");
    }
    S21Matrix neo(this->_rows, this->_cols);
    if (this->_rows == 1 && this->_cols == 1) {
        neo._matrix[0][0] = 1;
    } else {
        for (int i = 0; i < neo._rows; ++i) {
            for (int j = 0; j < neo._cols; ++j) {
                S21Matrix temp = minor_matrix(*this, i, j);
                neo._matrix[i][j] = temp.determinant() * pow(-1.0, (i + 1) + (j + 1));
            }
        }
    }
    return neo;
}

S21Matrix S21Matrix::minor_matrix(const S21Matrix& other, int i_rows, int j_cols) {
    S21Matrix neo(other._rows - 1, other._cols - 1);
    for (int i = 0; i < other._rows; ++i) {
        for (int j = 0; j < other._cols; ++j) {
            if (i != i_rows && j != j_cols) {
                if (i > i_rows && j < j_cols) {
                    neo._matrix[i - 1][j] = other._matrix[i][j];
                } else if (i > i_rows && j > j_cols) {
                    neo._matrix[i - 1][j - 1] = other._matrix[i][j];
                } else if (i < i_rows && j > j_cols) {
                    neo._matrix[i][j - 1] = other._matrix[i][j];
                } else {
                    neo._matrix[i][j] = other._matrix[i][j];
                }
            }
        }
    }

    return neo;
}

double S21Matrix::determinant() {
    if (this->_rows != this->_cols) {
        throw std::out_of_range("Error: Matrix have different dimensions");
    }
    double det = 0;
    if (this->_rows == 1 && this->_cols == 1) {
        det = _matrix[0][0];
    } else if (this->_rows == 2 && this->_cols == 2) {
        det = (this->_matrix[0][0] * this->_matrix[1][1]) - (this->_matrix[1][0] * this->_matrix[0][1]);
    } else {
        for (int i = 1; i <= this->_cols; ++i) {
            S21Matrix neo = minor_matrix(*this, 0, i - 1);
            det += pow(-1, 1 + (double)i) * _matrix[0][i - 1] * neo.determinant();
        }
    }
    return det;
}
S21Matrix operator*(const double num, const S21Matrix& other) {
    S21Matrix neo(other);
    neo.mul_number(num);
    return neo;
}
