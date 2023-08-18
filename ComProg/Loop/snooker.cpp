#include<iostream>
#include<string>
using namespace std;
int main (){
    int n;
    string s1,t = "YGNBPK";
    cin >> n;
    for(int i = 0;i<n+1;i++){
        int sum = 0;
        string s = "";
        getline(cin, s1);
        if(s1 == ""){
            continue;
        }
        for(int j=0;j<s1.length();j+=2){
            s+=s1[j];
            //cout << "s= "<<s<<endl;
        }
        // if(s[0] != 'R'){
        //     cout << "WRONG_INPUT" <<endl;
        //     continue;
        // }
        //cout << s<<endl;
        if (s[0] != 'R'){
            cout << "WRONG_INPUT"<<endl;
            continue;
        }
        for(int j = 0;j<s.length();j++){
            //cout << "j = "<<j <<"  s[j] = " << s[j]<<endl;
            if(j % 2 == 1 && s[j] == 'R'){
                cout << "WRONG_INPUT"<<endl;
                break;
            }
            else if(j%2 == 0 && s[j] != 'R'){
                bool check = 1;
                if(s.substr(j,s.length() - j) != t.substr(0,s.length()-j)){
                    cout << "WRONG_INPUT"<<endl;
                    j = s.length();
                }
                else{
                    sum += (2+(s.length()-j+1))*(s.length()-j)/2;
                    cout << sum << endl;
                    j = s.length();
                }
            }
            else if(j%2 == 0){
                sum+=1;
            }
            else if(j%2 == 1){
                for(int k=0;k<6;k++){
                    if(s[j] == t[k]){
                        sum += k+2;
                    }
                }
            }
            if(j == s.length()-1){
                cout << sum<<endl;
            }
        }
    }
}