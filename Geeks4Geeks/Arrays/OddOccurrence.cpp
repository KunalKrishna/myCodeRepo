// http://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/

#include<iostream>
using namespace std;

int getOddOccurrence(int a[], int size){
    int res =0;
    for(int i=0; i< size; i++){
        res = res^a[i];
    }
    return res;

}

int main(){

    int ar[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
     int n = sizeof(ar)/sizeof(ar[0]);
     cout<< getOddOccurrence(ar, n);
     return 0;
}
