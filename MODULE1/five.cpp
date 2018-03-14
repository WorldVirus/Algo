/*Стековые анаграммы.
 Пара слов называется стековой анаграммой, если одно слово можно получить из другого, проведя последовательность стековых операций с его буквами (взять очередную букву исходного слова и поместить ее в стек; взять букву из стека и добавить ее в конец выходного слова).
 Для заданной пары слов требуется определить, можно ли выполнить последовательность стековых операций, переводящую первое слово во второе. Все буквы в слове различные.
 Длина анаграммы ≤ 10000.
 Формат входных данных.  Пара слов, являющихся анаграммой.
 Формат выходных данных.   YES , если последовательность стековых операций существует и  NO  в противном случае.*/

#include <assert.h>
#include <iostream>

using std::cin;
using std::cout;

bool compare(char* fisrt_word, char* second_word, int n);
class CStack {
public:
    explicit CStack(int array_Size);
    ~CStack();
    void push(char a);
    char pop();
    
private:
    char* buffer;
    int bufferSize;
    int top;
};

CStack::CStack(int array_Size)
: bufferSize(array_Size)
, top(-1)
{
    buffer = new char[bufferSize];
}
CStack::~CStack()
{
    delete[] buffer;
}

void CStack::push(char a)
{
    assert(top + 1 < bufferSize);
    buffer[++top] = a;
}
char CStack::pop()
{
    assert(top != -1);
    return buffer[top--];
}

int main()
{
    int m = 1, n = 1;
    char* first_word = new char[n];
    char* second_word = new char[m];
    char buffer;
    for ( int i = 0; (buffer = getchar()) != '\n'; ++i ) {
        first_word[i] = buffer;
        ++m;
    }
    
    for ( int i = 0; (buffer = getchar()) != '\n'; ++i ) {
        second_word[i] = buffer;
        ++n;
    }
    assert(n <= 10000 && m <= 10000);
    if (m != n) {
        cout << "NO";
        return 0;
    }
    
    if ( compare(first_word, second_word, n) ) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    delete []first_word;
    delete []second_word;
    return 0;
}

bool compare(char* fisrt_word, char* second_word, int n)
{
    CStack object(n);
    int count = -1;
    int* flag_array = new int[count + 1];
    
    for ( int i = 0; i != n; ++i )
    {
        if ( fisrt_word[i] != second_word[i] ) {
            object.push(fisrt_word[i]);
            flag_array[++count] = i;
        }
    }
    
    for ( int j = 0; j <= count; ++j )
    {
        int bufer_new = flag_array[j];
        if ( second_word[bufer_new] != object.pop() ) {
            return false;
        }
    }
    delete []flag_array;
    return true;
}
