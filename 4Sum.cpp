class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n=a.size();
        unordered_map<int,vector<array<int,2>>> mp;
        map<vector<int>,int> mp2;
        vector<vector<int>> vc;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp.find(target-a[i]-a[j])!=mp.end()){
                    vector<array<int,2>> p = mp[target-a[i]-a[j]];
                    for(array<int,2> p2 : p){
                        vector<int> tb = {a[i],a[j],a[p2[0]],a[p2[1]]};
                        sort(tb.begin(),tb.end());
                        if(mp2.find(tb)==mp2.end()) {vc.push_back(tb);mp2[tb]++;}
                    }
                }
            }
            for(int j=0;j<i;j++){
                mp[a[i]+a[j]].push_back({i,j});
            }
        }
        return vc;
    }
};