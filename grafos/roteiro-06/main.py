from meu_grafo_matriz_adj_dir import MeuGrafo
from bibgrafo.grafo_builder import GrafoBuilder
from bibgrafo.aresta import ArestaDirecionada

grafo = GrafoBuilder().tipo(MeuGrafo()).vertices(4).arestas(6).build()

print(grafo)
grafo.dijkstra('A', 'D')
