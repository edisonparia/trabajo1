#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Función para multiplicar matrices clásicamente
vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; ++i)
    {
        for (int j = 0; j < colsB; ++j)
        {
            for (int k = 0; k < colsA; ++k)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int main()
{
    int sizes[] = {100, 200, 300}; // Tamaños de matriz a evaluar
    int numSizes = sizeof(sizes) / sizeof(int);

    for (int i = 0; i < numSizes; ++i)
    {
        int size = sizes[i];

        // Inicializar matrices A y B con valores aleatorios
        vector<vector<int>> A(size, vector<int>(size));
        vector<vector<int>> B(size, vector<int>(size));
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                A[i][j] = rand() % 10;
                B[i][j] = rand() % 10;
            }
        }

        // Medir el tiempo de ejecución
        auto start = high_resolution_clock::now();
        vector<vector<int>> result = multiplyMatrices(A, B);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Tamaño de matriz: " << size << " x " << size << endl;
        cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;
    }

    return 0;
}