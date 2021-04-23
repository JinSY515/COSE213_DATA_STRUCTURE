#include <iostream>
using namespace std;

int binarySum(int *a, int i, int n){
    if(n==1) return a[i];
    return binarySum(a, i, n/2)+binarySum(a, i+n/2, n/2);
}