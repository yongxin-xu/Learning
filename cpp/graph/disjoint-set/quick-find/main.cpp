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

    return 0;
} 
