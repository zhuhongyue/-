#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <malloc.h>
#define maxn 105
#define LOCAL
char s[maxn];
char buf[maxn];
char grid[maxn][maxn];
int grid_index[maxn][maxn];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    int height, width;
    int kase = 1;
    while(scanf("%d ",&height) && height != 0){
        scanf("%d\n",&width);
        memset(grid_index,0,sizeof(grid_index));
        memset(grid,'0',sizeof(grid));
        for(int i = 0; i < height; i++){
            scanf("%s",buf);
            for(int j = 0; j < width; j++)
                grid[i][j] = buf[j];
        }
        int index = 1;
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                if(grid[i][j] == '*'){
                    grid_index[i][j] = -1;
                    continue;
                }
                if( i-1<0 ){
                    grid_index[i][j] = index++;
                }
                else if(j - 1 < 0){
                    grid_index[i][j] = index++;
                }
                else if(grid[i - 1][j] == '*'){
                    grid_index[i][j] = index++;
                }
                else if(grid[i][j - 1] == '*'){
                    grid_index[i][j] = index++;
                }
            }
        }
        /*   
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                printf("%3d ",grid_index[i][j]);
                }
            printf("\n");
        }
        printf("######################################\n");
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                printf("%3c ",grid[i][j]);
            }
            printf("\n");
        }
        printf("######################################\n");
        */
        if(kase == 1)
            printf("puzzle #%d:\n",kase++);
        else
            printf("\npuzzle #%d:\n",kase++);
        printf("Across");
        for(int i = 0; i < height; ++i){
            int count = 0;
            for (int j = 0; j < width; ++j){
                if(grid_index[i][j] >= 0){
                    if(count++ == 0)
                        printf("\n%3d.",grid_index[i][j]);
                    printf("%c",grid[i][j]);
                }
                else count =0;
            }

        }
        printf("\nDown");
        for(int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                if(grid_index[i][j] > 0){
                    int count = 0;
                    for(int k = i; k < height; ++k){
                        if(grid_index[k][j] >= 0){
                            if(count++ == 0)
                                printf("\n%3d.",grid_index[k][j]);
                            grid_index[k][j] = -1;
                            printf("%c",grid[k][j]);
                        }
                        else break;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
