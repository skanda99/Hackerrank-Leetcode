
// problem: "https://leetcode.com/problems/guess-number-higher-or-lower/"

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

#define ll long long

class Solution {
public:
    int guessNumber(int n) {
        
        ll i = 1;
        ll j = n;
        ll m;
        while(i <= j)
        {
            m = (i+j)/2;
            
            if(guess(m) == 0)
                return m;
            else if(guess(m) == 1)
                i = m+1;
            else
                j = m-1;
        }
        
        return -1;
    }
};
