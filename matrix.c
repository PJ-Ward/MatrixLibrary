#include <stdio.h>

    void multiplyMatracies(int *mat1, int *mat2, int rows1, int cols1, int cols2, int *result) {
        int size = rows1*cols2;
        int total = 0;
        for(int i=0; i<size; i++){
            //for every cell in result
            total = 0;
            for(int j = 0; j<cols1; j++){
                //multiply the row of mat1 by the column of mat2
                total += mat1[i+1-((i+1)%cols1)+j] * mat2[(i%(cols1-1))+(j*cols2)];
            }
            result[i] = total;
        }
    }

    void scalarMultiply(int *mat1, int rows, int cols, int scalar, int *result) {
        int size = rows*cols;
        for(int i=0; i<size; i++){
            result[i] = scalar * mat1[i];
        }
    }

    void addMatracies(int *mat1, int *mat2, int rows, int cols, int *result) {
        int size = rows*cols;
        for(int i=0; i<size; i++){
            result[i] = mat1[i]+mat2[i];
        }
    }

    void transposeMatrix(int *mat1, int rows1, int cols1, int *result) {
        int counter = 0;
        for(int i=0; i<cols1; i++){
            for(int j=0; j<rows1; j++){
                result[counter] = mat1[i+(j*cols1)];
                counter++;
            }
        }
    }

    void printMatrix(int *mat1, int rows1, int cols1) {
        int size = rows1 * cols1;
        printf("\nMATRIX:");
        for(int i=0; i<size; i++){
            if(i%cols1 == 0){
                printf("\n");
            }
            printf("%d ", mat1[i]);
        }
        printf("\n");
        }
    
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

    int matrixA[] = {6, 4, 8, 3};
    int matrixB[] = {1, 2, 3, 4, 5, 6};
    int matrixC[] = {2, 4, 6, 1, 3, 5};
    int bScalar = 3;


    int matrixC1[cTRows * cTCols];
    int matrixB1[bRows * bCols];
    int matrixBC[bRows * cTCols];
    int matrixD[aRows * aCols];

    scalarMultiply(matrixB, bRows, bCols, bScalar, matrixB1);
    //printMatrix(matrixB1, bRows, bCols);
    transposeMatrix(matrixC, cRows, cCols, matrixC1);
    //printMatrix(matrixC1, cTRows, cTCols);
    multiplyMatracies(matrixB1, matrixC1, bRows, bCols, cTCols, matrixBC);
    //printMatrix(matrixBC, bRows, cTCols);
    addMatracies(matrixA, matrixBC, aRows, aCols, matrixD);

    printMatrix(matrixD, aRows, aCols);

    return 0;
  }/* main() */
