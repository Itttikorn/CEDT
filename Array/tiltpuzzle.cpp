#include<iostream>
using namespace std;

int main(){
    int size;
    cin >> size;
    int table[size*size];
    int zerorow;
    int count=0;
    for(int i=0;i<size*size;i++){
        cin >> table[i];
        if(table[i]==0){
            zerorow = (i%size);
            //cout << zerorow << endl;
        }
    }
    for(int i=0;i<size*size;i++){
        for(int j=i+1;j<size*size;j++){
            if(table[i]!=0 && table[j]!=0){
                if(table[i] > table[j]){
                    count++;
                }
            }            
        }
    }
    //cout << count;

    if(size%2==1 && count%2==0){
        cout << "YES";
    }else if(size%2==0 && count%2==1 && zerorow%2==0){
        cout << "YES";
    }else if(size%2==0 && count%2==0 && zerorow%2==1){
        cout << "YES";
    }else{
        cout << "NO";
    }
}