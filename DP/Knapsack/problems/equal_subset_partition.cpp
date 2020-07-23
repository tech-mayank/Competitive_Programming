#include<bits/stdc++.h>
using namespace std;
int subset(int arr[],int sum,int n){
    int dp[n+1][sum+1] = {0};
    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<sum+1;j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            if(j==0){
                dp[i][j] = 1;
            }
        }
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<sum+1;j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n,s=0;
    cin>>n>>s;
    int arr[n];
    int su = 0;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        su = su + arr[i];
    }
    if(su %2 == 0){
        cout<<subset(arr,s,n)<<endl;
    }else{
        cout<<-1<<endl;
    }
}

