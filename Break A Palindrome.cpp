class Solution {
public:
    string breakPalindrome(string p) {
        int n = p.size();
        if(n==1)return "";
        bool done = 0;
        for(int i = 0;i < n; i++){
            if(p[i]!='a'){
                for(char c = 'a'; c <= 'z'; c++){
                    if(c == p[i])continue;
                    if(p[n-i-1]==c || n-i-1==i)continue;
                    p[i]=c;
                    done=1;
                    break;
                }
                if(done) break;
            }
        }
        if(done) return p;
        for(int i = n-1;i >= 0; i--){
            if(p[i]=='a'){
                for(char c = 'b'; c <= 'z'; c++){
                    if(p[n-i-1]==c || n-i-1==i)continue;
                    p[i]=c;
                    done=1;
                    break;
                }
                if(done) break;
            }
        }
        return p;
    }
};