#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        this->vec2d = vec2d;
        if(vec2d.size() == 0)
            return;
        num_elem = vec2d[0].size();
        num_arr = vec2d.size();
    }

    int next() {
        if(col < num_elem)
        {
            return vec2d[row][col++];
        }
        if(col == num_elem && row < num_arr)
        {
            ++row;
            col = 0;
            num_elem = vec2d[row].size();
            return vec2d[row][col++];
        }
        // otherwise it's empty
        return 0;
    }

    bool hasNext() {
        return !(row == num_arr - 1 && col == num_elem);
    }
private:
    vector<vector<int>> vec2d;
    int row = 0;
    int col = 0;
    int num_elem = 0;
    int num_arr = 0;    
};

int main(void)
{
    vector<vector<int>> vec2d;
    vec2d.push_back({1, 2});
    vec2d.push_back({3});
    vec2d.push_back({4, 5, 6});
    printf("%d\n", vec2d[0][1]);
    Vector2D i(vec2d);
    while(i.hasNext()) cout << i.next();
    return 0;
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */