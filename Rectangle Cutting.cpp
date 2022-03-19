#include<bits/stdc++.h>
using namespace std;
 
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
 
#define lol long long int
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
bool prime(lol n)
{
    // Corner case
 
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (lol i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
 
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------BIT MASKING FUNCTIONS---------------------------------------------------------------------*/
lol SetBitCount(lol n)
{
    lol count=0;
    while(n){
      count++;
      n=n&(n-1);
    }
    return count;
}
 
int GetIthBit(lol n, lol i){
  return (n & (1<<i))? 1:0;
}
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
string lcs(string a, string b){
 
  int la = a.length(), lb  = b.length();
  int arr[la+1][lb+1];
  memset(arr,0,sizeof(arr));
 
  for(int i = 1 ; i < la; i++){
    for(int j = 1 ; j < lb; j++){
      if(a[i-1] == b[j-1]){
        arr[i][j] = arr[i-1][j-1  ]+1;
      }
      else{
        arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
      }
    }
  }
  int x = la, y = lb;
  string ans = "";
  
  while(x > 0 && y > 0){
    if(a[x-1] == b[y-1]){
      ans+=a[x-1];
      x--;y--;
    }
    else{
      if(arr[x-1][y] > arr[x][y-1]){
        x--;
      }
      else{
        y--;
      }
    }
  }
  reverse(ans.begin(),ans.end());
  // cout <<ans <<endl;
  return ans;
}
void solve(){
/*--------------------------------------------------------------------------------------------------*/
  int x , y;
  cin >> x >> y;
  int a[x+1][y+1];
  memset(a, 0x3f, sizeof(a));
 
  // cout << a[x][y] << " LL " <<endl;
    for(int  i = 0 ; i<=x; i++){
        a[i][0] = 0;
    }
    for(int  i = 0 ; i<=y; i++){
        a[0][i] = 0;
    }
 
  for(int i = 1; i<=x; i++){
    a[i][1] = i-1;
  }
  for(int i = 1; i<=y; i++){
    a[1][i] = i-1;
  }
  a[1][1] = 0;
  for(int i = 2; i<=x; i++){
    for(int j = 2; j<=y; j++){
        if(i==j){
            a[i][j] = 0;
        }
        else{
            
                for(int k = 1; k <= i/2; k++){
                    a[i][j] = min(a[i][j],1 + a[i-k][j] + a[k][j]);
                }
                for(int k = 1; k <= j/2; k++){
                    a[i][j] = min(a[i][j],1 + a[i][j-k] + a[i][k]);
                }
            
        }
    }
  }
  cout << a[x][y] <<endl;
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