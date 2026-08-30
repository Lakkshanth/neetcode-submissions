class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxsofar=nums[0];
        int curmax=nums[0];
        int curmin=nums[0];
        for(int i=1;i<nums.size();i++){
            int num=nums[i];
            if(num<0){
                swap(curmax,curmin);
            }
            curmax=max(num,num*curmax);
            curmin=min(num,num*curmin);
            maxsofar=max(maxsofar,curmax);

        }
        return maxsofar;
    }
};
