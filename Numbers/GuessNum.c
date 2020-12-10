/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 * Link - https://leetcode.com/problems/guess-number-higher-or-lower/
 */

int guessNumber(int n){
	int result, l, r, mid;
    l = 1;
    r = n;
    mid = l + (r-l)/2;
    
    result = guess(mid);
    
    while(result != 0)
    {
        if(result == -1)
        {
            r = mid - 1;
        }
        else if(result == 1)
        {
            l = mid + 1;
        }
        mid = l + (r - l)/2;
        result = guess(mid);
    }
    return mid;
}
