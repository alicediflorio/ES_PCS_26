#include "unidirected_edge.hpp"

unidirected_edge::unidirected_edge(int a, int b) {
	if (a < b) {
		m_from = a;
		m_to = b;
	}
	else {
		m_from = b;
		m_to = a;
	}
}

/* chiedo che sia restituito il nodo iniziale */
int unidirected_edge::from() const
{
	return m_from;
}

/* chiedo che sia restituito il nodo finale */
int unidirected_edge::to() const
{
	return m_to;
}

/* operator< */
bool unidirected_edge::operator<(const unidirected_edge& other) const
{
	if (m_from != other.m_from)
		return m_from < other.m_from;
	
	return m_to < other.m_to;
}

/* operatore== */
bool unidirected_edge::operator==(const unidirected_edge& other) const
{
	return (m_from == other.m_from && m_to == other.m_to);
}

/* operator << */
std::ostream& operator<<(std::ostream& os, const unidirected_edge& edge)
{
    os << "(" << edge.from() << ", " << edge.to() << ")";
	return os;
}