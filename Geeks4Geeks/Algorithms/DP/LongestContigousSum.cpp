// http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

#include<iostream>
#include<vector>
#include<cstring>


using namespace std;

int max(int a , int b)
{
    return (a>=b)? a : b;
}

int maxSubArraySum(int* a, int  n)
{
    int max_ending_here =0;
    int max_so_far =0;
    for(int i=0; i<n; i++)
    {
        max_ending_here += a[i];
        if(max_ending_here < 0)
            max_ending_here = 0;
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}


// Memoization
int maxSubArraySum2(int* a, int  n)
{
    int max_ending_here =a[0];
    int max_so_far =a[0];
    for(int i=1; i<n; i++)
    {
        max_ending_here = max(a[i], a[i]+max_ending_here);
        max_so_far = max(max_ending_here, max_so_far); ;
    }
    return max_so_far;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum2(a, n);
    cout<<"Maximum contiguous sum is "<< max_sum<<endl;
    return 0;
}
