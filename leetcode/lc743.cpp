class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,1e9);
        dist[k-1]=0;
        for(auto it:times)
        {
            int a = it[0];
            int b=it[1];
            int we=it[2];

            adj[a-1].push_back({b-1,we});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k-1});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int u = it.second;
            int d= it.first;
            if (d > dist[u]) continue;
            for(auto i : adj[u])
            {
                int v= i.first;
                int wei=i.second;

                if(dist[u]+wei < dist[v] )
                {
                    dist[v]=dist[u]+wei;
                    pq.push({dist[v],v});
                }
            }
        }
        int ma=0;
        for(int i : dist)
        {
            ma=max(ma,i);
        }

        if(ma==1e9) return -1;

        return ma;

    }
};