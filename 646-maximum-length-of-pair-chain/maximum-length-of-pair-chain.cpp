class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //initialization
        int count = 1;
        int ansEnd = INT_MIN;
        //sorting vector
        sort(pairs.begin(),pairs.end(),[](const vector<int>&a, const vector<int>&b){
           return  a[1] < b[1];
        });
        //traversing array
        for(auto num : pairs){
            if(ansEnd<num[0]){
                if(ansEnd != INT_MIN){
                    count++;
                }
                ansEnd = num[1];
            }
        }
        return count;
    }
};