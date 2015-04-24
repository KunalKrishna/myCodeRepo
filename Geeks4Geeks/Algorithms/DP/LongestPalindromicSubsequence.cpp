// http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/

#include<iostream>
#include<vector>
#include<cstring>


using namespace std;

int max(int a , int b)
{
    return (a>=b)? a : b;
}

int lpsRecur(char w[], int start, int end)
{

    if(start == end) // end-1 if n is passed instead of n-1
        return 1;
    if(start > end) // end-1 if n is passed instead of n-1
        return 0;

    if(w[start] == w[end]) // end-1 if n is passed instead of n-1
        return 2 + lpsRecur(w, start+1, end-1);

    return max( lpsRecur(w, start+1, end),
                lpsRecur(w, start,   end-1)
               );
}

// Memoization
int lpsDP(char* str, int  n)
{
    char LPS[n+1][n+1];
    int i,j;
    int width; //width of current substring

    // first row 0
    for(i=0; i<=n; i++)
        LPS[0][i] = 0;
    // first col 0
    for(i=0; i<=n; i++)
        LPS[i][0] = 0;

    // single char string are palindrome of len 1
    for(i=1; i<=n; i++)
        LPS[i][i] = 1;

    for(width=2; width<=n; width++)
    {
        for(i=1; i<=n-width+1; i++)
        {
            j=i+width-1;
            if(str[i] == str[j])
                LPS[i][j] = 2+ LPS[i+1][j-1];
            else
                LPS[i][j] = max( LPS[i][j-1], LPS[i+1][j]);
        }
    }
    return LPS[1][n];
}

int main()
{
    char seq[] = "GEEKSFORGEEKS"; //GEEKSFORGEEKS -5 BBABCBCAB -7 XHAX -3
    int n = strlen(seq);
    cout<<"The length of the LPS is (recursion)   "<<lpsRecur(seq, 0, n-1)<<endl;
    cout<<"The length of the LPS is (Memoization) "<<lpsDP(seq, n);
    return 0;
}
