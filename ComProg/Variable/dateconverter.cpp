#include<iostream>
#include<cmath>
using namespace std;
int main(){
    string ipt;
    cin >> ipt;

    string date = ipt.substr(0,2);
    int date2 = stoi(date);
    string month = ipt.substr(3,5);
    int month2 = stoi(month);
    string txtmonth;
    if (month2 == 1){
        txtmonth = "JAN";
    }else if (month2 == 2){
        txtmonth = "FEB";
    }else if (month2 == 3){
        txtmonth = "MAR";
    }else if (month2 == 4){
        txtmonth = "APR";
    }else if (month2 == 5){
        txtmonth = "MAY";
    }else if (month2 == 6){
        txtmonth = "JUN";
    }else if (month2 == 7){
        txtmonth = "JUL";
    }else if (month2 == 8){
        txtmonth = "AUG";
    }else if (month2 == 9){
        txtmonth = "SEP";
    }else if (month2 == 10){
        txtmonth = "OCT";
    }else if (month2 == 11){
        txtmonth = "NOV";
    }else if (month2 == 12){
        txtmonth = "DEC";
    }
    string year = ipt.substr(6,10);
    int be = stoi(year);
    int ad = be-543;
    cout << txtmonth << " " <<date2<<", "<< ad;
}