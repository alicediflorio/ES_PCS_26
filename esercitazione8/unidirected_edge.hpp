#pragma once

#include <iostream>


class unidirected_edge {
private:
	int m_from;
	int m_to;

public:
	
	/* costruttore user-defined */
	unidirected_edge(int a, int b);
	
	int from() const;
	int to() const;
	
	/* operatore < */
	bool operator<(const unidirected_edge& other) const;
	
	/* operatore == */
	bool operator==(const unidirected_edge& other) const;
};

/* operatore << */
std::ostream& operator<<(std::ostream& os, const unidirected_edge& edge);