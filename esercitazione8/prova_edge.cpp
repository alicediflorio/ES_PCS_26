#include <iostream>
#include <set>

#include "unidirected_edge.hpp"

int main()
{
    unidirected_edge e1(5,2);
    unidirected_edge e2(2,5);

    std::cout << e1 << std::endl;

    if (e1 == e2)
        std::cout << "uguali" << std::endl;

    std::set<unidirected_edge> edges;

    edges.insert(e1);
    edges.insert(e2);

    std::cout << edges.size() << std::endl;
}