#ifndef QANTRI_H
#define QANTRI_H

#include <iostream>
using namespace std;

#define MAX 5
#define NIL -1

typedef int infotype;
struct queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmptyQueue(queue Q);
bool isFullQueue(queue Q);
void enqueue(queue &Q, infotype x);
infotype dequeue(queue &Q);
void printInfo(queue Q);

#endif