// Questa esercitazione è stata svolta utilizzando il supporto di intelligenza artificiale


#include <iostream>
#include <vector>
#include <set>

#include "unidirected_graph.hpp"

int main() {
	unidirected_graph G1;
	
	// Test per aggiunta archi
	std::cout << "\n1) TEST add_edge e all_edges:" << std::endl;
	
	G1.add_edge(10, 20);
	G1.add_edge(30, 20); // sarà ordinato come (20, 30)
	G1.add_edge(10, 20); // essendo duplicato non dovrebbe essere aggiunto
	
	auto archi = G1.all_edges();
	
	std::cout << "Numero archi totali: " << archi.size() << " (Atteso: 2)" << std::endl;
	for (const auto& e : archi) {
		std::cout << "   Arco: " << e << std::endl;
		}
		
	// Test nodi e vicini
	std::cout << "\n2) TEST all_nodes e neighbours:" << std::endl;
	
	std::set<int> nodi = G1.all_nodes();
	std::cout << "Nodi presenti: ";
	
	for (int n : nodi) std::cout << n << " "; // 10 20 30
	std::cout << std::endl;
	
	std::set<int> vicini20 = G1.neighbours(20);
	std::cout << "Vicini del nodo 20: ";
	for (int v : vicini20) std::cout << v << " "; // 10 30
	std::cout << std::endl;
	
	// Test numerazione archi
	std::cout << "\n3) TEST numerazione (edge_number e edge_at):" << std::endl;
	unidirected_edge cercato(10, 20);
	int id = G1.edge_number(cercato);
	std::cout << "L'arco (10,20) ha indice: " << id << std::endl;
	
	unidirected_edge ripreso = G1.edge_at(id);
	std::cout << "L'arco all'indice " << id << " è: " << ripreso << std::endl;
	
	// Test differenza tra grafi
	std::cout << "\n4) TEST operatore differenza (G - G'):" << std::endl;
	unidirected_graph G2;
	G2.add_edge(20, 30); // G2 ha solo un arco in comune con G1
	
	unidirected_graph diff = G1 - G2; // G1 ha (10,20) e (20,30). G2 ha (20,30).
	std::cout << "Archi risultanti da G1 - G2:" << std::endl;
	for (const auto& e : diff.all_edges()) {
		std::cout << "   " << e << std::endl; // Dovrebbe restare solo (10, 20)
	}
	
	return 0;
}