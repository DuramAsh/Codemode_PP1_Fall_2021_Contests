#include <iostream>
using namespace std;

int array[505][505], fsa[505][505], kip[505];
int INF = 1e8;
int main()
{
  int n, m, x, y, z;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> array[i][j];

  for (int k = 1; k <= n; ++k)
  {
    cin >> x;
    kip[x] = 1;
    int maxx = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        array[i][j] = min(array[i][j], array[i][x] + array[x][j]);

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
      {
        if (kip[i] && kip[j])
        {
          maxx = max(array[i][j], maxx);
        }
      }
    cout << maxx << endl;
  }
  return 0;
}