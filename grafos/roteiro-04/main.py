from meu_grafo_matriz_adj_nao_dir import *
from bibgrafo.vertice import Vertice
from bibgrafo.aresta import Aresta
from bibgrafo.grafo_builder import GrafoBuilder

grafo = GrafoBuilder().tipo(MeuGrafo()) \
    .vertices(['A', 'B', 'C', 'D']) \
    .arestas([
        Aresta('a1', Vertice('A'), Vertice('B')),
        Aresta('a2', Vertice('A'), Vertice('C')),
        Aresta('a3', Vertice('C'), Vertice('D')),
        Aresta('a4', Vertice('D'), Vertice('B')),
        Aresta('a5', Vertice('A'), Vertice('B')),
    ]) \
    .build()
grafo.vertices_nao_adjacentes()


