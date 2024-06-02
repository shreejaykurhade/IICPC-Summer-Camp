#include<bits/stdc++.h>
using namespace std;

int n,W,K;
int w[1001];
int p[1001];

int dp[101][1001][101];

int rec(int i,int w_taken,int k_taken)
{
    //pruning - if something is not feasible you remove that from the code

    //basecase
    if(i==n)
    {
        return 0;
    }
    //cache check
    if(dp[i][w_taken][k_taken]!=-1)
    {
        return dp[i][w_taken][k_taken];
    }
    //recursion
    int ans = rec(i+1,w_taken,k_taken);

        if(w_taken+w[i]<=W && k_taken+1<=K)
        {
        //i can take it.
        ans = max(ans, p[i] + rec(i+1, w_taken+w[i],k_taken+1));
        }

    //transition

    //return
    dp[i][w_taken][k_taken] = ans;
    return ans;

}

int main()
{
    cin>>n>>W>>K;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>p[i];
    }
    memset(dp,-1,sizeof(dp));

    int ans = rec(0,0,0);
    cout<<ans<<endl;

    return 0;
}
