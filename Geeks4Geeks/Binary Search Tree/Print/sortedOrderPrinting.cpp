// http://www.geeksforgeeks.org/sorted-order-printing-of-an-array-that-represents-a-bst/

#include<iostream>
using namespace std;
void printSorted(int a[], int index, int size)
{
    if(index>size)
        return;
    printSorted(a, 2*index +1, size);
        cout<<a[index]<<" ";
    printSorted(a, 2*index +2, size);
}

int main()
{
  int arr[] = {4, 2, 5, 1, 3};
  int arr_size = sizeof(arr)/sizeof(int);
  printSorted(arr, 0, arr_size-1);

  return 0;
}
