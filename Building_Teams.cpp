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

int flg;

void dfs(int i,int my,vector<vector<int>>&adj,vector<int>&vis,vector<int>&color){
    vis[i]=1;
    color[i]=my;

    int nmy = (my==1 ? 2 : 1);

    for(auto c:adj[i]){
        if(vis[c]==0){
            dfs(c,nmy,adj,vis,color);
        }
        else {
            if(color[c]==my){
                flg=1;
            }
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

    vector<int> color(n+1,0),vis(n+1,0);
    flg=0; 

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,1,adj,vis,color);
        }
    }

    if(flg){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    for(int i=1;i<=n;i++)
        cout<<color[i]<<" ";

    cout<<"\n";
}

signed main(){
    kirTxn;
    int t=1;
    while(t--) solution(0);
}