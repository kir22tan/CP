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


int f(int n,int xmask,int ymask,vector<vector<vector<int>>>&v,vector<vector<int>>&dp)
{
    int z = ((bitset<13>)xmask).count()+1;
    if(z>n) return 0;

    if(dp[xmask][ymask] != -1)
        return dp[xmask][ymask];

    int ans = 1e18;

    for(int x=1;x<=n;x++){
        if((xmask>>(x-1))&1) continue;
        for(int y=1;y<=n;y++){
            if((ymask>>(y-1))&1) continue;
            ans = min(ans,v[x][y][z] + f(n,xmask|(1<<(x-1)),ymask|(1<<(y-1)),v,dp));
        }
    }

    return dp[xmask][ymask] = ans;
}


void solution(int test_num){
    
    int n;
    cin>>n;
    vector<vector<vector<int>>>v(n+1,vector<vector<int>>(n+1,vector<int>(n+1)));
    vector<vector<int>>dp(1<<n,vector<int>(1<<n, -1));
    for(int i=0;i<n*n*n;i++){
        int no;
        cin>>no;
        int z = 1 + i%n;
        int x = 1 + i/(n*n);
        int y = 1 + (i-((x-1)*(n*n)))/n;
        v[x][y][z]=no;
    }
    cout<<f(n,0,0,v,dp)<<endl;

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
