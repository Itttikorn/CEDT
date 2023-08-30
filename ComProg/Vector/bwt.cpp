#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string x;
    cin >> x;
    string y = x+"$";
    vector<string> table;
    for(int i=0;i<y.length();i++){
        //copy first char
        char temp = y[0];
        //move all to left
        for(int j=1;j<y.length();j++){
            y[j-1] = y[j];
        }
        //paste
        y[y.length()-1]=temp;
        table.push_back(y);
    }
    sort(table.begin(),table.end());
    string encoded="";
    for(auto itr=table.begin();itr!=table.end();itr++){
        string text = *itr;
        cout << text[text.length()-1];
    }
}