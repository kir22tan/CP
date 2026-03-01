#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
 #include "C:/Users/siddh/Desktop/cpp/currTemplate/debug_temp.h"
#else
 #define debug(...) void(1)
#endif
using namespace std;
#define kirTxn ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define all(a) a.begin(), a.end()

int inf=1e11;

int f(int i,int j,vector<vector<int>>&dp,vector<int>&pre,vector<int>&v,vector<int>&on){
    if(j<0) return 0;
    if(i<0) return inf;
    if(pre[i]<j) return inf;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans = f(i-1,j,dp,pre,v,on);
    if(v[i]==0){
        ans = min(ans,abs(i-on[j])+f(i-1,j-1,dp,pre,v,on));
    }

    return dp[i][j]=ans;
}

void solution(int test_num){

    int n;
    cin>>n;
    vector<int> v(n,0),pre(n,0),on;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        if(v[i]) on.push_back(i);}
        pre[0]=(v[0]==0)?1:0;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1];
            pre[i]+=(v[i]==0);
        }
    vector<vector<int>>dp(n+1,vector<int>(on.size()+1,-1));
    debug(pre,on);
    cout<<f(n-1,on.size()-1,dp,pre,v,on)<<endl;
}


/* Main()  function */
signed main(){
    kirTxn;
    clock_t myclock = clock();
    int t = 1;
    // cin>>t;
    for(int i=1;i<t+1;i++){
         solution(i);
         }
    cerr << "Run time: " << ((double)(clock() - myclock)/CLOCKS_PER_SEC) * 1000 << " ms" << endl;
    return 0;
}
