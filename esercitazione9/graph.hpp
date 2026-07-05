#pragma once

#include <set>
#include <vector>
#include <map>

#include <iostream>
#include <algorithm>


class unidirected_edge {
	int m_from, m_to;

public:

	/* costruttore user-defined */
	unidirected_edge(int a, int b) {
		// il vertice di partenza deve essere minore di quello di arrivo
		m_from = std::min(a,b);
		m_to = std::max(a,b);
	}
	
	// metodi per restituire i nodi
	int from() const {return m_from; }
	int to() const {return m_to; }
	
	/* operatore < --> oridina gli archi */
	bool operator<(const unidirected_edge& other) const {
		if (m_from != other.m_from) {
			return m_from < other.m_from;
		}
		return m_to < other.m_to;
	}

	/* operatore == */
	bool operator==(const unidirected_edge& other) const {
		return m_from == other.m_from && m_to == other.m_to;
}

	/* operatore << */
	friend std::ostream& operator<<(std::ostream& os, const unidirected_edge& edge) {
		os << "(" << edge.m_from << ")--(" << edge.m_to << ")";
		return os;
	}
};


class unidirected_graph {
private:
	// lista di adiacenza ==> dato un nodo fornisce il set di vicini 
    std::map<int, std::set<int>> vicini;

	// lista di archi a cui si accede tramite indice
    std::vector<unidirected_edge> edges;
	
	// mappa per trovare l'indice di un arco esistente
    std::map<unidirected_edge, int> id_edge;

public:
	/* costruttore user-defined */
	unidirected_graph() = default;
	
	/* costruttore di copia */
	unidirected_graph(const unidirected_graph& other) = default;
	
	/* neighbours ==> restituisce i vicini di un nodo */
    std::set<int> neighbours(int node) const {
		if (vicini.count(node)) {
			return vicini.at(node);
		}
		return {};
	}
	
	/* add_edge ==> aggiunge un arco al grafo */
    void add_edge(int a, int b) {
		unidirected_edge new_edge(a, b);
		
		if (std::find(edges.begin(), edges.end(), new_edge) == edges.end()) {
			edges.push_back(new_edge);
            vicini[a].insert(b);
            vicini[b].insert(a);
		}
	}
	
	/* all_edges ==> restituisce tutti gli archi */
    std::vector<unidirected_edge> all_edges() const {
		return edges;
	}
	
	/* all_nodes ==> restituisce tutti i nodi */
    std::set<int> all_nodes() const {
		std::set<int> nodes;
		
		for (const auto& element : vicini) {
			nodes.insert(element.first);
		}
		return nodes;
	}
	
	/* edge_number ==> restituisce la numerazione dell'arco all'interno del grafo */
	int edge_number(const unidirected_edge& edge) const {
		for (size_t i = 0; i < edges.size(); i++) {
			if (edges[i] == edge) {
				return i;
			}
		}
		return -1;
	}
	
	/* edge_at ==> restituisce l'arco alla posizione 'indice' nel grafo */
	unidirected_edge edge_at(int indice) const {
		if (indice >= 0 && indice < edges.size()) {
			return edges[indice];
		}
		
		std::cerr << "Errore: indice non valido." << "\n";
		return unidirected_edge(-1, -1);
	}
	
	/* operator- ==> calcola la differenza tra due grafi*/
	unidirected_graph operator-(const unidirected_graph& other) const {
		unidirected_graph risultato;
		auto other_edges = other.all_edges();
		
		for (const auto& edge : edges) {
			if (std::find(other_edges.begin(), other_edges.end(), edge) == other_edges.end()) {
				risultato.add_edge(edge.from(), edge.to());
			}
		}
		return risultato;
	}
};