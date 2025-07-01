class Node {
public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        Node* p = head;
        for(int i=0;i<index;i++){
            if(!p){
                return -1;
            }
            p = p->next;
        }
        return p ? p->val : -1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(!head){
            head = newNode;
            return;
        }

        Node* p = head;
        while(p->next){
            p = p->next;
        }
        p->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        Node* newNode = new Node(val);

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* p = head;
        for(int i=0;i<index-1;i++){
            if(!p)  return;
            p = p->next;
        }

        if(!p)  return;

        newNode->next = p->next;
        p->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        if (!head) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* p = head;
        for (int i = 0; i < index - 1; i++) {
            if (!p || !p->next) return;
            p = p->next;
        }

        if (!p->next) return;

        Node* temp = p->next;
        p->next = p->next->next;
        delete temp;
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