class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        int n=bills.size();
        for (int i=0;i<n;i++){
        if (bills[i]==5){
            five+=1;
        }
        else if (bills[i]==10){
            five-=1;
            ten+=1;
        }
        else if(ten>0){
                ten-=1;
                five-=1;
            }
        else{
            five-=3;
        }

        
        if(five<0){
            return false;
        }
        
        
        }
        return true;
    }
};