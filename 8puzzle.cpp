// Link : [https://binarysearch.com/problems/8-Puzzle]

#define pb push_back
int solve(vector<vector<int>>&board) {

    string b="";
    for(int i=0;i<3;++i) for(int j=0;j<3;++j) b+=(board[i][j]+'0');
    
    string ans="012345678";
    vector<int>vx={3,-3,1,-1};
    
    unordered_map<string,int>mp;
    queue<string>q;
    q.push(b);
    mp[b]=0;
    
    while(q.size())
    {
        string cr=q.front();
        q.pop();
        int lev=mp[cr];
        
        if(cr==ans) {
            return lev;
        }
        
        
        int pos=0;
        for(int i=0;i<9;++i) {
            if(cr[i]=='0') {
                pos=i; break;
            }
        }
        
        int low = (pos/3)*3;
        int high = ((pos/3)+1)*3;
        
        for(auto it : vx)
        {
            if((abs(it)==1 && pos+it>=low && pos+it<high) || (abs(it)==3 && pos+it>=0 && pos+it<9) )
            {
                int pos1=pos+it;
                swap(cr[pos], cr[pos1]);
                if(mp.find(cr)==mp.end()) {
                    q.push(cr); mp[cr]=lev+1;
                }
                else {
                    if(mp[cr]>lev+1) { q.push(cr); mp[cr]=lev+1; }
                }
                swap(cr[pos], cr[pos1]);
            }
        }
    }
    
    return -1;

}

