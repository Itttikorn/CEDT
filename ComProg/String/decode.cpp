#include<iostream>
using namespace std;

int main(){
    string line;
    while(getline(cin,line)){
        if(line.length()==0){
            break;
        }
        bool fake=true;
        int n=0;
        string good = "";
        char special;
        //find first special char;
        for(int i=0; i<line.length(); i++){
            if(line[i]=='!' || line[i]=='@' || line[i]=='#'  || line[i]=='$'  || line[i]=='%' || line[i]=='^' || line[i]=='&' || line[i]=='*'){
                special = line[i];
                break;
            }
        }
        //cout << "special" << special << endl;
        for(int i=0;i<line.length();i++){
            int count=0;
            for(int j=i;j<line.length();j++){
                if(fake==true){
                    //cout << j << line[j] << "fake" << endl;
                    if(line[j]==special){
                        fake=false;
                        i=j;
                        break;
                    }
                }else if(fake==false){
                    //cout << j << line[j]<< "real" << endl;
                    if(line[j]==special){
                        fake=true;
                        good += line.substr(i,count);
                        i=j;
                        break;
                    }else{
                        count++;
                        //cout << "realcount"<<count << endl;
                    }
                }
            }
        }
        cout << good << endl;
    }
}