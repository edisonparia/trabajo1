#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int N = 1000;        // Tamaño de la matriz
const int blockSize = 100; // Tamaño del bloque

// Función para multiplicar matrices por bloques
vector<vector<int>> multiplyMatricesBlock(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i += blockSize)
    {
        for (int j = 0; j < n; j += blockSize)
        {
            for (int k = 0; k < n; k += blockSize)
            {
                for (int i1 = i; i1 < min(i + blockSize, n); ++i1)
                {
                    for (int j1 = j; j1 < min(j + blockSize, n); ++j1)
                    {
                        for (int k1 = k; k1 < min(k + blockSize, n); ++k1)
                        {
                            result[i1][j1] += A[i1][k1] * B[k1][j1];
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    // Inicializar matrices A y B con valores aleatorios
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Multiplicación de matrices clásica
    auto startClassic = high_resolution_clock::now();
    vector<vector<int>> resultClassic = multiplyMatricesBlock(A, B);
    auto stopClassic = high_resolution_clock::now();
    auto durationClassic = duration_cast<milliseconds>(stopClassic - startClassic);

    // Multiplicación de matrices por bloques
    auto startBlock = high_resolution_clock::now();
    vector<vector<int>> resultBlock = multiplyMatricesBlock(A, B);
    auto stopBlock = high_resolution_clock::now();
    auto durationBlock = duration_cast<milliseconds>(stopBlock - startBlock);

    cout << "Tiempo de multiplicación clásica: " << durationClassic.count() << " ms" << endl;
    cout << "Tiempo de multiplicación por bloques: " << durationBlock.count() << " ms" << endl;

    return 0;
}