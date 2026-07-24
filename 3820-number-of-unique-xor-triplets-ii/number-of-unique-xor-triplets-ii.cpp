class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxi = 2048;
        int n = nums.size();
        vector<int>pairs(maxi,false);
        vector<int> triplets(maxi,false);

        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                int val = nums[i] ^ nums[j];
                pairs[val] = true;
            }
        }
            for(int j = 0;j<maxi;j++){
                if(pairs[j]){
                    for(int i = 0;i<n;i++){
                        int val = j ^ nums[i];
        
                        triplets[val] = true;

                    }
                }
            }
        int count = 0;
        for(int j = 0;j<maxi;j++){
            if(triplets[j]) count++;
        }
        return count;
    }
};