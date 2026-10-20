class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int stop) {

     vector<vector<pair<int,int>>>adj(n);
     for(auto it : flights)   
     {
        int fr = it[0];
        int to= it[1];
        int pr=it[2];
        adj[fr].push_back({pr,to});
     }
     vector<int>dis(n,1e9);
     dis[src]=0;
     queue<pair<int,pair<int,int>>>tq;
     tq.push({0,{src,0}});
     while(!tq.empty())
     {
        auto [k,no]=tq.front();
        tq.pop();
        int node=no.first;
        int dist= no.second;

        if(k>stop) continue;
        for(auto it : adj[node])
        {
            int ad= it.second;
            int we=it.first;
            if(dist+we < dis[ad] && k<=stop)
            {
                dis[ad]=dist+we;
                tq.push({k+1,{ad,dis[ad]}});
            }
        }

     }
     if(dis[dst]==1e9) return -1;
     else return dis[dst];
    }
};