// http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
// https://www.youtube.com/watch?v=uufaK2uLnSI&list=PL2_aWCzGMAwL3ldWlrii6YeLszojgH77j&index=7

#include<stdio.h>
using namespace std;

int pivotedBinarySearch(int a[], int size, int key){

    int low = 0;
    int high = size-1;
    int mid;
    while(low <= high ){
        mid = low + (high-low)/2;
        if(a[mid] == key)
            return mid;
        if( a[low] <= a[mid] ){
            if( key>=a[low] && key <a[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        if( a[mid] <= a[high] ){
            if(key>a[mid] && key<=a[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}

int main(){

    // Let us search 3 in below array
   int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int arr_size = sizeof(arr1)/sizeof(arr1[0]);
   int no = 3;
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr1, arr_size, no));

    // Let us search 3 in below array
   int arr2[] = {3, 4, 5, 1, 2};
   arr_size = sizeof(arr2)/sizeof(arr2[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr2, arr_size, no));

   // Let us search for 4 in above array
   no = 4;
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr2, arr_size, no));

   // Let us search 0 in below array

   return 0;
}
