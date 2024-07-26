#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLinkList {
public:
    Node* head;
    Node* tail;
    int size;

    DLinkList() {
        head = tail = NULL;
        size = 0;
    }

    void InsertAtEnd(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
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
            head->prev = temp;  // Update the previous head's prev pointer
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
            ptr->next->prev = new_node;  // Update the next node's prev pointer
            ptr->next = new_node;
            new_node->prev = ptr;  // Update new node's prev pointer
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
        if (head != NULL) {
            head->prev = NULL;  // Update the new head's prev pointer
        }
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
            Node* ptr = tail->prev;
            ptr->next = NULL;
            delete tail;
            tail = ptr;
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
            temp->next->prev = ptr;  // Update the next node's prev pointer
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

    void rev_display(Node* tail) {
        while (tail) {
            cout << tail->val << " ";
            tail = tail->prev;
        }
        cout << endl;
    }
};

int main() {
    DLinkList list;
    list.InsertAtEnd(10);
    list.InsertAtEnd(20);
    list.InsertAtEnd(30);
    list.InsertAtHead(5);
    list.InsertAtIdx(25, 3);

    cout << "List: ";
    list.display();

    cout << "Reversed List: ";
    list.rev_display(list.tail);

    list.DeleteAtHead();
    list.DeleteAtTail();
    list.DeleteAtIdx(1);

    cout << "List after deletions: ";
    list.display();

    return 0;
}
