class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        if(high==0){
            return nums[high];
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(mid==0){
                return nums[mid];
            }
            if(mid==nums.size()-1){
                return nums[mid];
            }
            if((mid)%2==0){
                if(nums[mid]==nums[mid-1]){
                    high=mid-1;
                }else if(nums[mid]==nums[mid+1]){
                    low=mid+1;
                }else{
                    return nums[mid];
                }
            }else{
                if(nums[mid]==nums[mid-1]){
                    low=mid+1;
                }else if(nums[mid]==nums[mid+1]){
                    high=mid-1;
                }else{
                    return nums[mid];
                }
            }
        }
        return 0;
    }
};
