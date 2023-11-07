#include<bits/stdc++.h>
using namespace std;

int main(){
    string one,two;
    getline(cin,one);
    getline(cin,two);
    multiset<char> setone;
    multiset<char> settwo;
    for(int i=0;i<one.length();i++){
        if(one[i]!=' '){
            if(one[i]>='a' && one[i]<='z'){
                setone.insert(char(one[i]-('a'-'A')));
            }else{
                setone.insert(one[i]);
            }
        }
    }
    // for(auto itr=setone.begin();itr!=setone.end();itr++){
    //     cout << *itr << " ";
    // }
    // cout << endl;
    for(int i=0;i<two.length();i++){
        if(two[i]!=' '){
            if(two[i]>='a' && two[i]<='z'){
                settwo.insert(char(two[i]-('a'-'A')));
            }else{
                settwo.insert(two[i]);
            }
        }
    }
    // for(auto itr=settwo.begin();itr!=settwo.end();itr++){
    //     cout << *itr << " ";
    // }
    // cout << endl;
    if(setone==settwo){
        cout << "YES";
    }else{
        cout << "NO";
    }
}