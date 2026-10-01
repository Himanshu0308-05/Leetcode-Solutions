class Dsu {
public:
    vector<int> par, siz;

    Dsu(int n) {
        par.resize(n);
        siz.resize(n, 1);

        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int findpar(int u) {
        if (par[u] == u)
            return u;

        return par[u] = findpar(par[u]);
    }

    void Merge(int u, int v) {
        u = findpar(u);
        v = findpar(v);

        if (u == v) return;

        if (siz[u] < siz[v])
            swap(u, v);

        par[v] = u;
        siz[u] += siz[v];
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

      
        vector<tuple<int, int, int>> edges;

       
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int cost = abs(points[i][0] - points[j][0])
                         + abs(points[i][1] - points[j][1]);

                edges.push_back({cost, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        Dsu ds(n);

        int totalCost = 0;
        int edgesUsed = 0;

        
        for (auto &[cost, u, v] : edges) {

            if (ds.findpar(u) != ds.findpar(v)) {

                ds.Merge(u, v);

                totalCost += cost;
                edgesUsed++;

                if (edgesUsed == n - 1)
                    break;
            }
        }

        return totalCost;
    }
};