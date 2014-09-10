#include <iostream>
#include <vector>
#include <map>
using namespace std;



class LRUCache{
public:
    LRUCache(int capacity) {
        this->mCap = capacity;
    }

    void _resetLessUsedKey(int key){
        TLRUCacheMapIter it;
        TLRUCacheMapIter minIt;
        minIt = this->mMap.begin();
        for (it = this->mMap.begin() ; it != this->mMap.end(); ++it)
        {
            if (it->second->second < minIt->second->second)
            {
                minIt = it;
            }
        }
        this->mLessUserdKey = minIt->first;
    }

    int get(int key) {
        TLRUCacheMapIter it = this->mMap.find(key);
        if (it == this->mMap.end())
        {
           return -1;
        }

       it->second->second ++;
       if (key == this->mLessUserdKey)
       {
            _resetLessUsedKey(key);
       }
       return it->second->first;
    }

    void set(int key, int value) {
        //cout << ">" << endl;
        //cout << this->mMap.size() << endl;
        TLRUCacheMapIter it = this->mMap.find(key);
        if (it == this->mMap.end())
        {
            if (this->mMap.size() == this->mCap)
            {
        cout << ">" << endl;
                cout << this->mMap.size() << endl;
                this->mMap.erase(this->mMap.find(mLessUserdKey));
                cout << this->mMap.size() << endl;
        cout << ">" << endl;
            }

            this->mMap[key] = new TLRUValuePair(value, 1);
            _resetLessUsedKey(key);
            return;
        }

        it->second->second ++;
        if (key == this->mLessUserdKey)
        {
            _resetLessUsedKey(key);
        }
        it->second->first = value;
    }

private:
    typedef std::pair<int, int> TLRUValuePair;
    typedef std::map<int, TLRUValuePair*> TLRUCacheMap;
    typedef std::map<int, TLRUValuePair*>::iterator TLRUCacheMapIter;
    //typedef std::map<int, TLRUValuePair*>::iter ITLRUCacheMap;
    TLRUCacheMap       mMap;
    int mCap;
    int mLessUserdKey;
};

int main(int argc, char *argv[])
{

    LRUCache c(3);
    c.set(1, 10);
    c.set(2, 20);
    cout << c.get(2) << endl;
    cout << c.get(2) << endl;
    c.set(3, 30);
    c.set(4, 40);
    c.set(4, 41);
    c.set(5, 50);
    c.set(6, 60);

    cout << c.get(1) << endl;
    cout << c.get(2) << endl;
    cout << c.get(2) << endl;
    cout << c.get(3) << endl;
    cout << c.get(4) << endl;
    cout << c.get(5) << endl;
    cout << c.get(6) << endl;

    return 0;
}
