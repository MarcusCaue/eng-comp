from bibgrafo.grafo_builder import GrafoBuilder
from meu_grafo_lista_adj_nao_dir import MeuGrafo
from bibgrafo.grafo_lista_adj_nao_dir import Aresta
from bibgrafo.grafo import Vertice

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

grafo_k5 = GrafoBuilder().tipo(MeuGrafo()).vertices(5).arestas(True).build()

print(grafo_k5)
print(grafo_k5.ha_ciclo())