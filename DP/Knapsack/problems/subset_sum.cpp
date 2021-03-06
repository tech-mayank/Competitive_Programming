#include<bits/stdc++.h>
#define ll long long
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
    //input the array, it's size and sum of the subset.
    int n,su=0;
    cin>>n>>su;
    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<subset(arr,su,n)<<endl;  // it will return 1 if subset is present and 0 if not.
}
