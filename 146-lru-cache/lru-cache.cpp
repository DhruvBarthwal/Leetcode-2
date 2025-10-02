class LRUCache {
public:
    int n ;
    class Node{
        public:
        int key,val;
        Node* prev;
        Node* next;
        Node(int key, int value){
            this->key = key;
            this-> val = value;
        }
    };
    unordered_map<int,Node*> keyValue;
    //shorcut intialize
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        this -> n = capacity;
        head-> next = tail;
        tail -> prev = head;
    }
    void addNode(Node* newNode){
        //adding at head
        newNode->prev = head;
        head->next -> prev = newNode;
        newNode->next = head->next;
        head-> next = newNode;

    }
    void deleteNode(Node* newNode){
        //deleting from tail
        newNode->prev->next = newNode->next;
        newNode->next->prev = newNode->prev;
    }
    
    int get(int key) {
        if(keyValue.find(key) != keyValue.end()){
            Node* currNode = keyValue[key];
            int ans = currNode->val;
            deleteNode(currNode);
            addNode(currNode);
            keyValue[key] = currNode;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyValue.find(key) != keyValue.end()){
            Node* currNode = keyValue[key];
            keyValue.erase(key);
            deleteNode(currNode);
        }
        if(keyValue.size() == n){
            keyValue.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key,value);
        addNode(newNode);
        keyValue[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */