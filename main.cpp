#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

struct DLL {
    Node* head = NULL;

    void InsertAtHead(int d);
    void InsertAtEnd(int d);
    void InsertAtAnyposition(int d, int position);
    void DeleteHead();
    void DeleteTail();
    void DeleteAnyPosition(int position);
    int MaximumValue();
    int MinimumValue();
    void SearchItem(int value);
    void print();
};

void DLL::print() {
    if (head == NULL) {
        cout << "List is empty";
    }
    else {
        Node* h = head;
        while (h != NULL) {
            cout << h->data << " ";
            h = h->next;
        }
    }
    cout<<endl;
}

void DLL::InsertAtHead(int d) {
    Node* n = new Node(d);
    if (head == NULL) {
        head = n;
    } else {
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void DLL::InsertAtEnd(int d) {
    Node* n = new Node(d);
    if (head == NULL) {
        head = n;
    } else {
        Node* h = head;
        while (h->next != NULL) {
            h = h->next;
        }
        h->next = n;
        n->prev = h;
    }
}

void DLL::InsertAtAnyposition(int d, int position) {
    Node* n = new Node(d);
    if (position == 1) {
        n->next = head;
        if (head != NULL) head->prev = n;
        head = n;
    } else {
        Node* h = head;
        for (int i = 1; i <= position - 2; i++) {
            h = h->next;
        }
        n->next = h->next;
        if (h->next != NULL) h->next->prev = n;
        h->next = n;
        n->prev = h;
    }
}

void DLL::DeleteHead() {
    if (head == NULL) {
        cout << "The List Is Empty";
    } else {
        Node* h = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete h;
    }
}

void DLL::DeleteTail() {
    if (head == NULL) {
        cout << "The List is empty";
    } else if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* h = head;
        while (h->next != NULL) {
            h = h->next;
        }
        h->prev->next = NULL;
        delete h;
    }
}

void DLL::DeleteAnyPosition(int position) {
    if (head == NULL) {
        cout << "List is empty";
    } else if (position == 1) {
        Node* h = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete h;
    } else {
        Node* h = head;
        for (int i = 1; i <= position - 2; i++) {
            h = h->next;
        }
        Node* g = h->next;
        if (g->next != NULL) g->next->prev = h;
        h->next = g->next;
        delete g;
    }
}

int DLL::MaximumValue() {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return -1;
    }

    Node* h = head;
    int maxvalue = head->data;
    while (h != NULL) {
        if (h->data > maxvalue) {
            maxvalue = h->data;
        }
        h = h->next;
    }
    cout << "Max Value: " << maxvalue << endl;
    return maxvalue;
}

int DLL::MinimumValue() {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return -1;
    }

    Node* h = head;
    int minvalue = head->data;
    while (h != NULL) {
        if (h->data < minvalue) {
            minvalue = h->data;
        }
        h = h->next;
    }
    cout << "Min Value: " << minvalue << endl;
    return minvalue;
}

void DLL::SearchItem(int value) {
    Node* h = head;
    int position = 1;
    while (h != NULL) {
        if (h->data == value) {
            cout << "Value " << value << " found at position " << position << endl;
            return;
        }
        h = h->next;
        position++;
    }
    cout << "Value " << value << " not found in the list" << endl;
}

int main() {
    DLL lists;
    lists.InsertAtHead(10);
    lists.InsertAtHead(11);
    lists.InsertAtHead(12);
    lists.InsertAtHead(13);
    lists.InsertAtHead(14);
    lists.InsertAtEnd(599);
    lists.InsertAtAnyposition(333, 2);
    lists.DeleteHead();
    lists.DeleteTail();
    lists.DeleteAnyPosition(3);
    lists.MaximumValue();
    lists.MinimumValue();
    lists.SearchItem(599);

    cout << "Linked List :" << " ";
    lists.print();

    return 0;
}
