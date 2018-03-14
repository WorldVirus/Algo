//“Считалочка”. В круг выстроено N человек, пронумерованных числами от 1 до N. Будем исключать каждого k-ого до тех пор, пока не уцелеет только один человек. (Например, если N=10, k=3, то сначала умрет 3-й, потом 6-й, затем 9-й, затем 2-й, затем 7-й, потом 1-й, потом 8-й, за ним - 5-й, и потом 10-й. Таким образом, уцелеет 4-й.) Необходимо определить номер уцелевшего. N, k ≤ 10000.

#include <iostream>
#include <stdlib.h>
struct node
{ int item; node* next;
    node(int x, node* t)
    { item = x; next = t; }
};
typedef node *link;
int main(int argc, char *argv[])
{ int i, N = atoi(argv[1]), M = atoi(argv[2]);
    link t = new node(1, 0); t->next = t;
    link x = t;
    for (i = 2; i <= N; i++)
        x = (x->next = new node(i, t));
    while (x != x->next)
    { for (i = 1; i < M; i++) x = x->next;
        x->next = x->next->next;
    }
    std::cout << x->item ;
}
