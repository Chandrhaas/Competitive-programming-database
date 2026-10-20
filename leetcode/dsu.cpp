#include<bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i]=1;
        } 
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); 
    }

    void unite(int i, int j) {
        int upi = find(i);
        int upj = find(j);
        if (upi == upj) {
           return; 
        }
        int szi = size[i];
        int szj = size[j];
        if(szi < szj){
            parent[upi] = upj;
            size[upj] += size[upi];
        }
        else{
            parent[upj] = upi;
            size[upi] += size[upj];
        }
    }
};


signed main(){

    DSU *dd = new DSU(5);
    dd->unite(1,2);
    dd->unite(2,4);
    dd->unite(1,3);
    dd->unite(1,4);
    
    cout << dd->find(4) <<" ";

 
}