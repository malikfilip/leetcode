class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());

        while(left < right){
            int mid = (left + right) / 2;
            int time = 0;
            for(int pile:piles){
                time+= ceil(1.0*pile/mid); //jebeno celobrojno deljenje fak of
            }
            if (time > h){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return right;
    }
};
