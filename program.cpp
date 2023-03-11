#include <iostream>
#include <string>
#include "LinkedList.h"

int main() {
    LinkedList myList;
    int choice;

    do {
        std::cout << "\nLinked List Menu\n"
                  << "1. Add element to the end\n"
                  << "2. Add element to the beginning\n"
                  << "3. Remove element from list\n"
                  << "4. Copy first element to end\n"
                  << "5. Display list\n"
                  << "6. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter value to add to end of list: ";
                std::cin >> value;
                myList.addLast(value);
                std::cout << "Value added to end of list.\n";
                break;
            }
            case 2: {
                int value;
                std::cout << "Enter value to add to beginning of list: ";
                std::cin >> value;
                myList.addFirst(value);
                std::cout << "Value added to beginning of list.\n";
                break;
            }
            case 3: {
                int value;
                std::cout << "Enter value to remove from list: ";
                std::cin >> value;
                if (myList.remove(value)) {
                    std::cout << "Value removed from list.\n";
                } else {
                    std::cout << "Value not found in list.\n";
                }
                break;
            }
            case 4: {
                myList.copyFirstToLast();
                std::cout << "First element copied to end of list.\n";
                break;
            }
            case 5: {
                std::cout << "List contents:\n";
                myList.printList();
                break;
            }
            case 6: {
                std::cout << "Exiting...\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
//its program