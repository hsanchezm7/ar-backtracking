#include <iostream>
#include <chrono>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

void generador(int n) {
    int K, r;
    for(int i = 0; i < n; i++) {
        K = rand() % 200 + 1;
        cout << K << " ";
        for(int j = 0; j < K; j++) {
            r = rand() % 10 + 1;
            cout << r  << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int n = stoi(argv[1]);
    
    int M = rand() % 200 + 1;
    cout << 1 << endl;
    cout << M << " " << n << endl;
    generador(n);

    return 0;
}