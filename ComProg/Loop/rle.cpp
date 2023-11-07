#include<iostream>
using namespace std;

int main(){
    string input;
    cin >> input;
    char search;
    int count=1;
    for(int i=0;i<input.length();i++){
        search = input[i];
        if(input[i]==input[i+1]){
            count++;
        }else{
            cout << input[i] << " " << count << " ";
            count=1;
        }
        
    }
}