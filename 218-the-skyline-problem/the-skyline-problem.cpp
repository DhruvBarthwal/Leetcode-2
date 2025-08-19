class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //initialization
        //saving every point in the vector
        vector<pair<int,int>> event;
        for(auto b : buildings){
            event.push_back({b[0],-b[2]});
            event.push_back({b[1],b[2]});
        }
        //sorting
        sort(event.begin(),event.end());
        //multiset for stroing heights
        multiset<int> heights ={0};
        vector<vector<int>> result;
        int prevMax = 0;
        //traversing events
        for(auto e : event){
            int x = e.first;
            int h = e.second;
            if(h<0){
                heights.insert(-h);
            }
            else{
                heights.erase(heights.find(h));
            }
            
            int currMax = *heights.rbegin();
            if(currMax != prevMax){
                result.push_back({x,currMax});
                prevMax = currMax;
            }
        }
        return result;
    }
};