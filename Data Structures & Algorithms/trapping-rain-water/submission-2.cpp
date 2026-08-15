class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1;
        int res=0;
        int leftmax=height[l];
        int rightmax=height[r];
        while(l<r){
            if (leftmax<=rightmax){
                l+=1;
                leftmax=max(leftmax,height[l]);
                res+=leftmax-height[l];
            }else{
                r-=1;
                rightmax=max(rightmax,height[r]);
                res+=rightmax-height[r];

            }
        }
        return res;
    }
};
