#include<bits/stdc++.h>
using namespace std;

int main(){
    //fill map
    map<char,string> texttonum;
    int lettercount=0;
    char letter='a';
    int number=2;
    for(int i=0;i<26;i++){
        lettercount++;
        string newstring;
        for(int j=0;j<lettercount;j++){
            newstring+=to_string(number);
        }
        texttonum[letter] = newstring;
        letter++;
        if(lettercount==3 && number!=7 && number!=9){
            lettercount=0;
            number++;
        }
        if(lettercount==4 && (number==7 || number==9)){
            lettercount=0;
            number++;
        }
    }
    texttonum[' ']="0";

    map<string,char> numtotext;
    number=2;
    letter='a';
    lettercount=0;
    for(int i=0;i<26;i++){
        lettercount++;
        string newstring;
        for(int j=0;j<lettercount;j++){
            newstring+=to_string(number);
        }
        numtotext[newstring] = letter;
        letter++;
        if(lettercount==3 && number!=7 && number!=9){
            lettercount=0;
            number++;
        }
        if(lettercount==4 && (number==7 || number==9)){
            lettercount=0;
            number++;
        }
    }
    numtotext["0"]=' ';
    // for(auto i=numtotext.begin();i!=numtotext.end();i++){
    //     cout << i->first << " " << i->second << endl;
    // }
    string input;
    while(getline(cin,input)){
        for(int i=0;i<input.length();i++){
            input[i] = tolower(input[i]);
        }
        if(input.substr(0,3)=="t2k"){
            cout << ">> ";
            for(int i=4;i<input.length();i++){
                if(texttonum.find(input[i])!=texttonum.end()){
                    cout << texttonum.find(input[i])->second << " ";
                }
            }
            cout << endl;
        }else if(input.substr(0,3)=="k2t"){
            cout << ">> ";
            for(int i=4;i<input.length();i++){
                int count=0;
                for(int j=i;j<input.length();j++){
                    //cout << j << endl;
                    if(j==input.length()-1){
                        count++;
                        //cout << input.substr(i,count) << endl;
                        cout << numtotext.find(input.substr(i,count))->second;
                        i=j;
                        break;
                    }
                    if(input[j]==' '){
                        //cout << input.substr(i,count) << endl;
                        if(numtotext.find(input.substr(i,count))!=numtotext.end()){
                            cout << numtotext.find(input.substr(i,count))->second;
                            i=j;
                            break;
                        }
                    }else{
                        count++;
                    }
                }
            }
            cout << endl;
        }
    }
}