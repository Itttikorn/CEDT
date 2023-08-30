#include<iostream>
using namespace std;

int main(){
    string x,y;
    cin >> x >> y;
    //cout << x << " " << y;
    int max=0;
    string maxx=x,maxy=y;
    string checkx=x,checky=y;
    int xlength = x.length();
    int ylength = y.length();
    int maxlength;
    int minlength;
    if(xlength>=ylength){
        maxlength=xlength;
        minlength=ylength;
    }else{
        maxlength=ylength;
        minlength=xlength;
    }
    //move x to right
    for(int i=0;i<ylength;i++){
        int count=0;
        //fill in the blank
        if(i>=1){
            checkx = "-"+checkx;
        }
        //cout << checkx << endl;
        //cout << checky << endl << endl;
        for(int j=0;j<checkx.length();j++){
            //cout << checkx[j] << checky[j] << endl;
            if(checkx[j]==checky[j]){
                count++;
            }
        }
        //cout << count << endl << endl;
        if(count>max){
            max=count;
            maxx=checkx;
            maxy=checky;
        }
    }
    checkx=x;
    checky=y;
    //move y to right
    for(int i=0;i<xlength;i++){
        int count=0;
        //fill in the blank
        if(i>=1){
            checky = "-"+checky;
        }
        //cout << checkx << endl;
        //cout << checky << endl << endl;
        for(int j=0;j<checky.length();j++){
            if(checkx[j]==checky[j]){
                //cout << j << checkx[j] << checky[j] << endl;
                count++;
            }
        }
        //cout << count << endl << endl;
        if(count>max){
            max=count;
            maxx=checkx;
            maxy=checky;
        }
    }

    cout << maxx << endl << maxy << endl << max << endl;
}