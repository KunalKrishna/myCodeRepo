// http://www.geeksforgeeks.org/check-binary-representation-number-palindrome/

#include<iostream>
using namespace std;

bool isKthBitSet(unsigned int x, int k){
    return x & (1<(k-1)) ? 1 : 0;

}

bool isPalindrome(unsigned int x){
    int l = 1;
    int r =sizeof(unsigned int)*8;

    while(l<r){
        if(isKthBitSet(x, l) != isKthBitSet(x, r)){
            return false;
        }
        l++; r--;
    }
    return true;
}

int main()
{
    unsigned int x = 1<<15 + 1<<16;
    cout << isPalindrome(x) << endl;
    x= 1783;
    unsigned int y = 0xFF;
    cout<<"y = " <<x & 0xFF;

    x = 1<<5;
    cout<<"x = " <<x<<endl;
    x += 1<<6 ;
    cout<<"x = " <<x<<endl;
    cout << isPalindrome(x) << endl;

    x = 1<<31 + 1;
    cout << isPalindrome(x) << endl;

    x = 2;
    cout << isPalindrome(x) << endl;


    return 0;
}
