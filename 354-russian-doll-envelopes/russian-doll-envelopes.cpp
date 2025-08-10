class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sorting the array
        sort(envelopes.begin(),envelopes.end(), [](const vector<int>&a , const vector<int>&b){
            if(a[0] == b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        //storing heights
        vector<int> heights;
        for(auto e : envelopes){
            heights.push_back(e[1]);
        }
        //traversing the array
        vector<int> result;
        for(auto num : heights){
            auto it = lower_bound(result.begin(),result.end(),num);
            if(it == result.end()){
                result.push_back(num);
            }
            else{
                *it = num;
            }
        }
        return result.size();
    }
};