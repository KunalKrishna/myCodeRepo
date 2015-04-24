// http://www.geeksforgeeks.org/find-the-missing-number/

#include<iostream>
using namespace std;

int getMissingNo(int a[], int size){

    int x1 =0;
    int i=1;
    for( ; i< size; i++){
        x1 = (x1^a[i-1]) ^ i;
    }
    x1 = x1 ^ i;
    return x1;
}

int main(){

    int a[] = {1, 2, 4, 5, 6};
    cout<<getMissingNo(a, 5);
    return 0;
}
