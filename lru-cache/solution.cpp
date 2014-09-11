#include <iostream>
#include <map>
#include <assert.h>
using namespace std;


struct Node {
    int key;
    int value;
    Node* pre;
    Node* next;
};


class LRUCache{
public:
    LRUCache(int capacity) {
        mCap = capacity;

        mHead = NULL;
        mTail = NULL;
    }

    int _moveNodeToHead(Node* node){
        if (node == mHead)
        {
            return mHead->value;
        }

        if (node == mTail)
        {
            node->pre->next = NULL;
            mTail = node->pre;
        }
        else{
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }

        node->pre = NULL;
        node->next = mHead;
        mHead->pre = node;
        mHead = node;
        return mHead->value;
    }

    int get(int key) {
        TLRUCacheMapIter it = mMap.find(key);
        if (it != mMap.end())
        {
            return _moveNodeToHead(it->second);
        }

        return -1;
    }

    void set(int key, int value) {
        TLRUCacheMapIter it = mMap.find(key);
        // hit the cache
        if (it != mMap.end())
        {
            it->second->value = value;
            _moveNodeToHead(it->second);
            return;
        }

        Node* node = new Node;
        node->key = key;
        node->value = value;

        // first element to set
        if (mHead == NULL && mTail == NULL)
        {
            mHead = node;
            mTail = node;
            mMap[key] = node;
            return;
        }

        // append to head
        node->next = mHead;
        mHead->pre = node;
        mHead = node;

        // reach capacity, invalid the tail
        if(mMap.size() == mCap) {
            // remove tail element
            Node* toBeTail = mTail->pre;
            toBeTail->next = NULL;
            mMap.erase(mTail->key);
            delete mTail;
            mTail = toBeTail;
        }

        mMap[key] = node;
    }

    Node* mHead;
    Node* mTail;
private:
    typedef std::map<int, Node*> TLRUCacheMap;
    typedef std::map<int, Node*>::iterator TLRUCacheMapIter;

    int mCap;
    TLRUCacheMap       mMap;
};

int main(int argc, char *argv[])
{

    LRUCache c(3);
    c.set(1, 10);
    c.set(2, 20);
    c.set(3, 30);
    c.set(4, 40);
    c.set(4, 41);
    c.set(3, 31);
    c.set(5, 50);
    c.set(6, 60);


    assert(c.get(1) == -1);
    assert(c.get(2) == -1);
    assert(c.get(3) == 31);
    assert(c.get(4) == -1);
    assert(c.get(5) == 50);
    assert(c.get(6) == 60);

    return 0;
}
