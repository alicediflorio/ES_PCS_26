#pragma once

#include <set>

#include "graph.hpp"

// Funzione di supporto per la DFS ricorsiva
inline void recursive_dfs_helper(const unidirected_graph& G, int u, std::set<int>& visitati, unidirected_graph& albero) {
	
	// il nodo corrente è inserito tra quelli visitati
	visitati.insert(u);
	
	// visito i vicini di u
	for (int v : G.neighbours(u)) {
		
		// se il vicino non è stato ancora visitato
		if (visitati.find(v) == visitati.end()) {
			
			// aggiungo l'arco all'albero
			albero.add_edge(u, v);
			
			// chiamata ricorsiva sul vicino
			recursive_dfs_helper(G, v, visitati, albero);
		}
	}
}

// Funzione principale per la DFS ricorsiva
inline unidirected_graph recursive_dfs(const unidirected_graph& G, int sorgente) {
	unidirected_graph albero_visita;
	std::set<int> visitati;
	
	// controllo che il nodo sorgente esista nel grafo
	std::set<int> nodi_totali = G.all_nodes();
	if (nodi_totali.find(sorgente) != nodi_totali.end()) {
		recursive_dfs_helper(G, sorgente, visitati, albero_visita);
	}
	
	return albero_visita;
}
	