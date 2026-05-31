class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int maxi = *max_element(asteroids.begin(),asteroids.end());
        long long m = mass;
        int n = asteroids.size();
        for(int i = 0;i<n;i++){
            if(asteroids[i] <= m){
                m += asteroids[i];
            }
            else return false;
            if(m == maxi) break;
        }
        return true;
    }
};