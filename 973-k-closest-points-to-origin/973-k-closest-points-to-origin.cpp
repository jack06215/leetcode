class Solution {
public:
    void combine(vector<vector<int> >& points, int lo, int mid, int hi) {
    int lsize = mid - lo + 1, rsize = hi - mid;
    vector<pair<vector<int>, double> > L(lsize + 1), R(rsize + 1);
    for(int i = 0; i < lsize; i++)
        L[i] = make_pair(points[lo + i], sqrt(pow(points[lo + i][1], 2) + pow(points[lo + i][0], 2)));

    for(int i = 0; i < rsize; i++)
        R[i] = make_pair(points[mid + i + 1], sqrt(pow(points[mid + i + 1][1], 2) + pow(points[mid + i + 1][0], 2)));

    L[lsize] = make_pair(vector<int>{ }, numeric_limits<double>::max());
    R[rsize] = make_pair(vector<int>{ }, numeric_limits<double>::max());
    int i = 0, j = 0;
    for(int k = lo; k <= hi; k++) {
        if(islessequal(L[i].second, R[j].second))
            points[k] = L[i].first, i++;
        else
            points[k] = R[j].first, j++;
    }
}

void kClosest(vector<vector<int> >& points, int lo, int hi) {
    if(lo < hi) {
        int mid = floor((lo + hi) >> 1);
        kClosest(points, lo, mid);
        kClosest(points, mid + 1, hi);
        combine(points, lo, mid, hi);
    }
}

vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
    vector<vector<int> > closest;
    kClosest(points, 0, points.size() - 1);

    int counter = 0;
    for(auto& point : points) {
        closest.push_back(point);
        if(++counter == K) break;
    }
	
    return closest;
}
};