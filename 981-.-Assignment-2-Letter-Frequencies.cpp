#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int str[26],strc[26],temp,num;
    //bool flag = false;

    for(int i=0;i<26;i++){
        str[i] = 0;
        strc[i] = 0;
    }

    getline(cin, s);

    for(int i=0;i<s.length();i++){
        s[i]-='A';
        str[s[i]]++;
   }

    for(int i=0;i<26;i++){
        strc[i] = str[i];
    }

    for(int i=0;i<25;i++){
        for(int j=0;j<25-i;j++){
            if(strc[j]<strc[j+1]){
                temp = strc[j];
                strc[j] = strc[j+1];
                strc[j+1] = temp;
            }
        }
    }

    for(int i=0;i<26;i++){
        temp = strc[i];
        if(temp == 0) break;
        for(int j=0;j<26;j++){
            if(str[j] == temp){
                cout << j+65 << " " << str[j] << endl;
                str[j] = 0;
                /*
                if(flag == false) cout << endl;
                for(int k=0;k<26;k++){
                    if(str[k] == 0){
                        flag = true;
                    }
                }
                */
            }
        }
    }

}
