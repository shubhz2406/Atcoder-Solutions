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
       dp(i,j,k) = (N + (i * dp(i-1,j,k) + j * dp(i+1,j-1,k) + k * dp(i,j+1,k-1)))/(i+j+k);
       base case ->  dp[0][0][0] = 0;
   */
   int n;
   cin >> n;
   setprecision(10);
   double x = 0.0000000000;
   vector a(n,0);
   int c1=0,c2=0,c3=0;
   
   for(int i=0;i<n;i++)
   {
      cin >> a[i];
      if(a[i]==1) c1++;
      else if(a[i]==2) c2++;
      else c3++;
   }
   debug(c1) debug(c2) debug(c3)
   vector dp(n+5,vector(n+5,vector(n+5,x)));
   
   for(int k=0;k<=n;k++)
      for(int j=0;j<=n;j++)
         for(int i=0;i<=n;i++)
         {
            if(i+j+k == 0) continue;
            double di=0,dj=0,dk=0;

            
            if(i != 0) di = (double(1) * i * dp[i-1][j][k]);
           
            if(j != 0) dj = (double(1) * j * dp[i+1][j-1][k]);

            if(k!= 0) dk = (double(1) * k * dp[i][j+1][k-1]);
            
            debug(i) debug(j) debug(k)
            debug(di) debug(dj) debug(dk)
            
            dp[i][j][k] = (di + dj + dk + n)/(i+j+k);

            debug(dp[i][j][k])



            

         }
   

   cout<<fixed<<setprecision(15)<<dp[c1][c2][c3]<<nline;

   debug(dp)



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