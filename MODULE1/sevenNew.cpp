/*В большой IT-фирме есть только одна переговорная комната. Желающие посовещаться заполняют заявки с желаемым временем начала и конца. Ваша задача определить максимальное количество заявок, которое может быть удовлетворено.
 Число заявок  ≤ 100000.
 Формат входных данных:
 Вход содержит только пары целых чисел  —  начала и концы заявок.
 Формат выходных данных:
 Выход должен содержать натуральное число  — максимальное число заявок*/

#include <iostream>
#include <assert.h>

void sorting(int* firstArray, int* secondArray, int sizeFirst);
int sercher(int* firstArray, int* secondArray, int sizeFirst);

int main(int argc, const char* argv[])
{
    int sizeFirst = 0;
    int sizeSecond = 0;
    int* firstArray = new int[100000];
    int* secondArray = new int[100000];
    int firstBuffer = 0;
    int secondBuffer = 0;
    int result = 0;
    
    while (scanf("%d", &firstBuffer) == 1) {
        if ( firstBuffer == -1 )
            break;
        firstArray[sizeFirst] = firstBuffer;
        ++sizeFirst;
        scanf("%d", &secondBuffer);
        secondArray[sizeSecond] = secondBuffer;
        ++sizeSecond;
    }
    
    assert(sizeFirst == sizeSecond);
    sorting(firstArray, secondArray, sizeFirst);
    
    result = sercher(firstArray, secondArray, sizeFirst);
    std::cout << result;
    return 0;
}

void sorting(int* firstArray, int* secondArray, int sizeFirst)
{
    
    int buff = 0;
    int secondBufer = 0;
    for (int i = 0; i != sizeFirst - 1; ++i) {
        for (int j = 0; j != sizeFirst - i - 1; ++j) {
            if ( secondArray[j] > secondArray[j + 1] ) {
                buff = secondArray[j];
                secondArray[j] = secondArray[j + 1];
                secondArray[j + 1] = buff;
                
                secondBufer = firstArray[j];
                firstArray[j] = firstArray[j + 1];
                firstArray[j + 1] = secondBufer;
            }
        }
    }
}

int sercher(int* firstArray, int* secondArray, int sizeFirst)
{
    int count = 0;
    int flag = 0;
    
    for (int i = 0; i < sizeFirst; ++i) {
        
        if ( secondArray[i - 1] <= firstArray[i] ) {
            ++count;
            
            flag = i;
        }
        
        else if ( firstArray[i] >= secondArray[flag] ) {
            flag = i;
            
            ++count;
        }
    }
    
    return count;
}
