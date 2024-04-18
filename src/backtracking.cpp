#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#define NO_SOLUTION -1

using namespace std;

vector<int> readPrecios() {
    vector<int> precios;

    string line;
    getline(cin, line);

    int n;
    stringstream ss(line);
    while (ss >> n)
        precios.push_back(n);

    return precios;
}

int backtracking(int M, int C, vector<vector<int>>& prendas) {
    vector<bool> dp(M + 1, false);
    dp[0] = true;

    for (const auto& precios : prendas) {
        for (int p : precios) {
            for (int i = M; i >= p; --i) {
                if (dp[i - p]) {
                    dp[i] = true;
                }
            }
        }
    }

    for (int i = M; i >= 0; --i) {
        if (dp[i]) {
            return M - i;
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

        for (int i = 0; i < C; i++)
            prendas.push_back(readPrecios());

        int sol = backtracking(M, C, prendas);
        if (sol == NO_SOLUTION) {
            cout << "no solution" << endl;
        } else {
            cout << sol << endl;
        }
    }

    return 0;
}
