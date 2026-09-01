class Solution {
public:
    int minMoves(vector<string>& g, int en) {
        int m=g.size(),n=g[0].size(),cnt=0,sr=0,sc=0;
        vector<vector<int>> id(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]=='S'){ sr=i; sc=j; }
                if(g[i][j]=='L'){ id[i][j]=cnt; cnt++; }
            }
        }
        int full=(1<<cnt)-1;
        if(full==0) return 0;
        vector<vector<vector<int>>> best(m,vector<vector<int>>(n,vector<int>(1<<cnt,-1)));
        vector<int> dr{-1,1,0,0},dc{0,0,-1,1};
        queue<vector<int>> q;
        best[sr][sc][0]=en;
        q.push({sr,sc,0,en});
        int mv=0;
        while(!q.empty()){
            int sz=q.size();
            for(int t=0;t<sz;t++){
                vector<int> c=q.front(); q.pop();
                int r=c[0],cl=c[1],mask=c[2],e=c[3];
                for(int d=0;d<4;d++){
                    int nr=r+dr[d],nc=cl+dc[d];
                    if(nr<0||nr>=m||nc<0||nc>=n) continue;
                    if(g[nr][nc]=='X') continue;
                    int ne=e-1;
                    if(ne<0) continue;
                    int nm=mask;
                    if(id[nr][nc]>=0) nm|=(1<<id[nr][nc]);
                    if(g[nr][nc]=='R') ne=en;
                    if(nm==full) return mv+1;
                    if(best[nr][nc][nm]>=ne) continue;
                    best[nr][nc][nm]=ne;
                    q.push({nr,nc,nm,ne});
                }
            }
            mv++;
        }
        return -1;
    }
};