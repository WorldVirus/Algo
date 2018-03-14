/*В большой IT-фирме есть только одна переговорная комната. Желающие посовещаться заполняют заявки с желаемым временем начала и конца. Ваша задача определить максимальное количество заявок, которое может быть удовлетворено.
 Число заявок  ≤ 100000.
 Формат входных данных:
 Вход содержит только пары целых чисел  —  начала и концы заявок.
 Формат выходных данных:
 Выход должен содержать натуральное число  — максимальное число заявок*/

#include <iostream>
#include <assert.h>
#include<string>
void sorting(int* firstArray, int* secondArray, int sizeFirst);
int sercher(int* firstArray, int* secondArray, int sizeFirst);
void heap_sort(int* data,int* firstArray, int firstSize) ;
void heap_pop(int *secondArray,int*firstArray,int sizrFirst);
void heap_insert(int *secondArray,int *firstArray, int sizeFirst, int x);



int main(int argc, const char* argv[])
{
    int sizeFirst = 0;
    int sizeSecond = 0;
    int* firstArray = new int[100000];
    int* secondArray = new int[100000];
    int firstBuffer = 0;
    int secondBuffer = 0;
    int result = 0;
    
    while (scanf("%d", &firstBuffer) != -1) {
        if ( firstBuffer == -1 )
            break;
        firstArray[sizeFirst] = firstBuffer;
        ++sizeFirst;
        scanf("%d", &secondBuffer);
        secondArray[sizeSecond] = secondBuffer;
        ++sizeSecond;
    }
    
    assert(sizeFirst == sizeSecond);
    heap_sort( secondArray, firstArray, sizeFirst) ;
    
    result = sercher(firstArray, secondArray, sizeFirst);
    std::cout << result;
    return 0;
}




void heap_insert(int *secondArray,int *firstArray, int sizeFirst, int x)
{
    secondArray[sizeFirst+1] = x;
    for (int i = sizeFirst+1; i > 1;) {
        if (secondArray[i] > secondArray[i/2]) {
          int  buff = secondArray[i];
            secondArray[i] = secondArray[i/2];
            secondArray[i/2] = buff;
            
           int secondBufer = firstArray[i];
            firstArray[i] = firstArray[i/2];
            firstArray[i/2] = secondBufer;
            i = i/2;
        } else {
            break;
        } }
}
void heap_pop(int *secondArray,int*firstArray,int sizrFirst) {
    secondArray[sizrFirst]=secondArray[1];
    for (int i = 1; 2*i < sizrFirst;) {
        i *= 2;
        if (i+1 < sizrFirst && secondArray[i] < secondArray[i+1]) {
            i += 1;
        }
        if (secondArray[i/2] < secondArray[i]) {
            int buffer=secondArray[i/2];
            secondArray[i/2]=secondArray[i];
            secondArray[i]=buffer;
            
            
            int second_buffer=firstArray[i/2];
            firstArray[i/2]=firstArray[i];
            firstArray[i]=second_buffer;
        }
    } }


void heap_sort(int* data,int* firstArray, int firstSize) {
    int *buff = new int[firstSize+1];
    for (int i = 0; i < firstSize; ++i) {
        heap_insert(buff,firstArray, i, data[i]);
    }
    for (int i = 0; i < firstSize; ++i) {
        data[firstSize-1-i] = buff[1];
        heap_pop(buff,firstArray, firstSize - i);
    }
    delete [] buff;
}
    /*void sorting(int* firstArray, int* secondArray, int sizeFirst)
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
}*/

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

    
    
