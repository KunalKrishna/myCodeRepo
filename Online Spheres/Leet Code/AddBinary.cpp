#include<iostream>
#include<cstring>
using namespace std;

string reverseStr(char arr[], int len){
    int i=0;
    char c;
    cout<<"\narr = ";
    while(( c = arr[i])!='\0'){
        cout<<c<<" ";
        i++;
    }
    string result="";
    len--;
    while(len--){
        result = result + arr[len];
    }
//    cout<<"\nResult = "<<result<<" ";
    return result;
}

string addBinary(string a, string b) {
    int lenA = a.length();
    int lenB = b.length();
//    cout<<"lenA = "<<lenA << " lenB = "<<lenB<<endl;
    if( !lenA ) {return b;}
    if( !lenB ) {return a;}

    char result[1000];
    int c =0;
    int s =0;
    int pos =0;
    int digitA;
    int digitB;
    lenA--;lenB--;
    while(lenA>=0 && lenB>=0){
//            cout<<"lenA = "<<lenA;
//            cout<<" lenB = "<<lenB;
        digitA = (int) (a[lenA]-'0');
        digitB = (int) (b[lenB]-'0');
//        cout<<"\ndigitA= "<<digitA<<" digitB= "<<digitB;
        int sum = digitA + digitB + c;
        s  =sum%2;
        c = sum/2;
//        cout<<"\n result["<<pos<<"]= "<<s<<endl;
        result[pos++] = (s) ? '1':'0';
        lenA--;
        lenB--;
    }
    while(lenA>=0){
        digitA = (int) (a[lenA]-'0');
//        cout<<"\ndigitA= "<<digitA<<endl;
        int sum = digitA  + c;
        s = sum%2;
        c = sum/2;
//        cout<<"\n result["<<pos<<"]= "<<s<<endl;
        result[pos++] = (s) ? '1':'0';
        lenA--;
    }
    while(lenB>=0){
        digitB = (int) (b[lenB]-'0');
//        cout<<"\ndigitB= "<<digitB<<endl;
        int sum = digitB  + c;
        s = sum%2;
        c = sum/2;
//        cout<<"\n result["<<pos<<"]= "<<s<<endl;
        result[pos++] = (s) ? '1':'0';
        lenB--;
    }
    if(c)
        result[pos++] =(char)(((int)'0')+c);
    result[pos++] = '\0';

    return reverseStr(result, pos);
}

int main(){
    string a = "101";
    string b = "1";
//    cout<<a<<b;
    cout<<addBinary(a, b);
    return 0;
}
