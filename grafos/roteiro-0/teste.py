from bibgrafo.grafo_lista_adjacencia import GrafoListaAdjacencia, Aresta, Vertice

paraiba = GrafoListaAdjacencia(
  vertices = [Vertice("João Pessoa"), Vertice("Monteiro"), Vertice("Cajazeiras"), Vertice("Teresina")],
)

paraiba.adiciona_vertice("Esperança")
paraiba.adiciona_vertice("Patos")
paraiba.adiciona_vertice("Campina")

paraiba.arestas = {
  "a1": Aresta("a1", paraiba.get_vertice("João Pessoa"), paraiba.get_vertice("Campina")),
  "a2": Aresta("a2", paraiba.get_vertice("Campina"), paraiba.get_vertice("Esperança")),
  "a3": Aresta("a3", paraiba.get_vertice("Campina"), paraiba.get_vertice("Esperança")),
  "a4": Aresta("a4", paraiba.get_vertice("Campina"), paraiba.get_vertice("Patos")),
  "a5": Aresta("a5", paraiba.get_vertice("Campina"), paraiba.get_vertice("Patos")),
  "a6": Aresta("a6", paraiba.get_vertice("Campina"), paraiba.get_vertice("Monteiro")),
  "a7": Aresta("a7", paraiba.get_vertice("Campina"), paraiba.get_vertice("Teresina")),
}

paraiba.adiciona_aresta("a8", "Monteiro", "Teresina")
paraiba.adiciona_aresta("a9", "Teresina", "Cajazeiras")

print(paraiba)