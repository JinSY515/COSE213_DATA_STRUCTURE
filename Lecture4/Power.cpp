#include <iostream>

using namespace std;

int power(int x, int n){
    int y;
    if(n==0)  return 1;
    if(n%2==0){
        y=power(x, (n-1)/2);
        return x*y*y;
    }
    else{
        y=power(x, n/2);
        return y*y;
    }
}