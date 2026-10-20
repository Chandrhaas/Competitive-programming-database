//brute force hard coded 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef string str;

int main() 
{
int m,n,k;
str a;
cout<<"enter m,n,k"<<endl;
 cin>>m>>n>>k;
 vector<string>vs(m);
 for(int i=0;i<=m-1;i++)
 { //cout<<"enter string"<<endl;
    cin>>a;
    vs[i]=a;
 }
 int b=0,c=0;
 for(int l=0;l<=m-1;l++)
 {  c=0;
    for(int r=1;r<=k;r++){ 
    for(int p=0;p<=n-1;p++)
    { c++;
        if(vs[l][p]!=vs[l][p+1])
        { 
            for(int q=1;q<=k*c;q++)
            cout<<vs[l][p];
            
            
            c=0;
        }
         
    }
    cout<<endl;
    }

 }
    return 0;
}