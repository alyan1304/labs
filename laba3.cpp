#include <iostream>
#include <vector>
using namespace std;


// нахождение номеров строк, которые не содержат отрицательные элементы
vector<int> find_lines(vector<vector<int>> matrix, vector<int>& lines, int size) {
    for(int i = 0; i < size; i++) {
        lines.push_back(i);
        for(int j = 0; j < size; j++) {
            if (matrix[i][j] < 0) {
                lines.pop_back();
                j = size;
            }
        }
        
}
return lines;
}

//нахождение произведения в этих строках
void mult(vector<vector<int>> matrix, vector<int> lines) {
    vector<int>::iterator start = lines.begin();
    for(;start != lines.end(); start++) {
    int mult = 1;
        for(int j = 0; j < matrix.size(); j++) {
            mult *= matrix[*start][j];
        }
    cout << mult << "\t";
    }
     cout << endl;
}

//нахождение сумм эл-ов диагоналей, параллельных главной (не включая главную диагональ) и нахождение наименьшей из сумм диагоналей:
vector<int> sums_d(vector<int> all_sums, vector<vector<int>> matrix, int size) {
    for(int k = 0; k < size; k++) {
        int sum = 0;
        
        for(int l = 0; l < size; l++) {
        int a = size-1-k+l;
            if ((a!=0)&&(a<size)) {
        sum+=matrix[l][a];
        }
        }
    all_sums.push_back(sum);
    }
    all_sums.pop_back();

    for(int k = 0; k < size; k++) {
        int sum = 0;
        
        for(int l = 0; l < size; l++) {
        int a = size-1-k+l;
            if ((a!=0)&&(a<size)) {
        sum+=matrix[a][l];
        }
        }
    all_sums.push_back(sum);
    }
    all_sums.pop_back();
for(int i = 0; i < all_sums.size(); i++) {
            cout << all_sums[i] << "\t";
        }

cout << endl;

int min = all_sums[0];
    for(int i = 0; i < (all_sums.size()-1); i++) {
        if (min > all_sums[i+1]) {
            min = all_sums[i+1];
        }
    }
    cout << min;

return all_sums;
}


int main(){
    //ввод размерности матрицы
    const int max_size = 10;
    int n;
    do {
        cout << "Input square matrix size n<=10" << endl; 
        cin >> n;
    }
    while((n<=1)||(n>10));
    //создание матрицы
    vector<vector<int>> matrix(n,vector<int>(n));
    //заполнение матрицы с клавиатуры
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                continue;
            }
            cout << "Input element " << "[" << i << ", " << j << "]" << endl;
            cin >> matrix[i][j];
            matrix[n-j-1][n-i-1] = matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
    cout << endl;
}

vector<int> lines;
find_lines(matrix, lines, n);

mult(matrix, lines);

vector<int> all_sums;
sums_d(all_sums, matrix, n);




    return 0;
}

