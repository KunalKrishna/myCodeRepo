// http://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/

#include<iostream>
using namespace std;

void reverseArray(int a[], int left, int right){
    if(right <= left) return;
    for(; left<right; left++,right--){
        int temp = a[left];
        a[left] = a[right];
        a[right]=temp;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

void leftRotate(int a[], int d, int size){
    if(d>0 && size >1){
        reverseArray(a, 0, d-1);
        reverseArray(a, d, size-1);
        reverseArray(a, 0, size-1);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    leftRotate(arr, 2, 7);
    printArray(arr, 7);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    leftRotate(arr2, 6, 7);
    printArray(arr2, 7);


    return 0;
}
