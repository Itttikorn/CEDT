#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int d1,m1,y1,d2,m2,y2,date1,date2,year,days;
    cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    y1-=543;
    y2-=543;
    bool plus1=false,plus2=false;
    if(y1%4==0){
        plus1=true;
    }
    if(y1%100==0){
        plus1=false;
    }
    if(y1%400==0){
        plus1=true;
    }

    if(plus1==true){
        if(m1==1){
            d1+=0;
        }else if(m1==2){
            d1+=31;
        }else if(m1==3){
            d1+=60;
        }else if(m1==4){
            d1+=91;
        }else if(m1==5){
            d1+=121;
        }else if(m1==6){
            d1+=152;
        }else if(m1==7){
            d1+=182;
        }else if(m1==8){
            d1+=213;
        }else if(m1==9){
            d1+=244;
        }else if(m1==10){
            d1+=274;
        }else if(m1==11){
            d1+=305;
        }else if(m1==12){
            d1+=335;
        }
        date1 = 366-d1;
    }else{
        if(m1==1){
            d1+=0;
        }else if(m1==2){
            d1+=31;
        }else if(m1==3){
            d1+=59;
        }else if(m1==4){
            d1+=90;
        }else if(m1==5){
            d1+=120;
        }else if(m1==6){
            d1+=151;
        }else if(m1==7){
            d1+=181;
        }else if(m1==8){
            d1+=212;
        }else if(m1==9){
            d1+=243;
        }else if(m1==10){
            d1+=273;
        }else if(m1==11){
            d1+=304;
        }else if(m1==12){
            d1+=334;
        }
        date1 = 365-d1;
    }
    //cout << date1;
    if(y2%4==0){
        plus2=true;
    }
    if(y2%100==0){
        plus2=false;
    }
    if(y2%400==0){
        plus2=true;
    }

    if(plus2==true){
        if(m2==1){
            d2+=0;
        }else if(m2==2){
            d2+=31;
        }else if(m2==3){
            d2+=60;
        }else if(m2==4){
            d2+=91;
        }else if(m2==5){
            d2+=121;
        }else if(m2==6){
            d2+=152;
        }else if(m2==7){
            d2+=182;
        }else if(m2==8){
            d2+=213;
        }else if(m2==9){
            d2+=244;
        }else if(m2==10){
            d2+=274;
        }else if(m2==11){
            d2+=305;
        }else if(m2==12){
            d2+=335;
        }
        date2 = d2;
    }else{
        if(m2==1){
            d2+=0;
        }else if(m2==2){
            d2+=31;
        }else if(m2==3){
            d2+=59;
        }else if(m2==4){
            d2+=90;
        }else if(m2==5){
            d2+=120;
        }else if(m2==6){
            d2+=151;
        }else if(m2==7){
            d2+=181;
        }else if(m2==8){
            d2+=212;
        }else if(m2==9){
            d2+=243;
        }else if(m2==10){
            d2+=273;
        }else if(m2==11){
            d2+=304;
        }else if(m2==12){
            d2+=334;
        }
        date2 = d2;
    }
    date2-=1;
    date1+=1;
    year=y2-y1-1;
    year=year*365;
    days = year+date1+date2;
    //cout << " " << date1 << "+" << date2 <<"+"<<year<<"="<<days;
    double phy,emo,inte;
    phy = sin((2*M_PI*days)/23);
    emo = sin((2*M_PI*days)/28);
    inte = sin((2*M_PI*days)/33);
    cout << days << " " << round(phy*100.0)/100.0 << " " << round(emo*100.0)/100.0 << " " << round(inte*100.0)/100.0;
}