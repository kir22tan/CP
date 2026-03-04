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

int flg=0;

void dfs(int idx,int pidx,vector<int>&vis,vector<vector<int>>&adj,vector<int>&par){

    vis[idx]=1;

    for(auto c:adj[idx]){

        if(c==pidx) continue; 

        if(vis[c]==0){
            par[c]=idx;
            dfs(c,idx,vis,adj,par);
        }
        else{
            vector<int> ans;
            int curr=idx;

            ans.push_back(c);

            while(curr!=c){
                ans.push_back(curr);
                curr=par[curr];
            }

            ans.push_back(c);   // close cycle
            reverse(all(ans));

            cout<<ans.size()<<"\n";
            for(auto e:ans) cout<<e<<" ";
            cout<<"\n";

            flg=1;
            return;
        }
    }
}

void solution(int test_num){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1,0),par(n+1,-1);
    flg=0;

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,-1,vis,adj,par);
            if(flg) break;
        }
    }

    if(flg==0){
        cout<<"IMPOSSIBLE\n";
    }
}

signed main(){
    kirTxn;
    solution(0);  
}