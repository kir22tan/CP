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

// the failing case was this:

// 10 10
// XX.XX...XX
// XXXXX...XX
// .X.XX..XXX
// XXX.X...XX
// ..........
// ..........
// XXX....XXX
// .XXX..XXXX
// XXXXX.X.XX
// XXXXX.XXXX
// 1
// 9 10

// fixed using the condition 
// -X                                      -X
// X(X) => this is replacable with .       X(.)
// is the same

int inf=1e7;

void dfs(int i,int j,vector<vector<int>> &vis,vector<string>&v){
    vis[i][j]=1;
    int m=vis[0].size(),n=vis.size();
    if(j+1<m && v[i][j+1]=='.' && vis[i][j+1]==0){
        dfs(i,j+1,vis,v);
    }
    if(i+1<n && v[i+1][j]=='.' && vis[i+1][j]==0){
        dfs(i+1,j,vis,v);
    }
}

void solutionOldFailing(int test_num){

    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    vector<vector<int>> vis(n,vector<int>(m,0));

    for(int j=0;j<m;j++){
        if(v[0][j]=='.' && vis[0][j]==0){
            dfs(0,j,vis,v);
        }
    }

    for(int i=0;i<n;i++){
        if(v[i][0]=='.' && vis[i][0]==0){
            dfs(i,0,vis,v);
        }
    }

    debug(vis);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==1 || v[i][j]=='X') vis[i][j]=-inf;
        }
    }

    for(int j=1;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(vis[i][j]==-inf) continue;
            if(v[i][j]=='.'){
                if(v[i][j-1]=='.') vis[i][j]=vis[i][j-1];
                else{
                    if(v[i][j-1]=='X') {vis[i][j]=j; 
                    }
                }
            }
        }
    }

    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(j-1>=0 && i-1>=0){
                if(v[i][j]=='X' && v[i-1][j]=='X' && v[i][j-1]=='X') vis[i][j]=inf;
            }
        }
    }

    debug(vis);
    
    vector<int> mx(m,-inf);
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            mx[j]=max(mx[j],vis[i][j]);
        }
    }

    vector<vector<int>> mxr(m,vector<int>(m,-inf));

    for(int j=0;j<m;j++){
        int mxst = mx[j];
        for(int i=j;i<m;i++){
            mxst = max(mxst,mx[i]);
            mxr[j][i]=mxst;
        }
    }
    
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int mx = mxr[l][r];
        if(l>=mx) cout<<"YES\n";
        else cout<<"NO\n";
    }

}

void solution(int tst){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    // bad[j] = 1 if there exists a row i (1-based >=2) such that
    // a[i-1][j] == 'X' and a[i][j-1] == 'X'  (0-based: i>=1, j>=1)
    vector<int> bad(m,0);
    for(int j=1;j<m;j++){
        for(int i=1;i<n;i++){
            if(a[i-1][j]=='X' && a[i][j-1]=='X'){
                bad[j]=1;
                break;
            }
        }
    }

    // prefix sum on columns
    vector<int> pref(m,0);
    pref[0]=bad[0];
    for(int j=1;j<m;j++) pref[j]=pref[j-1]+bad[j];

    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        l--; r--; // to 0-based
        if(l==r){
            cout<<"YES\n";
            continue;
        }
        // check bad columns in (l+1 .. r) -> pref[r]-pref[l]
        if(pref[r]-pref[l] == 0) cout<<"YES\n";
        else cout<<"NO\n";
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
