#include <iostream>

template <class KeyType>
void sort(KeyType *a, int n){
    for(int i=0; i<n; i++){
        int j=i;

        for(int k=i+1; k<n; k++){
            if(a[k]<a[j]) j=k;
        }

        KeyType tmp=a[j];
        a[j]=a[i];
        a[i]=tmp;
    }
}