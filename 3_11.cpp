#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <stack> 
#include <queue> 
#include <utility> 
#include <vector> 
#include <cmath> 
#include <set> 
#include <map> 
#include <iostream> 
#include <algorithm> 
#include <sstream>
using namespace std;
#define maxn 1005
#define LOCAL
char a[maxn];
char b[maxn];
char temp[maxn];

int int_(char x){
    return x - '0';
}

int match(char* a,int step, int len1, int len2){
    for(int i = 0; i < min(step+1,len2);i ++){
        if(int_(a[len1-1-step+i])+int_(a[len1+i])>3)
            return false;
    }
    // printf("step is %d\n",step);
    // for(int i = 0; i < min(step+1,len2);i ++)
        // printf("%c", a[len1-1-step+i]);
    // printf("\n");
    // for(int i = 0; i < min(step+1,len2);i ++)
        // printf("%c", a[len1+i]);
    // printf("\n");
    return true;
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    while(~scanf("%s \n %s",a,b)){
        int len1 = strlen(a);
        int len2 = strlen(b);
        int min_contain = len1 + len2;
        int start1 = len1-1, end1 = len1-1;
        int start2 = 0, end2 = 0;
        //printf("a:%s len:%d\n",a,len1);
        //printf("b:%s len:%d\n",b,len2);
        strcpy(temp,a);
        strcat(a,b);
        strcat(b,temp);
        // printf("cat a:%s len:%d\n",a,int(strlen(a)));
        // printf("cat a process:\n");
        for(int i = 0; i < len1; i++){
            // printf("step:%d\n",i);
            if(match(a,i,len1,len2)){
               min_contain = min(min_contain,len1+len2-min(i+1,len2));
            }
        }
        // printf("cat b:%s len:%d\n",b,int(strlen(b)));
        // printf("cat b process:\n");
        for(int i = 0; i < len2; i++){
            // printf("step:%d\n",i);
            if(match(b,i,len2,len1))
               min_contain = min(min_contain,len1+len2-min(i+1,len1));
        }
        printf("%d\n",min_contain);
    }
    return 0;
}
