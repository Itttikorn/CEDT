#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double total=0,count=0,avg=0,input=0;
    while (input!=-1){
        cin >> input;
        if (input!=-1){
            total+=input;
            count+=1;
        }  
    }
    avg = total/count;
    if (count == 0 && input == -1){
        cout << "No Data";
    }else{
        cout << round(avg*100)/100;
    }
}