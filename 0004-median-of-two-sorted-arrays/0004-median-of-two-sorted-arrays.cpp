class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
          if(nums1[i] <= nums2[j]){
            temp.push_back(nums1[i]);
            i++;
          }
          else if(nums2[j] < nums1[i]){
            temp.push_back(nums2[j]);
            j++;
          }
        }
        while(i < nums1.size()){
          temp.push_back(nums1[i]);
          i++;
        }
        while(j < nums2.size()){
          temp.push_back(nums2[j]);
          j++;
        }
        if(temp.size() % 2 == 0){
          int x = temp.size() / 2;
          int y = x - 1;
          float z = temp[x] + temp[y];
          return z/2;
        }
        int x = (temp.size() + 1)/2;
        x = x - 1;
        return temp[x];
        
    }
};