class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return n;
        int res = 0;
        vector<int> pre(n,0);
        if(arr[1] > arr[0]){pre[1]=1;pre[0]=-1;}
        else if(arr[1] < arr[0]){pre[1]=-1;pre[0]=1;}
        for(int i = 2;i < n; i++){
            if(arr[i] > arr[i-1])pre[i] = 1;
            else if(arr[i] < arr[i-1])pre[i]=-1;
            else pre[i]=pre[i-1];
        }
        for(int i = 0;i < n;){
            int j = i+1;
            while(j < n){
                if(pre[j] == pre[j-1])break;
                j++;
            }
            int len = j-i;
            if(i > 0){
                if(pre[i]==pre[i-1] && arr[i]!=arr[i-1])len+=1;
            }
            if(j<=n-1){
                if(pre[j-1]!=pre[j])len+=1;
            }
            res = max(res,len);
            if(j>i) i=j;
            else i+=1;
        }
        return res;
    }
};