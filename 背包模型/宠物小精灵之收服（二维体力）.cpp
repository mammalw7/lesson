#include <iostream>
using namespace std;
const int N = 1010 , M = 510;
int V1 , V2 , n;
int f[N][M];
int main()
{
    cin >> V1 >> V2 >> n;
    for(int i = 0 ; i < n ; i ++ )
    {
        int v1 , v2;
        cin >> v1 >> v2;
        for(int j = V1 ; j >= v1 ; j -- )
            for(int k = V2 - 1 ; k >= v2 ; k -- )      //体力值不能为0，最少为1
                f[j][k] = max(f[j][k] , f[j - v1][k - v2] + 1);
    }
    cout << f[V1][V2 - 1] << ' ';
    int k = V2 - 1;
    while(k > 0 && f[V1][k - 1] == f[V1][V2 - 1])        k --;
    cout << V2 - k ;
    return 0;
}