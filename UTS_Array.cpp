#include <iostream>
using namespace std;

int main() {
    system("cls");

    int arr[2][3][4];
    int calcArr[3][4];

    // Input 3D Array
    for (int i = 0; i < 2; i++) {
        int seq = 1;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                if (i == 0) {
                    arr[i][j][k] = 2 * seq;
                }
                else {
                    arr[i][j][k] = 3 * seq;
                }
                seq++;
            }
        }
    }

    // Calculate
    int layer = 0;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 4; k++) {
            calcArr[j][k] = arr[layer][j][k] * arr[layer+1][j][k];
            cout << calcArr[j][k] << ' ';
        }
        cout << "\n";
    }

    // Output

    return 0;
}