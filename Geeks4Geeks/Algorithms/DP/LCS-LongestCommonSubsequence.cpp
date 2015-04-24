#include<iostream>
#include<vector>
#include<cstring>


using namespace std;

int max(int a , int b){
    return (a>=b)? a : b;
}

int lcs(char X[], char Y[], int lenX, int lenY){
    if(!lenX || !lenY)
        return 0;
    if(X[lenX-1] == Y[lenY-1])
        return 1 + lcs(X, Y, lenX-1, lenY-1 );
    else
        return max(lcs(X, Y, lenX-1, lenY ), lcs(X, Y, lenX, lenY-1 ));

}

// uses Memoization
int LCS(char *X, char *Y, int m , int n){
    int LCS[m+1][n+1];
    int i,j;
    for(i =0; i<=m; i++){
        LCS[i][0]=0;
    }
    for(j =0; j<=n; j++){
        LCS[0][j]=0;
    }
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(X[i-1] == Y[j-1]) {
                LCS[i][j] = 1 + LCS[i-1][j-1];
            } else {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    return LCS[m][n];
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    cout<<"Length of LCS is "<< lcs( X, Y, m, n )<<endl ;
    cout<<"Length of LCS is (memot)"<< LCS( X, Y, m, n )<<endl ;
////////
    char A[] = "ABCDGH";
    char B[] = "AEDFHR";

    m = strlen(A);
    n = strlen(B);

    cout<<"Length of LCS is "<< lcs( A, B, m, n )<<endl ;
    cout<<"Length of LCS is (memot)"<< LCS( A, B, m, n )<<endl ;

    return 0;
}


