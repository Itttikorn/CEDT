#include<iostream>
#include<string>
using namespace std;

int main(){
    int num;
    cin >> num;
    cin.ignore();
    string cards[num];
    for(int i=0;i<num;i++){
        cin >> cards[i];
    }
    cin.ignore();
    string act;
    getline(cin,act);
    

    for(int i=0;i<act.length();i++){
        if(act[i]=='C'){
            int mid = num/2;
            //copy to cards1
            string cards1[mid];
            int k=0;
            for(int j=mid;j<num;j++){
                cards1[k] = cards[j];
                k++;
            }
            //move
            for(int j=0;j<mid;j++){
                cards[j+mid] = cards[j];
                cards[j] = cards1[j];
            }
        }else if(act[i]=='S'){
            int mid = num/2;
            //copy to cards1
            string cards1[mid];
            int k=0;
            for(int j=mid;j<num;j++){
                cards1[k] = cards[j];
                k++;
            }
            //copy to cards2
            string cards2[mid];
            k=0;
            for(int j=0;j<mid;j++){
                cards2[k] = cards[j];
                k++;
            }
            //move
            k=0;
            int e=0;
            for(int j=0;j<num;j++){
                if(j%2==0){
                    cards[j]=cards2[k];
                    k++;
                }else{
                    cards[j]=cards1[e];
                    e++;
                }
            }
        }
    }
    for(int i=0;i<num;i++){
        cout << cards[i] << " ";
    }
}