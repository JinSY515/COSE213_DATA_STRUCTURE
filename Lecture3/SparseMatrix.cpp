#include <iostream>

class SparseMatrix;

class MatrixTerm{
    friend class SparseMatrix;
    private:
    int col;
    int row;
    int value;

};
class SparseMatrix{
    public:
    SparseMatrix Transpose();
    SparseMatrix FastTranspose();

    private:
    int rows, cols, terms, capacity;
    MatrixTerm *smArray;
};

SparseMatrix SparseMatrix::Transpose(){
    SparseMatrix b;
    b.rows=cols;
    b.cols=rows;
    b.terms=terms;

    if(terms>0){
        int currentB=0;
        for(int c=0; c<cols; c++){
            for(int i=0; i<rows; i++){
                if(smArray[i].col==c){
                    b.smArray[currentB].row=smArray[i].col;
                    b.smArray[currentB].col=smArray[i].row;
                    b.smArray[currentB].value=smArray[i].value;
                    currentB++;
                }
            }
        }
    }

    return b;
}

SparseMatrix SparseMatrix::FastTranspose(){
    SparseMatrix B;
    int *RowSize=new int[cols];
    int *RowStart=new int[cols];

    B.rows=cols;
    B.cols=rows;
    B.terms=terms;

    if(terms>0){
        for(int i=0; i<cols; i++){
            RowSize[i]=0;
        }
        for(int i=0; i<terms; i++){
            RowSize[smArray[i].col]++;
        }
        RowStart[0]++;

        for(int i=1; i<cols; i++){
            RowStart[i]=RowSize[i-1]+RowStart[i-1];
        }

        for(int i=0; i<terms; i++){
            int j=RowStart[smArray[i].col];
            B.smArray[j].col = smArray[i].row;
            B.smArray[j].row = smArray[i].col;
            B.smArray[j].value = smArray[i].value;
            RowStart[smArray[i].col]++;
        }

    }
    delete[] RowSize;
    delete[] RowStart;

    return B;
}