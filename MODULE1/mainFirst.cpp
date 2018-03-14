// Найти, на сколько нулей оканчивается n! = 1 * 2 * 3 * ... * n. n ≤ 1000
#include <iostream>
#include <assert.h>
int searching(int*, int n);
int main()
{
    int n = 0;
    std::cin >> n;
    assert(n <= 1000 && n > 0);
    int* masChisel = new int[n + 1];
    for ( int i = 1; i <= n; ++i ) {
        masChisel[i] = i;
    }
    
    std::cout << searching( masChisel, n ) << std::endl;
    delete[] masChisel;
    return 0;
}
int searching( int* masChisel, int n )
{
    int counter = 0;
    for ( int i = 1; i <= n; ++i ) {
        if ( masChisel[i] % 5 == 0 ) {
            ++counter;
            if ( counter % 5 == 0 && counter != 0 ) {
                ++counter;
            }
        }
    }
    return counter;
}

