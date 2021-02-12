// https://codeforces.com/problemset/problem/1200/D

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
#define all(x) (x).begin(),(x).end()
#define int long long int
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define F first
#define S second
#define inf 1e18
#define vi vector<int>
#define Point complex<int>
#define X real()
#define Y imag()
#define pii pair<int,int>
#define num0Beg(x) __builtin_clz(x) // no. of zero in beginning of bit representation
#define num0end(x) __builtin_ctz(x) // no. of zero in the end
#define numOf1(x) __builtin_popcount(x) // no. of ones in bit rep.
#define parity(x) __builtin_parity(x) // parity of 1
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
const int N = 2010;
char M[N][N];
int blk[N][N],goodr[N][N],goodc[N][N],bl[N][N],gd[N][N],g[N][N];
int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      int n,k;
      cin>>n>>k;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
          cin>>M[i][j];  
      }       
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
          blk[i][j]+=(M[i][j]=='B')+blk[i][j-1];
          bl[i][j]+=(M[i][j]=='B')+bl[i-1][j];
        }  
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
          //  i,j is the particular cell
          if(blk[i][n]>0 && blk[i][n]==blk[i][min(j+k-1,n)]-blk[i][j-1])
            goodr[i][j]++;
          if(bl[n][j]>0 && bl[n][j]==bl[min(n,i+k-1)][j]-bl[i-1][j])
            goodc[i][j]++;  
        }
      }
      for(int i=n;i>=1;i--)
      {
        int rs=0;  
        for(int j=n;j>=1;j--)
        {
          if(j+k<=n)
          rs-=goodc[i][j+k]; 
          rs+=goodc[i][j];
          gd[i][j]+=rs; 
        }
      }
      for(int i=n;i>=1;i--)
      {
        int rs=0;  
        for(int j=n;j>=1;j--)
        {
          rs+=goodr[j][i];
          if(j+k<=n)
          rs-=goodr[j+k][i];   
          g[j][i]+=rs; 
        }
      }
      int x=1,y=1;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
          if(gd[i][j]+g[i][j]>gd[x][y]+g[x][y])
            x=i,y=j;  
        }  
      }
      for(int i=x;i<=x+k-1;i++)
      {
        for(int j=y;j<=y+k-1;j++)
        {
          M[i][j]='W';  
        }  
      }
      int ans=0;
      for(int i=1;i<=n;i++)
      {
        int rs=0;
        for(int j=1;j<=n;j++)
        {
          if(M[i][j]=='B')
            rs=1;
        }
        if(!rs)
          ans++;  
      }
      for(int i=1;i<=n;i++)
      {
        int rs=0;  
        for(int j=1;j<=n;j++)
        {
          if(M[j][i]=='B')
            rs=1;  
        }
        if(!rs)
          ans++;
      }
     cout<<ans;    
    }
    return 0;
}
