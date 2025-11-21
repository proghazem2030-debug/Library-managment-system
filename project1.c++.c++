#include <iostream>
using namespace std;
class Book {
private:
    int id;
    string title;
    string author;
    int year;
    bool isAvailable = true;
public:
    // defult constructor
    Book () {
        
    }
    // Parameterized Constructor
    Book(int i, string t, string a, int y) {
        id = i;
        title = t;
        author = a;
        year = y;
        isAvailable = true;
    }
    void setValues(int i, string t, string a, int y) {
        id = i;
        title = t;
        author = a;
        year = y;
        isAvailable = true;
    }
    int getId() { 
        return id; 
    }
    string getTitle() { 
        return title; 
    }
    string getAuthor() { 
        return author; 
    }
    int getYear() { 
        return year; 
    }
    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Nice You Borrowed The Book" << endl;
        } 
        else {
            cout << "Book is borrowed" << endl;
        }
    }
    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "The Book Is Returned" << endl;
        } 
        else {
            cout << "The Book Is Not Borrowed" << endl;
        }
    }
    void printDetails() {
        cout << "Id = " << id << " "<< "The Title Is : " << title << " "<< "The Author Is : " << author << " "<< "Year = " << year << endl;
    }
};

struct node {
    Book data;
    node* next;
};
class Library {
private:
    node* head = NULL;
public:
    // Add book
    void insertBook(int id, string title, string author, int year) {
        node* newBook = new node;
        node *last;
        newBook->data.setValues(id, title, author, year);
        newBook->next = NULL;
        if (head == NULL) {
            head = newBook;
        } 
        else {
            last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newBook;
        }
    }
    // Display all books
    void display() {
        if (head == NULL) {
            cout << "The Library Is Empty\n";
            return;
        }
        node* current = head;
        while (current != NULL) {
            current->data.printDetails();
            current = current->next;
        }
    }
    // Delete book 
    void deleteBook(int key) {
        if (head == NULL) {
            return;
        }
        node* current = head;
        node* previous = NULL;
        if (current->data.getId() == key) {
            head = current->next;
            delete current;   
            return;
        }
        while (current != NULL && current->data.getId() != key) {
            previous = current;
            current = current->next;
        }
        if (current == NULL) {
            return ;
        }
        previous->next = current->next;
        delete current;   
    }
    // Sort by year using Selection Sort
    void sortBooks() {
        if (head == NULL || head->next == NULL) return;
        for (node* i = head; i->next != NULL; i = i->next) {
            for (node* j = i->next; j != NULL; j = j->next) {
                if (i->data.getYear() > j->data.getYear()) {
                    swap(i->data, j->data);
                }
            }
        }
    }
    // Search by Id
    void searchBook(int id) {
        node* current = head;
        while (current != NULL) {
            if (current->data.getId() == id) {
                cout <<"The Book Is Found : ";
                current->data.printDetails();
                return;
            }
            current = current->next;
        }
        cout << "This Book Not Found" << endl;
    }
    // Borrow Book
    void borrowBook(int id) {
        node* current = head;
        while (current != NULL) {
            if (current->data.getId() == id) {
                current->data.borrowBook();
                cout << "Book status updated successfully (Borrow).\n";
                return;
            }
            current = current->next;
        }
        cout << "Book Not Found\n";
    }
    // Return Book
    void returnBook(int id) {
        node* current = head;
        while (current != NULL) {
            if (current->data.getId() == id) {
                current->data.returnBook();
                cout << "Book status updated successfully (Return).\n";
                return;
            }
            current = current->next;
        }
        cout << "Book Not Found\n";
    }
};
int main() {
    Library l1;

    l1.insertBook(1, "loyalty", "hazem", 2020);
    l1.insertBook(2, "friendship", "ahmed", 2024);
    l1.insertBook(3, "programming", "mohammed", 2022);
    l1.insertBook(4, "logical", "sama", 2025);
    l1.display();

    l1.deleteBook(2);
    l1.display();

    l1.sortBooks();
    l1.display();

    l1.searchBook(2);
    l1.borrowBook(2);
    l1.returnBook(2);
    l1.deleteBook(3);
    l1.display();

    return 0;
}
