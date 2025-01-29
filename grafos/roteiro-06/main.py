from meu_grafo_matriz_adj_dir import MeuGrafo
from bibgrafo.grafo_builder import GrafoBuilder
from bibgrafo.aresta import ArestaDirecionada
from bibgrafo.vertice import Vertice

vertices = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
arestas = [
  ArestaDirecionada('a0', Vertice(vertices[0]), Vertice(vertices[1]), 1), # A -> B
  ArestaDirecionada('a1', Vertice(vertices[0]), Vertice(vertices[2]), 4), # A -> C
  ArestaDirecionada('a2', Vertice(vertices[1]), Vertice(vertices[3]), 5), # B -> D
  ArestaDirecionada('a3', Vertice(vertices[2]), Vertice(vertices[3]), 1), # C -> D
  ArestaDirecionada('a4', Vertice(vertices[3]), Vertice(vertices[4]), 2), # D -> E
  ArestaDirecionada('a5', Vertice(vertices[3]), Vertice(vertices[5]), 1), # D -> F
  ArestaDirecionada('a6', Vertice(vertices[2]), Vertice(vertices[5]), 3), # C -> F
  ArestaDirecionada('a7', Vertice(vertices[5]), Vertice(vertices[6]), 4), # F -> G
  ArestaDirecionada('a8', Vertice(vertices[4]), Vertice(vertices[6]), 2)  # E -> G
]

grafo = GrafoBuilder().tipo(MeuGrafo()).vertices(vertices).arestas(arestas).build()

print(grafo)
grafo.dijkstra('A', 'E')
