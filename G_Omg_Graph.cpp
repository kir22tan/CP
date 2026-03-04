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

#define node pair<int,int>
#define state tuple<int,int,int> //max idx min

int n,m,inf=1e18;
vector<vector<node>> adj;
vector<int> dp;
vector<node> v;

void solution(int test_num){

    cin>>n>>m;
    adj.assign(n+1,{});
    dp.assign(n+1,1e11);
    v.clear();

    for(int i=0;i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }

    dp[1]=0;
    priority_queue<state,vector<state>,greater<>> pq;
    for(auto [c,d]:adj[1]){
        pq.push({d,c,d});
        dp[c]=d;
        v.push_back({d,d});
    }

    while(!pq.empty()){
        auto[mx,idx,mn]=pq.top();
        pq.pop();
        v.push_back({mx,mn});
        if(dp[idx]<mx) continue;
        for(auto [c,d]:adj[idx]){
            int nmx = max(mx,d), nmn = min(mn,d);
            if(dp[c]>nmx){
                pq.push({nmx,c,nmn});
                dp[c]=nmx;
            }
            v.push_back({nmx,nmn});
        }
    }

    debug(dp);
    sort(all(v));
    v.erase(unique(v.begin(),v.end()),v.end());
    vector<node> u;
    for(int i=0;i<v.size();i++){
        if(u.empty()) u.push_back(v[i]);
        else if(u.back().first != v[i].first) u.push_back(v[i]);
    }
    debug(v);
    debug(u);
    int maxi = dp[n];
    int mini = maxi;
    for(int i=0;i<u.size();i++){
        if(u[i].first<=maxi) mini=min(mini,u[i].second);
        else break;
    }
    int ans=maxi+mini;
    for(int i=0;i<v.size();i++){
        if(v[i].first>=maxi){
            ans=min(ans,v[i].first+v[i].second);
        }
    }
    cout<<ans<<endl;

}

signed main(){
    kirTxn;
    int t;
    cin>>t;
    while(t--) solution(0);
}