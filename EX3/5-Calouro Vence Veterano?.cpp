/*

Professor Denis está curioso para saber se a classificação final de seus N alunos de programação competitiva segue a ordem de matrícula na universidade. Ele pediu a sua ajuda para, dada a classificação final, contar quantos pares (i, j) existem tais que i < j e m[i] > m[j], onde 1 ≤ i,j ≤ N e m[i] significa a matrícula do aluno que ficou em i-ésimo lugar.

Entrada
A entrada contém vários casos de teste.

A primeira linha de um caso de teste contém um único inteiro N, que representa o número de alunos, onde 1 ≤ N ≤ 105.

As próximas N linhas são a classificação final dos alunos. Cada linha contém uma cadeia de exatamente 10 caracteres.

Saída
Para cada caso de teste, imprima uma única linha com o número pedido na especificação.

Exemplo de Entrada

4
12/0001111
14/0001111
11/0001111
10/0001111

Exemplo de Saída

5

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long mergeAndCount(vector<string> &arr, vector<string> &temp, int left, int mid, int right)
{
    int i = left;    // Índice para a metade esquerda
    int j = mid + 1; // Índice para a metade direita
    int k = left;    // Índice para o array temporário
    long long inv_count = 0;

    // Mescla as duas metades contando inversões
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            // Quando arr[i] > arr[j], temos inversões
            // arr[i] é maior que todos os elementos restantes da metade esquerda
            inv_count += (mid - i + 1);
        }
    }

    // Copia elementos restantes
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // Copia de volta para o array original
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inv_count;
}

long long mergeSortAndCount(vector<string> &arr, vector<string> &temp, int left, int right)
{
    long long inv_count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main()
{
    int n;

    while (cin >> n)
    {
        vector<string> matriculas(n);

        // Lê as matrículas
        for (int i = 0; i < n; i++)
        {
            cin >> matriculas[i];
        }

        // Cria array temporário para merge sort
        vector<string> temp(n);

        // Conta inversões usando merge sort
        long long inversions = mergeSortAndCount(matriculas, temp, 0, n - 1);

        cout << inversions << endl;
    }

    return 0;
}