class Solution {
private:
    bool bfs(int i, vector<int>& arr,int n){
        //base case
        if(i < 0 || i >= n){
            return false;
        }
        //negative number
        if(arr[i] < 0){
            return false;
        }
        arr[i] = arr[i] * (-1);
        //termination
        if(arr[i] == 0){
            return true;
        }
        return (bfs(i+arr[i],arr,n) || bfs(i-arr[i],arr,n));

    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        return bfs(start,arr,n);
    }
};