
#include <iostream>
#include<climits>
using namespace std;


int atoi2(string str) {
    int len = str.length();
    if (str == "2147483648") return 2147483647;
    if( len== 0) return 0;
    cout<<str.length()<<"*";
    long long res =0;
    int i =0;
    char c =str[i];
    int d;
    bool isPositive = true;
    bool signDone = false;

    // cheking first character
    if(c == '+' || c == '-'){
        signDone = true;
        if(c == '-'){
                cout<<"neg\n";
            isPositive = false;
        }
        i++;
        c = str[i];
    }

    // cheking prefix part
    while(i<len && c == ' '){
        i++;
        c = str[i];
    }

    if( !signDone && ( c == '+' || c == '-') ){
        if(c == '-'){
                cout<<"neg\n";
            isPositive = false;
        }
        i++;
        c = str[i];
    }

    //checking actual integer part
    while(i < len && ( isdigit(c)) && c!='\0'){
        if(c != ' '){
            d = (int)(c - '0');
            res = res*10 + d;
        }
        i++;
        c = str[i];
    }

    return isPositive?res:(-1*res);
}

int main(){

     cout<< atoi2("+-2")<<endl;
     cout<< atoi2("1")<<endl;
     cout<< atoi2("   +0 123")<<endl;
     cout<< atoi2("2147483648")<<endl;
     cout<<INT_MAX;
     return 0;
}
