from bibgrafo.grafo_builder import GrafoBuilder
from meu_grafo_lista_adj_nao_dir import MeuGrafo
from bibgrafo.grafo_lista_adj_nao_dir import Aresta
from bibgrafo.grafo import Vertice

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

# Todo grafo por padrão é conectado
# grafo_aleatorio = GrafoBuilder().tipo(MeuGrafo()).vertices(8).arestas(8).build()

# print("Grafo aleatório: ")
# print(grafo_aleatorio)

# print("Árvores DFS:")

# for i in range(5):
#   print(f"Árvore {i}")
#   print(grafo_aleatorio.dfs('A'))

# print("Grafo da Paraíba")
# print(paraiba)

# print("Árvore DFS: ")
# print(paraiba.dfs('J'))

# print("Árvore BFS: ")
# print(paraiba.bfs("J"))
