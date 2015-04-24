#include<iostream>
#include<cstring>
using namespace std;

bool smaller(){

}
bool foo(string s, string t){
    int len = s.length();
    bool flag =false;
    int curr;
    for(int i = len-1; i>=0; i--){
        if(s[i] < t[i] ){
            curr =i;
            break;
        }
    }
//    cout<<"fpd = "<<curr <<endl;
    for(int i = curr; i>=0; i--){
        string temp = s;
        while(temp[i] < t[i]){
//            cout<<"trying "<<temp[i]<<"->";
            temp[i] +=1;
//            cout<<" with "<<temp[i]<<endl;
            if(temp.compare(t)<0){
                cout<<temp;
                return true;
            }
        }
    }
    return flag;
}

int main()
{
    string a;
    string b;
    cin>>a>>b;
    if(!foo(a,b)){
        cout<<"No such string";
    }
    return 0;
}
