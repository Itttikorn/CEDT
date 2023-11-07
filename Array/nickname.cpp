#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    string names[10][2] = {{"Robert","Dick"},{"William","Bill"},{"James","Jim"},{"John","Jack"},{"Margaret","Peggy"},{"Edward","Ed"},{"Sarah","Sally"},{"Andrew","Andy"},{"Anthony","Tony"},{"Deborah","Debbie"}};
    for(int i=0;i<num;i++){
        string searchfor;
        cin >> searchfor;
        bool found=false;
        string answer;
        for(int j=0;j<10;j++){
            if(searchfor==names[j][0]){
                answer = names[j][1];
                found=true;
                break;
            }
            if(searchfor==names[j][1]){
                answer = names[j][0];
                found=true;
                break;
            }
            
        }
        if(found==true){
            cout << answer << endl;
        }else{
            cout << "Not found" << endl;
        }
    }

}