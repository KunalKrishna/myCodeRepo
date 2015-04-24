#include<iostream>
#include<vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    vector<int> result;
    int len = digits.size();
//    cout<<"len "<<len;
    int carry = 1;
    int sum;
    if( len == 0) return result;
    if( len == 1){
        if(digits[0]<9){
            result.push_back(digits[0]+1);

        } else{
            result.push_back(1);
            result.push_back(0);
        }
        return result;
    }
    while(len--){
        sum = digits[len] + carry;
        result.push_back(sum%10);
        cout<<"pusing "<<sum%10;
        carry = sum/10;
    }
    if(carry) {
        result.push_back(1);
        cout<<"pusing "<<1;
    }
    //reverse
    int i =0;
    int j =result.size()-1;
    int temp;
    while(i<j){
        temp = result[i];
        result[i] = result[j];
        result[j] = temp;
        i++;
        j--;
    }
    return result;
}

int main(){
    vector<int> a;
    a.push_back(9);
    a.push_back(9);
    a.push_back(9);

    vector<int> b ;
    std::vector<int>::iterator it;
    b = plusOne(a);
    it = b.begin();
    b.insert (it, a.begin(), a.end());

    cout << "myvector contains:";
    for (it=b.begin(); it<b.end(); it++)
        cout << ' ' << *it;
    cout << '\n';
    return 0;
}


