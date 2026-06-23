#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    const int SIZE = 7;
    int arr[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            arr[i][j] = rand() % 90 + 10;
        }
    }
    cout << "Массив:\n";
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    int mainDiag = 0;
    for (int i = 0; i < SIZE; i++){
        mainDiag += arr[i][i];
    }

    int sideDiag = 0;
    for (int i = 0; i < SIZE; i++){
        sideDiag += arr[i][SIZE -1 -i];
    }

    cout << "Сумм главной диагонали: " << mainDiag << "\n";
    cout << "Сумм побочной диагонали: " << sideDiag << "\n";

    int maxColSum = 0;
    int maxColIndex = 0;

    for (int j = 0; j < SIZE; j++){
        int colSum = 0;
        for (int i = 0; i < SIZE; i++){
            colSum += arr[i][j];
        } 
        if (j==0 || colSum > maxColSum){
            maxColSum = colSum;
            maxColIndex = j;
        }
    }
    cout << "Номер столбца с макс суммой: " << (maxColIndex + 1) << "\n";
    cout << "Номер столбца с макс суммой: " <<  maxColSum << "\n";
    
}