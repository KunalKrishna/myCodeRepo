
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

bool areSame(char a, char A){
    int diff = (int )(a-A);
    //cout<<" diff = "<<diff<<" ";
    diff = abs(diff);
    if (diff == 0 || diff == 32)
        return true;
    return false;
}

bool isCharacter(char c){
    //cout<<"character testing of ... "<< c << " : ";
    if( (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') ){
        //cout<< "OK \n";
        return true;
    }
    //cout<<" failed \n";
    return false;
}
bool isPalindrome(string s) {
        int len = s.length();
        if( len <2) return true;

        int start = 0;
        int end = len-1;
        while(start<end){
            //cout<< "start = " <<start<< " end= "<<end <<" "<<endl;
           // cout<< "s[start] =\"" <<s[start] <<"\" :: s[end] =\""<<s[end]<<"\""<<endl;
            while(start<end && !isCharacter(s[start]) ){
                    //cout<<"incrementing ... \n";
                start++;
            }
            //cout<< "start = " <<start<< " end= "<<end <<" "<<endl;
            //cout<< "s[start] =\"" <<s[start] <<"\" :: s[end] =\""<<s[end]<<"\""<<endl;
            while( start<end && !isCharacter(s[end]) ){
                //cout<<"decrementing ... \n";
                end--;
            }

            if( start<end && !areSame(s[start], s[end]) ){
                    //cout<< "start = " <<start<< " end= "<<end <<" "<<endl;
                   // cout<< "s[start] =\"" <<s[start] <<"\" :: s[end] =\""<<s[end]<<"\""<<endl;;
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

int main(){
/*
    if(isPalindrome("A man, a plan, a canal: Panama")){
        cout<<"yes\n";
    }else{
        cout<<"No\n";
    }

    if(isPalindrome("race a car")){
        cout<<"yes\n";
    }else{
        cout<<"No\n";
    }
*/
    if(isPalindrome("1, 2: 1")){
        cout<<"yes\n";
    }else{
        cout<<"No\n";
    }

     return 0;
}
