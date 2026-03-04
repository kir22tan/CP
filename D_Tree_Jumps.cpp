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

int mod = 998244353;

void solution(int test_num){

    int n;
    cin>>n;
    vector<vector<int>> adj(n+1),lev(n+1);
    vector<int> dp(n+2,0);
    vector<int> vis(n+2,0);
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    int last=1;

    using node=pair<int,int>;
    queue<node>q;
    q.push({1,1});
    vis[1]=1;
    while(!q.empty()){
        auto[d,idx]=q.front();
        q.pop();
        last=max(last,d);
        lev[d].push_back(idx);
        for(auto c:adj[idx]){
            if(vis[c]==0){
                vis[c]=1;
                q.push({d+1,c});
            }
        }
    }
    
    int downsum=0,currsum=0;

    while(last){
        if(last==1){
            dp[1]++;
            for(auto ch:adj[1]){
                dp[1]+=dp[ch];
                dp[1]%=mod;
            }
            break;
        }
        for(auto v:lev[last])
        {
            int childsum=0;
            for(auto ch:adj[v]){
                if(vis[ch]==0) childsum+=dp[ch];
            }
            childsum%=mod;
            dp[v]=1+downsum-childsum+mod;
            dp[v]%=mod;
            vis[v]=0;
            currsum+=dp[v];
            currsum%=mod;
        }
        downsum=currsum;
        currsum=0;
        last--;
    }
    cout<<dp[1]<<endl;

}


/* Main()  function */
signed main(){
    kirTxn;
    clock_t myclock = clock();
    int t = 1;
    cin>>t;
    for(int i=1;i<t+1;i++){
         solution(i);
         }
    cerr << "Run time: " << ((double)(clock() - myclock)/CLOCKS_PER_SEC) * 1000 << " ms" << endl;
    return 0;
}
