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

int dfs(int idx,int par,vector<vector<int>> &adj,vector<int>&out,vector<int>&in,vector<int>&vis){
    if(vis[idx]!=0) return vis[idx];

    int ans=0;
    for (auto ch:adj[idx]){
        if(out[idx]>1 && in[ch]>1){
            ans = max(ans,dfs(ch,idx,adj,out,in,vis));
        }
    }

    return vis[idx] = ans+1;
}

void solution(int test_num){

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> out(n+1,0),in(n+1,0),vis(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        out[a]++,in[b]++;
        adj[a].push_back(b);
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            int ans2=dfs(i,-1,adj,out,in,vis);
            // debug(i,ans2);
            ans = max(ans,ans2);
        }
    }
    cout<<ans<<endl;

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
