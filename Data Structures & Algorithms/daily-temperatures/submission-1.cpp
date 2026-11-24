class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret (temperatures.size(),0);
        stack<int> stc; 
        for(int i = 0; i < temperatures.size();i++){
            while(!stc.empty() && temperatures[stc.top()] < temperatures[i]){
                ret[stc.top()] = i - stc.top();
                stc.pop();
            }
            stc.push(i);
        }
        return ret;
    }
};
