#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string line, char delimiter) {
    vector<string> words;
    for(int i=0;i<=line.length();i++){
        int count=0;
        for(int j=i;j<line.length();j++){
            if(j==line.length()-1 && line[line.length()-1]!=delimiter){
                string text = line.substr(i,count+1);
                if(text.length()!=0){
                    words.push_back(text);
                }
                i=j;
                break;
            }else if(line[j]==delimiter){
                string text = (line.substr(i,count));
                if(text.length()!=0){
                    words.push_back(text);
                }
                i=j;
                break;
            }else{
                count++;
            }
        }
    }
    return words;
}
int main() {
    string line;
    getline(cin, line);
    string delim;
    getline(cin, delim);
    for (string e : split(line, delim[0])) {
    cout << '(' << e << ')';
    }
}
