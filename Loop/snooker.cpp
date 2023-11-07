#include<iostream>
using namespace std;

int main(){
    int linecount=0;
    string maxline;
    getline(cin,maxline);
    int maxlinenum = stoi(maxline);
    while(linecount<maxlinenum){
        linecount++;
        string input;
        bool wrong=false,final=false,ended=false;
        int score=0;
        getline(cin,input);
        if(input[0]!='R'){
            wrong=true;
        }else{
            for(int i=2;i<input.length();i+=2){
                if(ended==true){
                    wrong=true;
                }
   
                if(i%4==0 && i>=2 && input[i-2]=='R'){
                    wrong=true;
                    //cout << "case01" << endl;
                }
                // if(input[i]=='R' && input[i+2]=='R'){
                //     wrong=true;
                //     //cout << "case02" << endl;
                // }
                if(input[i]=='R' && input[i-2]=='R'){
                    wrong=true;
                }
                if(final == false && i%4==0 && input[i]!='R' && input[i]!='Y'){
                    wrong=true;
                    //cout << "case03" << endl;
                }    
                if(i==input.length()-1){
                    final=true;
                    //cout << "final" << endl;
                }
                if(input[i]=='Y' && input[i-2]!='R'){
                    final=true;
                    //cout << "final" << endl;
                    if(input[i]=='Y' && input[i+2]!='G' && i!=input.length()-1){
                        wrong=true;
                        //cout << "case1" << endl;
                    }else if(input.length()>=i+4 && input[i]=='Y' && input[i+2]=='G' && input[i+4]!='N'){
                        wrong=true;
                        //cout << "case2" << endl;
                    }else if(input.length()>=i+6 && input[i]=='Y' && input[i+2]=='G' && input[i+4]=='N' && input[i+6]!='B'){
                        wrong=true;
                        //cout << "case3" << endl;
                    }else if(input.length()>=i+8 && input[i]=='Y' && input[i+2]=='G' && input[i+4]=='N' && input[i+6]=='B' && input[i+8]!='P'){
                        wrong=true;
                        //cout << "case4" << endl;
                    }else if(input.length()>=i+10 && input[i]=='Y' && input[i+2]=='G' && input[i+4]=='N' && input[i+6]=='B' && input[i+8]=='P' && input[i+10]!='K'){
                        wrong=true;
                        //cout << "case5" << endl;
                    }
                }
                if(input[i]=='K' && input[i-2]=='P' && input[i-4]=='B' && input[i-6]=='N' && input[i-8]=='G' && input[i-10]=='Y'){
                    ended=true;
                    //cout << "end" << endl;
                }
                if(input[i]=='R'){
                    score+=1;
                }else if(input[i]=='Y'){
                    score+=2;
                }else if(input[i]=='G'){
                    score+=3;
                }else if(input[i]=='N'){
                    score+=4;
                }else if(input[i]=='B'){
                    score+=5;
                }else if(input[i]=='P'){
                    score+=6;
                }else if(input[i]=='K'){
                    score+=7;
                }
            }
        }
        if(wrong==true){
            cout << "WRONG_INPUT" << endl;
        }else{
            cout << score+1 << endl;
        }

    }
}