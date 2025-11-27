#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> c(n + 1, vector<int>(n + 2));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cin >> c[i][j];
        }
    }

    vector<vector<int>> sol(n + 1, vector<int>(n + 2));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cin >> sol[i][j];
        }
    }

    vector<int> msc;
    int i = 0;
    int j = 1;

    while (j <= n)
    {
        if (sol[i][j] == 1)
        {
            msc.push_back(a[j]);
            i = j;
            j++;
        }
        else
        {
            j++;
        }
    }

    for (size_t k = 0; k < msc.size(); k++)
    {
        if (k > 0)
            cout << " ";
        cout << msc[k];
    }
    cout << endl;

    return 0;
}
