/*LSD для long long.
Дан массив неотрицательных целых 64-битных чисел. Количество чисел не больше 106   . Отсортировать массив методом поразряднй сортировки LSD по байтам.
*/


#include <iostream>
#include <assert.h>
using namespace std;


void output(long*array,long*bufferArray,int n);
long digit (long *number,long numberByte );
void countSort(long sortArray[],long *array,int i,int n);
int main() {
    int n=0;
    cin>>n;
    assert(n>0);
    long *array=new long [n];
    long *bufferArray=new long [n];
    for (int i=0;i!=n;++i){
        cin>>array[i];
    }
   /*
    for (int i=0;i!=8;++i){
        long sortArray[256]={};

        countSort(sortArray,array,i,n);
        for(int j = n-1; j >-1;j--)
        {
            bufferArray[--sortArray[digit(&array[j],i)]] = array[j];
        }
        for(int j = 0; j < n; j++)
        {
            array[j] = bufferArray[j];
        }
    }
*/
    output(array,bufferArray, n);
    for(int i = 0; i < n; i++)
    {
        cout << array[i]<<endl;
    }
    delete[]array;
   delete[]bufferArray;
    return 0;
}


long digit (long *number,long numberByte ){
    
    return (*number>>(8 * numberByte) & 255);
}


void output(long*array,long*bufferArray,int n){
    for (int i=0;i!=8;++i){
        long sortArray[256]={};
        
        countSort(sortArray,array,i,n);
        for(int j = n-1; j >-1;j--)
        {
            bufferArray[--sortArray[digit(&array[j],i)]] = array[j];
        }
        for(int j = 0; j < n; j++)
        {
            array[j] = bufferArray[j];
        }
    }
}

void countSort(long sortArray[],long *array,int i,int n){

    for(int j = 0; j < n; j++)
    {
        sortArray[digit(&array[j],i)]++;
    }
  
    for(int j = 1; j < 256;j++)
    {
        sortArray[j]+=sortArray[j-1];
    }
}







