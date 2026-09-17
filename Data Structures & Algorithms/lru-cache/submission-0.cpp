class LRUCache {
private:
    vector<pair<int, int>> cache; // the list
    int capacity;
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    int get(int key) {
        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){// if found
                pair<int, int> tmp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(tmp);
                return tmp.second;
            }
        }
        return -1;// if not found
    }
    void put(int key, int value) {
        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }
        if(cache.size() == capacity) cache.erase(cache.begin());
        cache.push_back({key, value});
    }
};
