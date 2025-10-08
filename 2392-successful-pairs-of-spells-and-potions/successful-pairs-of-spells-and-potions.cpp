class Solution {
public:
    int binarySearch(int val, int m ,long long success, vector<int>& spells, vector<int>& potions){
        int s = 0, e= m-1, mid = s + (e-s)/2;
        int ans = m;
        while(s<=e){
            long long prod = 1LL * val * potions[mid];
            if(prod >= success){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return m-ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //intialization
        int n = spells.size(), m = potions.size();
        //sorting
        sort(potions.begin(), potions.end());
        //result vector
        vector<int> result;
        //traversing the array
        for(int i =0;i<n;i++){
            int value = binarySearch(spells[i],m,success,spells,potions);
            result.push_back(value);
        }
        return result;
    }
};