#include<iostream>
#include<stdlib.h>

using namespace std;

int sqrt(int x){
    int start = 0;
    int end   = x;
    int mid = x/2;
    if(x==1) return x;
    while(start <= end){
        mid = start+(end-start)/2;
        if(mid*mid == x){
            return mid;
        }else if(mid*mid < x){
            start = mid;
        }else{
            end = mid;
        }
    }
    return -1;
}

int main(){
    cout<<sqrt(2);

    return 0;

}
