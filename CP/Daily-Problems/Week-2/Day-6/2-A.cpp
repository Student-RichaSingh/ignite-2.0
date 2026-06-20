class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int cols = grid[0].size();
        
        for (auto row : grid) {
            int low = 0;
            int high = cols - 1;
            int firstNegativeIdx = cols; 
          
            while (low <= high) {
                int mid = low + (high - low) / 2;
                
                if (row[mid] < 0) {
                    firstNegativeIdx = mid; 
                    high = mid - 1;       
                } else {
                    low = mid + 1;       
                }
            }
            
            ans += (cols - firstNegativeIdx);
        }
        
        return ans;
    }
};
