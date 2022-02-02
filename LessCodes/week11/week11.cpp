// week11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
#include "avl.h"

//using namespace std;

int main()
{
    AVL avl;

    cout << "Adding 50" << endl;
    avl.add(50);
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //             [50]

    cout << "Adding 40" << endl;
    avl.add(40);
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //             [50]
    //        [40]

    cout << "Adding 30" << endl;
    avl.add(30);  // LL imbalanced. Pivot 50
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //             [40]
    //        [30]      [50]

    cout << "Adding 60" << endl;
    avl.add(60);
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //             [40]
    //        [30]      [50]
    //                       [60]

    cout << "Adding 70" << endl;
    avl.add(70); // RR imbalanced. Pivot 50
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //             [40]
    //        [30]      [60]
    //              [50]     [70]

    cout << "Adding 55" << endl;
    avl.add(55); // RL imbalanced. Pivot 40
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //             [50]
    //        [40]      [60]
    //   [30]       [55]     [70]

    cout << "Adding 52" << endl;
    avl.add(52); 
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //             [50]
    //        [40]      [60]
    //   [30]       [55]     [70]
    //          [52]

    cout << "Adding 56" << endl;
    avl.add(56);
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //             [50]
    //        [40]      [60]
    //   [30]       [55]     [70]
    //          [52]    [56]


    cout << "Adding 57" << endl;
    avl.add(57); // LR imbalance. Pivot 60
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //             [50]
    //        [40]      [56]
    //   [30]       [55]     [60]
    //          [52]    [57]      [70]

    //============================================================

    cout << "Removing 30" << endl;
    avl.remove(30); // LL imbalance. Pivot 50
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //               [56]
    //        [50]           [60]
    //   [40]     [55]   [57]     [70]
    //         [52]    


    cout << "Removing 57" << endl;
    avl.remove(57); 
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //               [56]
    //        [50]           [60]
    //   [40]     [55]           [70]
    //         [52]  

    cout << "Removing 60" << endl;
    avl.remove(60); // LR imbalance. Pivot 60
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //               [55]
    //        [50]           [56]
    //   [40]     [52]           [70]


    cout << "Removing 55" << endl;
    avl.remove(55); 
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //               [52]
    //        [50]           [56]
    //   [40]                     [70]

    cout << "Removing 50" << endl;
    avl.remove(50);
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //               [52]
    //        [40]           [56]
    //                            [70]


    cout << "Removing 40" << endl;
    avl.remove(40); // RR imbalance. Pivot 52
    avl.printLevelByLevel();
    avl.print();
    printf("-----------------------------------------\n");
    // Tree looks like
    //               [56]
    //        [52]           [70]                          




    printf("\n");
    system("pause");
    return 0;
}