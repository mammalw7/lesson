#include <iostream>
using namespace std;
const int N = 20010;
int f[N];
int V;
int n;
int main()
{
    cin >> V;
    cin >> n;
    for(int i = 0 ; i < n ; i ++ )
    {
        int v;
        cin >> v;
        for(int j = V ; j >= v ; j -- )
            f[j] = max(f[j] , f[j - v] + v);
    }
    cout << V - f[V] << endl;
    return 0;
}