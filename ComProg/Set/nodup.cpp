#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int count=1;
    set<int> number;
    //first num
    cin >> n;
    number.insert(n);
    bool found=false;
    while(cin >> n){
        count++;
        if(number.find(n)!=number.end()){
            found=true;
            break;
        }else{
            number.insert(n);
        }
    }
    if(found==false){
        count=-1;
    }
    cout << count;
}