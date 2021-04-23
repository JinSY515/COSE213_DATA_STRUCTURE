#include <iostream>
#include <vector>
using namespace std;

bool isUnique_re(int *a, int start, int end){
    if(start>=end) return true;
    
    if(!isUnique_re(a, start, end-1)) return false;
    if(!isUnique_re(a, start+1, end)) return false;

    return (a[start]!=a[end]);
}

bool isUnique_ite(int *a, int start, int end){
    if(start>=end) return true;
    for(int i=start; i<end; i++){
        for(int j=i+1; j<=end; j++){
            if(a[i]==a[j]) return false;
        }
    }
    return true;
}
