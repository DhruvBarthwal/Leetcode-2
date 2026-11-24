class LFUCache {
public:
//map
//freqmap
//Node
//updateFreq

class Node {
    public:
    int key, value, freq;
    Node(int k, int v){
        this->key = k;
        this -> value = v;
        this -> freq = 1;
    }
};

unordered_map<int,Node*> mp;
unordered_map<int,list<Node*>> freqMap;

int capacity, minFreq;

void updateFreq(Node* node){
    int f = node -> freq;
    //remove the current node
    freqMap[f].remove(node);
    //if list is empty remove
    if(freqMap[f].empty()){
        freqMap.erase(f);
        if(f == minFreq) minFreq++;
    }
    //if f = minfreq inc++
    node -> freq++;
    //adding the node
    freqMap[node -> freq].push_front(node);
}
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        Node* node = mp[key];
        
        updateFreq(node);

        return node->value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        //if already present
        if(mp.count(key)){
            Node* node = mp[key];
            node -> value = value;
            updateFreq(node);
            return;
        }
        // if the cache is full
        if(mp.size() == capacity){
            //deletion
            Node* node = freqMap[minFreq].back();
            freqMap[minFreq].pop_back();
            mp.erase(node->key);
            delete node;
            if(freqMap[minFreq].empty()) freqMap.erase(minFreq);
        }

        Node* node = new Node(key,value);
        minFreq = 1;
        mp[key] = node;
        freqMap[1].push_front(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */