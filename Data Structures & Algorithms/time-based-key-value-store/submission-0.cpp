class TimeMap {
public:
    TimeMap() {}
    
    unordered_map<string, map<int, string>> m;

    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto tmp = m[key].upper_bound(timestamp);
        return tmp == m[key].begin()? "": prev(tmp) -> second;
    }
};
