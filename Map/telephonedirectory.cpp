#include<bits/stdc++.h>
using namespace std;

int main(){
    int namecount;
    cin >> namecount;
    map<string,string> names;
    map<string,string> names2;
    //int orderscount;
    string firstname,secondname;
    string in;
    cin.ignore();
    for(int i=0;i<namecount;i++){
        getline(cin,in);
        int namelength=0;
        // if(i==namecount){
        //     orderscount=stoi(in);
        //     continue;
        // }
        int spacecount=0;
        for(int i=0;i<in.length();i++){
            if(in[i]==' '){
                spacecount++;
                namelength++;
            }
            if(spacecount==2){
                //found number;
                firstname=in.substr(0,namelength-2);
                secondname=in.substr(i+1,in.length()-namelength+1);
                //cout << firstname << "a " << secondname << "a"<< endl;
                break;
            }else{
                namelength++;
            }
        }
        //cin.ignore();
        //cout << firstname << " " << secondname << endl;
        names[firstname] = secondname;
        names2[secondname] = firstname;
    }
    //cout << "done" << endl;
    string searchname;
    int orderscount;
    cin >> orderscount;
    cin.ignore();
    for(int i=0;i<orderscount;i++){
        bool found=false;
        getline(cin,searchname);
        cout << searchname << " --> ";
        if(names.find(searchname)!=names.end()){
            cout << names.find(searchname)->second << endl;
            found=true;
            continue;
        }
        if(names2.find(searchname)!=names2.end()){
            cout << names2.find(searchname)->second << endl;
            found=true;
            continue;
        }
        if(found==false){
            cout << "Not found" << endl;
        }
    }
}