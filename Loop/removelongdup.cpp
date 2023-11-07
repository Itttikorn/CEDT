#include<iostream>
using namespace std;

int main(){
    string text;
    cin >> text;
    int k;
    cin >> k;
    int pos;
    string answer;
    for(int i=0;i<text.length();i++){
        int count=1;
        int end=0;
        for(int j=i;j<text.length();j++){
            if(text[j+1]==text[j]){
                count++;
                //cout << "dup" << j << endl;
            }else if(count >= k && text[j+1]!=text[j]){
                //cout << count << endl;
                i=j;
                break;
            }else{
                answer+=text.substr(i,1);
                //cout << "nodup" << endl;
                break;
            }
        }
    }
    cout << answer;
}