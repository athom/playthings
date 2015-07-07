//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
private:
    static Solution* m_instance;
    Solution(){
    }
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        if (m_instance == NULL) {
            m_instance = new Solution();
        }
        return m_instance;
    }
    ~Solution(){
    }
};
Solution::m_instance = NULL;


int main(int argc, char *argv[])
{
    Solution* a = Solution::getInstance();
    Solution* b = Solution::getInstance();

    assert(a == b);
    assert(a != NULL);

    return 0;
}
