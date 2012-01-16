/*
 * Google code jam: GoroSort
 * 
 * Author: Jim
 * Date: 2011-05-07 Sat.
 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
  
//#define DEBUG 1
void parse();
void solve();

class Point
{
    public:
        Point(int x, int y)
        {
            m_x = x;
            m_y = y;
        }
        int x()
        {
            return m_x;
        }
        int y()
        {
            return m_y;
        }
        bool operator == (const Point& p)const
        {
            return m_x == p.m_x && m_y == p.m_y;
        }
        bool operator < (const Point& p)const
        {
            return m_x <  p.m_x && m_y < p.m_y;
        }
        bool operator > (const Point& p)const
        {
            return m_x >  p.m_x && m_y > p.m_y;
        }
        friend ostream& operator<<(ostream& out, const Point& p)
        {
            out << "(" << p.m_x <<", " << p.m_y << ")" <<endl;
            return out;
        }
        void AddLink(Point* i)
        {
           m_links.push_back(i);
        }
        vector<Point*> Links()
        {
            return m_links;
        }
        
    private:
        vector<Point*> m_links;
        
        int m_x;
        int m_y;
};

vector<Point> gPoints;

int main(int argc, char** argv)
{
    int n;

#if DEBUG
    if(argc != 1)
    {
        cout << "usage: ./gymnast a.in" << endl;
        return 1;
    }
    freopen("c.in","r",stdin); 
#else
    if(argc != 2)
    {
        cout << "usage: ./gymnast a.in" << endl;
        return 1;
    }
    freopen(argv[1],"r",stdin); 
    //freopen("output.txt","w",stdout); 
#endif

    //Add Your Code Here
    parse();
    solve();

    fclose(stdin);
    fclose(stdout);

    return EXIT_SUCCESS;
}

void parse()
{
    string s;
    gPoints.push_back(Point(0, 0));
    while(1)
    {
        cin >> s;
        if(cin.eof())
        {
            break;
        }
        int x, y;
        if(s[0] == '(')
        {
            x = atoi(s.erase(0,1).c_str());
        }
        cin >> s;
        if(s[s.size()-1] == ')')
        {
            y = atoi(s.erase(s.size()-1).c_str());
        }
        gPoints.push_back(Point(x, y));
    }
}

bool CleanRoomBetween(const Point& a, const Point& b)
{
    if(a == b || !(a < b || a > b))
    {
        return false;
    }
    for(vector<Point>::iterator i = gPoints.begin(); i != gPoints.end(); ++i)
    {
        if(a == *i || b == *i)
        {
            continue;
        }
        if(a < *i && *i < b)
        {
            return false;
        }
        if(a > *i && *i > b)
        {
            return false;
        }
    }
    return true;
}

void Link(Point & p)
{
    for(vector<Point>::iterator i = gPoints.begin(); i != gPoints.end(); ++i)
    {
        if(*i == p)
        {
            continue;
        }
        if(CleanRoomBetween(p, *i) && p < *i) 
        {
            p.AddLink(&(*i));
        }
    }
}

void SetupMap()
{
    for(vector<Point>::iterator i = gPoints.begin(); i != gPoints.end(); ++i)
    {
        Link(*i);
    }
}

int Height(Point& p)
{
    if(p.Links().empty())
    {
        return 0;
    }
    int max = 0, tmp = 0;
    vector<Point*> links = p.Links();
    for(int i = 0; i < links.size(); i++)
    {
        tmp = 1 + Height(*links[i]);
        if(tmp > max)
        {
            max = tmp;
        }
    }
    return max;
}

void solve()
{
    SetupMap();
    cout << Height(gPoints[0]) << endl;
}

