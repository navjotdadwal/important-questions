// https://codeforces.com/problemset/problem/1326/D2

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
 
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
        z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
           ++z[i];
        if (i + z[i] - 1 > r)
           l = i, r = i + z[i] - 1;
    }
    return z;
}
string calc(string ss,string rv)
{
  string s=ss+'$'+rv;
  int n=ss.length()+rv.length()+1;
  vector<int> z(n);
  z=z_function(s);
  int rs=0;
  string res="";
  for(int i=ss.length();i<n;i++)
  {
    if(z[rs]<=z[i] && i+z[i]>=n)
    {
      rs=i;
    }
  }
  return s.substr(rs,z[rs]);
}
int32_t main()
{
    FAST
    int tt=1;
    cin >> tt;
    while(tt--)
    {         
      string s;
      cin>>s;
      int n=s.length();
      int ans=0;
      int i,j;
      string rs="",q="";
      for(i=0,j=n-1;j>=i && s[i]==s[j];i++,j--)
      {
        if(i==j) 
        {
          q+=s[i];
        }
        else
        {
          rs+=s[i];
        }
      }
      string tp=rs;
      reverse(tp.begin(),tp.end());
      if(2*rs.length()+q.length()==n)
      {
        cout<<rs+q+tp<<"\n";
        continue;
      }
      string ss=s.substr(i,j-i+1);
      vector<int> z(ss.length());
      string rs1="",rv=ss;
      reverse(rv.begin(),rv.end());
      rs1=calc(ss,rv);
      string rs2=calc(rv,ss);
      if(rs1.length()<rs2.length())
        rs1=rs2;
      cout<<rs+rs1+tp<<"\n";     
    }
    return 0;
}
