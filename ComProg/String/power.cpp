#include<iostream>
#include<cmath>
using namespace std;

int main(){
    string base;
    string expo;
    int lastdigitsbase,lastdigitsexpo;
    while(cin >> base){
        if (base.length()==0){
            break;
        }
        cin >> expo;
        if(base=="0"){
            cout << ">> " << 0 << endl;
        }else if(expo=="0"){
            cout << ">> " << 1 << endl;
        }else{
            int num[4];
            for(int i=1;i<=4;i++){
                num[i-1] = pow((base[base.length()-1])-'0',i);
                //cout << num[i-1] << endl;
            }
            lastdigitsbase = base[base.length()-1]-'0';
            if(expo.length()>1){
                string last2digitsexpo=expo.substr(expo.length()-2,2);
                lastdigitsexpo=stoi(last2digitsexpo);
            }else{
                lastdigitsexpo = expo[expo.length()-1]-'0';
            }
            //cout << lastdigitsbase << " " << lastdigitsexpo;

            if(lastdigitsexpo%4==0){
                cout << ">> " <<num[3]%10 << endl;
            }else if(lastdigitsexpo%4==1){
                cout << ">> " <<num[0]%10 << endl;
            }else if(lastdigitsexpo%4==2){
                cout << ">> " <<num[1]%10 << endl;
            }else if(lastdigitsexpo%4==3){
                cout << ">> " <<num[2]%10 << endl;
            }
            
        }
        cin.ignore();
    }
}