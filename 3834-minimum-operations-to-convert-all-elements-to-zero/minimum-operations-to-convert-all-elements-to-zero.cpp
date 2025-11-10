class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        std::vector<int> st; 
        st.push_back(0);      
        
        for (int num : nums) {

            while (!st.empty() && st.back() > num) {
                st.pop_back();
            }

            if (st.empty() || st.back() < num) {
                ans++;
                st.push_back(num);
            }

        }
        
        return ans;
    }
};
