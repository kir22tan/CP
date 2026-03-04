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
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    using node = pair<int,int>;

    queue<node> q;
    vector<vector<int>> vis(n,vector<int>(m,0));    
    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(v[i][j]=='#' || vis[i][j]) continue;

            vis[i][j]=1;
            ans++;
            q.push({i,j});

            auto isvalid = [&](int x,int y){
                if (x>=0 && x<n && y>=0 && y<m && vis[x][y]==0 && v[x][y]=='.'){
                    vis[x][y]=1;
                    return 1;
                }
                return 0;
            };

            while(q.empty()==0){
                auto[x,y] = q.front();
                q.pop();

                if(isvalid(x-1,y)) q.push({x-1,y});
                if(isvalid(x+1,y)) q.push({x+1,y});
                if(isvalid(x,y-1)) q.push({x,y-1});
                if(isvalid(x,y+1)) q.push({x,y+1});

            }

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
