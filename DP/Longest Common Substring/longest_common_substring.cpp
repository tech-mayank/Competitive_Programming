#include<bits/stdc++.h>
using namespace std;

int LCString(string x, string y, int m, int n){
    int dp[m+1][n+1] = {0};
    for(int i = 0;i<m+1;i++){
        for(int j = 0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1;i<m+1;i++){
        for(int j = 1;j<n+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[m][n];
}
int main(){
    string x,y;
    cin>>x>>y;
    int res = LCString(x,y,x.length(),y.length());
    cout<<res<<endl;
}
