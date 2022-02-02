// week6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
// #include "Stack_array.h"
// #include "Stack_linklist.h"
#include <stack>

using namespace std;

int main()
{
#if 0 // Integer test
    Stack<int> myStack;

    printf("Pushing 1 to the stack\n");
    myStack.Push(1);

    printf("Pushing  3 to the stack\n");
    myStack.Push(3);

    printf("Pushing 5 to the stack\n");
    myStack.Push(5);

    printf("# of elements on the stack: %d\n", myStack.Size());
    cout << "Element on top of the stack: " << myStack.Top() << endl;
    cout << "Popping the element on top of the stack: " << myStack.Pop() << endl;
    printf("Is stack empty?: %d\n", myStack.IsEmpty());
    cout << "Popping the element on top of the stack: " << myStack.Pop() << endl;
    cout << "Popping the element on top of the stack: " << myStack.Pop() << endl;
    printf("Is stack empty?: %d\n", myStack.IsEmpty());
    printf("# of elements on the stack: %d\n", myStack.Size());

#endif

#if 0 // String test
    Stack<string> myStack;

    printf("Pushing Omer to the stack\n");
    myStack.Push("Omer");

    printf("Pushing  Ali to the stack\n");
    myStack.Push("Ali");

    printf("Pushing Fatma to the stack\n");
    myStack.Push("Fatma");

    printf("# of elements on the stack: %d\n", myStack.Size());
    cout << "Element on top of the stack: "<< myStack.Top()<<endl;
    cout << "Popping the element on top of the stack: "<< myStack.Pop() << endl;
    printf("Is stack empty?: %d\n", myStack.IsEmpty());
    cout << "Popping the element on top of the stack: "<< myStack.Pop() << endl;
    cout << "Popping the element on top of the stack: "<< myStack.Pop() << endl;
    printf("Is stack empty?: %d\n", myStack.IsEmpty());
    printf("# of elements on the stack: %d\n", myStack.Size());

#endif

#if 1 // C++ Stack Implementation Integer test
    // PAY ATTENTION TO TOP & POP USAGE
    stack<int> myStack;

    printf("Pushing 1 to the stack\n");
    myStack.push(1);

    printf("Pushing  3 to the stack\n");
    myStack.push(3);

    printf("Pushing 5 to the stack\n");
    myStack.push(5);

    printf("# of elements on the stack: %d\n", myStack.size());
    cout << "Element on top of the stack: " << myStack.top() << endl;
    cout << "Popping the element on top of the stack: " << myStack.top() << endl;
    myStack.pop();
    printf("Is stack empty?: %d\n", myStack.empty());
    cout << "Popping the element on top of the stack: " << myStack.top() << endl;
    myStack.pop();
    cout << "Popping the element on top of the stack: " << myStack.top() << endl;
    myStack.pop();
    printf("Is stack empty?: %d\n", myStack.empty());
    printf("# of elements on the stack: %d\n", myStack.size());

#endif

    printf("\n");
    system("pause");
    return 0;
}
