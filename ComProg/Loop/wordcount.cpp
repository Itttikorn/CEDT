#include<iostream>
using namespace std;

int main(){
    string search,text;
    getline(cin,search);
    getline(cin,text);

    int n=0,count=0;
    
    while(n<text.length()){
        if (text.find(search,n)!=string::npos){
            n = text.find(search,n);
            count++;
        }
        n++;
    }
    cout << count;
}