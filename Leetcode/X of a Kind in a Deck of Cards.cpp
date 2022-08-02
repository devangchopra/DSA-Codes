class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
       unordered_map<int, int> map;
        int ans = 0;
        for (int a : deck) map[a]++;
        for (auto a : map) ans = __gcd(a.second, ans);
        return ans >= 2;
    }
};



//We are dividing a deck of cards into groups of equal size and 
//the maximum size of the group can be found by taking the GCD 
//of all frequencies of all cards.

//For example:
//If the GCD of all frequencies is 4 
//then this tells that we can partition the array into groups of size = 4.


//My main approach was to look for the greatest common divisor (GCD) 
//for all the value counts. 
//If the gcd >= 2, then the conditions are met, 
//and you can equally separate all deck values into groups of X = gcd length.

//gcd(3,7)=1
//different = 1



//class ke andr you can use #define