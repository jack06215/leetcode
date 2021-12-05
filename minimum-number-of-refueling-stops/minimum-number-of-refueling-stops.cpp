class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int nextStop = 0;
        int fuelStock = 0;
        priority_queue<int> pq;
        pq.push(startFuel);
        for (int i = 0; !pq.empty(); i++) {
            int current = pq.top(); pq.pop();
            fuelStock += current;
            if (fuelStock >= target) {
                return i;
            }
            while (nextStop < stations.size() && fuelStock >= stations[nextStop][0]) {
                pq.push(stations[nextStop][1]);
                nextStop++;
            }
        }
        return -1;
    }
};