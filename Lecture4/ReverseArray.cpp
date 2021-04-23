#include <iostream>

using namespace std;

void ReverseArray(int*a, int i, int j){
    if(i<j){
        int tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
        ReverseArray(a, i+1,j-1);
    }
    return;
}