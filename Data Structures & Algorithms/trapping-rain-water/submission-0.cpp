class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax (height.size());
        vector<int> rightMax(height.size());
        //Msm da je ovde ideja samo da gledamo pojedinacne kolone grida, ona ce u sebi imati maks vode koliko je minimum od
        //njenog desnog najveceg stuba i levog najveceg stuba, ukoliko u toj koloni ima neke zemlje ispod nas moramo i to da pazimo
        
        //Ove 0 kazuju samo da ne posmatramo to polje
        leftMax[0] = 0;
        rightMax[height.size()-1] = 0;
        for(int i = 1;i < height.size();i++){
            leftMax[i] = max(height[i-1],leftMax[i-1]);
            rightMax[height.size()-1-i] = max(height[height.size()-i],rightMax[height.size()-i]);
        }

        int wota = 0;
        for(int i = 0;i < height.size();i++){
            if(leftMax[i]==0 || rightMax[i] ==0)continue;
            int botaOfWota = min(leftMax[i],rightMax[i])-height[i]; //Voda u 1 stubu
            if(botaOfWota > 0)wota+=botaOfWota;
        }
        return wota;
    }
};
