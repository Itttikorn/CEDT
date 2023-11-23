#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    int one = 0,two = 0, three = 0;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        v.push_back(in);
        if(in == 1) one++;
        if(in == 2) two++;
        if(in == 3) three++;
    }
    int count = 0, j=one;
    for(int i=0;i<one;i++){
        if(v[i]==2){
            while(j<n && v[j]!=1) j++;
            count++;
            //cout << "swapping" << i << j << endl;
            swap(v[i],v[j]);
        }
    }
    for(int i=0;i<one;i++){
        if(v[i]==3){
            while(j<n && v[j]!=1) j++;
            count++;
            swap(v[i],v[j]);
        }
    }
    j=one+two;
    for(int i=one;i<one+two;i++){
        if(v[i]==3){
            while(j<n && v[j]!=2) j++;
            count++;
            swap(v[i],v[j]);
        }
    }
    
    // for(auto &x : v){
    //     cout << x;
    // }
    cout << count;
    
}