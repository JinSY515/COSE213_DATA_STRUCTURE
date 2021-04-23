#include <iostream>
#include <stdlib.h>

int main(){
    int n=10;
    int *m=new int[n];


    int **M =  new int*[n];
    for(int i=0; i<n; i++){
        M[i]=new int[n];
    }

    for(int i=0; i<n; i++){
        delete[] M[i];
    }
    delete[] M;
}
