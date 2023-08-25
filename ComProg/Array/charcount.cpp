#include<iostream>
using namespace std;

int main(){
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int numbers1[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int numbers2[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string text;
    getline(cin,text);
    for(int i=0;i<text.length();i++){
        if(int(text[i])-65>=0 && int(text[i]-65)<26){
            numbers1[int(text[i]-65)]+=1;
            //cout << letters[int(text[i]-65)] << endl;
        }else if(int(text[i])-97>=0 && int(text[i]-97)<26){
            numbers2[int(text[i]-97)]+=1;
            //cout << letters[int(text[i]-97)] << endl;
        }
    }

    //print
    for(int i=0;i<26;i++){
        if(numbers1[i]+numbers2[i]!=0){
            cout << letters[i] << " -> " << numbers1[i]+numbers2[i] << endl;
        }
    }
}