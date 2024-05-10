#include <iostream>
#include <chrono>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

void generador(int n, int m) {
    int r;
    cout << 1 << endl;
    cout << n << " " << m << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            r = rand() % 10 + 1;
            cout << r  << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int n = stoi(argv[1]);
    int j;
    
    generador(n, (n+1)/2);

    return 0;
}