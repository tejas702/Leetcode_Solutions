class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        num1 = " "+num1 + " ";
        num2 = " "+num2 + " ";
        for(char& c : num1){
            if(c=='+')c=' ';
            if(c=='i')c=' ';
        }
        for(char& c : num2){
            if(c=='+')c=' ';
            if(c=='i')c=' ';
        }
        int a,n=(int)num1.size();
        int b[4];int ct=0;
        for(int i = 0;i < n;){
            int j = i;
            if(num1[i]==' '){
                j+=1;
                a=0;
                bool d=0,m=0;
                while(j<n&&num1[j]!=' '){
                    if(num1[j]=='-'){
                        m=1;j++;
                        continue;
                    }
                    a*=10;
                    if(m==0)a += (num1[j]-'0');
                    else a-=(num1[j]-'0');
                    j++;d=1;
                }
                if(d==1) b[ct++]=a;
            }
            i=j;
        }
        n = (int)num2.size();
        for(int i = 0;i < n;){
            int j = i;
            if(num2[i]==' '){
                j+=1;
                a=0;
                bool d=0,m=0;
                while(j<n&&num2[j]!=' '){
                    if(num2[j]=='-'){
                        m=1;j++;
                        continue;
                    }
                    a*=10;
                    if(m==0)a += (num2[j]-'0');
                    else a-=(num2[j]-'0');
                    j++;d=1;
                }
                if(d==1) b[ct++]=a;
            }
            i=j;
        }
        cout << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << "\n";
        int con = b[0]*b[2];
        con += (-1)*(b[1]*b[3]);
        int ayeaye = b[0]*b[3] + b[2]*b[1];
        string ff = "";
        ff += to_string(con);
        ff+="+";
        ff += to_string(ayeaye);
        ff+="i";
        return ff;
    }
};