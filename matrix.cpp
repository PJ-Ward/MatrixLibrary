#include <iostream>
using namespace std;

class Matrix {
public:

  //CONSTRUCTORS AND DESTRUCTORS
  Matrix(){
    //array_size = userArraySize;
  }

  //DATA MEMBERS 
  //int array_size;
  //int result[array_size];
    
  //FUNCTION MEMBERS
  /*multiplyMatracies
  Multiplies two matracies together
  mat1 and mat2 (int arrays) are the two matracies being multiplied together
  rows1 and cols1 (ints) are the number of rows and columns in matrix mat1
  cols2 (int) is the number of columns in matrix mat2
  result (int array) will be set to the product
  result must be of size rows1*cols2
  */
 void multiplyMatracies(int *mat1, int *mat2, int rows1, int cols1, int cols2, int *result) {
    int size = rows1*cols2;
    int total = 0;
    for(int i=0; i<size; i++){
        //for every cell in result
        total = 0;
        for(int j = 0; j<cols1; j++){
            //multiply the row of mat1 by the column of mat2
            //cout << "multiply " << mat1[i+1-((i+1)%cols1)+j] << " by " << mat2[(i%(cols1-1))+(j*cols2)] << endl;
            total += mat1[i+1-((i+1)%cols1)+j] * mat2[(i%(cols1-1))+(j*cols2)];
        }
        //cout << "total is " << total << endl;
        result[i] = total;
    }
    }

  /*scalarMultiply
  Multiplies a matrix by a scalar value
  mat1 (int array) is the matrix to multiply
  rows and cols (ints) are the number of rows and columns in matrix mat1
  scalar (int) is the scalar value to multiply the matrix by
  result (int array) will be set to the product
  mat1 and result must be the same size
  */
  void scalarMultiply(int *mat1, int rows, int cols, int scalar, int *result) {
    int size = rows*cols;
    for(int i=0; i<size; i++){
        result[i] = scalar * mat1[i];
    }
    }


  /*addMatracies
  Adds two matracies together
  mat1 and mat2 (int arrays) are the two matracies being added together
  rows and cols (ints) are the number of rows and columns in matrix mat1
  result (int array) will be set to the sum
  mat1, mat2 and result must all be the same size 
  */
  void addMatracies(int *mat1, int *mat2, int rows, int cols, int *result) {
    int size = rows*cols;
    for(int i=0; i<size; i++){
        result[i] = mat1[i]+mat2[i];
    }
    }

  /*transposeMatrix
  Creates the transpose of a matrix
  mat1 (int array) is the matrix to get the transpose of
  rows1 and cols1 (ints) are the number of rows and columns in matrix mat1
  result (int array) will be set to the transpose of mat1
  mat1 and result must have the same size. 
  The number of rows and cols in result will be the number of cols and rows in mat1, respectively
  */
  void transposeMatrix(int *mat1, int rows1, int cols1, int *result) {
    int counter = 0;
    for(int i=0; i<cols1; i++){
        for(int j=0; j<rows1; j++){
            result[counter] = mat1[i+(j*cols1)];
            counter++;
        }
    }
    }

  /*printMatrix
  Prints a given matrix
  mat1 (int array) is the matrix to print
  rows1 and cols1 (ints) are the number of rows and columns in matrix mat1
  */
  void printMatrix(int *mat1, int rows1, int cols1) {
    int size = rows1 * cols1;
    cout << endl;
    cout << "MATRIX:";
    for(int i=0; i<size; i++){
        if(i%cols1 == 0){
            cout << endl;
        }
        cout << mat1[i] << " ";
    }
    cout << endl;
    }

    
};/* class Matrix */

  int main()
  {
    int aRows = 2;
    int aCols = 2;
    int bRows = 2;
    int bCols = 3;
    int cRows = 2;
    int cCols = 3;
    int cTRows = cCols;
    int cTCols = cRows;

    int matrixA[aRows * aCols] = {6, 4, 8, 3};
    int matrixB[bRows * bCols] = {1, 2, 3, 4, 5, 6};
    int matrixC[cRows * cCols] = {2, 4, 6, 1, 3, 5};
    int bScalar = 3;


    int matrixC1[cTRows * cTCols];
    int matrixB1[bRows * bCols];
    int matrixBC[bRows * cTCols];
    int matrixD[aRows * aCols];

    Matrix funcs;
    funcs.scalarMultiply(matrixB, bRows, bCols, bScalar, matrixB1);
    //funcs.printMatrix(matrixB1, bRows, bCols);
    funcs.transposeMatrix(matrixC, cRows, cCols, matrixC1);
    //funcs.printMatrix(matrixC1, cTRows, cTCols);
    funcs.multiplyMatracies(matrixB1, matrixC1, bRows, bCols, cTCols, matrixBC);
    //funcs.printMatrix(matrixBC, bRows, cTCols);
    funcs.addMatracies(matrixA, matrixBC, aRows, aCols, matrixD);

    funcs.printMatrix(matrixD, aRows, aCols);

    return 0;
  }/* main() */