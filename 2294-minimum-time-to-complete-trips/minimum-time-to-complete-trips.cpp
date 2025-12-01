class Solution {
public:
bool isBool(long long num, vector<int>&time, int totalTrips){
    long long cnt = 0;
    for(int t : time){
        if(num >= t){
            cnt += num/t;
        }
    }
    return cnt >= totalTrips;
}
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s = 1, e = 1e14;
        while(s < e){
            long long mid = s + (e-s)/2;
            if(isBool(mid,time,totalTrips)){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return s; 
    }
};