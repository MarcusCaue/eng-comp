from bibgrafo.grafo_lista_adjacencia import GrafoListaAdjacencia, Aresta, Vertice

paraiba = GrafoListaAdjacencia(
  vertices = ["Jampa", "Monteiro", "Cajazeiras", "Teresina"],
)

paraiba.adiciona_vertice("Esperança")
paraiba.adiciona_vertice("Patos")
paraiba.adiciona_vertice("Campina")

paraiba.arestas = {
  "a1": Aresta("a1", "Jampa", "Campina"),
  "a2": Aresta("a2", "Campina", "Esperança"),
  "a3": Aresta("a3", "Campina", "Esperança"),
  "a4": Aresta("a4", "Campina", "Patos"),
  "a5": Aresta("a5", "Campina", "Patos"),
  "a6": Aresta("a6", "Campina", "Monteiro"),
  "a7": Aresta("a7", "Campina", "Teresina"),
}

paraiba.adiciona_aresta("a8", "Monteiro", "Teresina")
paraiba.adiciona_aresta("a9", "Teresina", "Cajazeiras")

print(paraiba)