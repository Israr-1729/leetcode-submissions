class Bank {
public:
    unordered_map<int, long long> accToBalance;
    int till;


    Bank(vector<long long>& balance) {

        for(int i = 0; i<balance.size(); i++)
        {
            accToBalance[i+1] = balance[i];
        }
        till = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {

        if(account1 >= 1 && account2 >= 1 && account1 <= till && account2 <= till && accToBalance[account1] >= money)
        {
            accToBalance[account1] -= money;
            accToBalance[account2] += money;

            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account >= 1 && account <= till)
        {
            accToBalance[account] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account >= 1 && account <= till && accToBalance[account] >= money)
        {
            accToBalance[account] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */