#include <iostream>
using namespace std;

int linearSum(int *a, int n){
    if(n==1) return a[0];
    else return linearSum(a, n-1)+a[n-1];
}