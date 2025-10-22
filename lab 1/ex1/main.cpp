#include <iostream>
#include <string>

using namespace std;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void sortString(string &str)
{
    int n = str.length();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                swap(str[j], str[j + 1]);
            }
        }
    }
}

void reverse(string &str, int start, int end)
{
    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

bool nextPermutation(string &str)
{
    int n = str.length();

    int i = n - 2;
    while (i >= 0 && str[i] >= str[i + 1])
    {
        i--;
    }

    if (i < 0)
    {
        return false;
    }

    int j = n - 1;
    while (str[j] <= str[i])
    {
        j--;
    }

    swap(str[i], str[j]);

    reverse(str, i + 1, n - 1);

    return true;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        sortString(str);

        cout << str << endl;

        while (nextPermutation(str))
        {
            cout << str << endl;
        }

        cout << endl;
    }

    return 0;
}
