class EventManager {
public:
    int n;
    struct cmp{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }  
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    unordered_map<int,int> mp;
    
    EventManager(vector<vector<int>>& events) {
        for(auto &event : events){
            pq.push({event[1],event[0]});
            mp[event[0]] = event[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority, eventId});
    }
    
    int pollHighest() {
        while(!pq.empty() && mp[pq.top().second] != pq.top().first){
            pq.pop();
        }
        if(pq.empty()) return -1;
        
        int val = pq.top().second;
        pq.pop();
        mp.erase(val);
        return val;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */