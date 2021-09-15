#include "disjointset.h"

int main() {
    DisjointSet d(10);
    d.Union(0,1);
    d.Union(0,2);
    d.Union(1,3);
    d.Union(4,8);
    d.Union(5,6);
    d.Union(5,7);

    d.__debug_print();

    std::cout << "Node 0 and 3 is " << (d.Connected(0, 3) ? "connected\n" : "unconnected\n");
    std::cout << "Node 1 and 5 is " << (d.Connected(1, 5) ? "connected\n" : "unconnected\n");
    std::cout << "Node 7 and 8 is " << (d.Connected(7, 8) ? "connected\n" : "unconnected\n");

    std::cout << "\n\n\n";

    std::cout << "Add a new edge (7, 8)\n";
    d.Union(7,8);

    d.__debug_print();
    std::cout << "Now, node 7 and 8 is " << (d.Connected(7, 8) ? "connected\n" : "unconnected\n");
    std::cout << "\n\n\n";

    /* a worst case, seems no use, since find() finds the final root */
    DisjointSet d2(10);
    d2.Union(0,1);
    d2.Union(1,2);
    d2.Union(2,3);
    d2.Union(3,4);
    d2.Union(4,5);

    d2.Union(6,7);

    d2.__debug_print();

    d2.Union(6,0);

    d2.__debug_print();

    std::cout << "\n\n\n";

    DisjointSet d3(10);
    d3.Union(0,1);
    d3.Union(1,2);
    d3.Union(2,3);
    d3.Union(3,4);
    d3.Union(4,5);

    d3.Union(6,7);

    d3.__debug_print();

    d3.Union(6,2);

    d3.__debug_print();

    return 0;
} 
