#pragma once

#include <set>
#include <vector>
#include <map>

#include "unidirected_edge.hpp"


class unidirected_graph {
private:
	// lista di adiacenza ==> dato un nodo fornisce il set di vicini 
    std::map<int, std::set<int>> lista_adiacenza;

	// lista di archi a cui si accede tramite indice
    std::vector<unidirected_edge> edges_list;
	
	// mappa per trovare l'indice di un arco esistente
    std::map<unidirected_edge, int> id_edge;

public:
	/* costruttore user-defined */
	unidirected_graph() = default;
	
	/* costruttore di copia */
	unidirected_graph(const unidirected_graph& other) = default;
	
	/* neighbours ==> restituisce i vicini di un nodo */
    std::set<int> neighbours(int node) const;
	
	/* add_edge ==> aggiunge un arco al grafo */
    void add_edge(int u, int v);
	
	/* all_edges ==> restituisce tutti gli archi */
    std::vector<unidirected_edge> all_edges() const;
	
	/* all_nodes ==> restituisce tutti i nodi */
    std::set<int> all_nodes() const;
	
	/* edge_number ==> restituisce la numerazione dell'arco all'interno del grafo */
	int edge_number(const unidirected_edge& edge) const;
	
	/* edge_at ==> restituisce l'arco alla posizione 'index' nel grafo */
	unidirected_edge edge_at(int index) const;
	
	/* operator- ==> calcola la differenza tra due grafi*/
	unidirected_graph operator-(const unidirected_graph& other) const;
};