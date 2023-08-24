#include<iostream>
#include<string>
using namespace std;

int main(){
    int num;
    cin >> num;
    string feelist[num][2];
    for(int i=0;i<num;i++){
        for(int j=0;j<2;j++){
            cin >> feelist[i][j];
        }
    }
    cin.ignore();
    string iternary;
    getline(cin,iternary);
    string previous = iternary.substr(4,2);
    string landed = iternary.substr(4,2);
    int fee=0;

    for(int i=0;i<iternary.length();i++){
        if (iternary[i]=='-'){
            landed[0]=iternary[i+1];
            landed[1]=iternary[i+2];
            //cout << landed << endl;
            if(landed==previous){
                continue;
            }else{
                for(int j=0;j<num;j++){
                    if(landed==feelist[j][0]){
                        fee+=stoi(feelist[j][1]);
                    }
                }
            }
            previous = landed;
        }
    }
    cout << fee;
}