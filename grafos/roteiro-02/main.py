import networkx as nx
import matplotlib.pyplot as plt

from bibgrafo.grafo_builder import GrafoBuilder
from meu_grafo_lista_adj_nao_dir import MeuGrafo
from bibgrafo.grafo_lista_adj_nao_dir import Aresta
from bibgrafo.grafo import Vertice

def plotarGrafo(grafo: MeuGrafo):
  g = nx.Graph()

  g.add_nodes_from( [ v.rotulo for v in grafo.vertices ] )
  g.add_edges_from([ (grafo.arestas[a].v1.rotulo, grafo.arestas[a].v2.rotulo) for a in grafo.arestas ])

  nx.draw(g, with_labels=True, arrows=True)
  plt.show()


# Setup do grafo da paraíba 
paraiba = GrafoBuilder().tipo(MeuGrafo()) \
  .vertices(["J", "C", "E", "M", "P", "T", "Z"]) \
  .arestas([
    Aresta('a1', Vertice('J'), Vertice('C')),
    Aresta('a2', Vertice('C'), Vertice('E')),
    Aresta('a3', Vertice('C'), Vertice('E')),
    Aresta('a4', Vertice('C'), Vertice('P')),
    Aresta('a5', Vertice('C'), Vertice('P')),
    Aresta('a6', Vertice('C'), Vertice('M')),
    Aresta('a7', Vertice('C'), Vertice('T')),
    Aresta('a8', Vertice('M'), Vertice('T')),
    Aresta('a9', Vertice('T'), Vertice('Z')),
  ]) \
  .build()

grafo_aleatorio = GrafoBuilder().tipo(MeuGrafo()).vertices(6).arestas(8).build()
grafo_conexo = GrafoBuilder().tipo(MeuGrafo()).vertices(4).arestas(True).build()

print("Grafo Aleatório: ")
print(grafo_aleatorio)

vertice = input("Escolha um vértice: ")
print(f"Vértices adjacentes a '{vertice}': {grafo_aleatorio.vertices_adjacentes(vertice)}")

# plotarGrafo(grafo_aleatorio)

# print("Árvores BFS:")
# bfs = grafo_aleatorio.bfs('A')
# print(bfs)

# for i in range(5):
#   bfs = grafo_aleatorio.bfs('A')
#   print(f"Árvore {i}")
#   print(bfs)
  # plotarGrafo(bfs)
