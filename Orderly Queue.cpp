class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        if(k == 1){
            string res = s;
            for(int i = 0;i < n; i++){
                string curr = s.substr(i)+s.substr(0,i);
                res = min(res, curr);
            }
            return res;
        }else{
            sort(begin(s),end(s));
            return s;
        }
    }
};