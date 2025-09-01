class Solution {
private:
    double gain(int a, int b){
        return (double)(a+1)/(b+1) - (double)a/b;
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        //initialization
        int n = classes.size();
        double sum = 0.0;
        priority_queue<pair<double,pair<int,int>>> pq;

        //traversing the array
        for(auto &num : classes){
            int p = num[0], q = num[1];
            sum += (double)p/q;
            pq.push({gain(p,q), {p,q}});
        }

        //assinging extra students
        while(extraStudents--){
            auto [g,p] = pq.top();
            pq.pop();
            int a= p.first  , b = p.second;
            sum -= (double)a/b;
            a++ , b++;
            sum += (double)a/b;
            
            pq.push({gain(a,b),{a,b}});
        }
        return sum/n;
    }
};