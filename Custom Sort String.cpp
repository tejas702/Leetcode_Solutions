class Solution {
public:
    string customSortString(string order, string str) {
        unordered_map<char,int> mp;
        string s = "";
        for(auto ch : str){
            mp[ch]++;
        }
        for(auto ch : order){
            if(mp.find(ch)!=mp.end()){
                auto it = mp.find(ch);
                while(it->second>0){
                    s += it->first;
                    it->second -= 1;
                }
                mp.erase(it);
            }
        }
        for(auto& it : mp){
            while(it.second > 0){
                s += it.first;
                it.second--;
            }
        }
        return s;
    }
};