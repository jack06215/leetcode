class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited = { 0 };
        dfs(0, rooms, visited);
        return rooms.size() == visited.size();
    }

    void dfs(int node, vector<vector<int>>& edges, unordered_set<int>& visited) {
        for (auto next: edges[node]) {
            if (visited.count(next) == 0) {
                visited.insert(next);
                dfs(next, edges, visited);
            }
        }
    }
};