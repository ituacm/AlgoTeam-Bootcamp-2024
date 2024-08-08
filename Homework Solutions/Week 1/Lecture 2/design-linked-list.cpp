// Ali Kemal Coşkun
// Question Link: https://leetcode.com/problems/design-linked-list/

class Node {
private: // SUGGESTION: Make the members private
    int val;
    Node* next;

public:
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }

    int getVal() {
        return val;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* next) {
        this->next = next;
    }
};

class MyLinkedList {
private: // SUGGESTION: Make the members private
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = NULL;
        size = 0;
        
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->getNext();
        }
        return current->getVal();
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->setNext(head);
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        if (size == 0) {
            addAtHead(val);
            return;
        }
        Node* current = head;
        while (current->getNext() != NULL) {
            current = current->getNext();
        }
        Node* newNode = new Node(val);
        current->setNext(newNode);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->getNext();
        }
        Node* newNode = new Node(val);
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->getNext();
            delete temp;
            size--;
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->getNext();
        }
        Node* temp = current->getNext();
        current->setNext(temp->getNext());
        delete temp; // COMMON MISTAKE: Do not forget to free the memory
        size--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */