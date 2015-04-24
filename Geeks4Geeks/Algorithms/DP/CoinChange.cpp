// http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/

#include<iostream>
#include<vector>
#include<climits>


using namespace std;

int max(int a , int b)
{
    return (a>=b)? a : b;
}

int coinChangeRecur(int coins[], int n, int sum)
{
    if(sum == 0)
        return 1; // only one way : CHOOSE NONE

    if(sum < 0)
        return 0; // no way to choose such arrangement

    if(n<=0 && sum>=1)
        return 0; // how many ways can one choose sum of >=1 from no given coin set? NONE

    int includeNthCoin = coinChangeRecur(coins, n, sum-coins[n-1]); // choose last and keep the possibility of choosing it again
    int excludeNthCoin = coinChangeRecur(coins, n-1, sum); // discard it now and for the subsequent rounds
    return includeNthCoin + excludeNthCoin;
}

// Memoization
int coinChangeDP(int coiins[], int n, int sum)
{
    int i,j, x,y;
    int table[sum+1][n];
    for(i=0; i<n; i++)
    {
        table[0][i] = 1;
    }
    for(i=1; i<sum+1; i++){
        for(j=0; j<m; j++){
            x = (i-S[j] )
        }
    }

    return 0;
}

int main()
{
    int arr[] = {1, 2, 3};
    int n= = sizeof(arr)/sizeof(arr[0]);
    cout<< coinChangeRecur(arr, n, 4);

    //cout<< coinChangeDP(arr, m, 4));
    return 0;
}


