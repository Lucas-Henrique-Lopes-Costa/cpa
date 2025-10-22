#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

/**
 * Laboratório de CPA: algoritmo de Huffman
 *
 * Neste laboratório, deve ser construído um programa que encontre uma
 * codificação binária para um arquivo de forma ótima. Para isso:
 *
 * 1. Construa uma função que lê da entrada padrão um arquivo de texto e produz
 *    uma tabela de frequências para cada caractere encontrado no documento
 *    texto.
 *
 * 2. Implemente o algoritmo de Huffman, que recebe a tabela gerada no passo
 *    anterior como entrada. A saída desse algoritmo será a própria árvore
 *    gerada na saída padrão. O formato gerado será descrito a seguir, na função
 *    correspondente.
 *
 * 3. Junte (1) e (2) em uma função principal (main) que, recebe um arquivo da
 *    entrada padrão e produza a árvore ótima de codificação do documento
 *
 * 4. Testes e entrega: entregar no Campus Virtual o .cpp acompanhado da saída
 *    do programa para os documentos de teste incluídos no Campus Virtual
 *
 */

// Estrutura para nó da árvore de Huffman
struct Node
{
  char ch;
  int freq;
  Node *left;
  Node *right;

  Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
  Node(int f, Node *l, Node *r) : ch('\0'), freq(f), left(l), right(r) {}
};

// Comparador para priority_queue (mín-heap)
struct Compare
{
  bool operator()(Node *a, Node *b)
  {
    return a->freq > b->freq;
  }
};

// Lê da entrada padrão e retorna tabela de frequências
// Considera apenas caracteres gráficos imprimíveis (ASCII 32-126)
map<char, int> getCharFrequencies()
{
  map<char, int> freq;
  char c;
  while (cin.get(c))
  {
    // Filtra apenas caracteres imprimíveis (ASCII 32-126)
    if (c >= 32 && c <= 126)
    {
      freq[c]++;
    }
  }
  return freq;
}

// Constrói a árvore de Huffman e armazena os códigos
void buildCodes(Node *root, string code, map<char, string> &codes)
{
  if (!root)
    return;

  // Se for folha (caractere)
  if (root->ch != '\0')
  {
    codes[root->ch] = code.empty() ? "0" : code;
    return;
  }

  // Recursivo: esquerda = 0, direita = 1
  if (root->left)
    buildCodes(root->left, code + "0", codes);
  if (root->right)
    buildCodes(root->right, code + "1", codes);
}

void huffman(map<char, int> freq)
{
  // Verifica se há caracteres
  if (freq.empty())
  {
    cerr << "Nenhum caractere encontrado!" << endl;
    return;
  }

  // Cria a fila de prioridade (mín-heap)
  priority_queue<Node *, vector<Node *>, Compare> pq;

  // Insere cada caractere na fila
  for (auto &p : freq)
  {
    pq.push(new Node(p.first, p.second));
  }

  // Constrói a árvore de Huffman
  while (pq.size() > 1)
  {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();

    Node *parent = new Node(left->freq + right->freq, left, right);
    pq.push(parent);
  }

  Node *root = pq.top();

  // Gera os códigos Huffman
  map<char, string> codes;
  if (root->ch != '\0')
  {
    // Caso especial: apenas um caractere
    codes[root->ch] = "0";
  }
  else
  {
    buildCodes(root, "", codes);
  }

  // Imprime os códigos em ordem de caractere (ASCII)
  for (auto &p : codes)
  {
    cout << p.first << " " << p.second << endl;
  }
}

int main()
{
  map<char, int> frequencies = getCharFrequencies();
  huffman(frequencies);
  return 0;
}
