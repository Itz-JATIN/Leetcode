class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        for(int val : nums){
            if(val == target){
                return i;
            }
            i++;
        }
        return -1;
    }
};