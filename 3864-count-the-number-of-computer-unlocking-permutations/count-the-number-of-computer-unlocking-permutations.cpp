class Solution {
public:
const long long MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int mini = complexity[0];
        int n = complexity.size();
        for(int i = 1;i<n;i++){
            if(complexity[i] <= mini) return 0;
        }
        long long fact = 1;
        for(int i = 2;i<n;i++){
            fact = (fact*i)%MOD;
        }
        return (int)fact;
    }
};