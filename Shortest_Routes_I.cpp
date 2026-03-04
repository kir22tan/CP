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

void solution(int test_num){
    
    using node=pair<int,int>;
    int n,m;
    cin>>n>>m;
    vector<vector<node>> adj(n+1);
    vector<int> dis(n+1,1e17);
    dis[1]=0;
    for(int i=0;i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        adj[u].push_back({v,d});
        // adj[v].push_back({u,d});
    }
    using state=node;
    priority_queue<state,vector<state>,greater<>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,idx]=pq.top();
        pq.pop();
        if(dis[idx]<d) continue;
        for(auto [ch,cost]:adj[idx]){
            if(dis[ch]>d+cost){
                dis[ch]=d+cost;
                pq.push({d+cost,ch});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";cout<<endl;
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
