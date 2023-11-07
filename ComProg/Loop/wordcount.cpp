#include<iostream>
using namespace std;

int main(){
    string search,text;
    getline(cin,text);
    getline(cin,search);

    int searchlength = search.length(),textlength = text.length(),count=0;
    
    for(int i=0;i<searchlength;i++){
        if(search.substr(i,textlength)==text){
            if((i!=0)&&((search[i-1]>='A' &&(search[i-1]<='Z') || (search[i-1]>='a') && (search[i-1]<='z')))){
                count=count;
            }else if((i+textlength < searchlength)&&((search[i+textlength]>='A' &&(search[i+textlength]<='Z') || (search[i+textlength]>='a') && (search[i+textlength]<='z')))){
                count=count;
            }else{
                count++;
            }
        }
    }
    cout << count;
}