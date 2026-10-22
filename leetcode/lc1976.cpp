class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using ll = long long;
        vector<vector<pair<ll,ll>>>adj(n);
        vector<ll>time(n,LLONG_MAX);
        vector<ll>ways(n,0);
        time[0]=0;
        ways[0]=1;

        for(auto it : roads)
        {   ll u = it[0];
            ll v=it[1];
            ll tim =it[2];
            adj[u].push_back({v, tim});
            adj[v].push_back({u, tim});

        }
        priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;

        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto a = pq.top();
            pq.pop();
            ll tim = a.first;
            ll node = a.second.first;
            ll way = a.second.second;
            if (tim > time[node]) continue;

            for(auto it:adj[node])
            {
                ll u = it.first;
                ll ti= it.second;
                if(ti+tim < time[u])
                {
                    ways[u]=ways[node];
                    time[u]=ti+tim;
                    pq.push({time[u],{u,ways[u]}});
                }
                else if(ti+tim==time[u])
                ways[u]=(ways[u]+ways[node])%(1000000007);
            }
        }
        return ways[n-1];

    }
};