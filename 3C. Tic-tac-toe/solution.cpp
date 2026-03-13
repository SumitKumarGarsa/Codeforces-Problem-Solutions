#include <bits/stdc++.h>
using namespace std;

bool win(vector<string>& a, char c){
    for(int i=0;i<3;i++){
        if(a[i][0]==c && a[i][1]==c && a[i][2]==c) return true;
        if(a[0][i]==c && a[1][i]==c && a[2][i]==c) return true;
    }
    if(a[0][0]==c && a[1][1]==c && a[2][2]==c) return true;
    if(a[0][2]==c && a[1][1]==c && a[2][0]==c) return true;
    return false;
}

int main(){
    vector<string> a(3);
    for(int i=0;i<3;i++) cin>>a[i];

    int x=0,o=0;
    for(auto &r:a)
        for(char c:r){
            if(c=='X') x++;
            if(c=='0') o++;
        }

    bool xWin = win(a,'X');
    bool oWin = win(a,'0');

    if(o > x || x - o > 1) {
        cout<<"illegal";
    }
    else if(xWin && oWin){
        cout<<"illegal";
    }
    else if(xWin){
        if(x == o + 1) cout<<"the first player won";
        else cout<<"illegal";
    }
    else if(oWin){
        if(x == o) cout<<"the second player won";
        else cout<<"illegal";
    }
    else{
        if(x + o == 9) cout<<"draw";
        else if(x == o) cout<<"first";
        else cout<<"second";
    }
}
