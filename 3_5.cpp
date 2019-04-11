#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <malloc.h>
#define maxn 100005
#define LOCAL
char s[maxn];
char buf[maxn];
const char* operation =    "A  B C D E F G H I J K  L M N O P Q  R S T U V W X Y Z";
const int operation_x[] = {-1,+1,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0};
const int operation_y[] = { 0, 0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,+1,0,0,0,0,0,0,0,0};
const int height = 5;
const int width = 5;
int exchange(char (*grid)[width], int* location, int x, int y){
    if(x+y == 0){
        return false;}
    int temp_x = location[0] + x;
    int temp_y = location[1] + y; 
    /*
    printf("x:%d\n",x);
    printf("y:%d\n",y);
    printf("temp_x:%d\n",temp_x);
    printf("temp_y:%d\n",temp_y);
    
    for(int i = 0;i < height;i++){
      	for(int j = 0; j < width; j++)
               	printf("%c ",grid[i][j]);
         printf("\n");        
    }
    printf("##########\n");
    */
    if(temp_x < 0 || temp_x >= height || temp_y < 0 || temp_y >= width){
        return false;
    }
    char temp = grid[temp_x][temp_y];
    grid[temp_x][temp_y] = grid[location[0]][location[1]];
    grid[location[0]][location[1]] = temp; 
    location[0]=temp_x;
    location[1]=temp_y;
    return true;
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    int location[2]={-1,-1};
    int kase = 1;
    char grid[height][width];    
    while(1){
        memset(grid,'0',sizeof(grid));
        char temp;
        //printf("#####buf read#######\n");
        for(int i = 0; i < height; i++){
            scanf("%[^\n]\n",buf);
            //printf("%s\n",buf);
            if(buf[0]=='Z' && int(strlen(buf)) == 1)goto end;
            for(int j = 0; j < width; j++){
                grid[i][j] = buf[j];
                if(grid[i][j] == ' '){
                    location[0] = i;
                    location[1] = j;
                }
            }
        }
        //printf("############\n");
        if(kase == 1)
            printf("Puzzle #%d:\n",kase++);
        else
            printf("\nPuzzle #%d:\n",kase++);

        /*printf("######grdi review######\n");
        for(int i = 0;i < height;i++){
                for(int j = 0; j < width; j++)
                    printf("%c ",grid[i][j]);
                 printf("\n");        
            }
        printf("############\n");
        */
        char q;
        bool prin = true;
        while(1){
            scanf("%c",&q);
            if(q == '\n') continue;
            //printf("q:%c\n", q);
            if(q == '0'){
                getchar();
                break;
            }
            if(!exchange(grid,location,operation_x[q-'A'],operation_y[q-'A'])){
                if(prin){
                    printf("This puzzle has no final configuration.\n");
                    prin = false;}
                continue;
            }
        }
        if(prin){
    	    for(int i = 0;i < height;i++){
                for(int j = 0; j < width; j++){
                    if(j == 0)    
                        printf("%c",grid[i][j]);
                    else
                        printf(" %c",grid[i][j]);
                }
               	 printf("\n");        
            }
        }
    }

end:
    return 0;
}
