class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> result = {1};
        while(result.size() < n){
            vector<int> temp;
            for(int i : result) if(2*i -1 <=n) temp.push_back(2*i-1);
            for(int i : result) if(2*i <= n) temp.push_back(2*i);
            result = temp;
        }
        return result;
    }
};