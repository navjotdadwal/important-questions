// https://codeforces.com/problemset/problem/1204/C
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
 
const int N = 110;
int dist[N][N];
int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      int n;
      cin>>n;
      char M[n+1][n+1];
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
          dist[i][j]=inf;
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
          cin>>M[i][j]; 
          if(M[i][j]=='1')
            dist[i][j]=1;
        }
        dist[i][i]=0; 
      }       
      for(int k=1;k<=n;k++)
      {
        for(int i=1;i<=n;i++)
        {
          for(int j=1;j<=n;j++)
          {
            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
          }
        }  
      }
      int m;
      cin>>m;
      int p[m+1];
      for(int i=1;i<=m;i++)
        cin>>p[i];
      vector<int> ans;
      ans.pb(1);
      for(int i=3;i<=m;i++)
      {
        if(dist[p[ans.back()]][p[i]]<i-ans.back())
          ans.pb(i-1);
      }
      ans.pb(m);
      cout<<ans.size()<<"\n";
      for(int el: ans)
        cout<<p[el]<<" ";
    }
    return 0;
}
