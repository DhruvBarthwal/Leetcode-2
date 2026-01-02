class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> count;
        int result = 0;
        for(int num : nums){
            count[num]++;
            if(count[num]>1){
                result = num;
                break;
            }
        }
        return result;
    }
};