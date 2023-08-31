#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    for(int i=0;i<5;i++){
        //input BINGO;
        cin >> a;
    }

    vector<pair<string,bool>> board;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            string in;
            cin >> in;
            if(j%5==0){
                in = "B"+in;
            }else if(j%5==1){
                in = "I"+in;
            }else if(j%5==2){
                in = "N"+in;
            }else if(j%5==3){
                in = "G"+in;
            }else if(j%5==4){
                in = "O"+in;
            }
            if(in=="N*"){
                board.push_back(make_pair("",true));
            }else{
                board.push_back(make_pair(in,false));
            }  
        }
    }
    //check vector
    // cout << "B  I  N  G  O " << endl;
    // int count=0;
    // for(auto itr=board.begin();itr!=board.end();itr++){
    //     pair<string,bool> result = *itr;
    //     cout << result.first << result.second << " ";
    //     if(count%5==4){
    //         cout << endl;
    //     }
    //     count++;
    // }

    //get calls
    vector<string> calls;
    string call1;
    bool bingo = false;
    int count = 0;
    while(bingo!=true){
        //check board
        cin >> call1;
        pair<string,bool> search = make_pair(call1,false);
        auto f = find(board.begin(),board.end(),search);
        if(f!=board.end()){
            //set found=true
            board[f-board.begin()].second = true; 
        }
        count++;
        //cout << "Found at" << f-board.begin();

        //check bingo
        //horizontal
        for(int i=0;i<=20;i+=5){
            //cout << i << endl;
            //cout << board[i].first << board[i].second << " " << board[i+1].first << board[i+1].second  << " " << board[i+2].first  << board[i+2].second << " " << board[i+3].first << board[i+3].second  << " " << board[i+4].first  << board[i+4].second << endl;
            if(board[i].second == true && board[i+1].second == true && board[i+2].second == true && board[i+3].second == true && board[i+4].second==true){
                if(bingo!=true){
                    cout << count << endl;
                }
                if(board[i+2].first!=""){
                    cout << board[i].first << ", " << board[i+1].first << ", " << board[i+2].first << ", " << board[i+3].first << ", " << board[i+4].first << endl;
                }else{
                    cout << board[i].first << ", " << board[i+1].first << ", " << board[i+3].first << ", " << board[i+4].first << endl;
                }
                bingo = true;
            }
        }
        //vertical
        for(int i=0;i<5;i++){
            if(board[i].second == true && board[i+5].second == true && board[i+10].second == true && board[i+15].second == true && board[i+20].second==true){
                if(bingo!=true){
                    cout << count << endl;
                }
                if(board[i+10].first!=""){
                    cout << board[i].first << ", " << board[i+5].first << ", " << board[i+10].first << ", " << board[i+15].first << ", " << board[i+20].first << endl;
                }else{
                    cout << board[i].first << ", " << board[i+5].first << ", " << board[i+15].first << ", " << board[i+20].first << endl;
                }
                
                bingo = true;
            }
        }
        //diagonal to right
        if(board[0].second == true && board[6].second == true && board[12].second == true && board[18].second == true && board[24].second==true){
            if(bingo!=true){
                cout << count << endl;
            }
            cout << board[0].first << ", " << board[6].first << ", " << board[18].first << ", " << board[24].first << endl;
            bingo=true;
        }
        //diagonal to left
        if(board[4].second == true && board[8].second == true && board[12].second == true && board[16].second == true && board[20].second==true){
            if(bingo!=true){
                cout << count << endl;
            }
            cout << board[4].first << ", " << board[8].first << ", " << board[16].first << ", " << board[20].first << endl;
            bingo=true;
        }
    }
}