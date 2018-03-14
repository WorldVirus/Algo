/*
 Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков
 пирамиду. Широкая пирамида.​ Каждый вышележащий слой пирамиды должен быть строго меньше нижележащего.
 */


#include <iostream>
#include <assert.h>


void fill_matrix(int  **matrix, int n);
void free_array2d (int **matrix,int n);
int ** create_array2d(int n);
using namespace std;



int main() {
    int n;
    cin >> n;
    
   int  **array = create_array2d(n*2+1);
    
    fill_matrix(array, n);
    cout << (array[n][n] + 1);
    
    free_array2d (array, n);
    return 0;
}


void fill_matrix(int  **matrix, int n) {
    for (int diagonal = 0; diagonal < n * 2 + 1; ++diagonal) {
        for (int m = 1; m <= diagonal + 1; ++m) {
            int n = diagonal - m + 1;
            if (n == 0) {
                matrix[n][m] = 1;
            } else {
                matrix[n][m] = 0;
                
                for (int j = 1; j <= n; ++j) {
                    int i = n - j;
                    
                    if (j < m) {matrix[n][m] += matrix[i][j];
                     }
                }
            }
        }
    }
}

int ** create_array2d(int n) {
    int **matrix = new int  *[n];
    
    for (int i = 0; i != n; ++i) {
        matrix[i] = new int [n];
    }
    
    return matrix;
}

void free_array2d (int **matrix,int n)
{
    for (int i=0;i!=n;++i)
    {
        delete []matrix[i];
    }
    delete[]matrix;
}










































/*
 Заполняем матрицу по числу n исходных кубиков и количеству s столбцов.
 В клетку m(n, 1) ставим 1. Остальные клетки заполняем по формуле
 f(n, s) = f(n - s, s) + f(n - s, s - 1) (2)
 Здесь первое слагаемое отражает случай, когда в первом столбце больше одного кубика, а второе - когда ровно один. Вычисляем
 значения, пока не дойдем до нулевого.
 Если n = N, то, вычисляя значения по формуле (2), одновременно находим их сумму, что и будет ответом
 По сути это задача двухмерного динамического программирования
 */

