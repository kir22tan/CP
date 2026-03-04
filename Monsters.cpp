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
    int inf = 1000000;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    using node=pair<int,int>;
    vector<node>mons;
    vector<vector<int>> dp(n,vector<int>(m,inf));
    vector<vector<int>> vis(n,vector<int>(m,0));
    node start;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]=='M') {
            mons.push_back({i,j});
            dp[i][j]=0;
            }
            else if(v[i][j]=='A') start={i,j};
        }
    }
    
    
    using ds=pair<int,node>;
    priority_queue<ds,vector<ds>,greater<>> pq;
    
    for(auto e:mons){
        pq.push({0ll,e});
    }

    auto isval=[&](int x,int y,int d){
        return (x>=0 && x<n && y>=0 && y<m && dp[x][y]>d+1 && v[x][y]!='#');
    };
    
    
    while(!pq.empty()){
        auto [d,idx]=pq.top();
        auto[x,y]=idx;
        pq.pop();
        
        for(auto dx:{0,0,-1,1})
        for(auto dy:{1,-1,0,0})
        if( (abs(dx)+abs(dy))==1 && isval(x+dx,y+dy,d)){
            dp[x+dx][y+dy]=d+1;
            pq.push({d+1,{x+dx,y+dy}});
        }
        
    }
    
    // debug(dp);
    
    auto isvalagain=[&](int x,int y){
        return (x>=0 && x<n && y>=0 && y<m && v[x][y]=='.' && vis[x][y]==0);
    };

    map<node,node> mp;

    pq.push({0,start});
    vis[start.first][start.second]=1;

    while(!pq.empty()){
        auto [d,idx]=pq.top();
        auto[x,y] = idx;
        pq.pop();

        if((x==0 || x==n-1 || y==0 || y==m-1) && dp[x][y]>d ){
                string ans;

                node curr = idx;
                
                while(curr!=start){
                    node par = mp[curr];
                    auto [px,py]=par;
                    auto [x,y]=curr;
                    debug(curr,par);
                    if(py<y) ans+='R';
                    else if(py>y) ans+='L';
                    else if(px<x) ans+='D';
                    else ans+='U';
                 
                    curr = par;
                }

                cout<<"YES"<<endl;
                cout<<ans.size()<<endl;
                reverse(all(ans));
                cout<<ans<<endl;
                return;
        }

        for(auto dx:{0,0,-1,1})
        for(auto dy:{1,-1,0,0})
        if( (abs(dx)+abs(dy))==1 && isvalagain(x+dx,y+dy)){
            pq.push({d+1,{x+dx,y+dy}});
            mp[{x+dx,y+dy}]=idx;
            vis[x+dx][y+dy]=1;
        }
    }

    cout<<"NO\n";

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
