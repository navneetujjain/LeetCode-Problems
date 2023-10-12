/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findpeak(int low, int high, MountainArray &mountainArr){
        while(low != high){
            int mid = low + (high - low) / 2;

            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) low = mid + 1;
            else high = mid;
        }

        return low;
    }

    int bs(int low, int high, int target, MountainArray &mountainArr, int check){
        while(low != high){
            int mid = low + (high - low) / 2;
            if(check == 1){
                if(mountainArr.get(mid) > target) low = mid + 1;
                else high = mid;
            }
            else{
                if(mountainArr.get(mid) >= target) high = mid;
                else low = mid + 1;
            }
        }
        return low;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int peak = findpeak(1, n - 2, mountainArr);

        int inc_part = bs(0, peak, target, mountainArr, 0);

        if(mountainArr.get(inc_part) == target) return inc_part;

        int dec_part = bs(peak + 1, n - 1, target, mountainArr, 1);

        if(mountainArr.get(dec_part) == target) return dec_part;

        return -1;
    }
};