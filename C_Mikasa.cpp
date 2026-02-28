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
    int val=0;
    set<int> st;
    for(int i=0;i<=m;i++) st.insert(i);
    for(int i=0;i<=m;i++){
        st.erase(i^n);
    }
    val=*st.begin();
    bitset<25> aa=n,ba=m,ca=val,da=aa^ca;
    debug(aa);
    debug(ba);
    debug(ca);
    // debug(da);
    // debug(n,val,n^val);

    if(m<n){
        cout<<0<<endl;
        return;
    }
    int flg=1;
    int lastz=0;
    bitset<32> a=n,b=m,c=0;
    for(int i=31;i>=0;i--){
        if(b[i]){
            if(!a[i] && i) c.flip(i);
        }else{
            if(a[i]) {
                flg=0;
                break;
            }
            else lastz=i;
        }
    }
    bitset<25>za = c.to_ullong();
    debug(za);
    // debug(lastz);
    // if(flg) c.flip(lastz);
    
    int r = 0;
    if(flg) r = (1ll<<lastz);
    int q = c.to_ullong()+r;
    cout<<q<<endl;

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
