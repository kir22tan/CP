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

int f(string &s){
    int n = s.size();
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(s[i]-'0')*(1ll<<i);
    }
    return ans;
}

int h(int no,int checker,int value){
    int bit=0;
    bitset<10> x=no,y=checker;
    for(int i=0;i<10;i++){
        if(y.test(i)) x[i]=value;
    }
    return x.to_ullong();
}

int g(int i,int val,int m,vector<vector<int>>&vp,vector<vector<int>>&dp){
    if(val==0) return 0;
    if(i==m){
        if(val) return 1e11;
        return 0;
    }
    if(dp[i][val]!=-1) return dp[i][val];
    int ans=g(i+1,val,m,vp,dp);
    int val2 = h(val,vp[i][1],0); 
    val2 = h(val2,vp[i][2],1);
    ans = min(ans,vp[i][0]+g(i+1,val2,m,vp,dp));
    return dp[i][val]=ans;
}

void solution(int test_num){

    int n,m;
    cin>>n>>m;
    string x; cin>>x;
    int init = f(x);
    vector<vector<int>> vp(m+1);
    
    for(int i=0;i<m;i++){
        int d;string x,y;
        cin>>d>>x>>y;
        vp[i+1]={d,f(x),f(y)};
    }
    // vector<vector<int>> dp(m*m+1,vector<int>((1ll<<n)+1,-1));
    // for(int i=0;i<m-1;i++)
    // {
        //     for(int j=0;j<m;j++) vp.push_back(vp[j]);
        // }
        
        // int ans = g(0,init,m*m,vp,dp);
        // if(ans==1e11) ans=-1;
        // cout<<ans<<endl;
        
    // node = dist, value, pos, iter 
    using node = tuple<int,int,int,int>;

    priority_queue<node, vector<node>, greater<node>> pq;

    int N = 1<<n;
    vector<int> dist(N, 1e18);

    dist[init] = 0;
    pq.push({0, init, 0, 0});

    while(!pq.empty()){
        auto [dis, val, idx, iter] = pq.top();
        pq.pop();

        if(dis > dist[val]) continue;   // important check

        if(val == 0){
            cout << dis << endl;
            return;
        }

        for(int i = 1; i <= m; i++){
            int new_mask = h(h(val, vp[i][1], 0), vp[i][2], 1);
            int new_dist = dis + vp[i][0];

            if(new_dist < dist[new_mask]){
                dist[new_mask] = new_dist;
                pq.push({new_dist, new_mask, 0, 0});
            }
        }
    }

    cout << -1 << endl;

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
