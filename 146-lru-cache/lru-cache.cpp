class LRUCache {
public:

//capacity - size
//get - returns value / -1 , put that key in front
//put - update value of key (cap == full - remove the least recently used key)
//hash map

//Global initialization
int n;

//Create Doubly Linked List

class Node {
    public:
    
    int key, value;
    Node* prev;
    Node* next;

    Node(int key, int value){
        this->key = key;
        this->value = value;
    }
};

unordered_map<int,Node*> mp; //key , node

Node* head = new Node(-1, -1);
Node* tail = new Node(-1, -1);

void addNode(Node* temp){
    temp -> prev = head;  
    head -> next -> prev = temp;
    temp -> next = head -> next;
    head -> next = temp;
}

void delNode(Node* temp){
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
}

    LRUCache(int capacity) {
        n = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* curr = mp[key];
            int val = curr -> value;
            delNode(curr);
            addNode(curr);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* curr = mp[key];
            delNode(curr);
        }
        else{
            if(mp.size() == n){
                Node* curr = tail -> prev;
                delNode(curr);
                mp.erase(curr->key);
            }
        }
        Node* newNode = new Node(key,value);
        addNode(newNode);
        mp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */