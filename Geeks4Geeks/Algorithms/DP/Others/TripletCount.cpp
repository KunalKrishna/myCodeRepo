// http://www.geeksforgeeks.org/myntra-interview-experience-set-4-for-senior-software-engineer/

#include<iostream>
#include<vector>
#include<climits>


using namespace std;

int max(int a , int b)
{
    return (a>=b)? a : b;
}

int tripletCount(int a[], int i, int k, int sum)
{
    if( i>= k || k-i == 1) return 0;
    int count = 0;

    if(a[i] < a[k]){
        cout<<"processing " <<i<<" & "<<k<<endl;
        for(int j=i+1; j<k; j++){
            if( a[i] < a[j] && a[j] < a[k] ){
                if( a[i]+a[j]+a[k] == sum ){
                    count =1;
                    cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<"\n";

                }
            }
        }
    }
    return count + tripletCount(a, i, k-1, sum) + tripletCount(a, i+1, k, sum);
}

int tripletCount2(int a[], int n, int sum)
{
    int aux[n][n]; // n=9
    int width,i,r,c;
    for(i=0; i<=n-2; i++){
        aux[0][0] =0;
        aux[i][i+1]=0;
    }
    //aux[n-1][n-1] = 0;

    for(width=2; width<=n-1; width++)
    {
        for(i=0; i<n-width; i++){
            r = i;
            c = i+width;
            //aux[r][c] = tripletInRange(a, c-width, c, sum) + aux[r][c-1]+aux[r+1][c];
            cout<<"aux["<<r<<"]["<<c<<"] = "<<aux[r][c]<<" ";
        }
        cout<<endl;
    }
    return aux[0][n-1];
}

int main()
{
    int arr[] ={ 0, 1 ,3 ,9, 2, 7, 8, 4, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    cout<< tripletCount(arr, 0, size-1, sum);
    //cout<< tripletCount2(arr, size, sum);
    return 0;
}


