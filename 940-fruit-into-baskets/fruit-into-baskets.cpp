class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //initialization
        int left = 0, maxLen =0;
        int n = fruits.size();
        unordered_map<int,int> freq;
        //traversal by sliding window
        for(int right = 0;right<n;right++){
            freq[fruits[right]]++;
            while(freq.size()>2){
                freq[fruits[left]]--;
                if(freq[fruits[left]]==0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};