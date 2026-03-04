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

void dfs(int idx,vector<vector<int>>&adj,vector<int>&vis){
    vis[idx]=1;
    for(auto ch:adj[idx]){
        if(vis[ch]==0)
        dfs(ch,adj,vis);
    }
}

void solution(int test_num){

    int n,m;
    cin>>n>>m;
    vector<int> vis(n+1,0);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> cc;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            cc.push_back(i);
            dfs(i,adj,vis);
        }
    }

    cout<<cc.size()-1<<endl;
    for(int i=1;i<cc.size();i++){
        cout<<cc[i-1]<<" "<<cc[i]<<endl;
    }
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
