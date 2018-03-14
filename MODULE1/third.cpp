/*
 Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1]. Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k], ближайшего по значению к B[i]. Время работы поиска для каждого элемента B[i]: O(log(k)).
 n ≤ 110000, m ≤ 1000.
 */

#include <iostream>
#include <assert.h>
int search(int* A, int array_index, int n, int m);
using std::cin;
using std::cout;
int main()
{
    int n = 0, m = 0;
    int result = 0;
    std::cin >> n;
    assert( n <= 110000 && n > 0 );
    
    int* A = new int[n];
    
    for ( int i = 0; i < n; ++i ) {
        cin >> A[i];
    }
    cin >> m;
    assert(m <= 1000 && m > 0);
    
    int* B = new int[m];
    for ( int i = 0; i < m; ++i ) {
        cin >> B[i];
    }
    for ( int i = 0; i < m; ++i ) {
        result = search(A, B[i], n, m);
        cout << result << " ";
    }
    delete[] A;
    delete[] B;
    return 0;
}

int search(int* A, int array_index, int n, int m)
{
    if ( A[n - 1] < array_index ) {
        return n - 1;
    }
 /*   int i=0;
    while(A[1 << i] < array_index && (1 << i) < n)
    {
        i++;
    }
    int first = (i == 0) ? 0 : 1 << (i - 1);
    int last = ((1 << i) < n)? 1 << i : n;*/

    int first=0;
    int last=n;
    
    while (first < last) {
        int mid = ( first + last ) / 2;
        if ( array_index <= A[mid] )
            last = mid;
        else {
            first = mid + 1;
        }
    }
    
    if ( A[first] > array_index && first != 0 ) {
        return A[first] - array_index >= array_index - A[first - 1] ? first - 1 : first;
    }
    else {
        return first;
    }
}














/*
 int i=0;
while(A[1 << i] < array_index && (1 << i) < n)
{
    i++;
}
int first = (i == 0) ? 0 : 1 << (i - 1);
int last = ((1 << i) < n)? 1 << i : n;
 
 
 
 */
