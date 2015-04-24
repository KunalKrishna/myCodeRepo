#include<iostream>


using namespace std;

int max(int a , int b){
    return (a>=b)? a : b;
}

int maxSumSubSequence(int arr[], int n){

    int maxSum[n];
    int i,j;
    int maxPos=0;
    maxSum[0] = arr[0];
    int maximum;
    int res=arr[0];

    cout<<"maxSum["<<0<<"] = "<< maxSum[0]<< "\n";
    for(i=1; i<n; i++){
        maximum = maxSum[i-1];
        for(j=i-1; j>=0; j--){
            if(arr[j]>maximum){
                maximum =maxSum[i-1];
            }
        }
        maxSum[i] = max( maximum + arr[i], arr[i]);
        cout<<"maxSum["<<i<<"] = "<< maxSum[i]<< "\n";
        if(maxSum[i]>res){
            res = maxSum[i];
            cout<<"result updated to "<<res<<endl;
        }
    }
    return res;
}

int main()
{
    int input[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(input)/sizeof(input[0]);

    cout<<maxSumSubSequence(input, n);
    return 0;
}


