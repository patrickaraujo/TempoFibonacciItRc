#include <stdio.h>
#include <time.h>

#define REPETICOES 1000  // Menor número de repetições por conta do tempo da versão recursiva

// Fibonacci recursivo simples (ineficiente)
unsigned long long fibonacciRecursivo(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

// Fibonacci iterativo (eficiente)
unsigned long long fibonacciIterativo(int n) {
    if (n <= 1)
        return n;
    unsigned long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n = 30;  // Valor de n para Fibonacci
    unsigned long long resultado;
    clock_t inicio, fim;
    double tempoRecursivo, tempoIterativo;

    // Medir tempo da versão recursiva
    inicio = clock();
    for (int i = 0; i < REPETICOES; i++) {
        resultado = fibonacciRecursivo(n);
    }
    fim = clock();
    tempoRecursivo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Medir tempo da versão iterativa
    inicio = clock();
    for (int i = 0; i < REPETICOES; i++) {
        resultado = fibonacciIterativo(n);
    }
    fim = clock();
    tempoIterativo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Imprimir resultados
    printf("Fibonacci de %d = %llu\n", n, resultado);
    printf("Tempo Recursivo (%d execuções): %f segundos\n", REPETICOES, tempoRecursivo);
    printf("Tempo Iterativo (%d execuções): %f segundos\n", REPETICOES, tempoIterativo);

    return 0;
}
