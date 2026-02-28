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

    int n,q;
    cin>>n>>q;
    vector<int> v(n),u(n+1);
    for(int i=0;i<n;i++) {cin>>v[i]; u[v[i]]=i+1;}

    while(q--){
        int l,r,k;
        cin>>l>>r>>k;

        if(u[k]<l || u[k]>r){
            cout<<-1<<" ";
            continue;
        }

        int target = u[k];
        int big=0,small=0;
        int havebig=0,havesmall=0;

        int L=l, R=r;

        while(true){
            int mid = (L+R)/2;
            if(mid==target) break;

            if(mid < target){
                small++;
                if(v[mid-1] < k) havesmall++;
                L = mid+1;
            }
            else{
                big++;
                if(v[mid-1] > k) havebig++;
                R = mid-1;
            }
        }

        if(big > (n-k) || small > (k-1)){
            cout<<-1<<" ";
            continue;
        }

        int needbig = max(0LL, big-havebig);
        int needsmall = max(0LL, small-havesmall);

        cout<<(2 * (needbig+needsmall))<<" ";
    }
    cout<<endl;
}

signed main(){
    kirTxn;
    clock_t myclock = clock();
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++){
         solution(i);
    }
    cerr << "Run time: " << ((double)(clock() - myclock)/CLOCKS_PER_SEC) * 1000 << " ms" << endl;
    return 0;
}