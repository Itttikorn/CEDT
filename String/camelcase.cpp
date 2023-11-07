#include<iostream>
using namespace std;

int main(){
    string text;
    cin >> text;
    bool number=false;
    if(text[0]>= '0' && text[0]<='9'){
        number=true;
    }
    text+="A";
    //cout << "textlength" << text.length() << endl;
    for(int i=1;i<text.length();i++){
        int count=1;
        for(int j=i;j<text.length();j++){
            //cout << j << text[j] << endl;
            //found upper case
            if(j+1==text.length()){
                cout << text.substr(i-1,count) << endl;
                i=j;
                break;
            }else if(text[j]>='A' && text[j] <= 'Z'){
                //cout << "case1" << endl;
                cout << text.substr(i-1,count) << ", ";
                i=j;
                number=false;
                break;
            }else if(text[j]>='0' && text[j]<='9' && number==false){
                //cout << "numberstart" << j << endl;
                //cout << "found number" << endl;
                //cout << "case2" << endl;
                cout << text.substr(i-1,count) << ", ";
                i=j;
                number=true;
                break;
                //count++;
            }else if(number==true && ((text[j]<'0') || (text[j]>'9'))){
                //cout << "numberend" << j << endl;
                //cout << "case3" << endl;
                cout << text.substr(i-1,count) << ", ";
                i=j;
                number=false;
                break;
            }else{
                count++;
            }
        }
    }
}