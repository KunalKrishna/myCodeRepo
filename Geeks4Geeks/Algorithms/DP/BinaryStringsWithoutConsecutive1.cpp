// http://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int max(int a , int b)
{
    return (a>=b)? a : b;
}

// Memoization
int countStrings(int n)
{
    int a[n],b[n];
    a[0] = 1;
    b[0] = 1;

    for(int i=1; i<n; i++){
        a[i] = a[i-1] + b[]
    }

    return 0;
}

int main()
{
    cout << countStrings(3) << endl;
    return 0;
}


