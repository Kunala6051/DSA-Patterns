#include <iostream>
#include <vector>
using namespace std;

double findPow(double x, int n){
    long binForm = n; // just to remember we are imagining binary form of n
    double ans = 1;

    // suppose n is 5 (101) and x=3, we are calculating 3^5 = 1(3^4) * 0(3^2) * 1(3^1)

    // we could simply run a loop and calculate x^n [whose time complexity would be 0(n)] (linear)
    // But the constraint in leet code challenge is that the power can be in the range [ 2^-31 - 2^31 ]
    // According to time complexity chapter the TC can be max 10^8 which is much smaller than the given range
    // so the erroe TIME LIMIT EXCEEDED will be shown in greater values of n.

    // Here we have more optimised method of solving this problem [TIME COMPLEXITY: 0(logn)]
    // Because binary value of n can have (logn + 1) digits so loop will run (logn + 1) no. of times

    // more constraints juss for logic 
    if (n==0) return 1.0;
    if (n==1) return x;
    if (x==0) return 0.0;
    if (x==1) return 1.0;
    if (x==-1 && n%2==0) return 1.0;
    if (x==-1 && n%2==0) return -1.0;

    if (binForm < 0){  // if negative power
        x = 1/x;
        binForm = -binForm;
    }
    while(binForm >0){
        if(binForm%2==1){ 
            ans *= x;
        }   

        x*=x; // x^2
        binForm /= 2;    
    }

    return ans;
}

int maxProfit(int arr[], int sz){    // MY TRIAL (but few test cases pending in leet code)

    // It is a method to find the maximum profit if a stock is to be bought on one day and sell on another.

    int bestBuy = arr[0];
    int sell=0;
    int maxProfit;
    

    for(int i=1; i<sz; i++){ // started from second index because stock can't be sell on the first day, it has to be bought first.

        if(bestBuy<arr[i]){ // Obviously if selling price is greater than buying price
            sell = max(sell,arr[i]); // finding the maximum selling price 
        }

        maxProfit = sell - bestBuy;

        // changing the bestBuy to check every possible combination
        
        bestBuy=min(bestBuy, arr[i]);
        
    }

    
    if(maxProfit<=0){ // incase of a always decreasing trend eg [90,70,40,10]
        return 0; // Avoiding negative answer
    }
    return maxProfit;
}

int maxProfitSharadha(int prices[], int sz){

    int maxProfit = 0, bestBuy = prices[0];

    for (int i=1; i<sz; i++) {
        if (bestBuy < prices[i]) {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
    
    bestBuy = min(bestBuy, prices[i]);
    
    }
    

    return maxProfit;
}


int maxWaterBrute(int arr[], int sz){
    int maxWater=0;

    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            int width = j - i;
            int h = min(arr[i] , arr[j]);
            int area = width * h;

            maxWater = max(maxWater, area);
        }
    }

    return maxWater;

// constraint => n <= 10^5
// Time complexity => O(n^2)
// In the worst case scenario no. of operations would be (10^5)^2 = 10^10 but max operations = 10^8 
// SO THERE WILL BE AN ERROR OF TIMIT LIMIT EXCEEDED

}

int twoPointerApproachWater(int arr[], int sz){  //time complexity => O(n)
    int leftPointer = 0;
    int rightPointer = sz-1;
    int maxWater = 0;
    
    while(leftPointer < rightPointer){
        int width = rightPointer - leftPointer;
        int height = min (arr[leftPointer], arr[rightPointer]);
        int crntArea = width * height;

        maxWater = max(maxWater, crntArea);

        if (arr[leftPointer] < arr[rightPointer]){
            leftPointer++;
        } else  {
            rightPointer--;
        }

    }

    return maxWater;
}





vector <int> productBrute(vector<int>& num){        // Time Complexity => O(n^2)
    int n=num.size();
    vector <int> ans(n,1);   // (size,element)  output => [1,1,1,1,_ _ _ upto n]
    for(int i=0; i<n; i++){
        int product=1;
        for(int j=0; j<n; j++){
            if(j!=i){
                product*=num[j];
            }
        }
        ans[i] = product;
    }

    return ans;
}

// NEW APPROACH [TC -> O(n) and Space Complexity - O(n)]
vector <int> OptimisedProduct(vector<int>& num){
    int n=num.size();
    vector <int> ans(n,1);
    vector <int> prefix(n,1);
    vector <int> suffix(n,1);

    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] * num[i-1];
    }

    for(int i=n-2; i>=0; i--){
        suffix[i] = suffix[i+1] * num[i+1];
    }
    
    
    for(int i=0; i<n; i++){
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
}

// MORE OPTIMISED APPROACH [TC -> O(n) and Space Complexity - O(n) (resultatnt vector not included in it)]

// DRY RUN for better understanding

vector <int> MoreOptimisedProduct(vector<int>& num){
    int n=num.size();
    vector <int> ans(n,1);

    // adding prefix directly to ans
    for(int i=1; i<n; i++){
        ans[i] = ans[i-1] * num[i-1];
    }

    int suffix=1; 
    for(int i=n-2; i>=0; i--){
        suffix *= num[i+1];
        ans[i] *= suffix;
    }
    
    return ans;
}


int main() {
    cout << findPow(2,1) << endl;

    int arr2[] = {2,4,1};
    cout << maxProfit(arr2, 3) << endl;


    int arr1[] = {2,1,2,0,1};
    cout << maxProfitSharadha(arr1, 5) << endl;

    int arr3[] = {1,8,6,2,5,4,8,3,7};
    cout << maxWaterBrute(arr3, 9) << endl;

    int arr4[] = {8,7,2,1};
    cout << twoPointerApproachWater(arr3, 9) << endl;
    cout << twoPointerApproachWater(arr4, 4) << endl;

    vector <int> vec1 = {3, 4, -1, 2, 5};
    vector <int> result = productBrute(vec1);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;

    vector <int> result2 = OptimisedProduct(vec1);
    for(int i : result2){
        cout << i << " ";
    }
    cout << endl;

    vector <int> result3 = MoreOptimisedProduct(vec1);
    for(int i : result3){
        cout << i << " ";
    }
    cout << endl;



    return 0;
}