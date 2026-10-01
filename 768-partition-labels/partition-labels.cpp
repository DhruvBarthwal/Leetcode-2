class Solution {
public:
//start --- end
// a - 0 --- 8
// b - 1 --- 5
// c - 4 --- 7
// maxi - 8
    vector<int> partitionLabels(string s) {
        unordered_map<int,int> mp;    
        int n = s.size();

        for(int i =0;i<n;i++){
            int ch = s[i] - 'a';
            mp[ch] = i;
        }

        vector<int> ans;
        int maxi = 0;
        int prev = 0;
        for(int i = 0;i<n;i++){
            int ch = s[i] - 'a';
            maxi = max(maxi,mp[ch]);
            if(i == maxi){
                maxi = 0;
                ans.push_back(i - prev + 1);
                prev = i+1;
                continue;
            }
        }
        return ans;
    }
};