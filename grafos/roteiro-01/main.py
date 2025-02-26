from bibgrafo.grafo_lista_adj_nao_dir import Aresta
from bibgrafo.grafo import Vertice
from meu_grafo_lista_adj_nao_dir import MeuGrafo

def init(grafo: MeuGrafo) -> MeuGrafo:
  grafo = MeuGrafo(
    vertices = [Vertice("J"), Vertice("M"), Vertice("Z"), Vertice("T")],
  )

  grafo.adiciona_vertice("E")
  grafo.adiciona_vertice("P")
  grafo.adiciona_vertice("C")

  grafo.arestas = {
    "a1": Aresta("a1", grafo.get_vertice("J"), grafo.get_vertice("C")),
    "a2": Aresta("a2", grafo.get_vertice("C"), grafo.get_vertice("E")),
    "a3": Aresta("a3", grafo.get_vertice("C"), grafo.get_vertice("E")),
    "a4": Aresta("a4", grafo.get_vertice("C"), grafo.get_vertice("P")),
    "a5": Aresta("a5", grafo.get_vertice("C"), grafo.get_vertice("P")),
    "a6": Aresta("a6", grafo.get_vertice("C"), grafo.get_vertice("M")),
    "a7": Aresta("a7", grafo.get_vertice("C"), grafo.get_vertice("T")),
  }

  grafo.adiciona_aresta("a8", "M", "T")
  grafo.adiciona_aresta("a9", "T", "Z")

  return grafo

# Setup do Grafo
paraiba = MeuGrafo()
paraiba = init(paraiba)

# Grafo Padrão
print(paraiba)

print("Há laços?", paraiba.ha_laco())
print("Há paralelas?", paraiba.ha_paralelas())
print("É completo?", paraiba.eh_completo())
print("Grau do vértice 'C' (Campina Grande):", paraiba.grau("C"))
print("Arestas sobre o vértice 'C' (Campina Grande):", paraiba.arestas_sobre_vertice('C'))
print(f"Conjunto de vértices não adjacentes:\n\t - {paraiba.vertices_nao_adjacentes()}")