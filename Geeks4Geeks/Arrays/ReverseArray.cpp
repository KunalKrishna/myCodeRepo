// http://www.geeksforgeeks.org/write-a-program-to-reverse-an-array/

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

void reverseArrayRec(int a[], int left, int right){
    if(right <= left) return;

    int temp = a[left];
    a[left] = a[right];
    a[right] = temp;

    reverseArrayRec(a, left+1, right-1);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

/* Driver function to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    printArray(arr, 6);
    reverseArray(arr, 0, 5);
    cout<<"Reversed array is \n";
    printArray(arr, 6);

    cout<<endl;
    printArray(arr, 6);
    reverseArrayRec(arr, 0, 5);
    cout<<"Reversed array is \n";
    printArray(arr, 6);

    cout<<endl;
    int arr2[] = {10, 20, 30, 40, 50};
    printArray(arr2, 5);
    reverseArray(arr2, 0, 4);
    cout<<"Reversed array is \n";
    printArray(arr2, 5);

    cout<<endl;
    printArray(arr2, 5);
    reverseArrayRec(arr2, 0, 4);
    cout<<"Reversed array is \n";
    printArray(arr2, 5);

    return 0;
}
