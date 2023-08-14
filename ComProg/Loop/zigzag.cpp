#include<iostream>
using namespace std;

int main(){
    int input=0,leftmax=0,rightmax=0,leftmin=0,rightmin=0,mode=0,count=1;
    while(input!= -998 || input!=-999){
        cin >> input;
        if(input==-998){
            mode=input;
            break;
        }else if(input==-999){
            mode=input;
            break;
        }
        if(count%4==1 || count%4==0){
            if(count==1){
                leftmax=input,leftmin=input;
            }
            if(input>leftmax){
                leftmax=input;
            }else if(input<leftmin){
                leftmin=input;
            }
        }else if(count%4==2 || count%4==3){
            if(count==2){
                rightmax=input,rightmin=input;
            }
            if(input>rightmax){
                rightmax=input;
            }else if(input<rightmin){
                rightmin=input;
            }
        }
        count++;
    }
    if(mode==-998){
        cout << leftmin << " " << rightmax;
    }else if(mode==-999){
        cout << rightmin << " " << leftmax;
    }
}