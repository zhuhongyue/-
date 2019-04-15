#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <malloc.h>
#define maxn 1000005
#define LOCAL
char buf1[maxn];
char buf2[maxn];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    while(~scanf("%s %s\n",buf1,buf2)){
        int len1 = strlen(buf1);
        int len2 = strlen(buf2);
        int count = 0;
        for(int i = 0; i < len1; i++){
            for(int j = count; j < len2; j++){
                count ++;
                if(buf1[i] == buf2[j]){
                    break;
                }
                if(j == len2 - 1){
                    count = -1;
                    break;
                }        
            }
            if(count == -1){
                printf("No\n");
                break;
            }
        }
        if(count > 0)
            printf("Yes\n");
    }
    return 0;
}
