class Solution {
public:
    int dijkstra(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int , int>>> adj(n);
        queue<vector<int>> q;
        for(auto &flight : flights){
            int a = flight[0];
            int b = flight[1];
            int c = flight[2];
            adj[a].push_back({b,c});
        }
        vector<int> dist(n,1e9);
        dist[src] = 0;
        q.push({0 , src , 0});

        while(!q.empty()){
            int stop = q.front()[0];
            int c = q.front()[1];
            int dis = q.front()[2];

            q.pop();
            if(stop > k ) continue;
            for(int i=0; i<adj[c].size(); i++ ){
                
                auto[next , wt] = adj[c][i];
            
                if(dis + wt < dist[next] && stop <= k  ){
                        dist[next] = dis + wt;

                        q.push({stop+1 , next , dist[next]});
                    }
                }
             
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        return dijkstra(n,flights,src,dst,k);
    }
};