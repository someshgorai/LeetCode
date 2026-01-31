class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        int ALPHA = 26;
        vector<vector<pair<int,int>>> adj(ALPHA);

        // Build graph (u -> v with weight)
        for(int i=0;i<(int)original.size();i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            adj[u].push_back({v,cost[i]});
        }

        const long long INF = 1e18;
        vector<vector<long long>> dist(ALPHA, vector<long long>(ALPHA, INF));

        // Run Dijkstra from each character (26 times)
        for(int start=0; start<ALPHA; start++){
            priority_queue<pair<long long,int>,
                           vector<pair<long long,int>>,
                           greater<pair<long long,int>>> pq;

            dist[start][start] = 0;
            pq.push({0,start});

            while(!pq.empty()){
                auto [d,node] = pq.top();
                pq.pop();

                if(d > dist[start][node]) continue;

                for(auto [nbr,w] : adj[node]){
                    if(dist[start][nbr] > d + w){
                        dist[start][nbr] = d + w;
                        pq.push({dist[start][nbr], nbr});
                    }
                }
            }
        }

        // Compute total conversion cost
        long long ans = 0;
        for(int i=0;i<(int)source.size();i++){
            int s = source[i]-'a';
            int t = target[i]-'a';

            if(s == t) continue;

            if(dist[s][t] == INF) return -1;

            ans += dist[s][t];
        }

        return ans;
    }
};
