#include <bits/stdc++.h>
using namespace std;
int main()
{ int n,a,b;
    cin>>n;
    vector<int>x,y;
    for(int i=0;i<n;i++)
     {
        cin>>a;
        x.push_back(a);
     }
      for(int i=0;i<n;i++)
     {
        cin>>b;
        y.push_back(b);
     }
     int maxi=0;
     for(int i=0;i<=n-1;i++)
     {
        for (int j=i+1;j<=n-1;j++)
        {
            maxi=max(maxi,(int)(pow((x[i]-x[j]),2)+pow(y[i]-y[j],2)));
        }
     }
     cout<<maxi;
}