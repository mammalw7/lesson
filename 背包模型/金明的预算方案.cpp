#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define v first 
#define w second
using namespace std;
const int N = 70 , M = 32100;
typedef pair<int , int> PII;
int f[M];
PII master[N];
vector <PII> servant[N];
int m , n;

int main()
{
    cin >> m >> n;
    for(int i = 1 ; i <= n ;i ++ )
    {
        int v , w , q;
        cin >> v >> w >> q;
        if(!q)          master[i] = {v , v * w};
        else            servant[q].push_back({v , v * w});
    }
    
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(master[i].v)
        {
            for(int j = m ; j >= 0 ; j -- )
                for(int k = 0 ; k < 1 << servant[i].size() ; k ++ )
                {
                    int v = master[i].v , w = master[i].w;
                    for(int u = 0 ; u < servant[i].size() ; u ++ )
                    {
                        if(k >> u & 1)                  //结果为1，表示选择物品
                        {
                            v += servant[i][u].v;       
                            w += servant[i][u].w;
                        }
                    }
                    if(j >= v)      f[j] = max(f[j] , f[j - v] + w);
                }
        }
    }
    
    cout << f[m] << endl;
    return 0;
}