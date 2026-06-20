class Solution {

private:
    bool canEatAll(vector<int>& piles, int h, int speed) {
        long long hoursSpent = 0;
        for (int pile : piles) {
            hoursSpent += (pile + speed - 1) / speed; 
            if (hoursSpent > h) return false; 
        }
        return hoursSpent <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = *max_element(piles.begin(), piles.end()); 
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canEatAll(piles, h, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return result;
    }

};
