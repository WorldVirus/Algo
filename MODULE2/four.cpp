/*
 Реализуйте стратегию выбора опорного элемента “случайный элемент”. Функцию Partition реализуйте методом прохода двумя итераторами от начала массива к концу. */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <assert.h>
int partation(std::vector<int>& array, int begin, int end);
int sercherK(std::vector<int>& masive, int begin, int end, int k);

int main()
{
    int n = 0, k = 0;
    int buffer = 0;
    std::cin >> n >> k;
    std::vector<int> array;
    
    assert(n > 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> buffer;
        array.push_back(buffer);
    }
    std::cout << sercherK(array, 0, n - 1, k) << std::endl;
    return 0;
}

int partation(std::vector<int>& array, int begin, int end)
{
    
    int randIndex = rand() % (end - begin + 1) + begin;
    int pivot = array[randIndex];
    std::swap(array[end], array[randIndex]);
    int i = begin, j = begin;
    while (i <= end && pivot >= array[i]) {
        ++i;
    }
    
    if (i >= end) {
        return end;
    }
    j = i + 1;
    while (j < end) {
        
        while (array[j] > pivot)
            ++j;
        if (j < end) {
            std::swap(array[i++], array[j++]);
        }
    }
    std::swap(array[i], array[end]);
    return i;
}

int sercherK(std::vector<int>& masive, int begin, int end, int k)
{
    while (true) {
        int posithion = partation(masive, begin, end);
        if (posithion < k)
            begin = posithion + 1;
        else if (posithion > k)
            end = posithion - 1;
        else
            return masive[k];
    }
}
