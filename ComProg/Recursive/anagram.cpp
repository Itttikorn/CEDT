#include<bits/stdc++.h>
using namespace std;

string rotate(string s){
    string temp = s+s;
    int stringsize = s.length();
    return temp.substr(1,stringsize);
}

void anagram(set<string> &ana,string &s,int l,int r){
    if(l==r){
        ana.insert(s);
    }
    for(int i=l;i<=r;i++){
        swap(s[i],s[l]);
        anagram(ana,s,l+1,r);
        swap(s[i],s[l]);
    }
}

int main(){
    string s;
    cin >> s;
    set<string> ana;
    anagram(ana,s,0,s.length()-1);
    for(auto itr=ana.begin();itr!=ana.end();itr++){
        cout << *itr << endl;
    }
}