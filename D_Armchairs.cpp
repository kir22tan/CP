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

    int n;
    cin>>n;
    int inf=1e11;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(v[i]==1){
            int lf=inf,rg=inf;
            for(int j=i-1;j>=1;j--){
                if(v[j]==0){
                    lf=abs(j-i);
                    break;
                }
            }
            for(int j=i+1;j<=n;j++){
                if(v[j]==0){
                    rg=abs(j-i);
                    break;
                }
            }
            if(lf<rg){
                v[i-lf]=-1;
                ans+=lf;
            }else{
                v[i+rg]=-1;
                ans+=rg;
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
