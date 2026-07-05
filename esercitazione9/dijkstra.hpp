#pragma once

#include <map>
#include <set>
#include <vector>
#include <limits> // Per definire il valore "infinito"
#include "graph.hpp"

// calcola le distanze minime da un nodo sorgente in un grafo non pesato
inline std::map<int, double> dijkstra(const unidirected_graph& G, int sorgente) {
	
	// mappa per salvare la distanza minima di ogni nodo dalla sorgente
	std::map<int, double> distanze;
	
	// insieme (std::set) dei nodi completati
	std::set<int> visitati;
	
	// tutti i nodi del grafo
	std::set<int> tutti_i_nodi = G.all_nodes();
	
	// Valore che rappresenta l'infinito
	double infinito = std::numeric_limits<double>::infinity();
	
	// 1. INIZIALIZZAZIONE: tutte le distanze sono fissate a infinito
	for (int nodo : tutti_i_nodi) {
		distanze[nodo] = infinito;
	}
	
	// La distanza della sorgente da se stessa è 0
	distanze[sorgente] = 0.0;
	
	// Ciclo principale: continua finché non soo stati visitati tutti i nodi
	while (visitati.size() < tutti_i_nodi.size()) {
		
		// Trova il nodo non visitato con la distanza minima corrente
		int u = -1;
		double min_dist = infinito;
		
		for (int nodo : tutti_i_nodi) {
			if (visitati.count(nodo) == 0 && distanze[nodo] < min_dist) {
				min_dist = distanze[nodo];
				u = nodo;
			}
		}
		
		// Se u è rimasto -1 o la sua distanza è infinito, i nodi rimanenti non sono raggiungibili dalla sorgente (grafo disconnesso)
		if (u == -1 || distanze[u] == infinito) {
			break;
		}
		
		// Inseriamo il nodo u tra i visitati
		visitati.insert(u);
		
		// 2. RILASSAMENTO DEGLI ARCHI: esploriamo i vicini di u
		for (int v : G.neighbours(u)) {
			// Saltiamo i vicini già visitati
			if (visitati.count(v) > 0) continue;
			
			// Poiché l'arco non ha un peso nel file unidirected_edge.hpp, impostiamo il costo fisso di ogni passo pari a 1.0
			double peso_arco = 1.0;
			
			// Aggiorna la distanza se passando da 'u' troviamo un cammino più breve per 'v'
			if (distanze[u] + peso_arco < distanze[v]) {
				distanze[v] = distanze[u] + peso_arco;
			}
		}
	}
    return distanze;
}