#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkList() {
        head = tail = NULL;
        size = 0;
    }

    void InsertAtEnd(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void InsertAtHead(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void InsertAtIdx(int val, int idx) {
        if (idx > size || idx < 0) {
            cout << "Invalid index." << endl;
            return;
        }
        if (idx == 0) {
            InsertAtHead(val);
        } else if (idx == size) {
            InsertAtEnd(val);
        } else {
            Node* new_node = new Node(val);
            Node* ptr = head;
            for (int i = 0; i < idx - 1; i++) {
                ptr = ptr->next;
            }
            new_node->next = ptr->next;
            ptr->next = new_node;
            size++;
        }
    }

    void DeleteAtHead() {
        if (size == 0) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (size == 0) {
            tail = NULL;
        }
    }

    void DeleteAtTail() {
        if (size == 0) {
            cout << "List is empty." << endl;
            return;
        }
        if (size == 1) {
            delete head;
            head = tail = NULL;
        } else {
            Node* ptr = head;
            while (ptr->next != tail) {
                ptr = ptr->next;
            }
            delete tail;
            tail = ptr;
            tail->next = NULL;
        }
        size--;
    }

    void DeleteAtIdx(int idx) {
        if (idx >= size || idx < 0) {
            cout << "Invalid index." << endl;
            return;
        }
        if (idx == 0) {
            DeleteAtHead();
        } else if (idx == size - 1) {
            DeleteAtTail();
        } else {
            Node* ptr = head;
            for (int i = 0; i < idx - 1; i++) {
                ptr = ptr->next;
            }
            Node* temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
            size--;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkList LL;
    LL.InsertAtEnd(10);
    LL.InsertAtEnd(20);
    LL.InsertAtEnd(30);
    LL.InsertAtEnd(40);
    LL.InsertAtHead(7);
    LL.display(); // Output: 7 10 20 30 40
    LL.InsertAtIdx(50, 0);
    LL.display(); // Output: 50 7 10 20 30 40
    LL.DeleteAtHead();
    LL.display(); // Output: 7 10 20 30 40
    LL.DeleteAtTail();
    LL.display(); // Output: 7 10 20 30
    LL.DeleteAtIdx(0);
    LL.display(); // Output: 10 20 30
    return 0;
}
