#include<bits/stdc++.h>
using namespace std;
 
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
 
#define lol long long 
#define ulol unsigned long long
#define pf cout
#define nl "\n"
#define elif else if
#define mod 1000000007
#define vi vector<int>
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define vpii vector<pii>
#define pb push_back
#define pob pop_back
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define mp            make_pair
#define PI            3.141592653589793238
#define E           2.7182818284590452353602874713527
#define deb(x)    cout<<endl<<#x<<"="<<x<<endl
#define deb2(x,y)    cout<<endl<<#x<<"="<<x<<" and "<<#y<<"="<<y<<endl
#define fp(x,n,y) for(int i=x; i<n; i+=y)
#define fn(a,c,b) for(int i=a; i>c; i-=b)
#define arrin(a,n) for(int i=0; i<n; i++){ cin>>a[i];}
#define arr2in(a,b,n) for(int i=0; i<n; i++){ cin>>a[i]; b[i]=a[i];}
 
template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
} 
 
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
struct project{
    ulol start;
    ulol end;
    ulol reward;
};
 
void solve(){
/*--------------------------------------------------------------------------------------------------*/
  int x;
  cin >> x;
 
  vector<project> v(x);
  vector<ulol> temp(x);
  for(int  i = 0 ; i < x; i++){
    cin >> v[i].start >> v[i].end >> v[i].reward;
    temp[i] = v[i].end;
  }
  sort(temp.begin(),temp.end());
 
  sort(v.begin(), v.end(), [](auto x, auto y){return x.end < y.end;});
 
  vector<ulol> dp(x,0);
  
  
  // for(int  i = 0 ; i < x; i++){
  //   cout << v[i].start<< " " << v[i].end<< " " <<v[i].reward<< " " << endl;
  //   // dp[v[i].end] = 0;
  // }
 
  dp[0] = v[0].reward;
  for(int  i = 1 ; i < x; i++)
{
    auto t = lower_bound(temp.begin(), temp.begin()+i,v[i].start) - temp.begin();
    t = t-1;
    // cout << t <<endl;
    if(t<0){
        dp[i] = max(dp[i-1], v[i].reward);
    }
    else{
        dp[i] = max(dp[i-1], v[i].reward + dp[t]);
    }
    
}  
 
cout << dp[x-1];
// cout << z <<  <<endl ;
 
 
 
 
 
/*--------------------------------------------------------------------------------------------------*/
}
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
 
int main(){
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ulol t=1;
    // cin>>t;
    // deb(t);
    while(t--){
        solve();
        cout<<'\n';
    }
}