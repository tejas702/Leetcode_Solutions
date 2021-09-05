/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ar array
#define ld long double

// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

// Comparator function by key for MAP
struct cmpmap {
    bool operator()(const string& a, const string& b) const {
        return a.length() < b.length();
    }
};

// Comparator function for PRIORITY QUEUE
struct cmppq {
    bool operator()(const string& p1, const string& p2){
        return p1.length() < p2.length();
    }
};

const int mod= (int)1e9 + 7;
const int mxN = 200005;
const int INF = INT_MAX;
#define pb push_back
#define forn(i,j,n) for(int (i)=(j);(i) >= (n); (i)--)
#define forr(i,j,n) for(int (i)=(j);(i) < (n); (i)++)
#define sz(x) ((int)(x).size())
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef map<int, int> mp;
typedef unordered_map<int,int> ump;
#define all(v) v.begin(), v.end() 
#define alla(arr, sz) arr, arr + sz 
#define sort(v) sort(all(v))
#define sorta(arr, sz) sort(alla(arr, sz))  

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(char c : s){
            if( c == '(' || c=='{' || c=='['){
                st.push(c);
            }else if(st.top() == '(' && c==')'){
                st.pop();
            }else if(st.top() == '[' && c==']'){
                st.pop();
            }else if(st.top() == '{' && c=='}'){
                st.pop();
            }
        }
        return (sz(st) == 0);
    }
};
// @lc code=end

