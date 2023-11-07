#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    map<string,vector<string>> table;
    for(int i=0;i<n;i++){
        string in;
        getline(cin,in);
        //cout << in << endl;
        int count=0;
        string songname,singer;
        for(int j=0;j<in.length();j++){
            if(in[j]==','){
                songname = in.substr(0,count);
                singer = in.substr(j+2,in.length()-j-1);
            }else{
                count++;
            }
        }
        //cout << songname << " " << singer << endl;
        if(table.find(songname)==table.end()){
            //cout << "new" << songname << endl;
            vector<string> newvector;
            newvector.push_back(singer);
            table[songname]=newvector;
        }else{
            table.find(songname)->second.push_back(singer);
        }
    }
    string search;
    getline(cin,search);
    vector<string> searchlist;
    for(int i=0;i<search.length();i++){
        int count=0;
        for(int j=i;j<search.length();j++){
            if(j==search.length()-1){
                string searchname=search.substr(i,count+1);
                searchlist.push_back(searchname);
                i=j+1;
                break;
            }
            if(search[j]==','){
                string searchname = search.substr(i,count);
                searchlist.push_back(searchname);
                i=j+1;
                break;
            }else{
                count++;
            }
        }
    }
    for(int i=0;i<searchlist.size();i++){
        //cout << searchlist[i] << endl;
        cout << searchlist[i] << " -> ";
        if(table.find(searchlist[i])==table.end()){
            cout << "Not found" << endl;
        }else{
            vector<string> foundlist = table.find(searchlist[i])->second;
            for(int i=0;i<foundlist.size();i++){
                if(i!=foundlist.size()-1){
                    cout << foundlist[i] << ", ";
                }else{
                    cout << foundlist[i] << endl;
                }
            }
        }
    }
}