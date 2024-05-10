#include <iostream>
#include <algorithm>
#include <cstring>
#define NO_SOLUTION -10000000

using namespace std;

/* Variables globales */
int M, C, price[20][20];
int memo[200][20];

/* Función genérica que indica si un subproblema es posible solución */
bool solucion(int budget, int n) {
    return (n == C && budget <= M);
}

/**
 * Solución mediante backtracking al problema de maximización 
 * de las prendas de ropa para la boda
 *
 * @param budget presupuesto del subproblema
 * @param n Número de prendas cogidas (nivel del árbol). Inicialmente 0
 * @return Suma máxima del precio de las prendas o "NO_SOLUTION" si
 * no hay ninguna combinación posible de C prendas
 */
int backtracking(int budget, int n = 0) {
    if (budget < 0)
        return NO_SOLUTION;

    if (solucion(budget, n))
        return M - budget;

    int & res = memo[budget][n];
    if (res != -1)
        return res;

    for (int model = 1; model <= price[n][0]; model++)
        res = max(res, backtracking(budget - price[n][model], n + 1));

    return res;
}

int main() {
    int i, j, T, sol;

    cin >> T;
    while (T--) {
        cin >> M >> C;
        for (i = 0; i < C; i++) {
            cin >> price[i][0];
            for (j = 1; j <= price[i][0]; j++) {
                cin >> price[i][j];
            }
        }
        memset(memo, -1, sizeof memo);
        sol = backtracking(M, 0);
        if (sol < 0) 
            cout << "no solution" << endl;
        else 
            cout << sol << endl;
    }
}
