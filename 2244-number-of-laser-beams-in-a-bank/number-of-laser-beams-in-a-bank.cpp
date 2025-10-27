class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int lasers = 0;
        int prev = 0;
        for(auto  s : bank){
            int devices = count(s.begin(), s.end(), '1');
            if(devices > 0){
                lasers += devices* prev;
                prev = devices;
            }
        }
        return lasers;
    }
};