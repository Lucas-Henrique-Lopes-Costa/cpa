#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    map<int, int> original_to_internal;
    vector<int> internal_to_original;

    vector<vector<int>> adj;
    int edges_count = 0;

    string line;
    while (getline(cin, line))
    {
        if (line.empty() || line[0] == '#')
            continue;

        stringstream ss(line);
        int u_orig, v_orig;
        if (ss >> u_orig >> v_orig)
        {
            if (u_orig == v_orig)
                continue;

            if (original_to_internal.find(u_orig) == original_to_internal.end())
            {
                original_to_internal[u_orig] = internal_to_original.size();
                internal_to_original.push_back(u_orig);
                adj.resize(internal_to_original.size());
            }
            if (original_to_internal.find(v_orig) == original_to_internal.end())
            {
                original_to_internal[v_orig] = internal_to_original.size();
                internal_to_original.push_back(v_orig);
                adj.resize(internal_to_original.size());
            }

            int u = original_to_internal[u_orig];
            int v = original_to_internal[v_orig];

            adj[u].push_back(v);
            adj[v].push_back(u);
            edges_count++;
        }
    }

    int n = adj.size();
    long long m = edges_count;

    m = 0;
    vector<int> degrees(n);
    for (int i = 0; i < n; i++)
    {
        degrees[i] = adj[i].size();
        m += degrees[i];
    }
    m /= 2;


    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({degrees[i], i});
    }

    vector<bool> removed(n, false);

    double max_density = (n > 0) ? (double)m / n : 0.0;
    int best_num_nodes = n;

    int current_n = n;
    long long current_m = m;

    vector<int> removed_at_size(n, 0);

    while (current_n > 0)
    {
        while (!pq.empty() && removed[pq.top().second])
        {
            pq.pop();
        }

        if (pq.empty())
            break;

        pii top = pq.top();
        pq.pop();
        int u = top.second;

        if (top.first != degrees[u])
        {
            if (top.first > degrees[u])
                continue;
        }

        removed[u] = true;
        removed_at_size[u] = current_n;

        for (int v : adj[u])
        {
            if (!removed[v])
            {
                degrees[v]--;
                pq.push({degrees[v], v});
                current_m--;
            }
        }

        current_n--;

        if (current_n > 0)
        {
            double density = (double)current_m / current_n;
            if (density > max_density)
            {
                max_density = density;
                best_num_nodes = current_n;
            }
        }
    }


    cout << fixed << setprecision(6) << max_density/2 << endl;

    bool first = true;
    for (int i = 0; i < n; i++)
    {
        if (removed_at_size[i] <= best_num_nodes)
        {
            if (!first)
                cout << " ";
            cout << internal_to_original[i];
            first = false;
        }
    }
    cout << endl;

    return 0;
}