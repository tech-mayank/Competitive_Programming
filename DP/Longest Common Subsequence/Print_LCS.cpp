#include<bits/stdc++.h>
using namespace std;

int dp[3001][3001] = {0};
string LCS(string x, string y, int m, int n){
    for(int i = 0;i<3001;i++){
        for(int j = 0;j<3001;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1;i<3001;i++){
        for(int j = 1;j<3001;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string str;
    int i = m;
    int j = n;
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            str.push_back(x[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j] >= dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(str.begin(),str.end());
    return str;
}
int main(){
    string x,y;
    cin>>x>>y;
    string res = LCS(x,y,x.length(),y.length());
    cout<<res<<endl;
}
