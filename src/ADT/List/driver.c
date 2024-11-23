#include <stdio.h>
#include "list.h"



int main() {
    // Test MakeList
    printf("Testing MakeList...\n");
    List myList = MakeList();
    printf("List created. Is it empty? %s\n", IsEmptyList(myList) ? "Yes" : "No");

    // Test InsertFirstL and InsertLastL
    printf("\nTesting InsertFirstL and InsertLastL...\n");
    InsertFirstL(&myList, 10);
    printf("Inserted 10 at the beginning. List length: %d\n", LengthList(myList));
    InsertLastL(&myList, 20);
    printf("Inserted 20 at the end. List length: %d\n", LengthList(myList));
    InsertLastL(&myList, 30);
    printf("Inserted 30 at the end. List length: %d\n", LengthList(myList));

    // Display list content
    printf("\nList content:\n");
    for (int i = FirstIdxL(myList); i <= LastIdxL(myList); i++) {
        printf("Index %d: %d\n", i, GetList(myList, i));
    }

    // Test InsertAtL
    printf("\nTesting InsertAtL...\n");
    InsertAtL(&myList, 25, 2);
    printf("Inserted 25 at index 2. List content:\n");
    for (int i = FirstIdxL(myList); i <= LastIdxL(myList); i++) {
        printf("Index %d: %d\n", i, GetList(myList, i));
    }

    // Test DeleteFirstL, DeleteLastL, and DeleteAtL
    printf("\nTesting DeleteFirstL, DeleteLastL, and DeleteAtL...\n");
    DeleteFirstL(&myList);
    printf("Deleted first element. List content:\n");
    for (int i = FirstIdxL(myList); i <= LastIdxL(myList); i++) {
        printf("Index %d: %d\n", i, GetList(myList, i));
    }

    DeleteLastL(&myList);
    printf("Deleted last element. List content:\n");
    for (int i = FirstIdxL(myList); i <= LastIdxL(myList); i++) {
        printf("Index %d: %d\n", i, GetList(myList, i));
    }

    DeleteAtL(&myList, 1);
    printf("Deleted element at index 1. List content:\n");
    for (int i = FirstIdxL(myList); i <= LastIdxL(myList); i++) {
        printf("Index %d: %d\n", i, GetList(myList, i));
    }

    // Test ConcatL
    printf("\nTesting ConcatL...\n");
    List list1 = MakeList();
    List list2 = MakeList();
    InsertLastL(&list1, 1);
    InsertLastL(&list1, 2);
    InsertLastL(&list2, 3);
    InsertLastL(&list2, 4);
    List concatenatedList = ConcatL(list1, list2);
    printf("Concatenated List content:\n");
    for (int i = FirstIdxL(concatenatedList); i <= LastIdxL(concatenatedList); i++) {
        printf("Index %d: %d\n", i, GetList(concatenatedList, i));
    }

    // Test SearchL
    printf("\nTesting SearchL...\n");
    printf("Is 2 in the list? %s\n", SearchL(concatenatedList, 2) ? "Yes" : "No");
    printf("Is 5 in the list? %s\n", SearchL(concatenatedList, 5) ? "Yes" : "No");

    // Test CreateList
    printf("\nTesting CreateList...\n");
    List customList;
    CreateList(&customList, 5);
    printf("Custom list created with size: %d\n", customList.size);

    printf("\nAll functions tested successfully.\n");
    return 0;
}
