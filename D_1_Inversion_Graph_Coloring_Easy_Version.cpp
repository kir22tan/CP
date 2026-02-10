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

    int n,mod=1e9+7;
    cin>>n;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++) cin>>v[i];

    vector<vector<vector<int>>> dp(n+2,vector<vector<int>>(n+1,vector<int>(n+1,0)));

    for(int j=0;j<=n;j++){
        for(int k=0;k<=n;k++){
            dp[n+1][j][k]=1;
        }
    }

    for(int i=n;i>=1;i--){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(v[j] < v[k]) continue;

                dp[i][j][k] = (dp[i][j][k] + dp[i+1][j][k]) % mod;

                if(v[i] >= v[j]){
                    dp[i][j][k] = (dp[i][j][k] + dp[i+1][i][k]) % mod;
                }else if(v[i] >= v[k]){
                    dp[i][j][k] = (dp[i][j][k] + dp[i+1][j][i]) % mod;
                }
            }
        }
    }

    cout<<dp[1][0][0]%mod<<endl;
}

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
