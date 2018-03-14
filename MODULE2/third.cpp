/*На числовой прямой окрасили  N  отрезков. Известны координаты левого и правого концов каждого отрезка ( L i  и  R i)  . Найти сумму длин частей числовой прямой, окрашенных ровно в один слой.*/

/*
#include <iostream>
#include <assert.h>
using std::cin;
using std::cout;


struct LinePoint {
    int line=0;
    int flag=0;
    bool operator<(const LinePoint& pole) {
        return this->line < pole.line;
    }
    
    bool operator>=(const LinePoint& pole) {
        return this->line >= pole.line;
    }
};

template <class T>

void HeapPop(T*a, int n) {
    std::swap(a[n],a[1]);
    for (int i = 1; 2*i < n;) {
        i *= 2;
        if (i+1 < n && a[i] < a[i+1]) {
            i += 1;
        }
        if (a[i/2] < a[i]) {
            std::swap(a[i/2], a[i]);
        }
    } }

template <class T>
void HeapMake(T *a, int n) {
    for (int i = n/2; i >= 1; --i) {
        for (int j = i; j <= n/2;) {
            int k = j*2;
            if (k+1 <= n and a[k] < a[k+1]) {
                ++k; }
            if (a[j] < a[k]) {
                std::swap(a[k],a[j]);
                j = k;
            } else {
                break;
            }
        }
    }
}

template <class T>
void heapSortFast(T *data, int n) {
    HeapMake(data - 1, n);
    for (int i = 0; i < n; ++i) {
        HeapPop(data - 1, n - i);
    }
}

int sercher (LinePoint*a,int n)
{
    int result=0;
    int counter=0;
    int j=0;
    for (int i=0;i!=n;++i)
    {
        result +=a[i].flag;

     if (result==1)
     {
         j=a[i].line;
     }
     else {
         counter+=a[i].line-j;
}
    }
    return counter;
}

int main (){
    int n=0;
    cin>>n;
    assert(n>0);
    n*=2;
    LinePoint *ArrayObject=new LinePoint [n];
    for (int i=0;i!=n;++i)
    {
        cin>>ArrayObject[i].line;
        if (i%2==0  ){
            ArrayObject[i].flag=1;
        }
        else
        ArrayObject[i].flag=-1;
    }
    heapSortFast(ArrayObject, n);
    cout<<sercher(ArrayObject,n)<<std::endl;
        delete []ArrayObject;

    return 0;
}
*/

/*

#include <iostream>
#include <assert.h>
using std::cin;
using std::cout;


struct LinePoint {
    int line=0;
    int flag=0;
    bool operator<(const LinePoint& pole) {
        return this->line < pole.line;
    }
    
    bool operator>=(const LinePoint& pole) {
        return this->line >= pole.line;
    }
};

bool compare (const LinePoint& pole,const LinePoint& pole2) {
    return pole2.line < pole.line;
}




template <class T>

void HeapPop(T*a, int n,int begin) {
    std::swap(a[n],a[1]);
    for (int i = 1; 2*i < n;) {
        i *= 2;
        if (i+1 < n && a[i] < a[i+1]) {
            i += 1;
        }
        if (a[i/2] < a[i]) {
            std::swap(a[i/2], a[i]);
        }
    } }

template <class T>
void HeapMake(T *a, int n,int begin,bool (* compareFunction)( const T&, const T& )) {
    for (int i = n/2; i >= 1; --i) {
        for (int j = i; j <= n/2;) {
            int k = j*2;
            if (k+1 <= n && compareFunction(a[k] , a[k+1])) {
                ++k; }
            if (a[j] < a[k]) {
                std::swap(a[k],a[j]);
                j = k;
            } else {
                break;
            }
        }
    }
}

template <class T>
void heapSortFast(T *data, int n,int begin) {
    HeapMake(data - 1, n,0,compare);
    for (int i = 0; i < n; ++i) {
        HeapPop(data - 1, n - i,0);
    }
}

int sercher (LinePoint*a,int n)
{
    int result=0;
    int counter=0;
    int j=0;
    for (int i=0;i!=n;++i)
    {
        result +=a[i].flag;
        
        if (result==1)
        {
            j=a[i].line;
        }
        else {
            counter+=a[i].line-j;
        }
    }
    return counter;
}

int main (){
    int n=0;
    cin>>n;
    assert(n>0);
    n*=2;
    LinePoint *ArrayObject=new LinePoint [n];
    for (int i=0;i!=n;++i)
    {
        cin>>ArrayObject[i].line;
        if (i%2==0  ){
            ArrayObject[i].flag=1;
        }
        else
            ArrayObject[i].flag=-1;
    }
  
    heapSortFast(ArrayObject, n,0);
 
    cout<<sercher(ArrayObject,n)<<std::endl;
    delete []ArrayObject;
    
    return 0;
}
*/

#include <iostream>
#include <assert.h>
using std::cin;
using std::cout;


struct LinePoint {
    int line=0;
    int point=1;
    
    bool operator<(const LinePoint& pole) {
        return this->line < pole.line;
    }
    
    bool operator>=(const LinePoint& pole) {
        return this->line >= pole.line;
    }
    
    bool operator>(const LinePoint& pole) {
        return this->line < pole.line;
    }
    
    bool operator<=(const LinePoint& pole) {
        return this->line >= pole.line;
    }

   LinePoint &operator=(const LinePoint &pole) {
       
            line= pole.line;
       return *this;
   }

    
};

template <class T>

void HeapPop(T*a, int n) {
    std::swap(a[n],a[1]);
    for (int i = 1; 2*i < n;) {
        i *= 2;
        if (i+1 < n && a[i] < a[i+1]) {
            i += 1;
        }
        if (a[i/2] < a[i]) {
            std::swap(a[i/2], a[i]);
        }
    } }

template <class T>
void HeapMake(T *a, int n) {
    for (int i = n/2; i >= 1; --i) {
        for (int j = i; j <= n/2;) {
            int k = j*2;
            if (k+1 <= n and a[k] < a[k+1]) {
                ++k; }
            if (a[j] < a[k]) {
                std::swap(a[k],a[j]);
                j = k;
            } else {
                break;
            }
        }
    }
}

template <class T>
void heapSortFast(T *data, int n) {
    HeapMake(data - 1, n);
    for (int i = 0; i < n; ++i) {
        HeapPop(data - 1, n - i);
    }
}

template <class T>

T Heap_Extract(T *a, int &n,int &buffer) {
    
    buffer=a[n-1].line;
    //cout<<buffer<<std::endl;
    // ПРОВЕКА ПУСТОТЫ
    T max_element = a[n];
    
   
   a[n] = a[n - 1];
    --n;
   // HeapMake(a,  n) ;
    heapSortFast(a, n);
    return max_element;
}


template <class T>
void heapInsert(T *a, int &n,  int x)
{
    //a[n+1].line=x;
   ++n;
    a[n].line = x;
    /* cout<<a[n+1].line<<std::endl;
    for (int i = n+1; i > 1;) {
        if (a[i] > a[i/2]) {
            std::swap(a[i], a[i/2]);
            i = i/2;
        }
        else {
            break;
        }
    }*/
   heapSortFast(a, n);
    //HeapMake(a, n);
}

template <class T>
void sercher (T*a,int n,int k)
{
    int buffer=0;
  //T b=Heap_Extract(a, n);
    int compare=0;
    int copySize=n;
   // cout<<n;
 //  cout<<buffer<<std::endl;
    int counter=0;
  //  {
    while (copySize!=0){
        Heap_Extract(a, n,buffer);

        if (buffer%2==0)
        {
            
        }
        if (buffer==1)
        {
          // j=a[i].line;
          //  cout<<"dsds";
            while (true){
                compare+=buffer;
                if (compare==k){
                    ++counter;
                    break;
                }
                Heap_Extract(a, copySize, buffer);
               // cout<<copySize<<" ";

              // cout<<compare;
        }
            buffer=0;
            compare=0;

           
        }
       
       // else {
         //   counter+=a[i].line-j;
        //}
    //}
    //return counter;
    }
cout<< counter;
}

int main (){
    int n=0,k=0;
    cin>>n;
    assert(n>0);
    
    LinePoint *ArrayObject=new LinePoint [n];//n+1 для теста только так как вершина будет сначала удаляться ,а потом добовляться
    for (int i=0;i!=n;++i)
    {
        cin>>ArrayObject[i].line;
    }
    cin>>k;
    heapSortFast(ArrayObject, n);
    
    // for (int i=0;i!=n;++i)
      //  cout<<ArrayObject[i].line<<std::endl;

  //  cout<< Heap_Extract(ArrayObject, n)<<std::endl;
  //  Heap_Extract(ArrayObject, n,n);
    //Heap_Extract(ArrayObject, n,n);

 // heapInsert(ArrayObject, n, 555);
 //   cout<<n;
    
//heapInsert(ArrayObject, n, x);
  //  cout<<n;
    sercher(ArrayObject, n,k);
    //for (int i=0;i!=n;++i)
//cout<<ArrayObject[i].line<<std::endl;

    delete []ArrayObject;
    
    return 0;
}



/*

#include <iostream>
#include <assert.h>
using std::cin;
using std::cout;

//template <class T>
class LinePoint {
public:

    int *array;
};

template <class T>

void HeapPop(T a, int n) {
    std::swap(a.array[n],a.array[1]);
    for (int i = 1; 2*i < n;) {
        i *= 2;
        if (i+1 < n && a.array[i] < a.array[i+1]) {
            i += 1;
        }
        if (a.array[i/2] < a.array[i]) {
            std::swap(a.array[i/2], a.array[i]);
        }
    } }
template <class T>

void HeapMake(T a, int n) {
    for (int i = n/2; i >= 1; --i) {
        for (int j = i; j <= n/2;) {
            int k = j*2;
            if (k+1 <= n and a.array[k] < a.array[k+1]) {
                ++k; }
            if (a.array[j] < a.array[k]) {
                std::swap(a.array[k],a.array[j]);
                j = k;
            } else {
                break;
            }
        }
    }
}
template <class T>

void heapSortFast(T data, int n) {
    HeapMake(data - 1, n);
    for (int i = 0; i < n; ++i) {
        HeapPop(data - 1, n - i);
    }
}


int Heap_Extract(LinePoint a, int &n) {
    
    // ПРОВЕКА ПУСТОТЫ
    int max_element = a.array[0];
    a.array[0] = a.array[n - 1];
    --n;
    // HeapMake(a,  n) ;
    heapSortFast(a, n);
    return max_element;
}


void heapInsert(LinePoint *a, int &n, size_t x)
{
    
    a->array[n+1] = x;
    for (int i = n+1; i > 1;) {
        if (a->array[i] > a->array[i/2]) {
            std::swap(a[i], a[i/2]);
            i = i/2;
        }
        else {
            break;
        }
    }
}



int main (){
    int n=0;
    cin>>n;
    assert(n>0);
  
    LinePoint ArrayObject;
    ArrayObject.array=new int[n];
    for (int i=0;i!=n;++i)
    {
        cin>>ArrayObject.array[i];
        
    }
  //  heapSortFast(ArrayObject, n);
    
    for (int i=0;i!=n;++i)
        cout<<ArrayObject.array[i]<<std::endl;
    
    //  cout<< Heap_Extract(ArrayObject, n)<<std::endl;
    //heapInsert(ArrayObject, n, 4444);
    Heap_Extract(&ArrayObject, n);
    size_t x=1222;
//heapInsert(&ArrayObject, n, x);
    for (int i=0;i!=n;++i)
        cout<<ArrayObject.array[i]<<std::endl;
    //  cout<<n<<std::endl;
    //   cout<<sercher(ArrayObject,n)<<std::endl;
 
    
    return 0;
}
*/






