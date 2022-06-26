/*
 * Author: Renan Gomes Acosta
 * [Estrutura de Dados I] IFRS - Campus Rio Grande
 * Professor: Luciano Vargas Gonçalves
 * Algorítimos de Ordenação 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int vet[];

void rebuild(int vetor[], int MAX, int pos)
{
    int c1, c2;

    c1 = 2 * pos;
    c2 = c1 + 1;

    if (c1 > MAX || (vetor[pos - 1] >= vetor[c1 - 1] && vetor[pos - 1] >= vetor[c2 - 1]))
        return;

    int greater_index = -1;

    if (c2 > MAX)
        greater_index = c1;
    else
    {
        if (vetor[c1 - 1] > vetor[c2 - 1])
            greater_index = c1;
        else
            greater_index = c2;
    }

    if (greater_index != -1)
    {
        int aux = vetor[greater_index - 1];
        vetor[greater_index - 1] = vetor[pos - 1];
        vetor[pos - 1] = aux;
        rebuild(vetor, MAX, greater_index);
    }
}
void build(int vetor[], int Vsize)
{
    int left;

    if (Vsize % 2 == 0)
        left = Vsize / 2 + 1;
    else
        left = (Vsize - 1) / 2 + 1;

    while (left > 1)
    {
        left--;
        rebuild(vetor, Vsize, left);
    }
}

// ordena por SelectionSort
void selectionSort(int vetor[], int Vsize)
{
    int i, j, min, aux;

    for (i = 0; i < Vsize - 1; i++)
    {
        min = i;
        for (j = i + 1; j < Vsize; j++)
        {
            if (vetor[j] < vetor[min])
                min = j;
        }
        if (min != i)
        {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}

// Ordena por InsertionSort
void insertionSort(int vetor[], int Vsize)
{
    int i, j, aux;

    for (i = 1; i < Vsize; i++)
    {
        j = i;
        while (j > 0 && vetor[j] < vetor[j - 1])
        {
            aux = vetor[j];
            vetor[j] = vetor[j - 1];
            vetor[j - 1] = aux;
            j--;
        }
    }
}

// Oedena por BubbleSort
void bubbleSort(int vetor[], int Vsize)
{
    int i, j, aux;

    for (i = 0; i < Vsize - 1; i++)
    {
        for (j = 0; j < Vsize - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

// Oedena por ShellSort
void shellSort(int vetor[], int Vsize)
{
    int i, j, k, aux;

    for (k = Vsize / 2; k > 0; k /= 2)
    {
        for (i = k; i < Vsize; i++)
        {
            aux = vetor[i];
            for (j = i; j >= k && vetor[j - k] > aux; j -= k)
                vetor[j] = vetor[j - k];
            vetor[j] = aux;
        }
    }
}

// Ordena por mergesort
void Merge(int *A, int *B, int leftCount, int *T, int rightCount)
{
    int i, j, k;

    i = 0;
    j = 0;
    k = 0;

    while (i < leftCount && j < rightCount)
    {
        if (B[i] < T[j])
            A[k++] = B[i++];
        else
            A[k++] = T[j++];
    }
    while (i < leftCount)
        A[k++] = B[i++];
    while (j < rightCount)
        A[k++] = T[j++];
}

void MergeSort(int *A, int n)
{
    int mid, i, *B, *T;
    if (n < 2)
        return;
    mid = n / 2;

    B = (int *)malloc(mid * sizeof(int));
    T = (int *)malloc((n - mid) * sizeof(int));

    for (i = 0; i < mid; i++)
        B[i] = A[i];
    for (i = mid; i < n; i++)
        T[i - mid] = A[i];

    MergeSort(B, mid);
    MergeSort(T, n - mid);
    Merge(A, B, mid, T, n - mid);
    free(B);
    free(T);
}

// ordena por quicksort
void quicksort(int *target, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int i = left, j = right;
    int tmp, pivot = target[i];
    for (;;)
    {
        while (target[i] < pivot)
        {
            i++;
        }
        while (pivot < target[j])
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        tmp = target[i];
        target[i] = target[j];
        target[j] = tmp;
        i++;
        j--;
    }
    quicksort(target, left, i - 1);
    quicksort(target, j + 1, right);
}

int main() {
    printf("\n================================");
    printf("\n    ALGORÍTIMOS DE ORDENAÇÃO");
    printf("\n================================\n\n");
    clock_t start, end;
    int k = NULL, *vet = NULL, a, b, inicio = 0, fim = k - 1;
    printf("INFORME O TAMANHO DO VETOR: ");
    scanf("%d", &k);
    int i;
    vet = (int *)malloc(k * sizeof(int));
    //mostrar o tamanho do vetor
    printf("\n[-> Seu vetor terá %d posições <-]\n", k);
    printf("\n--------------------------------\n");

    // menu de opções do vetor
    printf("\nQUAL TIPO DE VETOR SERÁ CRIADO?\n\n");
    printf("[1] - Gerar vetor aleatório\n");
    printf("[2] - Gerar vetor decrescente\n");
    printf("[3] - Gerar vetor crescente\n");
    printf("\nESCOLHA UMA OPÇÃO: ");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        for (i = 0; i < k; i++)
        {
            vet[i] = rand() % 100;
        }
        printf("\n[-> Vetor aleatório criado <-]\n");
        break;
    case 2:
        for (i = 0; i < k; i++)
        {
            vet[i] = k - i;
        }
        printf("\n[-> Vetor decrescente criado <-]\n");
        break;
    case 3:
        for (i = 0; i < k; i++)
        {
            vet[i] = i;
        }
        printf("\n[-> Vetor crescente criado <-]\n");
        break;
    }
    printf("\n");
    for (i = 0; i < k; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n\n--------------------------------\n\n");
    printf("\nQUAL O ALGORÍTMO DE ORDENAÇÃO DESEJADO?\n\n");
    printf("\n# ORDENAÇÃO SIMPLES\n\n");
    printf("[1] - SelectionSort\n");
    printf("[2] - InsertionSort\n");
    printf("[3] - BubbleSort\n");
    printf("\n# ORDENAÇÃO EFICIENTE\n\n");
    printf("[4] - ShellSort\n");
    printf("[5] - MergeSort\n");
    printf("[6] - QuickSort\n");
    printf("\n[0] - Sair\n");
    printf("\nESCOLHA UMA OPÇÃO: ");
    scanf("%d", &b);
    switch (b)
    {
    case 1:
        start = clock();
        selectionSort(vet, k);
        end = clock();
        printf("\n[-> Você escolheu SelectionSort <-]\n");
        printf("\n-----------------------------------\n\n");
        printf("[-> O vetor foi ordenado <-]\n");
        printf("\n");
        for (i = 0; i < k; i++)
        {
            printf("%d ", vet[i]);
        }
        printf("\n\n-----------------------------------\n\n");
        printf("-> Tempo de clock inicial: %f segundos\n", start);
        printf("-> Tempo de execução: %f segundos\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        break;
    case 2:
        start = clock();
        insertionSort(vet, k);
        end = clock();
        printf("\n[-> Você escolheu InsertionSort <-]\n");
        printf("\n-----------------------------------\n\n");
        printf("[-> O vetor foi ordenado <-]\n");
        printf("\n");
        for (i = 0; i < k; i++)
        {
            printf("%d ", vet[i]);
        }
        printf("\n\n-----------------------------------\n\n");
        printf("-> Tempo de clock inicial: %f segundos\n", start);
        printf("-> Tempo de execução: %f segundos\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        break;
    case 3:
        start = clock();
        bubbleSort(vet, k);
        end = clock();
        printf("\n[-> Você escolheu BubbleSort <-]\n");
        printf("\n-----------------------------------\n\n");
        printf("[-> O vetor foi ordenado <-]\n");
        printf("\n");
        for (i = 0; i < k; i++)
        {
            printf("%d ", vet[i]);
        }
        printf("\n\n-----------------------------------\n\n");
        printf("-> Tempo de clock inicial: %f segundos\n", start);
        printf("-> Tempo de execução: %f segundos\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        break;
    case 4:
        start = clock();
        shellSort(vet, k);
        end = clock();
        printf("\n[-> Você escolheu ShellSort <-]\n");
        printf("\n-----------------------------------\n\n");
        printf("[-> O vetor foi ordenado <-]\n");
        printf("\n");
        for (i = 0; i < k; i++)
        {
            printf("%d ", vet[i]);
        }
        printf("\n\n-----------------------------------\n\n");
        printf("-> Tempo de clock inicial: %f segundos\n", start);
        printf("-> Tempo de execução: %f segundos\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        break;
    case 5:
        start = clock();
        MergeSort(vet, k);
        end = clock();
        printf("\n[-> Você escolheu MergeSort <-]\n");
        printf("\n-----------------------------------\n\n");
        printf("[-> O vetor foi ordenado <-]\n\n");
        for (i = 0; i < k; i++)
        {
            printf("%d ", vet[i]);
        }
        printf("\n\n-----------------------------------\n\n");
        printf("-> Tempo de clock inicial: %f segundos\n", start);
        printf("-> Tempo de execução: %f segundos\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        break;
    case 6:
        start = clock();
        quicksort(vet, inicio, fim);
        end = clock();
        printf("\n[-> Você escolheu QuickSort <-]\n");
        printf("\n-----------------------------------\n\n");
        printf("[-> O vetor foi ordenado <-]\n\n");
        for (i = 0; i < k; i++)
        {
            printf("%d ", vet[i]);
        }
        printf("\n\n-----------------------------------\n\n");
        printf("-> Tempo de clock inicial: %f segundos\n", start);
        printf("-> Tempo de execução: %f segundos\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        break;
    case 0:
        printf("\n\nSaindo do programa...\n");
        break;
    }
    printf("\n\nFIM DO PROGRAMA\n\n");
    free(vet);
    return 0;

}
    