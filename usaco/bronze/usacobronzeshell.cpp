#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,a,b,c,c1=0,c2=0;
    cout<<"enter n \n";
	cin >> n;
	vector<tuple<int,int,int>>v;
    cout<<"enter values\n";
    for(int i=0;i<=n-1;i++)
    {
       cin>>a>>b>>c;
       v.push_back({a,b,c});
    }
    vector<int>v2(3,0);
    for(int k=1;k<=3;k++)
    { v2[k-1]=1;c2=0;
        for(int i=0;i<=n-1;i++)
        {  swap(v2[get<0>(v[i])-1],v2[get<1>(v[i])-1]);
            if(v2[get<2>(v[i])-1]==1)
            c2++;
        }
        //c1=max(c1,c2);
        cout<<c2;
        v2[0]=0;
        v2[1]=0;
        v2[2]=0;
    }
    //cout<<c1;
    return 0;
}