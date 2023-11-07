#include<bits/stdc++.h>
using namespace std;

int main(){
    string in;
    int count=1;
    //vector<string> v;
    string table[1000];
    int maxlength=0;
    while(cin >> in){
        if(in == "END"){
            break;
        }
        if(in.length()>maxlength){
            maxlength=in.length();
        }
        table[count] = in;
        count++;
        //v.push_back(in);
    }
    // sort(v.begin(),v.end());
    // for(auto itr=v.begin();itr!=v.end();itr++){
    //     cout << *itr << endl;
    // }
    //insert 0;
    for(int i=0;i<count;i++){
        int zeroneeded = maxlength-table[i].length();
        for(int j=0;j<zeroneeded;j++){
            //cout << maxlength << " " << table[i].length() << " " << maxlength-table[i].length() << endl;
            table[i] = "0"+table[i];
        }
        //cout << table[i] << endl;
    }
    //add each digits
    string answer="";
    for(int i=maxlength-1;i>0;i--){
        int addresult=0;
        for(int j=0;j<count;j++){
            //cout << table[j][i];
            addresult+=(table[j][i]-'0');
        }
        //cout << endl;
        //cout << addresult << endl;
        if(addresult!=0){}
        int whole = addresult%10;
        answer = to_string(whole) + answer;
        int remainder = addresult/10;
        //cout << whole << " " << remainder << endl;
        table[0][i-1] = remainder+'0';
    }
    //last digit
    int addresult=0;
    for(int i=0;i<count;i++){
        addresult+=(table[i][0]-'0');
    }
    int whole = addresult%10;
    answer = to_string(whole) + answer;
    int remainder = addresult/10;
    //cout << whole << " " << remainder << endl;
    answer = to_string(remainder) + answer;
    bool foundfirstnumber = false;
    for(int i=0;i<answer.length();i++){
        if(answer[i]=='0' && !foundfirstnumber){
            continue;
        }else if(answer[i]!=0 && !foundfirstnumber){
            foundfirstnumber=true;
            cout << answer[i];
        }else if(foundfirstnumber){
            cout << answer[i];
        }
    }
}