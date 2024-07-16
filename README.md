# matrix+

Implementation of the matrix_oop.h library.

![matrix](images/matrix.png)

### An example of a matrix class in C++
```cpp
class Matrix {
    private:
        // Attributes
        int _rows, _cols;         // Rows and columns
        double **_matrix;         // Pointer to the memory where the matrix is allocated

    public:
        Matrix();              // Default constructor
        ~Matrix();             // Destructor

        void sum_matrix(const Matrix& other); 
        // Other methods..
}

| Operation | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `bool eq_matrix(const Matrix& other)` | Checks matrices for equality with each other |  |
| `void sum_matrix(const Matrix& other)` | Adds the second matrix to the current one | different matrix dimensions |
| `void sub_matrix(const Matrix& other)` | Subtracts another matrix from the current one | different matrix dimensions |
| `void mul_number(const double num) ` | Multiplies the current matrix by a number |  |
| `void mul_matrix(const Matrix& other)` | Multiplies the current matrix by the second matrix | the number of columns of the first matrix is not equal to the number of rows of the second matrix |
| `Matrix transpose()` | Creates a new transposed matrix from the current one and returns it |  |
| `Matrix calc_complements()` | Calculates the algebraic addition matrix of the current one and returns it | the matrix is not square |
| `double determinant()` | Calculates and returns the determinant of the current matrix | the matrix is not square |
| `Matrix inverse_matrix()` | Calculates and returns the inverse matrix | matrix determinant is 0 |

Apart from those operations, you also need to implement constructors and destructors:

| Method | Description |
| ----------- | ----------- |
| `Matrix()` | A basic constructor that initialises a matrix of some predefined dimension |  
| `Matrix(int rows, int cols) ` | Parametrized constructor with number of rows and columns |
| `Matrix(const Matrix& other)` | Copy constructor |
| `Matrix(Matrix&& other)` | Move constructor |
| `~Matrix()` | Destructor |

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
