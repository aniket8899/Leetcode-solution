


class LRUCache {

 

public:


class Node{
public:

int val;
int key;
Node* next;
Node* prev;

Node(int k,int v){
    val=v;
    key=k;
    prev=next=NULL;
}




};

    int limit;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    unordered_map<int,Node*>mp;


    LRUCache(int c) {
        limit=c;
        head->next=tail;
        tail->prev=head;
    }

    void deletenode(Node* deletenode){
        Node* prevnode=deletenode->prev;
        Node* nextnode=deletenode->next;

        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }

    void addnode(Node* newnode){

        Node* first=head->next;

        head->next=newnode;
        newnode->prev=head;
        newnode->next=first;
        first->prev=newnode;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end()){
            return -1;
        }

        Node* ansnode=mp[key];
        int ans=ansnode->val;

        deletenode(ansnode);

        addnode(ansnode);

        mp[key]=ansnode;

        return ans;

    }
    
    void put(int key, int value) {

        // tw possibility h
        // map me ho

        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];

            deletenode(temp);

            mp.erase(key);

        }

        if(mp.size()==limit){
            Node* oldnode=tail->prev;
            deletenode(oldnode);
            mp.erase(oldnode->key);
        }

        Node* newnode=new Node(key,value);

        addnode(newnode);

        mp[key]=newnode;

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */