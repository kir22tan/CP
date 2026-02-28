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
    string s;
    cin>>n>>s;
    int ans=0;
    int upp=0,low=0;
    if(s[0]=='0'){
        low=n-1;
    }else{
        upp=low=1;
    }
    debug(ans,low,upp);
    ans=max({ans,upp,low});
    for(int i=0;i<n-1;i++){
        if(s[i]=='0' && s[i+1]=='0'){
            upp+=i+1;
            low+=(n-2-i);
        }
        else if(s[i]=='0' && s[i+1]=='1'){
            low+=1;
            upp=low;
        }
        else if(s[i]=='1' && s[i+1]=='1'){
            upp=1;
            low=1;
        }else{
            upp+=i+1;
            low=(n-2-i);
        }

        ans=max({ans,upp,low});
        debug(i,ans,upp,low);
    }
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
