#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define maxn 100005
#define LOCAL
char s[maxn];
char buf[maxn];

int isCycle(const char*s,int cyc){
    int len = strlen(s); 
    if(len%cyc!=0)return false;
    for(int i = 0;i < len-cyc;i++){
        if(s[i]!=s[i+cyc])
            return false;
    }
    return true;
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s\n",s);
        int len = strlen(s);
        int cyc = len;    
        for(int i = len; i > 0;i-=1){
            if(isCycle(s,i)){
                cyc = i;
            }
        }
        if(T>0)
            printf("%d\n\n",cyc);
        else
            printf("%d\n",cyc);
    }
    return 0;
}
