#include<iostream>
using namespace std;

int main(){
    char vowels[5] = {'a','e','i','o','u'};
    string text;
    getline(cin,text);
    //count space;
    int wordcount = 1;
    for(int i=0;i<text.length();i++){
        if(text[i]==' '){
            wordcount++;
        }
    }
    //cout << wordcount;
    string words[wordcount];
    int savedwordcount=0;
    for(int i=0;i<=text.length();i++){
        int count=0;
        for(int j=i;j<text.length();j++){
            //cout << savedwordcount << endl;
            if(j==text.length()-1){
                words[savedwordcount] = text.substr(i,count+1);
                //cout << words[savedwordcount] << endl;
                savedwordcount++;
                i=j;
                break;
            }else if(text[j]==' '){
                words[savedwordcount] = text.substr(i,count);
                //cout << words[savedwordcount] << endl;
                savedwordcount++;
                i=j;
                break;
            }else{
                count++;
            }
        }
    }
    // for(int i=0;i<wordcount;i++){
    //     cout << words[i] << " ";
    // }

    string firstword = words[0];
    string lastword = words[wordcount-1];
    string newfirstword, firstwordvowels, newlastword, lastwordvowels;
    //cout << firstword << " " << lastword;
    int lettercount=0;
    for(int i=0;i<firstword.length();i++){
        if(firstword[i]== 'a' || firstword[i]== 'e' || firstword[i]== 'i' || firstword[i]== 'o' || firstword[i]== 'u'){
            newfirstword = firstword.substr(0,lettercount);
            firstwordvowels = firstword.substr(i,(firstword.length()-i));
            break;
        }else{
            lettercount++;
        }
    }
    lettercount=0;
    for(int i=0;i<lastword.length();i++){
        if(lastword[i]== 'a' || lastword[i]== 'e' || lastword[i]== 'i' || lastword[i]== 'o' || lastword[i]== 'u'){
            newlastword = lastword.substr(0,lettercount);
            lastwordvowels = lastword.substr(i,(lastword.length()-i));
            break;
        }else{
            lettercount++;
        }
    }
    newfirstword+=lastwordvowels;
    newlastword+=firstwordvowels;
    words[0] = newfirstword;
    words[wordcount-1] = newlastword;

    for(int i=0;i<wordcount;i++){
        cout << words[i] << " ";
    }
}