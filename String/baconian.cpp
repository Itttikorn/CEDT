#include<iostream>
#include<string>
using namespace std;

int main(){
    string fake;
    getline(cin,fake);
    string order;

    while(getline(cin,order)){
        if(order.length()==0){
            break;
        }
        if(order[0]=='E'){
            //encode
            string newtext="";
            for(int i=0;i<order.length();i++){
                if(order[i]=='0'){
                    newtext+="UUUU";
                }else if(order[i]=='1'){
                    newtext+="UUUL";
                }else if(order[i]=='2'){
                    newtext+="UULU";
                }else if(order[i]=='3'){
                    newtext+="UULL";
                }else if(order[i]=='4'){
                    newtext+="ULUU";
                }else if(order[i]=='5'){
                    newtext+="ULUL";
                }else if(order[i]=='6'){
                    newtext+="ULLU";
                }else if(order[i]=='7'){
                    newtext+="ULLL";
                }else if(order[i]=='8'){
                    newtext+="LUUU";
                }else if(order[i]=='9'){
                    newtext+="LUUL";
                }else if(order[i]=='-'){
                    newtext+="LULU";
                }else if(order[i]==','){
                    newtext+="LULL";
                }
            }
            //cout << newtext;
            string encoded="";
            int offset=0;
            for(int i=0;i<=newtext.length()+offset;i++){
                //cout << fake[i%fake.length()] << newtext[i-offset] << i << " " <<offset << endl;
                // if(i%fake.length()==0 && i!=0){
                //      encoded+=" ";
                // }
                if(newtext[i-offset]=='U'){
                    if(fake[i%(fake.length())] >= 'A' && fake[i%(fake.length())] <= 'Z'){
                        //cout << "one" << endl;
                        encoded+=fake[i%(fake.length())];
                    }else if(fake[i%(fake.length())]>= 'a' && fake[i%(fake.length())]<='z'){
                        //cout << "two" << endl;
                        encoded+=(fake[i%(fake.length())]-32);
                    }else{
                        encoded+=fake[i%(fake.length())];
                        offset++;
                        //cout << "offset" << endl;
                    }
                }else if(newtext[i-offset]=='L'){
                    if(fake[i%(fake.length())] >= 'A' && fake[i%(fake.length())] <= 'Z'){
                        //cout << "three" << endl;
                        encoded+=(fake[i%(fake.length())]+32);
                    }else if(fake[i%(fake.length())]>= 'a' && fake[i%(fake.length())]<='z'){
                        //cout << "four" << endl;
                        encoded+=(fake[i%(fake.length())]);
                    }else{
                        encoded+=fake[i%(fake.length())];
                        offset++;
                        //cout << "offset" << endl;
                    }
                }
            }
            cout << encoded << endl;
        }else if(order[0]=='D'){
            //decode
            string newtext="";
            string decoded="";
            for(int i=2;i<order.length();i++){
                if(order[i] >= 'A' && order[i] <='Z'){
                    newtext+="U";
                }else if(order[i]>='a' && order[i]<='z'){
                    newtext+="L";
                }
            }
            //cout << newtext;
            for(int i=0;i<newtext.length();i+=4){
                if(newtext.substr(i,4)=="UUUU"){
                    decoded+="0";
                }else if(newtext.substr(i,4)=="UUUL"){
                    decoded+="1";
                }else if(newtext.substr(i,4)=="UULU"){
                    decoded+="2";
                }else if(newtext.substr(i,4)=="UULL"){
                    decoded+="3";
                }else if(newtext.substr(i,4)=="ULUU"){
                    decoded+="4";
                }else if(newtext.substr(i,4)=="ULUL"){
                    decoded+="5";
                }else if(newtext.substr(i,4)=="ULLU"){
                    decoded+="6";
                }else if(newtext.substr(i,4)=="ULLL"){
                    decoded+="7";
                }else if(newtext.substr(i,4)=="LUUU"){
                    decoded+="8";
                }else if(newtext.substr(i,4)=="LUUL"){
                    decoded+="9";
                }else if(newtext.substr(i,4)=="LULU"){
                    decoded+="-";
                }else if(newtext.substr(i,4)=="LULL"){
                    decoded+=",";
                }
            }
            cout << decoded << endl;
        }
    }

}