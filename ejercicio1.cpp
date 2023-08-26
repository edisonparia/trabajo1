#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX = 1000; // Tamaño de la matriz

// Función para inicializar una matriz con valores aleatorios
void initializeMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

int main()
{
    vector<vector<int>> A(MAX, vector<int>(MAX));
    vector<vector<int>> y(MAX, vector<int>(MAX, 0));

    initializeMatrix(A); // Inicializar matriz A

    // Primera pair de bucles
    auto startFirst = high_resolution_clock::now();
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            for (int k = 0; k < MAX; ++k)
            {
                y[i][j] += A[i][k];
            }
        }
    }
    auto stopFirst = high_resolution_clock::now();
    auto durationFirst = duration_cast<milliseconds>(stopFirst - startFirst);

    // Reiniciar matriz y
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            y[i][j] = 0;
        }
    }

    // Segunda pair de bucles
    auto startSecond = high_resolution_clock::now();
    for (int j = 0; j < MAX; ++j)
    {
        for (int i = 0; i < MAX; ++i)
        {
            for (int k = 0; k < MAX; ++k)
            {
                y[i][j] += A[i][k];
            }
        }
    }
    auto stopSecond = high_resolution_clock::now();
    auto durationSecond = duration_cast<milliseconds>(stopSecond - startSecond);

    cout << "Tiempo de ejecución del primer par de bucles: " << durationFirst.count() << " ms" << endl;
    cout << "Tiempo de ejecución del segundo par de bucles: " << durationSecond.count() << " ms" << endl;

    return 0;
}
