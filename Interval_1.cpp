#define pb push_back
class Solution {
public:
    
    vector<vector<int>> fun(vector<pair<int,int>>&v)
    {
        vector<vector<int>>ans;
        for(auto it : v)
        {
            vector<int>t;
            t.pb(it.first);
            t.pb(it.second);
            ans.pb(t);
        }
        
        return ans;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& inl) {
        
        sort(inl.begin(), inl.end());
        int l=inl[0][0],r=inl[0][1];
        
        vector<pair<int,int>>v;
        for(int i=1;i<inl.size();++i)
        {
            int x=inl[i][0],y=inl[i][1];
            if(y<=r)
            {
                continue;
            }
            
            if(x<=r)
            {
                r=y;
                continue;
            }
            
            v.pb({l,r});
            l=x;
            r=y;
        }
        v.pb({l,r});
        
        return fun(v);
        
    }
};



// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

