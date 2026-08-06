class Cashier {
public:

    int count = 0;
    unordered_map<int, int> price;
    int disc;
    int after;

    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {

        for(int i = 0; i<products.size(); i++)
        {
            price[products[i]] = prices[i];
        }

        disc = discount;
        after = n;
        
    }
    
    double getBill(vector<int> product, vector<int> amount) {

        double finalSum = 0;

        for(int i = 0; i<product.size(); i++)
        {
            finalSum += (price[product[i]] * amount[i]);
        }



        count++;
        if(count == after)
        {
            finalSum -= (double)(finalSum/100.0) * (double)(disc);
            count = 0;
        }

        return finalSum;
        
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */