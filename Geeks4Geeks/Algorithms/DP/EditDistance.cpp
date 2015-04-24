// http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/

#include<iostream>
#include<vector>
#include<climits>
#include<cstring>

#define R 3
#define C 3

using namespace std;

int min ( int a, int b)
{
    return (a<b)?a:b;
}

int Minimum(int a, int b, int c)
{
    return min( min(a,b),c);
}
int minDep(int a , int b, int c)
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

int EditDistanceRecursion(char X[], char Y[], int m, int n)
{
    if(m==0 && n==0) return 0;

    // n insertion
    if(m==0) return n;

    // m deletion
    if(n==0) return m;
/*
    int diff = (X[m-1] != Y[n-1]);

    int insert_ =
    int delete_ =
    //if last chars of both string are same then retain else replace
    int replace_retain = EditDistanceRecursion(X,Y,m-1,n-1)+diff;
*/
//    return Minimum(insert_, delete_, replace_);

    return Minimum(EditDistanceRecursion(X,Y,m-1,n)+1,
                   EditDistanceRecursion(X,Y,m,  n-1)+1,
                   EditDistanceRecursion(X,Y,m-1,n-1)+ (X[m-1] != Y[n-1])
                    );
}


// Memoization
int EditDistanceDP(char X[], char Y[])
{
    int m = strlen(X)+1;
    int n = strlen(Y)+1;

    int result[m][n];

    int i=0;
    int j=0;

    for(i=0 ; i<m; i++)
        result[i][0] = i;

    for(j=0 ; j<n; j++)
        result[0][j] = j;

    for(i=1; i<m; i++)
    {
        for(j=1; j<n; j++)
        {
            result[i][j] = Minimum(result[i-1][j]+1,
                                   result[i][j-1],
                                   result[i-1][j-1]+ (X[i]!=Y[j])
                                   );
        }
    }
    return result[m-1][n-1];
}

int main()
{
    char X[] = "SATURDAY"; // vertical
    char Y[] = "SUNDAY";   // horizontal
//
//    //test 2
//    char X[] = "DOG";
//    char Y[] = "DOF";   // 1
//    //test 3
//    char X[] = "ACT";
//    char Y[] = "CAT";   // 2
    //test 4
//    char X[] = "CAT";
//    char Y[] = "DOG";   // 3

    cout<<"Minimum edits required to convert "<< X<<" into "<<Y<<" is "<< EditDistanceDP(X, Y)<<"\n";
    cout<<"Minimum edits required to convert "<< X<<" into "<<Y<<" is "<<
                     EditDistanceRecursion(X, Y,strlen(X), strlen(Y))<<" by recursion\n";

    return 0;
}


