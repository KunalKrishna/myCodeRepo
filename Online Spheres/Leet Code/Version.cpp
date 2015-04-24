#include <iostream>
#include <vector>
using namespace std;

double strToDouble(string version){

    int i=0;
    int left=0;
    double right=0;
    char c = version[i];
    left = c-'0';
    int a;
    c = version[++i];
    while(c != '\0' && c != '.' ){
        a = (int)(c - '0');
        left = left*10 + a;
        c = version[++i];
    }
    double divider = 1;
    c = (c !='\0') ? version[++i]: '\0';
    while(c != '\0' && c != '.' ){
        a = (int)(c-'0');
        divider = divider/10;
        right = right + a*divider;
        c = version[++i];
    }
    return (left + right);
}

int compareVersion(string version1, string version2) {
    double v1 = strToDouble(version1);
    double v2 = strToDouble(version2);
    cout<<"v1 = "<<v1 <<endl;
    cout<<"v2 = "<<v2 <<endl;
    if(v1>v2){
        return 1;
    }else if( v1 < v2){
        return -1;
    }else{
        if (version1.find(".") != string::npos) {
            if(version1.length() < version2.length())
                return -1;
            if(version1.length() > version2.length())
                return 1;
        }
    }
    return 0;
}


int main() {

	string v1 = "1.2";
	string v2 = "1.10";
	cout<<compareVersion(v1,v2);
	return 0;
}

