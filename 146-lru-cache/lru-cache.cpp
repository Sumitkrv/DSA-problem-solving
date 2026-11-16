class LRUCache {
public:
    class Node{
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key=k;
            val=v;
            prev=NULL;
            next=NULL;
        }
    };
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int cap;

    //remove a node from linkedlist
    void removeNode(Node* node){
        Node* before=node->prev;
        Node* after=node->next;
        before->next=after;
        after->prev=before;
        
    }
    //insert node after head;
    void insertAtHead(Node* node){
        Node* curAfterHead=head->next;  
        head->next=node;
        node->next=curAfterHead;
        node->prev=head;
        curAfterHead->prev=node;
    }

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1, -1);
        tail=new Node(-1, -1);

        head->next=tail;
        tail->prev=head;

    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }

        Node* node=mp[key];
        removeNode(node);
        insertAtHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            removeNode(node);
            node->val=value;
            insertAtHead(node);
        }
        else{
            if(mp.size()==cap){
                Node* lru=tail->prev;
                mp.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
            Node* node= new Node(key, value);

            mp[key]=node;
            insertAtHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */