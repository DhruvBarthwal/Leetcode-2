class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5) return false;
        int five = 0, ten =0, twenty = 0;

        for(int &bill : bills){
            if(bill == 5) five++;
            else if(bill == 10){
                if(five == 0) return false;
                five--;
                ten++;
            }
            else{
                if(five == 0 || (ten == 0 && five < 3)) return false;
                if(ten != 0){
                    ten--;
                    five--;
                }
                else{
                    five -= 3;
                }
            }
        }
        return true;
    }
};