class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // intialization
        vector<int> st;
        // traversing the array
        for (int num : nums) {
            st.push_back(num);
            while (st.size() > 1) {
                int a = st[st.size() - 2];
                int b = st[st.size() - 1];
                int g = gcd(a, b);
                 if (g > 1) {
                    long long l = (1LL * a / g) * b;
                    st.pop_back();
                    st.pop_back();
                    st.push_back((int)l);
                }
                else {
                    break;
                }
            }
        }
        return st;
    }
};