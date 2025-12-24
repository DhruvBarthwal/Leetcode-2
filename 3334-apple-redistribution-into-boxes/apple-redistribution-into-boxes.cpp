class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int sum = accumulate(apple.begin(),apple.end(),0LL);
        int cap = 0;
        int boxes = 0;
        for(int num : capacity){
            cap += num;
            boxes++;
            if(cap >= sum){
                break;
            }
        }
        return boxes;
    }
};