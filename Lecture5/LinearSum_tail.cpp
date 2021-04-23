#include <iostream>
using namespace std;

int LinearSum_TR(int *a, int n, int sum){
    if(n==0) return sum;
    else{
        return LinearSum_TR(a, n-1, sum+a[n-1]);
    }
}