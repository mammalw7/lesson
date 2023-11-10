#include <iostream>
using namespace std;
const int N = 1010;
int f[N];
int T , M;

int main()
{
    cin >> T >> M;
    for(int i = 0 ; i < M ; i ++ )
    {
        int v , w;
        cin >> v >> w;
        for(int j = T ; j >= v ; j -- )         f[j] = max(f[j] , f[j - v] + w);
    }
    
    cout << f[T] << endl;
    return 0;
}