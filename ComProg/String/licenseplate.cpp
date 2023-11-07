#include<iostream>
using namespace std;

int main(){
    string plate1;
    int plate1num=0;
    cin >> plate1;
    int plate2num=0;
    cin >> plate2num;
    string plate2 = "0AA-";
    //0AA-000
    plate1num += stoi(plate1.substr(4,3));
    plate1num += (plate1[2] - 'A')*1000;
    plate1num += (plate1[1] - 'A')*26*1000;
    plate1num += (plate1[0]-'0')*26*26*1000;
    //cout << plate1num << endl;
    plate2num+=plate1num;
    //cout << plate2num << endl;
    plate2[0] = (plate2num/(26*26*1000)+'0');
    plate2[1] = ((plate2num/(26*1000))%26+'A');
    plate2[2] = ((plate2num/(1000))%26+'A');
    if(plate2num%1000 < 10){
        plate2+="00";
        plate2 += to_string(plate2num%1000);
    }else if(plate2num%1000 < 100){
        plate2+="0";
        plate2 += to_string(plate2num%1000);
    }else{
        plate2 += to_string(plate2num%1000);
    }
    cout << plate2;
}