
#include <iostream>
#include <climits>
#include <cmath>
#include <map>
using namespace std;

int romanToInt(string s) {
    map<char,int> mymap;

    mymap.insert ( std::pair<char,int>('I',1) );
    mymap.insert ( std::pair<char,int>('V',5) );
    mymap.insert ( std::pair<char,int>('X',10) );
    mymap.insert ( std::pair<char,int>('L',50) );
    mymap.insert ( std::pair<char,int>('C',100) );
    mymap.insert ( std::pair<char,int>('D',500) );
    mymap.insert ( std::pair<char,int>('M',1000) );

    int len = s.length();
    if(len == 0) return 0;
    if(len == 1) return mymap.find(s[0])->second;
    int result = mymap.find(s[len-1])->second;
//    cout<<result;
    int prev;
    int current;
    int i;
    for( i =len-2 ; i>=0; i--){
        prev = mymap.find((char)s[i+1])->second;
        current = mymap.find((char)s[i])->second;
        if(prev>current){
            result = result - current;
        }else{
            result = result + current;
        }
    }
    return result;
}

int main(){
    cout<<romanToInt("XI")<<endl;
    cout<<romanToInt("IX")<<endl;
    cout<<romanToInt("II")<<endl;
    cout<<romanToInt("III")<<endl;
    cout<<romanToInt("XIII")<<endl;
    return 0;
}
