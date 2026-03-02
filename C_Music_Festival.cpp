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

// sick dp!
// hmmm interesting shit
// used comment help ->
// https://codeforces.com/blog/entry/113857?#comment-1018913
// warna mujhe lawda aaraha tha ye sochne me.

// good stuff. good. appreciate the auth.

void solution(int test_num){

    int n;
    cin>>n;
    vector<deque<int>> v(n);
    
    vector<int> X,dp(n,0);

    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        int mn=0;
        for(int j=0;j<k;j++){
            int x;
            cin>>x;
            if(x>mn){
                mn=x;
                v[i].push_back(x);
            }
        }
    }
    sort(v.begin(),v.end());
    sort(v.begin(),v.end(),[&](deque<int>&a,deque<int>&b){
        return a.back()<b.back();
    });

    dp[0] = v[0].size();
    X.push_back(v[0].back());

    for(int i=1;i<n;i++){
        int sz = v[i].size();
        dp[i]=dp[i-1];
        for(int j=0;j<sz;j++){
            int contri = sz-j;
            int last = lower_bound(all(X),v[i][j])-X.begin()-1;
            if(last>=0)
            dp[i]=max(dp[i],dp[last]+contri);
            else
            dp[i]=max(dp[i],contri); 
        }
        X.push_back(v[i].back());
    }
    
    cout<<dp[n-1]<<endl;

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
