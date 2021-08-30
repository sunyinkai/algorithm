//http://codeforces.com/contest/1562/problem/C
#include<cstdio>
const int MAXN=2e4+7;
char s[MAXN];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int N;scanf("%d",&N);
        scanf("%s",s);
        bool isok=false;
        int cnt0=0;
        for(int i=0;i<N;i++){
            if(s[i]=='0'){
                if(N%2==1 && N/2==i){
                    cnt0++;
                }else{
                    isok=true;
                    if(i<N/2){
                        printf("%d %d %d %d\n",i+1,N,i+2,N);
                    }else{
                        printf("%d %d %d %d\n",1,i+1,1,i);
                    }
                    break;
                }
            }
        }
        if(!isok){
            if(cnt0==1){
                printf("%d %d %d %d\n",1,N/2+1,N/2+1,N);
            }else{
                printf("%d %d %d %d\n",1,N-1,2,N);
            }
        }
    }
    return 0;
}