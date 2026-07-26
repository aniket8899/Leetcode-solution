class LRUCache {
public:

    class Node{

        public:

        int val;
        int key;

        Node* prev;
        Node* next;

        Node(int k,int v){
            key=k;
            val=v;
            prev=next=NULL;
        }

    };

     Node* head =new Node(-1,-1);
     Node* tail=new Node(-1,-1);

     unordered_map<int,Node*>mp;

     int limit;

        // insert head->next
     void addNode(Node* newnode){
        Node* oldtail=head->next;

        head->next=newnode;
        oldtail->prev=newnode;

        newnode->next=oldtail;

        newnode->prev=head;
     }


        // delete node tail->prev

       void deleteNode(Node* oldnode){
        Node* oldprev=oldnode->prev;
        Node* oldnext=oldnode->next;

        oldprev->next=oldnext;
        oldnext->prev=oldprev;

     }



    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;

    }
    
    int get(int key) {

        if(mp.find(key)==mp.end()){
            return -1;
        }

        Node* ansnode=mp[key];
        int ans=ansnode->val;

        // most used ko phala layenga aur uska baad least use ko baad me

        mp.erase(key);

        deleteNode(ansnode);

        addNode(ansnode);

        mp[key]=ansnode;



        return ans;
        
    }
    
    void put(int key, int value) {

        // agar phala hi key present h 
        // jaisa ki put (1,2) aur put(1,3) diya ho tab
        if(mp.find(key)!=mp.end()){
            Node* oldnode=mp[key];
            deleteNode(oldnode);

            mp.erase(key);
        }


        // capacity reach

        if(mp.size()==limit){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // insert karo head ka next 

        Node* newnode=new Node(key,value);

        addNode(newnode);

        mp[key]=newnode;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */