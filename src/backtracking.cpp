#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define NO_SOLUTION -1

using namespace std;

vector<int> readModelos(int n_modelos) {
    vector<int> precios;
    int n;

    for (int i=0; i < n_modelos; i++) {
        cin >> n;
        precios.push_back(n);
    }

    return precios;
}

void printModelos(const vector<vector<int>>& prendas) {
    for (const auto& fila : prendas) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

int backtracking(int M, int C, vector<vector<int>>& prendas) {
    vector<bool> sumas;

    for (const auto& precios : prendas) {
        vector<vector<int>> locales = prendas;
        locales.erase(locales.begin());
        for (int p : precios) {
            return 
        }
    }

    return NO_SOLUTION;
}

int main() {
    int T, M, C;
    cin >> T;

    while(T--) {
        cin >> M >> C;

        vector<vector<int>> prendas;
        int n_modelos;
        for (int i = 0; i < C; i++) {
            cin >> n_modelos; 
            prendas.push_back(readModelos(n_modelos));
        }

        int sol = backtracking(M, C, prendas);
        if (sol == NO_SOLUTION) {
            cout << "no solution" << endl;
        } else {
            cout << sol << endl;
        }
        
        // printModelos(prendas);
    }

    return 0;
}
