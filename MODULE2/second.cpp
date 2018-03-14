/*
 Вовочка ест фрукты из бабушкиной корзины. В корзине лежат фрукты разной массы. Вовочка может поднять не более K грамм. Каждый фрукт весит не более K грамм. За раз он выбирает несколько самых тяжелых фруктов, которые может поднять одновременно, откусывает от каждого половину и кладет огрызки обратно в корзину. Если фрукт весит нечетное число грамм, он откусывает большую половину. Фрукт массы 1гр он съедает полностью.
 Определить за сколько подходов Вовочка съест все фрукты в корзине.
 Формат входных данных.  Вначале вводится n - количество фруктов и n строк с массами фруктов. Затем K - "грузоподъемность".
 Формат выходных данных.  Неотрицательное число - количество подходов к корзине*/
/*
#include <iostream>
#include<assert.h>

using std::cin;
using std::cout;

template <class T>
class Heap {
private:
    T*array;
    int size;
    int count;

public:
    void Add(const T&element);
    Heap(int size);
    void searcher(int k);
    void Heapify(T i);
   T get ();
  //  ~Heap();
 T & operator  [](int i){ return array[i];}
    const T& operator [] (int i) const {return array[i];}
    void print();
};

template <class T>
Heap<T>::Heap(int size)
{
    count =0;
    array=new T[Heap::size=size];

};

template <class T>
 
 void Heap<T>::Add(const T&element )
 {
 assert (count<=size);
 int currentIndex=count;
 int parentIndex;
     array[currentIndex]=element;
     parentIndex=(currentIndex-1)/2;
     
 while (parentIndex>=0 && currentIndex>0)
 {
     if (array[currentIndex]>array[parentIndex])
     {
         std::swap(array[currentIndex],array[parentIndex]);
     }
 currentIndex=parentIndex;
     parentIndex=(currentIndex-1)/2;
 }
     count++;
 }


template <class T>
void Heap<T>::Heapify(T i)
{

    
        int left, right;
        left = 2*i+1;
        right = 2*i+2;
        if(left < count) {
            if(array[i] < array[left]) {
                std::swap(array[left],array[i]);
                Heapify(left);
            }
        }
        if(right < count) {
            if(array[i] < array[right]) {
                std::swap(array[right],array[i]);
                Heapify(right);
            }
        }
    
}


template <class T>
void Heap<T>::searcher(int k)
{
    int counter=0;

while (count!=0)
{
    int i=0;

    int buffer=0;
   // if (array[i]<k &&count ==1){++counter; break;}
      while(1){
          
    buffer+=array[i];
         // cout<<i<<" " ;
  //  cout<<buffer<<" ";
          
          if ((buffer==k) &&(array[i]==1))
          {
            //  cout<<"workfirst";
         //cout<<count<<" ";

              while (i>0)
              {
                  get();
                  --i;
              }
              ++counter;

              break;
          }
        else if (count==1 &&array[i]==1)
          {

              ++counter;
              std::__1::cout<<counter;
              get();
              break;
          }
 
    if (buffer>k || array[0]==k) //если к =1
    {
//std::__1::cout<<buffer<<" ";

        if (array[0]%2==0)
        {
        int element=array[0]/2;
        get();
        Add(element);
        ++counter;
            break;
        }
        else
        {
         //   cout<<"worksecond";

            int element=1+(array[0]/2);
            get();
            Add(element);
            ++counter;
            break;
        }
        break;
        
    }
          
      
    if (buffer==k)
    {


        while (i!=0)
        {
            get();
            --i;
            
        }
          ++counter;
        break;
    }
          
          ++i;
}
}
    cout<<counter;

}
template <class T>
void Heap<T>::print()
{
    for (int i=0;i!= count;++i)
        cout<<array[i]<<" ";
}
template <class T>
T Heap<T>::get()
{
    T  peremen;
    peremen=array[0];
    array[0]=array[count-1];
    Heapify(0);
    --count;
    return peremen;
}


int main() {
    int n,k=0,masElement;
    cin>>n;
    assert(n>0);
    Heap<int>heap (n);

    while (n!=0){
        cin>>masElement;
        assert(masElement>0);
        heap.Add(masElement);
        --n;
    }
    cin>>k;
   //  heap.print();
   // cout<<std::endl;
    heap.searcher(k);
   //
    return 0;
}
*/




/*
struct Greedy {
    int*array;
   
    ~Greedy(){delete[]array;}
};



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

/*
template <class T>
void heapSortFast(T *data, int n,int begin) {
    HeapMake(data - 1, n,0,compare);
    for (int i = 0; i < n; ++i) {
        HeapPop(data - 1, n - i,0);
    }
}
*/
/*
int sercher (Greedy *a,int n)
{
    int result=0;
    int counter=0;
    int j=0;
    for (int i=0;i!=n;++i)
    {
        int counter=0;
        if (a->array[i]== 1){
        
        
        }
        
        if ()
        
        return counter;
}
    
    template <class T>

    void heapInsert(int *a, int n, int x)
    {
        a[n+1] = x;
        for (int i = n+1; i > 1;) {
            if (a[i] > a[i/2]) {
                swap(a[i], a[i/2]);
                i = i/2;
            } else {
                break;
            } }
    }

int main (){
    int n=0,k=0;
    cin>>n;
    assert(n>0);
    cin>>k;
    assert(k>0);

    for (int i=0;i!=n;++i)
    {
        cin>>ArrayObject[i].line;
            }
    heapSortFast(ArrayObject, n,0);
    cout<<sercher(ArrayObject,n)<<std::endl;
    delete []ArrayObject;
    
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <assert.h>

using std::cin;
using std::cout;
class heap
{
protected:
    std::vector<int> arr;
public:
    void SiftUp( int index );
    void SiftDown( int i );
    void BuildHeap( int n );
    bool arr_empty ();
};


class queue_priority : public heap
{
public:
    void InsertWithPriority ( int element );
    int PeekAtNext ();
    int GetMax ();
};

bool heap::arr_empty ()
{
    return !arr.empty();
}

void heap::SiftUp( int index )
{
    while( index > 0 ) {
        int parent = ( index - 1 ) / 2;
        if( arr[index] <= arr[parent] )
            return;
        std::swap( arr[index], arr[parent] );
        index = parent;
    }
}

void heap::SiftDown( int i )
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if( left < arr.size() && arr[left] > arr[i] )
        largest = left;
    if( right < arr.size() && arr[right] > arr[largest] )
        largest = right;
    if( largest != i ) {
        std::swap( arr[i], arr[largest] );
        SiftDown( largest );
    }
}

void heap::BuildHeap( int n )
{
    for ( int i = n / 2 - 1; i >= 0; --i) {
        SiftDown( i );
    }
}

void queue_priority::InsertWithPriority ( int element )
{
    arr.emplace_back(element);
    SiftUp( arr.size() - 1 );
}

int queue_priority::PeekAtNext ()
{
    return arr[0];
}

int queue_priority::GetMax ()
{
    int max = arr[0];
    std::swap(arr[0], arr[arr.size() - 1]);
    arr.pop_back();
    SiftDown ( 0 );
    return max;
}


int work ( queue_priority queue_p, int k )
{
    int answer = 0;
    if (queue_p.PeekAtNext() > k) {
        return answer;
    }
    std::vector<int> arr_apple;
    while (queue_p.arr_empty()) {
        int weight = 0;
        while (weight + queue_p.PeekAtNext() <= k && queue_p.arr_empty()) {
            arr_apple.push_back(queue_p.GetMax());
            weight += arr_apple[arr_apple.size() - 1];
        }
        answer++;
        while (!arr_apple.empty()) {
            if (arr_apple[arr_apple.size() - 1] == 1) {
                arr_apple.pop_back();
            }
            else if (arr_apple[arr_apple.size() - 1] % 2 == 0) {
                queue_p.InsertWithPriority (arr_apple[arr_apple.size() - 1] / 2);
                arr_apple.pop_back();
            }
            else {
                int push = arr_apple[arr_apple.size() - 1] / 2;
                queue_p.InsertWithPriority (push);
                arr_apple.pop_back();
            }
        }
    }
    return answer;
}

int main()
{
    int n = 0;
    cin >> n;
    assert(n>0);
    queue_priority queue_p;
    
    int value;
    for (int i = 0; i < n; i++) {
       cin >> value;
        queue_p.InsertWithPriority (value);
    }
    
    int k = 0;
 cin >> k;
    
    //BuildHeap (arr, n);
    
    while (queue_p.PeekAtNext() > k){
        queue_p.GetMax();
    }
    
    int answer = work (queue_p, k);
    
  cout << answer;
    
    return 0;
}




