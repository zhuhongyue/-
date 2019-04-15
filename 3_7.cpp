#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <malloc.h>
#define maxn 2005
#define LOCAL
int count[maxn][maxn];
char buf[maxn];
char nearst[maxn];
const char* DNA = "ACGT";
const int DAN_class = 4;
int getItem(char x){
    int len = strlen(DNA);
    for(int i = 0; i < len; i ++){
        if(DNA[i] == x){
            return i;
        }
    }
    return 0;
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    int c;
    scanf("%d\n",&c);
    while(c--){
        int distance = 0;
        memset(count,0,sizeof(count));
        int m,n;
        scanf("%d %d",&m,&n);
        for(int i = 0; i < m; i ++){
            scanf("%s\n",buf);
            for(int j = 0; j < n; j++){
                count[getItem(buf[j])][j]+=1;
            }
        }
        for(int j = 0; j < n; j++){
            int max = 0;
            for(int i = 0; i < DAN_class; i++){
                if(count[i][j] > count[max][j])max = i; 
            }
            distance += (m - count[max][j]);
            nearst[j] = max;
        }
        for(int i = 0; i < n;i++)
            printf("%c",DNA[nearst[i]]);
        printf("\n%d\n",distance);
    }
    return 0;
}
