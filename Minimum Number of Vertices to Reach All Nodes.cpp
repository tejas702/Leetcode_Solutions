class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        for(vector<int>& f : edges){
            mp[f[1]]++;
        }
        vector<int> vc;
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end())vc.push_back(i);
        }
        return vc;
    }
};