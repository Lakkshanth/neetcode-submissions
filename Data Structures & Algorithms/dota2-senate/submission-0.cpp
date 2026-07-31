class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R'){
                r.push(i);
            }else{
                d.push(i);
            }
        }
        while(!d.empty() && !r.empty()){
            int rturn=r.front(); r.pop();
            int dturn=d.front(); d.pop();
            if(rturn<dturn){
                r.push(rturn+n);
            }
            else{
                d.push(dturn+n);
            }
        }
        return r.empty()? "Dire" : "Radiant";
    }
};