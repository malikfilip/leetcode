class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret (temperatures.size(),0);
        stack<pair<int,int>> stc; //stek koji cuva par (temp,index)
        for(int i = 0; i < temperatures.size();i++){
            while(!stc.empty() && stc.top().first < temperatures[i]){
                ret[stc.top().second] = i - stc.top().second;
                stc.pop();
            }
            stc.push({temperatures[i],i});
        }
        return ret;
    }
};
