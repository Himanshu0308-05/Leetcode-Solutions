class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,1e9);
        dist[src] = 0;
        for(int i=0; i<k+1; i++){
            vector<int> ndist = dist;

            for(auto flight : flights){
                int u = flight[0];
                int v = flight[1];
                int wt = flight[2];

                if(dist[u] == 1e9) continue;

                if(dist[u] + wt < ndist[v]) ndist[v] = dist[u] + wt;

            }
            dist = ndist;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};