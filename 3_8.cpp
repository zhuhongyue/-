#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <malloc.h>
#define maxn 10005
#define LOCAL
int buf[maxn];
int remain[maxn];
int remain_count[maxn];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    int m, n; 
    int period = 1000;
    while(~scanf("%d %d\n",&m,&n)){
        memset(remain_count,-1,sizeof(remain_count));
        memset(remain,-1,sizeof(remain));
        int start = 0;
        printf("%d/%d = ",m,n);
        for(int i = 0; i < maxn- 1; i ++){
            buf[i] = m/n;
            m = m%n;
            if(remain[m] == -1){
                remain[m] = 1;
                remain_count[m] = i;
            }else{
                period = i - remain_count[m];
                start = remain_count[m];
                break;
            }
            m = m * 10;
        }
        for (int i = 0; i < period + start + 1; ++i){
            if(i == start+1)printf("(%d",buf[i]);
            else printf("%d",buf[i]);
            if(i == 0)printf(".");
            if(i == 50)break;
        }
        if(period + start + 1 > 50)printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n",period);
    }
    return 0;
}
