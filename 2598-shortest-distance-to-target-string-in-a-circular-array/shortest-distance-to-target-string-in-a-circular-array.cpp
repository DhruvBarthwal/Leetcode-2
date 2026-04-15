class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        bool flag = false;
        int prev = 0;
        int next = 0;
        //check front
        for(int i = startIndex;i<2*n;i++){
            if(words[i % n] == target){
                flag = true;
                break;
            }
            next++;
        }
        if(!flag) return -1;
        for(int i = startIndex;i> -n;i--){
            if(words[(i+n)%n] == target) break;
            prev++;
        }
        return min(next,prev);

    }
};