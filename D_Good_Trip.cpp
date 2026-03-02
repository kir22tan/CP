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

// shit dude, i used ML to predict the curve. the fuck.

// vector<vector<int>> ans;

// void f(int idx,vector<int> v,int A,int K){
//     if(v.size()==K){
//         ans.push_back(v);
//         return;
//     }

//     for(int i=1;i<=A;i++){
//         v.push_back(i);
//         f(idx+1,v,A,K);
//         v.pop_back();
//     }
// }

// vector<int> test;

// vector<vector<int>> dataframe;

// void g(int a,int k){
//     test.resize(k+1,0);
//     int fc=0,rc=0;
//     for(int i=0;i<ans.size();i++){
//         int val=0;
//         for(auto e:ans[i]){
//             if(e==1) val++;
//         }
//         fc+=val;
//         rc+=(val)*(val-1)/2;
//     }
//     dataframe.push_back({a,k,fc,rc});
// }


const int MOD = 1e9+7;

int modpow(int a, int b){
    int res = 1;
    a %= MOD;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

pair<int,int> f(int a, int k){
    a %= MOD;
    if(k == 1) return {1, 0};

    int ak_2 = modpow(a, k-2);          // a^(k-2)

    int y1 = k % MOD * (ak_2 * a % MOD) % MOD;   // k * a^(k-1)

    int comb = k % MOD * ((k-1)%MOD) % MOD;
    comb = comb * ((MOD+1)/2) % MOD;   // divide by 2

    int y2 = comb * ak_2 % MOD;

    return {y1, y2};
}

void solution(int test_num){
    
    int n,m,k;
    cin>>n>>m>>k;

    int sm=0;
    for(int i=0;i<m;i++)
    {
        int u,v,fv;
        cin>>u>>v>>fv;
        sm = (sm + fv) % MOD;
    }
    
    int a = n % MOD * ((n-1) % MOD) % MOD;
    a = a * ((MOD+1)/2) % MOD;

    auto [y1,y2] = f(a,k);
    debug(y1,y2);

    int ans1 = y1 % MOD * sm % MOD;
    int ans2 = y2 % MOD * (m % MOD) % MOD;

    int ans = (ans1 + ans2) % MOD;

    int denom = modpow(a, k);       
    int inv_denom = modpow(denom, MOD-2);

    ans = ans * inv_denom % MOD;

    cout << ans << "\n";

    // tf I used ml to predict the curve oh yeah
    //     int a=2,k=4;
    //     for(int a=1;a<=7;a++)
    //         for(int k=1;k<=6;k++)
    //     {
    //         f(0,{},a,k);
    //         g(a,k);
    //         ans.clear();
    //     }
    // debug(dataframe);
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
    cerr << "Run time: " 
         << ((double)(clock() - myclock)/CLOCKS_PER_SEC) * 1000 
         << " ms" << endl;
    return 0;
}