class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        const int kMod = 1e9 + 7;
        const int maxx = numeric_limits<int>::max();
        using pii = pair<int, int>;
        vector<vector<pii>> g(n + 1);
        for (auto& e : edges) {
            g[e[0]].push_back({ e[1], e[2] });
            g[e[1]].push_back({ e[0], e[2] });
        }

        // Shortest distance from n to x.
        vector<int> dist(n + 1, maxx);
        dist[n] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({ 0, n });
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (dist[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (dist[u] + w >= dist[v]) {
                    continue;
                }
                dist[v] = dist[u] + w;
                q.push({ dist[v], v });
            }
        }

        vector<int> dp(n + 1, maxx);
        function<int(int)> dfs = [&](int u) {
            if (u == n) {
                return 1;
            }
            if (dp[u] != maxx) {
                return dp[u];
            }
            int ans = 0;
            for (auto [v, w] : g[u]) {
                if (dist[u] > dist[v]) {
                    ans = (ans + dfs(v)) % kMod;
                }
            }
            return dp[u] = ans;
        };
        return dfs(1);
    }
};