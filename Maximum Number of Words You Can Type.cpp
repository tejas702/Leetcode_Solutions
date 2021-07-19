class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        text += " ";
        int n=text.size();
        int words = 0,j=-1;
        for(int i=0;i<n;i++){
            if(text[i]==' '){
                string now = text.substr(j,i-j);bool f=0;
                for(char c2 : now){for(char c : brokenLetters){
                    if(c==c2){
                        f=1;break;
                    }
                }
                                  if(f==1)break;}
                if(f==0)words+=1;
                j=-1;
            }else if(j==-1){
                j=i;
            }
        }
        return words;
    }
};