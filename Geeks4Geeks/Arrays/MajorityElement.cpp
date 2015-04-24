// http://www.geeksforgeeks.org/majority-element/

#include<iostream>
using namespace std;

int findCandidate(int a[], int size){
    int count =1;
    int pos  =0;

    for(int i=1; i<size; i++){
        if(a[pos] == a[i]){
            count++;
        }else{
            count--;
        }
        if(count == 0){
            pos = i;
            count =1;
        }
    }
    return a[pos];
}

bool isMajority(int a[], int size, int cand){
    int count =0;
    while(size){
        if(a[size--] == cand){
            count++;
            if(count > size/2)
                return true;
        }
    }
    return false;
}

void printMajority(int a[], int size){

    int cand = findCandidate(a, size);

    if(isMajority(a, size, cand)){
        cout<<"Majority element = "<<cand<<endl;
    }else{
        cout<<"No majority element\n";
    }
}


int main(){

    int a[] = {1, 3, 3, 1, 2,3,3};
    printMajority(a, 7);
    return 0;
}
