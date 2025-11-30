#include <iostream>
#include <cstring>

using namespace std;

int n, m, r, c;
int alvo[105][105];
int atual[105][105];
int flip[105][105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> m >> r >> c)
    {
        if (n == 0 && m == 0 && r == 0 && c == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            string linha;
            cin >> linha;
            for (int j = 0; j < m; j++)
            {
                alvo[i][j] = linha[j] - '0';
            }
        }

        memset(atual, 0, sizeof(atual));
        memset(flip, 0, sizeof(flip));

        int operacoes = 0;
        bool possivel = true;

        for (int i = 0; i < n && possivel; i++)
        {
            for (int j = 0; j < m && possivel; j++)
            {
                if (i > 0)
                    atual[i][j] += atual[i - 1][j];
                if (j > 0)
                    atual[i][j] += atual[i][j - 1];
                if (i > 0 && j > 0)
                    atual[i][j] -= atual[i - 1][j - 1];
                atual[i][j] += flip[i][j];

                int corAtual = atual[i][j] % 2;
                if (corAtual < 0)
                    corAtual += 2;

                if (corAtual != alvo[i][j])
                {
                    if (i + r > n || j + c > m)
                    {
                        possivel = false;
                    }
                    else
                    {
                        flip[i][j]++;
                        if (i + r < n)
                            flip[i + r][j]--;
                        if (j + c < m)
                            flip[i][j + c]--;
                        if (i + r < n && j + c < m)
                            flip[i + r][j + c]++;

                        atual[i][j]++;
                        operacoes++;
                    }
                }
            }
        }

        if (possivel)
        {
            cout << operacoes << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}
