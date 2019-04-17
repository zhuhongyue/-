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
#define maxn 1000005
#define LOCAL
int num;
map<int, int> mp;
int w, h;
int t[10][10];

bool Input(){
    num = 0;
    mp.clear();
    memset(t, 0, sizeof(t));
    for(int i=0; i<6; i++){
        if(scanf("%d%d", &w, &h) != 2) return false;
        if(mp.find(w) == mp.end()) mp[w] = num++;
        if(mp.find(h) == mp.end()) mp[h] = num++;
        t[mp[w]][mp[h]]++;
    }
    return true;
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    while(Input()){
        if(num==1 && t[0][0]==6){
            printf("POSSIBLE\n");
        }else if(   num==2 
                    && (t[0][0]==2 || t[1][1]==2) 
                    && t[0][1]+t[1][0]==4){
            printf("POSSIBLE\n");
        }else if(   num==3 
                    && t[0][1]+t[1][0]==2 
                    && t[0][2]+t[2][0]==2 
                    && t[1][2]+t[2][1]==2   ){
            printf("POSSIBLE\n");
        }else{
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
