
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        deque<pair<int,int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, 1, -1, 0};

        while(!dq.empty()) {

            auto [r, c] = dq.front();
            dq.pop_front();

            for(int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols) {

                    int cost = grid[nr][nc];

                    if(dist[r][c] + cost < dist[nr][nc]) {

                        dist[nr][nc] = dist[r][c] + cost;

                        if(cost == 0)
                            dq.push_front({nr, nc});
                        else
                            dq.push_back({nr, nc});
                    }
                }
            }
        }

        return dist[rows-1][cols-1];
    }
};