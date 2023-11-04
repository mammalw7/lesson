#include <iostream>
using namespace std;
const int N = 15;
int w[N][N];
int n;
int f[2 * N][N][N];           //第一维表示两条路径横纵坐标之和，第二、三维分别表示1、2条路径的横坐标
int main()
{
    cin >> n;
    int a , b , c;
    while (cin >> a >> b >> c , a || b || c)
        w[a][b] = c;
    
    //从(1 , 1) (1 , 1) 到(i1 , j1) , (i2 , j2)的所有路径的集合，如果i1 + j1 = i2 + j2 ，坐标重合，只加上第一次的结果
    for (int k = 2 ; k <= n + n ; k ++ )
            for (int i1 = 1 ; i1 <= n ; i1 ++ )
                for(int i2 = 1 ; i2 <= n ; i2 ++ ) 
                {
                    int j1 = k - i1 , j2 = k - i2;
                    if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
                    {
                        int t = w[i1][j1];
                        if(i1 != i2)        t += w[i2][j2];
                        int &x = f[k][i1][i2];
                        x = max(x , f[k - 1][i1 - 1][i2] + t);  //上一步分别从上、左来
                        x = max(x , f[k - 1][i1 - 1][i2 - 1] + t);   //上一步分别从上、上来
                        x = max(x , f[k - 1][i1][i2 - 1] + t);   //上一步分别从左，上来
                        x = max(x , f[k - 1][i1][i2] + t);   //上一步分别从左，左来
                        
                    }
                }
    cout << f[n + n][n][n] << endl;
    return 0;
}
