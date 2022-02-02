// week7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "array_queue.h"
//#include "list_queue.h" 
//#include <queue>
#include <deque>

using namespace std;

int main()
{
#if  0// Integer Test
    Queue<int> myQueue;

    printf("Adding 1 to the queue\n");
    myQueue.Enqueue(1);

    printf("Adding  3 to the queue\n");
    myQueue.Enqueue(3);

    printf("Adding 5 to the queue\n");
    myQueue.Enqueue(5);

    printf("# of elements on the queue: %d\n", myQueue.Size());
    cout << "First element on the queue: " << myQueue.Front() << endl;
    cout << "Taking the first element from the queue: " << myQueue.Dequeue() << endl;
    printf("Is queue empty?: %d\n", myQueue.IsEmpty());
    cout << "Taking the first element from the queue: " << myQueue.Dequeue() << endl;
    cout << "Taking the first element from the queue: " << myQueue.Dequeue() << endl;
    printf("Is queue empty ? : % d\n", myQueue.IsEmpty());
    printf("# of elements on the queue: %d\n", myQueue.Size());
#endif

#if 0// String Test
    Queue<string> myQueue;

    printf("Adding Omer to the queue\n");
    myQueue.Enqueue("Omer");

    printf("Adding  Ali to the queue\n");
    myQueue.Enqueue("Ali");

    printf("Adding Fatma to the queue\n");
    myQueue.Enqueue("Fatma");

    printf("# of elements on the queue: %d\n", myQueue.Size());
    cout << "First element on the queue: " << myQueue.Front() << endl;
    cout << "Taking the first element from the queue: " << myQueue.Dequeue() << endl;
    printf("Is queue empty?: %d\n", myQueue.IsEmpty());
    cout << "Taking the first element from the queue: " << myQueue.Dequeue() << endl;
    cout << "Taking the first element from the queue: " << myQueue.Dequeue() << endl;
    printf("Is queue empty ? : % d\n", myQueue.IsEmpty());
    printf("# of elements on the queue: %d\n", myQueue.Size());
#endif

#if 0 // C++ Queue Implementation Integer test
    queue<int> myQueue;
    printf("C++ Queue Implementation !!!\n");
    printf("Adding 1 to the queue\n");
    myQueue.push(1);

    printf("Adding  3 to the queue\n");
    myQueue.push(3);

    printf("Adding 5 to the queue\n");
    myQueue.push(5);

    printf("# of elements on the queue: %d\n", myQueue.size());
    cout << "First element on the queue: " << myQueue.front() << endl;
    cout << "Taking the first element from the queue: " << myQueue.front() << endl;
    myQueue.pop();
    printf("Is queue empty?: %d\n", myQueue.empty());
    cout << "Taking the first element from the queue: " << myQueue.front() << endl;
    myQueue.pop();
    cout << "Taking the first element from the queue: " << myQueue.front() << endl;
    myQueue.pop();
    printf("Is queue empty ? : % d\n", myQueue.empty());
    printf("# of elements on the queue: %d\n", myQueue.size());
#endif

#if 1 // C++ Deque Implementation Integer test
    deque<int> myQueue;
    printf("C++ Deque Implementation !!!\n");
    printf("Adding 1 @ the end\n");
    myQueue.push_back(1);

    printf("Adding  3 @ the end\n");
    myQueue.push_back(3);

    printf("Adding 5 to the front\n");
    myQueue.push_front(5);

    printf("# of elements in the queue: %d\n", myQueue.size());
    cout << "First element in the queue: " << myQueue.front() << endl;
    cout << "Last element in the queue: " << myQueue.back() << endl;
    cout << "Taking the first element from the queue: " << myQueue.front() << endl;
    myQueue.pop_front();
    printf("Is queue empty?: %d\n", myQueue.empty());
    cout << "Taking the last element from the queue: " << myQueue.back() << endl;
    myQueue.pop_back();
    cout << "Taking the first element from the queue: " << myQueue.front() << endl;
    myQueue.pop_front();
    printf("Is queue empty ? : % d\n", myQueue.empty());
    printf("# of elements in the queue: %d\n", myQueue.size());
#endif

    printf("\n");
    system("pause");
    return 0;
}

