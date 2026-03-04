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

// overkilled this shite..anyway

struct state{
    int x,y;
};

void solution(int test_num){
    
    int n;
    cin>>n;

    state A,B;
    cin>>A.x>>A.y>>B.x>>B.y;

    vector<state> v(n+1);

    for(int i=0;i<n;i++) cin>>v[i].x;
    for(int i=0;i<n;i++) cin>>v[i].y;

    v[n]=B;

    set<int> tmp;
    for(int i=0;i<=n;i++) tmp.insert(v[i].x);

    int ans=B.x-A.x;

    map<int,int> mp;

    mp[A.x]=0;

    auto it=tmp.begin();
    for(int i=0;i<tmp.size();i++){
        mp[*it]=i+1;
        it++;
    }

    vector<vector<int>> u(mp.size()+1);

    u[0].push_back(A.y);

    for(int i=0;i<=n;i++){
        u[mp[v[i].x]].push_back(v[i].y);
    }

    for(auto&vec:u){
        sort(all(vec));
        vec.erase(unique(all(vec)),vec.end());
    }

    vector<vector<int>> a;

    for(auto&e:u){
        if(e.size()){
            a.push_back(e);
        }else break;
    }

    u=a;

    int m=u.size();

    vector<vector<int>> dp(m+1,vector<int>(2,0));

    for(int idx=m-1;idx>=0;idx--){

        int len=u[idx].back()-u[idx][0];

        for(int pos=0;pos<2;pos++){

            int currpos=u[idx][0];

            if(idx>0)
                currpos=(pos==0)?u[idx-1][0]:u[idx-1].back();

            dp[idx][pos]=len+min(
                dp[idx+1][0]+abs(currpos-u[idx].back()),
                dp[idx+1][1]+abs(currpos-u[idx][0])
            );
        }
    }

    ans+=min(dp[0][0],dp[0][1]);

    cout<<ans<<endl;
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