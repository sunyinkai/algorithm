// http://codeforces.com/contest/1562/problem/B
#include<cstdio>
#include<cstring>
int ToInt(int a,int b,int c){
    int res=a;
    res=res*10+b;
    res=res*10+c;
    return res;
}
bool isPrime[2000];
void init(){
    for(int i=2;i<=1000;i++){
        int val=i;
        isPrime[i]=true;
        for(int j=2;j*j<=val;j++){
            if(val%j==0){
                isPrime[i]=false;
                break;
            }
        }
    }
}
int main(){
    int T;scanf("%d",&T);
    char s[100];
    int cnt[11];
    init();
    while(T--){
        int n;scanf("%d",&n);
        int len=n;
        scanf("%s",s);
       for(int i=1;i<=10;i++)cnt[i]=0;
        for(int i=0;i<n;i++){
            cnt[s[i]-'0']++;
        }
        bool isok=false;
        for(int i=1;i<=9;i++){
            if(i==1 || i==4 || i==6 || i==8 || i==9){
                if(cnt[i]!=0){
                    printf("%d\n%d\n",1,i);
                    isok=true;
                    break;
                }
            }
        }
        if(isok)continue;
        //else
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                int val=ToInt(0,s[i]-'0',s[j]-'0');
                if(!isPrime[val]){
                    printf("2\n%d\n",val);
                    isok=true;
                    break;
                }
            }
            if(isok)break;
        }
        if(isok)continue;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                for(int k=j+1;k<len;k++){
                    int val=ToInt(s[i]-'0',s[j]-'0',s[k]-'0');
                    if(!isPrime[val]){
                        printf("3\n%d\n",val);
                        isok=true;
                        break;
                    }
                }
                if(isok)break;
            }
            if(isok)break;
        }
    }
    return 0;
}