// http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/

#include<iostream>
#include<vector>
#include<climits>


using namespace std;

int max(int a , int b)
{
    return (a>=b)? a : b;
}

int knapSack(int W, int w[], int val[], int n)
{
    if(n == 0 || W == 0)
        return 0;

    if(W < w[n-1])
        return knapSack(W, w, val, n-1);

    return max( val[n-1]+ knapSack(W-w[n-1] ,w, val, n-1),
                knapSack(W, w, val, n-1));
}

// Memoization
int knapSackDP(int price[], int n)
{

    return 0;
}

int main()
{
//    int val[] = {60, 100, 120};
//    int wt[]  = {10, 20, 30};
//    int  W = 50;

    int val[] = {10, 20, 30};
    int wt[]  = {1, 1, 1};
    int  W = 2;

    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSack(W, wt, val, n);
    return 0;
}
