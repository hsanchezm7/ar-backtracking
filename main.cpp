#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> distances(n, vector<int>(n));

        // Leer las distancias entre elementos
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> distances[i][j];
            }
        }

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

        // Imprimir la suma máxima y el subconjunto correspondiente
        cout << maxSum << endl;
        for (int i = 0; i < n; ++i) {
            if (maxSubset.count(i)) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}