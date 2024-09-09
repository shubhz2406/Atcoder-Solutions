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
   
   /* 
         dp(i,j) -> number of C sequence that can be made if j will be the element 
         base case dp(0,j) = 1;
    */
      int n;
      cin >> n;
      vi a(n+1),b(n+1);
      for1(i,n) cin >> a[i];
      for1(i,n) cin >> b[i];
      int mx  = max(a[n],b[n]);

      vector dp(n+1,vector(mx+1,-1));
      for(int i=0;i<=mx;i++) {
         if(i <= b[1] && i >= a[1]) dp[1][i] = 1;
      }

      for(int i=2;i<=n;i++)
      {
         int sum = 0;
         for(int j = 0;j<=mx;j++)
         {
            if(dp[i-1][j] != -1) sum = (sum+dp[i-1][j])%MOD1;
            if(j >= a[i] && j <= b[i]) dp[i][j] = sum;
         }
      }
      int ans = 0;
      for(int i=0;i<=mx;i++)
      {
         if(i <= b[n] && i >= a[n]) ans = (ans + dp[n][i])%MOD1;
      }
      cout<<ans<<nline;
      debug(dp)

   /* int testCase;
   cin >> testCase;
   while(testCase--)
   {
      debug(testCase) 
      

   } */
   
   

   


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