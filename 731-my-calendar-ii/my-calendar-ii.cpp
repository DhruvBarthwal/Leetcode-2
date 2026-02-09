class MyCalendarTwo {
public:
vector<pair<int,int>>booked;
vector<pair<int,int>>overlaps;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        //triple check
        for(auto &[s,e] : overlaps){
            if(max(s,startTime) < min(e,endTime)){
                return false;
            }
        }
        //overlap
        for(auto [s,e] : booked){
            int l = max(s,startTime);
            int r = min(e,endTime);
            if(l < r) overlaps.push_back({l,r});
        }
        //new booking
        booked.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */