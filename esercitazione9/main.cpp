#include <iostream>
#include <fstream>
#include <string>

#include "graph.hpp"
#include "methods.hpp"
#include "graph_visit.hpp"
#include "recursive_dfs.hpp"
#include "dijkstra.hpp"

// Funzione per stampare un grafo in formato GraphViz (.dot)
void esporta_graphviz(const unidirected_graph& G, const std::string& nome_grafo) {
	std::cout << "--- GRAFO " << nome_grafo << " (Formato GraphViz) ---" << std::endl;
	std::cout << "graph " << nome_grafo << " {" << std::endl;
	
	// Iteriamo su tutti gli archi del grafo e li stampiamo nel formato corretto
	for (const auto& edge : G.all_edges()) {
		std::cout << "  " << edge.from() << " -- " << edge.to() << ";" << std::endl;
	}
	
	std::cout << "}" << std::endl << std::endl;
}

int main() {
	// 1. CREAZIONE DEL GRAFO DI TEST
	// Creiamo un grafo semplice, ad esempio un ciclo a 4 nodi con una diramazione:
	// 1 -- 2 -- 3
	// |    |
	// 4 -- 5
	unidirected_graph G;
	G.add_edge(1, 2);
	G.add_edge(2, 3);
	G.add_edge(1, 4);
	G.add_edge(4, 5);
	G.add_edge(2, 5);
	
	std::cout << "Grafo originale configurato con successo." << std::endl << std::endl;
	
	int nodo_sorgente = 1;
	
	// 2. TEST DI GRAPH_VISIT CON POLITICA LIFO (DFS Iterativa)
	lifo<int> s;
	unidirected_graph dfs_iterativo = graph_visit(G, nodo_sorgente, s);
	esporta_graphviz(dfs_iterativo, "DFS_Iterativo");
	
	// 3. TEST DI GRAPH_VISIT CON POLITICA FIFO (BFS)
	fifo<int> q;
	unidirected_graph bfs_albero = graph_visit(G, nodo_sorgente, q);
	esporta_graphviz(bfs_albero, "BFS_Albero");
	
	// 4. TEST DELLA DFS RICORSIVA
	unidirected_graph dfs_ricorsivo = recursive_dfs(G, nodo_sorgente);
	esporta_graphviz(dfs_ricorsivo, "DFS_Ricorsivo");
	
	// 5. TEST DELL'ALGORITMO DI DIJKSTRA
	std::map<int, double> distanze = dijkstra(G, nodo_sorgente);
    
	std::cout << "--- RISULTATI DIJKSTRA (Sorgente: " << nodo_sorgente << ") ---" << std::endl;
    for (const auto& coppia : distanze) {
        std::cout << "Distanza minima dal nodo " << nodo_sorgente 
                  << " al nodo " << coppia.first 
                  << " = " << coppia.second << std::endl;
    }
    
    return 0;
}