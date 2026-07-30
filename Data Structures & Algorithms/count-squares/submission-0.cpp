class CountSquares {
private:
    unordered_map<long, int> ptsCount;
    vector<pair<int, int>> pts;
    long getKey(int x, int y){
        return (static_cast<long>(x) << 32 | static_cast<long>(y));
    }
public:
    CountSquares() {}
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        ptsCount[getKey(x, y)]++;
        pts.push_back({x, y});
    }
    
    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1];
        for(auto& pt: pts){
            int x = pt.first, y = pt.second;
            if(abs(px - x) != abs(py - y) || px == x) continue;
            res += ptsCount[getKey(x, py)] * ptsCount[getKey(px, y)];
        }
        return res;
    }
};