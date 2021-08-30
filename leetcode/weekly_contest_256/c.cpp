// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/
const int MAXN=1<<14;
const int SIZE=16;
const int INF= 1e9+7;
class Solution {
public:
    int dp[MAXN][SIZE];
    int a[SIZE],len;
    int session;
    int dfs(int nowState,int size){
        if(nowState==0){
            return 1;
        }
        
        if(dp[nowState][size]!=INF){
            return dp[nowState][size];
        }
        int res=INF;
        for(int i=0;i<len;i++){
            int cur=1<<i;
            if(cur&nowState){
                //yes
                if(a[i]>size){
                    res=min(res,dfs(nowState-cur,session-a[i])+1);
                }else{
                    res=min(res,dfs(nowState-cur,size-a[i]));
                }
            }
        }
        dp[nowState][size]=res;
        return res;
    }
    int minSessions(vector<int>& tasks, int t) {
        for(int i=0;i<MAXN;i++){
            for(int j=0;j<SIZE;j++){
                dp[i][j]=INF;
            }
        }
        session=t;
        len=tasks.size();
        for(int i=0;i<len;i++){
            a[i]=tasks[i];
        }
        return dfs((1<<len)-1,t);
    }
};
