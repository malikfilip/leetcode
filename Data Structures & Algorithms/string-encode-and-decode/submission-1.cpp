class Solution {
public:

    string encode(vector<string>& strs) {
        string ret;
        for(string curr: strs){//posto je duzina stringa od 0 do 199 mozemo koristiti 3 chara da kodiramo duzinu stringa, onda citamo toliko karaktera i tako u krug. lagana stella artois cuvena
            int numOfLetters = curr.size();
            string numString = "";
            if(numOfLetters < 10){
                numString = "00"+to_string(numOfLetters);
            }else if (numOfLetters < 100){
                numString = "0"+to_string(numOfLetters);
            }
            else{
                numString = to_string(numOfLetters);
            }
            ret+=numString;
            ret+=curr;
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int i = 0;
        while(i < s.size()){
            int numOfLetters = stoi(s.substr(i,3)); //uzmi broj
            ret.push_back(s.substr(i+3,numOfLetters));
            i+=3 + numOfLetters;
        }
        return ret;
        
    }
};
