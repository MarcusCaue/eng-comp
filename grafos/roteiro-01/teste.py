from bibgrafo.grafo_lista_adjacencia import Aresta, Vertice
from meu_grafo import MeuGrafo

paraiba = MeuGrafo(
  vertices = [Vertice("J"), Vertice("M"), Vertice("Z"), Vertice("T")],
)

paraiba.adiciona_vertice("E")
paraiba.adiciona_vertice("P")
paraiba.adiciona_vertice("C")

paraiba.arestas = {
  "a1": Aresta("a1", paraiba.get_vertice("J"), paraiba.get_vertice("C")),
  "a2": Aresta("a2", paraiba.get_vertice("C"), paraiba.get_vertice("E")),
  "a3": Aresta("a3", paraiba.get_vertice("C"), paraiba.get_vertice("E")),
  "a4": Aresta("a4", paraiba.get_vertice("C"), paraiba.get_vertice("P")),
  "a5": Aresta("a5", paraiba.get_vertice("C"), paraiba.get_vertice("P")),
  "a6": Aresta("a6", paraiba.get_vertice("C"), paraiba.get_vertice("M")),
  "a7": Aresta("a7", paraiba.get_vertice("C"), paraiba.get_vertice("T")),
}

paraiba.adiciona_aresta("a8", "M", "T")
paraiba.adiciona_aresta("a9", "T", "Z")

# paraiba.vertices_nao_adjacentes()

print(paraiba)
# print(paraiba.vertices)