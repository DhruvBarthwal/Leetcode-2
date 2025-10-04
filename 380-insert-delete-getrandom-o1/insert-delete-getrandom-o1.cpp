class RandomizedSet {
public:
    unordered_map<int,int> count;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(count.find(val) == count.end()){
            count[val]++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(count.find(val) != count.end()){
            count.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int r = rand() % count.size();
        auto it = count.begin();
        advance(it,r);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */