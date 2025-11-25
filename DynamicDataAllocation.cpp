
#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class DynamicMemoryAllocation {
private:
    Node* Head;

public:
    DynamicMemoryAllocation() {
        Head = nullptr;
    }

    void append(int data) {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        if (Head == nullptr) {
            Head = new_node;
            return;
        }

        Node* current = Head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new_node;
        cout << "Appended: " << data << endl;
    }

    void display() {
        if (Head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = Head;
        cout << "Linked List: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void insert_at_beginning(int data) {
        Node* new_node = new Node;
        new_node->data = data;
        
        new_node->next = Head;
        
        Head = new_node;
        
        cout << "Inserted at beginning: " << data << endl;
    }

    bool Search(int key) {
        Node* current = Head;
        int position = 1;

        while (current != nullptr) {
            if (current->data == key) {
                cout << "Found " << key << " at position " << position << "." << endl;
                return true;
            }
            current = current->next;
            position++;
        }
        cout << "Search failed: " << key << " not found." << endl;
        return false;
    }

    void Delete_node(int key) {
        if (Head == nullptr) {
            cout << "Deletion failed: List is empty." << endl;
            return;
        }

        Node* current = Head;
        Node* prev = nullptr;

        if (current != nullptr && current->data == key) {
            Head = current->next;
            delete current;
            cout << "Deleted (Head): " << key << endl;
            return;
        }

        while (current != nullptr && current->data != key) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Deletion failed: " << key << " not found." << endl;
            return;
        }

        prev->next = current->next;

        delete current;
        cout << "Deleted: " << key << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = Head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next; 
            current->next = prev;   
            prev = current;         
            current = next;         
        }
        Head = prev;
        cout << "List has been reversed." << endl;
    }
    
    ~DynamicMemoryAllocation() {
        Node* current = Head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        Head = nullptr;
    }
};

int main() {
    cout << "--- Project 3: Dynamic Data Allocation (Linked List) ---" << endl;
    
    DynamicMemoryAllocation list;

    cout << "\n--- 1. Basic Implementation (append & display) ---" << endl;
    list.append(10);
    list.append(20);
    list.append(30);
    list.display();

    cout << "\n--- 2. Insert at Beginning & Search ---" << endl;
    list.insert_at_beginning(5);
    list.display();
    list.Search(20);
    list.Search(99);

    cout << "\n--- 3. Deletion of a Node ---" << endl;
    list.Delete_node(5);
    list.display();
    list.Delete_node(20);
    list.display();
    list.Delete_node(10);
    list.display();
    list.Delete_node(30);
    list.display();
    list.Delete_node(50);
    
    list.append(100);
    list.append(200);
    list.append(300);
    list.display();

    cout << "\n--- 4. Reversing the Linked List ---" << endl;
    list.reverse();
    list.display();
    
    cout << "\n--- CRUD Operations Complete ---" << endl;

    return 0;
} 
