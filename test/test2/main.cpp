#include <iostream>
#include <ctime>

using namespace std;

int main(){
    srand(time(0));

    const int SIZE = 20;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++){
        arr[i] = rand() % 100;
    }

    for (int i = 0; i < SIZE; i++){
        cout << arr[i]<<" ";
    }
    cout << "\n";

    for (int i = 0; i < SIZE - 1;i++){
        for (int j = 0; j < SIZE -1 -i; j++){
            if (arr[j] < arr[j+1]){
                int tempor = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempor;
            }
        }
    }

    for (int i = 0; i < SIZE; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    int minValue = arr[0];
    int maxValue = arr[0];

    for (int i = 1; i < SIZE; i++){
        if (arr[i] < minValue){
            minValue = arr[i];
        }
        if (arr[i]> maxValue){
            maxValue = arr[i];
        }
    }

    cout<<"Мин знач:"<<minValue<<"\n";
    cout<<"Макс знач"<<maxValue<<"\n";

    return 0;
}