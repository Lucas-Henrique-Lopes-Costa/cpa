#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    a[0] = INT32_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int m = n;

    vector<vector<int>> c(n + 1, vector<int>(m + 2, 0));

    vector<vector<int>> sol(n + 1, vector<int>(m + 2, 0));

    for (int i = 0; i <= n; i++)
    {
        c[i][m + 1] = 0;
    }

    for (int j = m; j >= 1; j--)
    {
        for (int i = 0; i <= j - 1; i++)
        {
            if (a[i] >= a[j])
            {
                c[i][j] = c[i][j + 1];
                sol[i][j] = 0;
            }
            else
            {
                int nao_adiciona = c[i][j + 1];
                int adiciona = 1 + c[j][j + 1];

                if (adiciona > nao_adiciona)
                {
                    c[i][j] = adiciona;
                    sol[i][j] = 1;
                }
                else
                {
                    c[i][j] = nao_adiciona;
                    sol[i][j] = 0;
                }
            }
        }
    }

    cout << n << endl;

    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            cout << " ";
        cout << a[i];
    }
    cout << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            if (j > 1)
                cout << " ";
            cout << c[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            if (j > 1)
                cout << " ";
            cout << sol[i][j];
        }
        cout << endl;
    }

    return 0;
}
