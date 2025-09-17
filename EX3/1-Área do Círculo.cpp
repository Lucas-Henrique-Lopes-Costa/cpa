/*
Área do Círculo

A fórmula para calcular a área de uma circunferência é: area = π . raio2. Considerando para este problema que π = 3.14159:

- Efetue o cálculo da área, elevando o valor de raio ao quadrado e multiplicando por π.

Entrada
A entrada contém um valor de ponto flutuante (dupla precisão), no caso, a variável raio.

Saída
Apresentar a mensagem "A=" seguido pelo valor da variável area, conforme exemplo abaixo, com 4 casas após o ponto decimal. Utilize variáveis de dupla precisão (double). Como todos os problemas, não esqueça de imprimir o fim de linha após o resultado, caso contrário, você receberá "Presentation Error".

Exemplos de Entrada

2.00

100. 64

150.00

Exemplos de Saída

A=12.5664

A=31819.3103

A=70685.7750
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // ALGORITMO: Cálculo da área de um círculo
    // Fórmula: área = π × raio²
    // Onde π é aproximadamente 3.14159

    double raio;
    double pi = 3.14159; // Constante π definida pelo problema
    cin >> raio;         // Lê o valor do raio

    // Calcula a área usando a fórmula matemática
    // pow(raio, 2) eleva o raio ao quadrado
    double area = pi * pow(raio, 2);

    // Imprime o resultado com 4 casas decimais de precisão
    // fixed e setprecision(4) garantem a formatação correta
    cout << "A=" << fixed << setprecision(4) << area << endl;

    return 0;
}
