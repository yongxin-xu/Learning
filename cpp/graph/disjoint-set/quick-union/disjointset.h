
#ifndef __DISJOINT_SET_QUICK_UNION_H
#define __DISJOINT_SET_QUICK_UNION_H

#include <iostream>
#include <vector>

class DisjointSet {
public:

    /* initialize the disjoint set and set default value */
    DisjointSet(int size): m_root_array(size) {
        assert(size > 0);
        for (int i = 0; i < size; i++)
            m_root_array[i] = i;
    }

    /* quick-find disjoint set, just return the value of root_array[i],
       takes O(H) time, H is the height of the rootValue tree */
    int Find(int i) {
        assert(i >= 0 && i < m_root_array.size());
        int idx = i;
        while (idx != m_root_array[idx]) {
            idx = m_root_array[idx];
        }
        return idx;
    }

    /* Union, add an edge to the disjoint set,
       takes O(H) time */
    void Union(int x, int y) {
        assert(x >= 0 && x < m_root_array.size());
        assert(y >= 0 && y < m_root_array.size());
        int rootX = Find(x);
        int rootY = Find(y);
        if (rootX != rootY) {
            m_root_array[rootY] = rootX;
        }
    }

    /* Connected returns true if two given nodes are connected,
       takes O(H) time */
    bool Connected(int x, int y) {
        return Find(x) == Find(y);
    }

    void __debug_print() {
        for (int &v : m_root_array)
            std::cout << v << "\t";
        std::cout << "\n";
    }

private:
    std::vector<int> m_root_array;
};

#endif
