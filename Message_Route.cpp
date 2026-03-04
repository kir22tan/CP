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
    using node = pair<int,int>;
    queue<node> q;
    q.push({0,1});
    vis[1]=1;
    while(!q.empty()){
        auto[d,idx]=q.front();
        q.pop();
        if(idx==n){
            vector<int> ans;
            int curr=idx;
            while(curr!=-1){
                ans.push_back(curr);
                curr = par[curr];
            }
            reverse(ans.begin(),ans.end());
            cout<<ans.size()<<endl;
            for(auto e:ans) cout<<e<<" ";
            cout<<endl;
            return;
        }
        for(auto c:adj[idx]){
            if(vis[c]==0){
                vis[c]=1;
                q.push({d+1,c});
                par[c]=idx;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
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
