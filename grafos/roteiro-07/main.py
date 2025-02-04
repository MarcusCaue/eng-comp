from bibgrafo.grafo_builder import GrafoBuilder
from meu_grafo_matriz_adj_dir import MeuGrafo
from bibgrafo.aresta import ArestaDirecionada
from bibgrafo.vertice import Vertice

grafo = GrafoBuilder().tipo(MeuGrafo()) \
    .vertices(['I', 'A', 'B', 'C', 'D', 'E']) \
    .arestas([
        ArestaDirecionada('a1', Vertice('I'), Vertice('A'), 10),
        ArestaDirecionada('a2', Vertice('I'), Vertice('E'), 8),
        ArestaDirecionada('a3', Vertice('E'), Vertice('D'), 1),
        ArestaDirecionada('a4', Vertice('A'), Vertice('C'), 2),
        ArestaDirecionada('a5', Vertice('D'), Vertice('C'), -1),
        ArestaDirecionada('a6', Vertice('D'), Vertice('A'), -4),
        ArestaDirecionada('a7', Vertice('C'), Vertice('B'), -2),
        ArestaDirecionada('a8', Vertice('B'), Vertice('A'), 1),
    ]).build()


print(grafo)
print(grafo.bellman_ford('A', 'E'))
