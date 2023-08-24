#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int n[num];
    int count=0;
    for(int i=0;i<num;i++){
        cin >> n[i];
    }
    for(int i=1;i<num-1;i++){
        if(n[i]>n[i-1] && n[i] > n[i+1]){
            count++;
        }
    }
    cout << count;
}