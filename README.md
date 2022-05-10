# s21_matrix+

Implementation of the s21_matrix_oop.h library.

![s21_matrix](images/s21_matrix.png)

### An example of a matrix class in C++
```cpp
class S21Matrix {
    private:
        // Attributes
        int _rows, _cols;         // Rows and columns
        double **_matrix;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();              // Default constructor
        ~S21Matrix();             // Destructor

        void sum_matrix(const S21Matrix& other); 
        // Other methods..
}

| Operation | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `bool eq_matrix(const S21Matrix& other)` | Checks matrices for equality with each other |  |
| `void sum_matrix(const S21Matrix& other)` | Adds the second matrix to the current one | different matrix dimensions |
| `void sub_matrix(const S21Matrix& other)` | Subtracts another matrix from the current one | different matrix dimensions |
| `void mul_number(const double num) ` | Multiplies the current matrix by a number |  |
| `void mul_matrix(const S21Matrix& other)` | Multiplies the current matrix by the second matrix | the number of columns of the first matrix is not equal to the number of rows of the second matrix |
| `S21Matrix transpose()` | Creates a new transposed matrix from the current one and returns it |  |
| `S21Matrix calc_complements()` | Calculates the algebraic addition matrix of the current one and returns it | the matrix is not square |
| `double determinant()` | Calculates and returns the determinant of the current matrix | the matrix is not square |
| `S21Matrix inverse_matrix()` | Calculates and returns the inverse matrix | matrix determinant is 0 |

Apart from those operations, you also need to implement constructors and destructors:

| Method | Description |
| ----------- | ----------- |
| `S21Matrix()` | A basic constructor that initialises a matrix of some predefined dimension |  
| `S21Matrix(int rows, int cols) ` | Parametrized constructor with number of rows and columns |
| `S21Matrix(const S21Matrix& other)` | Copy constructor |
| `S21Matrix(S21Matrix&& other)` | Move constructor |
| `~S21Matrix()` | Destructor |

And you also need to overload the following operators, partly corresponding to the operations above:

| Operator | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `+`      | Addition of two matrices | different matrix dimensions |
| `-`   | Subtraction of one matrix from another | different matrix dimensions |
| `*`  | Matrix multiplication and matrix multiplication by a number | the number of columns of the first matrix does not equal the number of rows of the second matrix |
| `==`  | Checks for matrices equality (`eq_matrix`) | |
| `=`  | Assignment of values from one matrix to another one | |
| `+=`  | Addition assignment (`sum_matrix`) | different matrix dimensions |
| `-=`  | Difference assignment (`sub_matrix`) | different matrix dimensions |
| `*=`  | Multiplication assignment (`mul_matrix`/`mul_number`) | the number of columns of the first matrix does not equal the number of rows of the second matrix |
| `(int i, int j)`  | Indexation by matrix elements (row, column) | index is outside the matrix |
