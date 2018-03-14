/*
  Первые k элементов длинной последовательности.
 Дана очень длинная последовательность целых чисел длины n. Требуется вывести в отсортированном виде её первые k элементов. Последовательность может не помещаться в память. Время работы O(n * log(k)). Доп. память O(k). Использовать слияние.
 
 */

#include <iostream>
#include <assert.h>

using std::cin;
using std::cout;

int* Merge(int *mas1, int *mas2, int s1, int s2, int SizeResult=0)
{
    SizeResult = SizeResult == 0? s1 + s2: SizeResult;
    int *mas = new int[ SizeResult ];
    int n = 0;
    while (s1 && s2 && n < SizeResult)
    {
        if (*mas1 < *mas2)
        {
            mas[n] = *mas1;
            mas1++;
            --s1;
        }
        else
        {
            mas[n] = *mas2;
            ++mas2;
            --s2;
        }
        ++n;
    }
    if (s1 == 0)
    {
        for (int i = 0; i < s2 && n < SizeResult; ++i)
        {
            mas[n++] = *mas2++;
        }
    }
    else
    {
        for (int i = 0; i < s1 && n < SizeResult; ++i)
        {
            mas[n++] = *mas1++;
        }
    }
    return mas;
}

void Sort(int* Buffer, int Size)
{
    int n = 1, l, ost;
    int* mas;
    while (n < Size)
    {
        l = 0;
        while (l < Size)
        {
            if (l + n >= Size) break;
            ost = (l + n * 2 > Size) ? (Size - (l + n)) : n;
            mas = Merge(Buffer + l, Buffer + l + n, n, ost);
            for (int i = 0; i < n + ost; ++i)
                Buffer[l+i] = mas[i];
            delete[] mas;
            l += n * 2;
        }
        n *= 2;
    }
}

void GetFirstNumber(int* Result, int* Mas, int Portion, int Number)
{
    int i = Portion, x;
    for( i = 0; i < Portion; ++i)
    {
        cin>>x;
        if (x == 0)
            break;
        Result[i] = x;
    }
    Sort(Result, Portion);
    int j = Portion;
    int* temp;
    while ( j < Number )
    {
        for( i = 0; i < Portion && j < Number; ++i, ++j)
        {
            cin>>x;
            Mas[i] = x;
        }
        Sort(Mas, i);
        temp=Merge(Result, Mas, Portion, i, Portion);
        for (int z = 0; z < Portion; ++z)
            Result[z] = temp[z];
        delete[] temp;
    }
}

int main()
{
    int Number = 0, Portion = 0;
    cin>>Number;cin>>Portion;
    assert( Portion > 0 );
    assert( Number >= Portion );
    int* Result = new int [Portion];
    int* Mas = new int [Portion];
    GetFirstNumber(Result, Mas, Portion, Number);
    for ( int i = 0; i < Portion; ++i)
    {
cout<<Result[i]<<" ";
    }
    delete[] Mas;
    delete[] Result;
    return 0;
}
