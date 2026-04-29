#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    // step1: create DP
    vector<int> dp(n+1);
    // step2: Initialize base case
    dp[0]=0;
    dp[1]=1;
    //step3: call the DP

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<endl;

}