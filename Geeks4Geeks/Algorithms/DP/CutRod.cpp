// http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/

#include<iostream>
#include<vector>
#include<climits>


using namespace std;

int max(int a , int b)
{
    return (a>=b)? a : b;
}

int cutRod(int price[], int n)
{
    if(n<=0) return 0;
    int max_val = INT_MIN;

    for(int i=0; i<n; i++)
        max_val = max(max_val, price[i]+ cutRod(price, n-i-1));
    return max_val;
}

// Memoization
int cutRod2(int price[], int n)
{
    int val[n+1];
    val[0] = 0;
    int max_val;

    for(int i=1; i<=n; i++)
    {
        max_val = INT_MIN;
        for(int j=0; j<i; j++)
            max_val = max( max_val, price[j]+ val[i-j-1]);
        val[i]=max_val;
    }
    return val[n];
}

int main()
{
    int price[] ={ 1,   5,   8,   9,  10,  17,  17,  20};
    int size = sizeof(price)/sizeof(price[0]);
//    cout<< cutRod(price, size);
    cout<< cutRod2(price, size);
    return 0;
}


