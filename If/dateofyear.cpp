#include <iostream>
using namespace std;
int main() {
    int d,m,y;
    cin >> d >> m >> y;
    y-=543;
    bool plus=false;
    if(y%4==0){
        plus=true;
    }
    if(y%100==0){
        plus=false;
    }
    if(y%400==0){
        plus=true;
    }

    if(plus==true){
        if(m==1){
            d+=0;
        }else if(m==2){
            d+=31;
        }else if(m==3){
            d+=60;
        }else if(m==4){
            d+=91;
        }else if(m==5){
            d+=121;
        }else if(m==6){
            d+=152;
        }else if(m==7){
            d+=182;
        }else if(m==8){
            d+=213;
        }else if(m==9){
            d+=244;
        }else if(m==10){
            d+=274;
        }else if(m==11){
            d+=305;
        }else if(m==12){
            d+=335;
        }
    }else{
        if(m==1){
            d+=0;
        }else if(m==2){
            d+=31;
        }else if(m==3){
            d+=59;
        }else if(m==4){
            d+=90;
        }else if(m==5){
            d+=120;
        }else if(m==6){
            d+=151;
        }else if(m==7){
            d+=181;
        }else if(m==8){
            d+=212;
        }else if(m==9){
            d+=243;
        }else if(m==10){
            d+=273;
        }else if(m==11){
            d+=304;
        }else if(m==12){
            d+=334;
        }
    }
    cout << d;
}