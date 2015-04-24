#include<iostream>
#include<climits>


using namespace std;

int max(int a , int b){
    return (a>=b)? a : b;
}

int LIS(int A[], int n){
    int LS[n]; // L[i] : Length of Increasing Subsequence whose last element is A[i]
    int i, j;
    int res =1;
    LS[0] =1;
    int maxim;

    for(i=1; i<n; i++) {
        maxim = INT_MIN;
        for(j=i-1; j>=0; j--) {
            if( A[i]>A[j] ){
                if(LS[j]>maxim){
                    maxim = LS[j];
                }
            }
        }
        LS[i] = 1 + maxim;
        // maintains the result , avoid seperate loop to find max
        if(LS[i]>res){
            res = LS[i];
        }
    }
    return res;
}

int main()
{
    int input[]={2, 7, 3, 4, 9, 8, 12};
//    int input[]={10, 22, 9, 33, 21, 50, 41, 60};
//    int input[]={9,8};
    int n = sizeof(input)/sizeof(input[0]);

    cout<<LIS(input, n);
    return 0;
}


