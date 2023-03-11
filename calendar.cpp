#include <iostream>
#include <string>
using namespace std;

// Структура для представлення дати
struct Date {
    int day;
    int month;
    int year;
};

// Структура для представлення події в календарі
struct Event {
    string name;
    Date date;
};

// Вузол списку
struct Node {
    Event event;
    Node* next;
};

// Клас для роботи зі списком
class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }

    // Додавання події в календар
    void addEvent(Event event) {
        Node* newNode = new Node;
        newNode->event = event;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* currentNode = head;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    // Виведення всіх подій у заданий день
    void printEvents(Date date) {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            if (currentNode->event.date.day == date.day &&
                currentNode->event.date.month == date.month &&
                currentNode->event.date.year == date.year) {
                cout << currentNode->event.name << endl;
            }
            currentNode = currentNode->next;
        }
    }

    // Виведення всіх подій у календарі
    void printAllEvents() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->event.date.day << "/" << currentNode->event.date.month << "/" << currentNode->event.date.year << " - " << currentNode->event.name << endl;
            currentNode = currentNode->next;
        }
    }

private:
    Node* head;
};

// Функція для створення дати
Date createDate(int day, int month, int year) {
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

int main() {
    LinkedList calendar;

    // Додавання подій до календаря
    calendar.addEvent({"Meeting with client", createDate(15, 3, 2023)});
    calendar.addEvent({"Dentist appointment", createDate(18, 3, 2023)});
    calendar.addEvent({"Birthday party", createDate(20, 3, 2023)});
    calendar.addEvent({"Conference call", createDate(25, 3, 2023)});
    calendar.addEvent({"Project deadline", createDate(31, 3, 2023)});
    calendar.addEvent({"Shoping day",createDate(11,3,2023)});

    // Виведення всіх подій у календарі
    cout << "All events:" << endl;
    calendar.printAllEvents();

    // Виведення подій у заданий день
    cout << "Events on 18/03/2023:" << endl;
    calendar.printEvents(createDate(18, 3, 2023));

    return 0;
}
//its calendar