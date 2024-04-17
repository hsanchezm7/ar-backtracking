#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Solucion {
    int diversidad;
    set<int> subset;
};

// Lee las diversidades de cada elemento y las guarda en una matriz
void readDistances(int n, vector<vector<int>>& distances) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> distances[i][j];
        }
    }
}

// Imprime la suma máxima y el subconjunt solución
void printSolution(int n, Solucion s) {
    cout << s.diversidad << endl;
    for (int i = 0; i < n; ++i) {
        if (s.subset.count(i)) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }
    cout << endl;
}

Solucion greedy(int n, int m, const vector<vector<int>> distances) {
    int maxSum = 0;
    set<int> maxSubset;

    // Iterar sobre todos los subconjuntos posibles de tamaño m
    for (int subset = 0; subset < (1 << n); ++subset) {
        if (__builtin_popcount(subset) == m) {
            int sum = 0;
            set<int> selectedIndices;

            // Calcular la suma de distancias para este subconjunto
            for (int i = 0; i < n; ++i) {
                if (subset & (1 << i)) {
                    selectedIndices.insert(i);
                    for (int j = 0; j < n; ++j) {
                        if (subset & (1 << j)) {
                            sum += distances[i][j];
                        }
                    }
                }
            }
            // Actualizar si esta suma es mayor que la máxima encontrada hasta ahora
            if (sum > maxSum) {
                maxSum = sum;
                maxSubset = selectedIndices;
            }
        }
    }
    Solucion s;
    s.diversidad = maxSum;
    s.subset = maxSubset;

    return s;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        // Matriz de distancias
        vector<vector<int>> distances(n, vector<int>(n));
        readDistances(n, distances);
        
        Solucion sol = greedy(n, m, distances);
        printSolution(n, sol);
    }

    return 0;
}