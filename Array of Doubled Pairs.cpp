class Solution {
public:
    
    struct cmp{
        bool operator()(const int& a, const int& b) const {
            if (abs(a) == abs(b)) return a < b;
            else return abs(a) < abs(b);
        }
    };
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        multiset<int,cmp> m;
        for(auto i : arr)m.insert(i);
        while(m.size()){
            auto i = *m.begin();
            m.erase(m.begin());
            auto i2 = m.find(i*2);
            if(i2==m.end())return false;
            m.erase(i2);
        }
        return true;
    }
};