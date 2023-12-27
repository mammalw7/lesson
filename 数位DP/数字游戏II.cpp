#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 11 , M = 110;
int f[N][10][M];
int p;

int mod(int a , int b)
{
    return (a % b + b) % b;
}

void init()
{
    memset(f , 0 , sizeof f);
    for(int i = 0 ; i <= 9 ; i ++ )             f[1][i][mod(i , p)] ++;
    
    for(int i = 2 ; i < N ; i ++ )
        for(int j = 0 ; j <= 9 ; j ++ )
            for(int k = 0 ; k <= p ; k ++ )
                for(int x = 0 ; x <= 9 ; x ++ )
                    f[i][j][k] += f[i - 1][x][mod(k - j , p)];
}

int dp(int n)
{
    if(!n)              return 1;
    vector<int> nums;
    while(n)            nums.push_back(n % 10) , n /= 10;
    int res = 0 , last = 0;
    for(int i = nums.size() - 1 ; i >= 0 ; i -- )
    {
        int x = nums[i];
        for(int j = 0 ; j < x ; j ++ )
            res += f[i + 1][j][mod(-last , p)];     // last + dp % p == 0 -> dp % p = -last
        
        last += x;
        if(!i && !mod(last , p))              res ++;
    }
    return res;
}

int main()
{
    int l , r;
    while(cin >> l >> r >> p)
    {
        init();
        cout << dp(r) - dp(l - 1) << endl;
    }
    return 0;
}