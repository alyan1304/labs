#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    //создание массива и заполнение его элементами (двумя способами)
    const int max = 15;
    int n = 0;
    while ((n<1)||(n>max)) {
        cout << "Input n from 1 to " << max << endl;
        cin >> n;
    }
    int* arr = new int[n];
    int choice = 2;
    while ((choice!=1)&&(choice!=0)) {
        cout << "Press 0 to input elements\nInput 1 to generate random elements" << endl;
        cin >> choice;
    }

    if (choice==0) {
        cout << "Input " << n << " elements" << endl;
        for(int i=0; i<n; i++){
            cin >> arr[i]; 
        }
    }
    else if (choice==1) {
        int lim1, lim2;
        cout << "Generate random numbers in the range: \nfrom ";
        cin >> lim1;
        cout << "to ";
        cin >> lim2;
        for(int i=0; i<n; i++){
            arr[i]=rand() % (lim2-lim1+1) + lim1;
        }
        for(int i = 0; i<n; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    //переставление местами максимального и минимального по модулю элементов (если несколько, брать первые)
    int max_el {(arr[n-1])}, min_el {(arr[n-1])};
    int index_max, index_min;
    for(int i = n - 1; i >= 0; i--){
        if (abs(arr[i]) >= abs(max_el)) {
            index_max = i;
            max_el = arr[i];
        }
        if (abs(arr[i]) <= abs(min_el)) {
            index_min = i;
            min_el = arr[i];
        }
        }
    arr[index_max] = min_el;
    arr[index_min] = max_el;
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    //вычисление суммы элементов массива, расположенных после последнего минимального по модулю элемента
    int last_min {(arr[0])}, sum{0};
    int index_last_min;
    for(int i = 0; i < n; i++){
        if (abs(arr[i]) <= abs(last_min)) {
            index_last_min = i;
            last_min = arr[i];
        }
    }
    for(int i = 0; i < n; i++) {
        if (i > index_last_min) {
            sum+=arr[i];
        }
    }
    cout << endl << "sum = " << sum << endl;

    //замена всех отрицательных элементов массива на их квадраты; упорядочивание элементов массива по возрастанию      
    for(int i = 0; i<n; i++) {
        if (arr[i] < 0) {
            arr[i]*=arr[i];
        }
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++) {
        int a, b;
        if (arr[i] < arr[i-1]) {
            a = arr[i];
            b = arr[i-1];
            arr[i] = b;
            arr[i-1] = a;
            i = 0;
        }

        
    }

    for(int i = 0; i<n; i++) {
            cout << arr[i] << " ";
        }
    
    
    return 0;
    }
    
