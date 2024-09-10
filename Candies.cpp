#include<bits/stdc++.h>

#ifdef Shubh37
#include "debug.h"
#else
#define debug(x)  
#endif

using namespace std;
using namespace chrono;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define for0(i,x) for(int i=0;i<x;i++)
#define for1(i,x) for(int i=1;i<=x;i++) 
#define forR(i,x) for(int i=x-1;i>=0;i--)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<long long> vill;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*

*/

void solve()
{
   
   
      int n,k;
      cin >> n >> k;
      vi a(n+1);
      for1(i,n) cin >> a[i];
      vector dp(k+2,vector(n+2,0));

      for(int i=0;i<=n;i++) dp[0][i] = 1;
      int sum = 0;
      vector prefix_prev(k+2,1),curr(k+2,0);
      prefix_prev[0] = 0;
      

      debug(a)

      for(int i=1;i<=n;i++)
      {
         sum += a[i];
         curr[0] = 0;
         curr[1] = 1;
         for(int j=1;j<=k;j++)
         {
            if(j <= sum) 
            {
               int l = max(0,j - a[i]);
               
               dp[j][i] = (prefix_prev[j+1]%MOD - prefix_prev[l]%MOD + MOD)%MOD;
               
            }
            curr[j+1] = (curr[j] + dp[j][i])%MOD;
         }
         
         prefix_prev = curr;

      }
      cout<<dp[k][n]<<nline;
   
   

   


}


int main()
{
   #ifdef Shubh37
      freopen("Error.txt", "w", stderr);
   #endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
   #ifdef Shubh37
    cerr << "Time: " << duration . count() / 1000 << endl;
   #endif
   
   return 0;
   
} 