#include<iostream>
using namespace std;

int main(){
    while(true){
        string password;
        bool eight=false,lower=false,upper=false,num=false,special=false,twelve=false;
        cin >> password;
        if(password.length()==0){
            break;
        }
        if(password.length()>=8){
            eight=true;
        }
        if(password.length()>=12){
            eight=false;
            twelve=true;
        }
        for(int i=0;i<password.length();i++){
            if(password[i]>='A' && password[i]<='Z'){
                upper=true;
            }
            if(password[i]>='a' && password[i]<='z'){
                lower=true;
            }
            if(password[i]>='0' && password[i]<='9'){
                num=true;
            }
            if(password[i]>='!' && password[i]<='/'){
                special=true;
            }
            if(password[i]>=':' && password[i]<='@'){
                special=true;
            }
            if(password[i]>='[' && password[i]<='`'){
                special=true;
            }
            if(password[i]>='{' && password[i]<='~'){
                special=true;
            }
        }
        if((eight || twelve) && (upper && lower && num)&& !special){
            cout << ">> " << "weak" << endl;
        }else if(eight && (upper && lower && num && special)){
            cout << ">> " << "weak"<< endl;
        }else if(twelve && (upper && lower && num && special)){
            cout << ">> " << "strong"<< endl;
        }else{
            cout << ">> " << "invalid"<< endl;
        }
    }
    
}