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

// huhh.. fucking diabolical
#define n1 vector<int>
#define n2 vector<n1>
#define n3 vector<n2>

int backwards(n2&start,n2&v,int n,int m){
    int ans=0;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            int my = v[i][j];
            int val = (my^v[i-1][j])+(my^v[i+1][j])+(my^v[i][j+1])+(my^v[i][j-1]);
            my = start[i][j];
            int sal = (my^v[i-1][j])+(my^v[i+1][j])+(my^v[i][j+1])+(my^v[i][j-1]);
            if(val==4 && sal==0) ans++;
        }
    }
    return ans;
}

void f(map<n2,n1>&mp2,map<n2,int>&mp,n2&ans,n2&start,int x,int sflag){
    if(sflag==0)
    for(int i=0;i<mp2[start].size();i++){
        ans.push_back({2,mp2[start][i]});
    }
    
    if(sflag==1){
        for(int i=0;i<mp2[start].size();i++){
            if(mp2[start][i]!=x)
            ans.push_back({2,mp2[start][i]});
        }
    }
}

void g(n2&ans,n2& newvec,n2& oldvec,int n,int m){
    
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            int my = newvec[i][j];
            int nval = (my^newvec[i-1][j])+(my^newvec[i+1][j])+(my^newvec[i][j+1])+(my^newvec[i][j-1]);
            my = oldvec[i][j];
            int oval = (my^oldvec[i-1][j])+(my^oldvec[i+1][j])+(my^oldvec[i][j+1])+(my^oldvec[i][j-1]);
            if(nval==0 && oval==4 && newvec[i][j]!=oldvec[i][j]){
                ans.push_back({1,i+1,j+1});
            }
        }
    }

}

void solution(int test_num){

    int n,m,k;
    cin>>n>>m>>k;
    map<n2,int> mp;
    map<n2,vector<int>> mp2;
    n3 v(k+1,n2(n,n1(m)));
    for(int x=0;x<=k;x++){
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++) v[x][i][j] = s[j]-'0';
        }
        mp[v[x]]++;
        mp2[v[x]].push_back(x+1);
    }
    
    // find init
    n2 start = v[0];
    int init = 1;
    for(int i=1;i<=k;i++){
        if(backwards(start,v[i],n,m)){
            start=v[i];
            init = i+1;
        }
    }

    debug(init,start);
    n2 ans;
    f(mp2,mp,ans,start,init,1);
    for(int _=0;_<=k;_++){
        int mini = 1e9;
        n2 minvec = start;
        for(int i=0;i<=k;i++){
            int chng = backwards(v[i],start,n,m);
            if(chng){
                if(chng<mini){
                    minvec = v[i];
                    mini = chng;
                }
            }
        }
        if(mini == 1e9) break;
        
        g(ans,minvec,start,n,m);
        start = minvec;
        f(mp2,mp,ans,minvec,mini,0);
    }

    // debug(ans);
    cout<<init<<endl;
    cout<<ans.size()<<endl;
    for(auto v:ans){
        for(auto u:v) cout<<u<<" ";
        cout<<endl;
    }


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
