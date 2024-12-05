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

# Ciclos do Grafo da Paraíba
"""

Notas:
  - Todo vértice que tem somente uma aresta não possui um ciclo partindo dele e ele não pode estar no meio do caminho.
    - É o caso de 'J' e 'Z'
  
  - Um vértice cujas arestas são todas paralelas a um mesmo vértice não possui ciclo e não pode estar no meio do caminho
    - É o caso de 'E' e 'P'

T a7 C a6 M a8 T
T a8 M a6 C a7 T

T a8 M a6 C a2 E a3 C a7 T (ERRO, 'C' se repete)
T a8 M a6 C a4 P a5 C a7 T (ERRO, 'C' se repete)

"""

for v in paraiba.get_rotulos_vertices():
  plotarGrafo(paraiba.bfs(v))

