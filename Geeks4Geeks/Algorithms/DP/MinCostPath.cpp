// http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/

#include<iostream>
#include<vector>
#include<climits>

#define R 3
#define C 3

using namespace std;

int min(int a , int b, int c)
{
    if(a<b)
    {
        if(a<c)
            return a;
        return c;
    } else
    {
        if(b<c)
            return b;
        return c;
    }
}

int minCost(int cost[R][C], int m, int n)
{
    if(m<0 || n<0) return INT_MAX;

    if(m==0 && n==0) return cost[0][0];

    return cost[m][n] + min( minCost(cost, m-1,n-1),
                             minCost(cost, m  ,n-1),
                             minCost(cost, m-1,n)
                            );
}

// Memoization
int minCost2(int cost[R][C])
{
    int aux[R][C];
    int j=0 ,  i=0;

    aux[0][0] = cost[0][0];
    for(j=1; j<C; j++){
        aux[0][j] = aux[0][j-1] + cost[0][j];
    }

    for(i=1; i<R; i++){
        aux[i][0] = aux[i-1][0] + cost[i][0];
    }

    for(i=1; i<R; i++){
        for(j=1; j<C; j++){
            aux[i][j] =cost[i][j] + min( aux[i-1][j-1],
                                         aux[i][j-1],
                                         aux[i-1][j]);
        }
    }
    return aux[R-1][C-1];
}

int main()
{
    int cost[R][C] = {{1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3}};
//    cout<< minCost(cost, 2, 2);
    cout<< minCost2(cost);
    return 0;

}


