#include <iostream>

using namespace std;

void ReverseArray_iter(int*a, int i, int j){
    while(i<j){
        int tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;

        i++;
        j--;
    }
    return;
}