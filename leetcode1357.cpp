
// problem: "https://leetcode.com/problems/apply-discount-every-n-orders/"

class Cashier {
public:
    
    int numCustomers, numCusDiscount, numProducts, discountPercentage;
    unordered_map<int, int>prodPrice;
    
    
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        numCustomers = 1;
        numCusDiscount = n;
        numProducts = products.size();
        discountPercentage = discount;
        
        int i;
        for(i=0;i!=numProducts;i++) {
            prodPrice[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double price = 0.0;
        int i;
        for(i=0;i!=product.size();i++) {
            price += prodPrice[product[i]] * amount[i];
        }
        
        if(numCustomers % numCusDiscount) {
            numCustomers++;
            return price;
        }
        
        numCustomers++;
        return price - price * discountPercentage / 100.0;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
