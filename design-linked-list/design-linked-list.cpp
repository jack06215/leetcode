struct Node {
    int val;
    Node* next;
    Node() : next(nullptr) {}
    Node(int val) : val(val), next(nullptr) {}
};

class MyLinkedList {
public:
    MyLinkedList() {
        this->head = new Node();
        this->size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* iter = this->head;
        index++;
        while (index--) {
            iter = iter->next;
        }
        return iter->val;
    }

    void addAtHead(int val) {
        Node* curr = this->head->next;
        this->head->next = new Node(val);
        this->head->next->next = curr;
        this->size++;
    }

    void addAtTail(int val) {
        Node* iter = this->head;
        while (iter->next) {
            iter = iter->next;
        }
        iter->next = new Node(val);
        this->size++;
    }

    void addAtIndex(int index, int val) {
        if (index > this->size) {
            return;
        }
        Node* newNode = this->head;
        while (index--) {
            newNode = newNode->next;
        }
        Node* tmp = newNode->next;
        newNode->next = new Node(val);
        newNode->next->next = tmp;
        this->size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        Node* curr = head;
        while (index--) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        --size;
        delete temp;
    }

    void print() {
        Node* curr = new Node();
        curr = head->next;
        while (curr != nullptr) {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << endl;
    }

private:
    Node* head;
    size_t size;
};