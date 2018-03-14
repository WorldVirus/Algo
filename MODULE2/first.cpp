/*На склад привезли много пустых ящиков. Все ящики пронумерованы по порядку поступления от 0. Известно, что их все можно сложить один в один (то есть так, что каждый следующий помещается в предыдущий). Один ящик можно вложить в другой, если его можно перевернуть так, что размеры одного ящика по всем осям станут строго меньше размеров другого ящика по соответствующим осям. Требуется определить, в какой последовательности они будут вложены друг в друга. Вывести номера ящиков.*/

#include <iostream>
using std::cin;
using std::cout;

struct box {
    int size;
    int id;
    
    bool operator<(const box& pole)
    {
        return this->size < pole.size;
    }
    
    bool operator>=(const box& pole)
    {
        return this->size >= pole.size;
    }
};
template <typename T>
void InsertionSort(T* Mas, size_t end, size_t begin)
{
    size_t i, j;
    T tmp;
    for (i = 1; i < end; ++i) {
        tmp = Mas[i];
        for (j = i; j > begin && tmp < Mas[j - 1]; --j) {
            Mas[j] = Mas[j - 1];
        }
        Mas[j] = tmp;
    }
}

int main()
{
    int number = 0;
    cin >> number;
    box* ArrayObject = new box[number];
    for (int i = 0; i != number; ++i) {
        int coordinates = 0;
        int counter = 0;
        int buffer = 0;
        while (counter != 3) {
            cin >> coordinates;
            
            ++counter;
            buffer += coordinates;
        }
        
        ArrayObject[i].id = i;
        ArrayObject[i].size = buffer;
    }
    InsertionSort(ArrayObject, number, 0);
    for (size_t i = 0; i < number; ++i) {
        std::cout << ArrayObject[i].id << std::endl;
    }
    delete[] ArrayObject;
    return 0;
}
