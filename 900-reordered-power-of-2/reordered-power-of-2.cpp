class Solution {
private:
    vector<int> freqValue(int n ){
        vector<int> freq(10,0);
        while(n>0){
            freq[n%10]++;
            n /= 10;
        }
        return freq;
    }
    bool checkPower(const vector<int> &a,const  vector<int> &b){
        for(int i = 0;i<a.size();i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool reorderedPowerOf2(int n) {
        //frequency of digits
        vector<int> target = freqValue(n);
        //matching with 2^i
        for(int i = 0;i<=30;i++){
            int powerValue = (int)pow(2,i);
            if(checkPower(target,freqValue(powerValue))){
                return true;
            }
        }
        return false;
    }
};