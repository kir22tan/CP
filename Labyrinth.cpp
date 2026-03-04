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

using node = pair<int,int>;

map<node,node> mp;
node ultimate={-1,-1};

void solution(int test_num){

    int n,m;
    cin>>n>>m;

    vector<vector<char>> v(n,vector<char>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));

    node A,B;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]=='A') A={i,j};
            else if(v[i][j]=='B') B={i,j};
        }
    }

    using node2 = pair<int,node>;
    queue<node2> q;

    q.push({0,A});
    vis[A.first][A.second]=1;
    mp[A]=ultimate;

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    while(!q.empty()){

        auto [d,idx]=q.front();
        q.pop();

        if(idx==B){
            cout<<"YES\n";
            cout<<d<<"\n";

            string ans="";
            node cur=idx;

            while(mp[cur]!=ultimate){
                node par=mp[cur];
                auto [x,y]=cur;
                auto [px,py]=par;

                if(px==x-1) ans+='D';
                else if(px==x+1) ans+='U';
                else if(py==y-1) ans+='R';
                else ans+='L';

                cur=par;
            }

            reverse(all(ans));
            cout<<ans<<"\n";
            return;
        }

        auto [x,y]=idx;

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m &&
               !vis[nx][ny] && v[nx][ny]!='#'){

                vis[nx][ny]=1;
                mp[{nx,ny}]={x,y};
                q.push({d+1,{nx,ny}});
            }
        }
    }

    cout<<"NO\n";
}

signed main(){
    kirTxn;
    solution(0);
}