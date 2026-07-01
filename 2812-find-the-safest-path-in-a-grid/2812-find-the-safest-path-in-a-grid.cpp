class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Step 1: multi-source BFS from all thieves
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    safeness[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(int d = 0; d < 4; d++){
                int nx = x + dx[d], ny = y + dy[d];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && safeness[nx][ny] == -1){
                    safeness[nx][ny] = safeness[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // Step 2: Dijkstra-style max-heap to maximize the minimum safeness along path
        // pair<safeness_so_far, {x, y}>, max-heap based on safeness_so_far
        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<int>> maxSafe(n, vector<int>(n, -1));

        pq.push({safeness[0][0], {0, 0}});
        maxSafe[0][0] = safeness[0][0];

        while(!pq.empty()){
            auto [curSafe, pos] = pq.top(); pq.pop();
            int x = pos.first, y = pos.second;

            if(x == n-1 && y == n-1) return curSafe;

            if(curSafe < maxSafe[x][y]) continue; // stale entry

            for(int d = 0; d < 4; d++){
                int nx = x + dx[d], ny = y + dy[d];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                    int newSafe = min(curSafe, safeness[nx][ny]);
                    if(newSafe > maxSafe[nx][ny]){
                        maxSafe[nx][ny] = newSafe;
                        pq.push({newSafe, {nx, ny}});
                    }
                }
            }
        }

        return maxSafe[n-1][n-1];
    }
};