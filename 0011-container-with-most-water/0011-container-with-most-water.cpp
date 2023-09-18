class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = height.size() - 1;
        int maxi = 0;
        while(left < right){
            int h = min(height[left], height[right]);
            maxi = max(maxi, (right - left) * h);

            while(height[left] <= h && left < right) left++;
            while(height[right] <= h && left < right) right--;
        }

        return maxi;
    }
};