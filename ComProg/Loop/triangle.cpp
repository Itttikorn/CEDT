#include<iostream>
using namespace std;

int main(){
    int height;
    cin >> height;
    int i=1,dots,dotsmid;
    dots = height;
    dotsmid = -3;
    while(i<=height){
        dots--;
        dotsmid+=2;
        if(i==1){
            for(int n=1;n<height;n++){
                cout<<".";
            }
            cout<<"*"<<endl;
        }else if (i==height){
            for(int n=1;n<height*2;n++){
                cout<<"*";
            }
        }else{
            for(int n=1;n<=dots;n++){
                cout<<".";
            }
            cout<<"*";
            for(int n=1;n<=dotsmid;n++){
                cout<<".";
            }
            cout<<"*"<<endl;
        }
        i++;
    }
}