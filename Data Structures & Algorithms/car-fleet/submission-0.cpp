class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> cars; //posto cemo sortirati position da a on je unique mozemo napraviti maput position->speed
        for(int i = 0; i < speed.size();i++){
            cars[position[i]] = speed[i];
        }

        sort(position.begin(),position.end(),greater<>()); // sortiramo opadajuce po pozicijama
        stack<double>stk;
        for(int pos:position){
            double myArrival = 1.0*(target-pos)/cars[pos];
            if(stk.empty() || myArrival>stk.top()){
                stk.push(myArrival);
            }
        }
        return stk.size();
    }
};
