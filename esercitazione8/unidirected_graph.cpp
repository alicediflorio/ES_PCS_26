#include <algorithm>
#include <stdexcept>

#include "unidirected_graph.hpp"


// add_edge: aggiunge un arco al grafo e aggiorna i contenitori
void unidirected_graph::add_edge(int u, int v)
{	
	unidirected_edge edge(u, v);
    
    // verifico che l'arco non esista per non duplicarlo
    if (id_edge.find(edge) == id_edge.end()) {
		
		// 1. aggiorno la lista di adiacenza per entrambi i nodi
		lista_adiacenza[u].insert(v);
		lista_adiacenza[v].insert(u);
		
		// 2. calcolo la posizione dell'arco nel grafo
		int posizione = edges_list.size();
		
		// 3. salvo la posizione nella mappa id_edge
		id_edge[edge] = posizione;
		
		// 4. aggiungo l'arco in fondo alla lista
		edges_list.push_back(edge);
    }
}

// neighbours: restituisce i vicini di un nodo
std::set<int> unidirected_graph::neighbours(int node) const
{
	// 1. cerco il nodo nella mappa
	auto it = lista_adiacenza.find(node);
	
	// 2. se lo trvo, chiedo che venga restituita il set di vicini
    if (it != lista_adiacenza.end())
	{
        return it->second; 
    }
	
	// se il nodo non esiste ==> chiedo che venga restituito un set vuoto
    return {};
}

// all_edges: restituisce tutti gli archi presenti nel grafo
std::vector<unidirected_edge> unidirected_graph::all_edges() const
{
    return edges_list;
}

// all_nodes: restituisce tutti i nodi presenti nel grafo
std::set<int> unidirected_graph::all_nodes() const
{
    std::set<int> nodes;
	
	// estraggo solo le chiavi della mappa
    for (auto const& [node, vicini] : lista_adiacenza) {
        nodes.insert(node);
    }
    return nodes;
}

// edge_number: restituisce la numerazione di un arco
int unidirected_graph::edge_number(const unidirected_edge& edge) const
{
	auto it = id_edge.find(edge);
	
	if (it != id_edge.end())
	{
		return it->second;
	}
	
	// se l'arco non esiste nel grafo sarà restituito -1
	return -1;
}

// edge_at: restituisce l'arco dato il numero
unidirected_edge unidirected_graph::edge_at(int index) const {
	
    // .at() gestisce il controllo dei limiti del vettore
    return edges_list.at(index);
}

// operator-: calcola la differenza tra due grafi (G - G')
unidirected_graph
unidirected_graph::operator-(const unidirected_graph& other) const
{
    unidirected_graph result;
    
    // la differenza G - G' è data dagli archi presenti in G e non in G' 
    for (const auto& edge : edges_list) {
        
		// Se l'arco 'edge' non si trova nella mappa degli archi dell'altro grafo
        if (other.id_edge.find(edge) == other.id_edge.end())
		{
            result.add_edge(edge.from(), edge.to());
        }
    }
    return result;
}