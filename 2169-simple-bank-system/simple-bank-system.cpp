class Bank {
public:
    int n;
    vector<long long>B;

    Bank(vector<long long>& balance) {
        n = balance.size();
        B = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        //base case
        if(account1-1 > n || account2-1 > n)  return false;
        if(B[account1-1] < money) return false;
        //if valid balance
        B[account1-1] -= money;
        B[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        //base case
        if(account-1 > n) return false;
        //valid account
        B[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        //base case
        if(account-1 > n) return false;
        if(B[account-1] < money) return false;
        //valid balance
        B[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */