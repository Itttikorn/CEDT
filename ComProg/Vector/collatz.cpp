#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    v.push_back(n);
    int count=1;
    while(n!=1){
        if(n%2==0){
            n=n/2;
            if(count>14){
                v.erase(v.begin());
            }
            v.push_back(n);
            count++;
        }else{
            n=3*n+1;
            if(count>14){
                v.erase(v.begin());
            }
            v.push_back(n);
            count++;
        }
    }
    //string result="";
    for(auto itr=v.begin();itr!=v.end();itr++){
        cout << *itr;
        if(itr!=v.end()-1){
            cout << "->";
        }
    }

}