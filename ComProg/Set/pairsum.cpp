#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int in;
    set<int> numbers;
    while(cin >> in){
        numbers.insert(in);
    }
    // for(auto itr=numbers.begin();itr!=numbers.end();itr++){
    //     cout << *itr << " ";
    // }
    //cout << endl;
    // auto pos = numbers.end();
    // for(int i=n;i>=0;i--){
    //     auto itr = numbers.find(i);
    //     if(itr!=numbers.end()){
    //         itr++;
    //         pos=itr;
    //         //cout << "found" << i << endl;
    //         break;
    //     }
    // }
    int count=0;
    // for(auto itr=numbers.begin();itr!=pos;itr++){
    //     for(auto jtr=itr;jtr!=pos;jtr++){
    //         //cout << *itr << "+" << *jtr << endl;
    //         if(itr==jtr){
    //             continue;
    //         }else if(*itr + *jtr == n){
    //             //cout << *itr << "+" << *jtr << endl;
    //             count++;
    //         }
    //     }
    // }

    int half = n/2;
    for(int i=0,j=n;i<half;i++,j--){
        if(numbers.find(i)!=numbers.end() && numbers.find(j)!=numbers.end()){
            //cout << *numbers.find(i) << "+" << *numbers.find(j) << endl;
            count++;
        }
    }
    cout << count;
}