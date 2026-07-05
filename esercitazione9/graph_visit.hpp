#pragma once

#include <set>

#include "methods.hpp"
#include "graph.hpp"

/* graph_visit effettua una visita in ampiezza (BFS) o in profondità (DFS) in base all'oggetto passato come terzo parametro (fifo o lifo) */
template <typename ContainerType>
unidirected_graph graph_visit(const unidirected_graph& G, int sorgente, ContainerType s) {
	
	unidirected_graph albero_visita;
	std::set<int> visitati;
	
	// controllo se il nodo sorgente esiste nel grafo
	std::set<int> nodi_totali = G.all_nodes();
	if (nodi_totali.find(sorgente) == nodi_totali.end()) {
		return albero_visita;
	}
	
	// inserisco il nodo iniziale nel metodo
	s.put(sorgente);
	visitati.insert(sorgente);
	
	while (!s.empty()) {
        int u = s.get();

        // guardo i vicini del nodo estratto
        for (int v : G.neighbours(u)) {
			
            // se il vicino non è ancora stato visitato
            if (visitati.find(v) == visitati.end()) {
                visitati.insert(v);
                
                // Costruisce l'albero di copertura aggiungendo l'arco
                albero_visita.add_edge(u, v);
				s.put(v);
            }
        }
    }

    return albero_visita;
}