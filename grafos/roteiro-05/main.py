from meu_grafo_matriz_adj_dir import *
# from meu_grafo_matriz_adj_nao_dir import *
from bibgrafo.vertice import Vertice
from bibgrafo.aresta import Aresta
from bibgrafo.grafo_builder import GrafoBuilder

"""grafoNaoDir = GrafoBuilder().tipo(MeuGrafo()) \
    .vertices(['A', 'B', 'C', 'D']) \
    .arestas([
        Aresta('a1', Vertice('A'), Vertice('B')),
        Aresta('a2', Vertice('A'), Vertice('C')),
        Aresta('a3', Vertice('C'), Vertice('D')),
        Aresta('a4', Vertice('D'), Vertice('B')),
        Aresta('a5', Vertice('A'), Vertice('B')),
    ]) \
    .build()

# EXEMPLO COM O GRAFO NÃO DIRECIONADO
print("Contemple o meu grafo NÃO-DIRECIONADO: ")
print(grafoNaoDir)

print(f"Arestas não adjacentes: {grafoNaoDir.vertices_nao_adjacentes()}")
print(f"Há laço? {grafoNaoDir.ha_laco()}")
print(f"Grau do vértice D: {grafoNaoDir.grau('D')}")
print(f"Possui arestas paralelas? {grafoNaoDir.ha_paralelas()}")
print(f"É um grafo completo? {grafoNaoDir.eh_completo()}")
print(f"Arestas incidentes no vértice 'A': {grafoNaoDir.arestas_sobre_vertice('A')}")
# ==================================================================================="""

grafoDir = GrafoBuilder().tipo(MeuGrafo()).vertices(4).arestas(3).build()

print("Contemple o meu grafo DIRECIONADO: ")
print(grafoDir)

# print(f"Arestas não adjacentes: {grafoDir.vertices_nao_adjacentes()}")
# print(f"Há laço? {grafoDir.ha_laco()}")
# print(f"Grau do vértice D: {grafoDir.grau('D')}")
# print(f"Possui arestas paralelas? {grafoDir.ha_paralelas()}")
# print(f"É um grafo completo? {grafoDir.eh_completo()}")
# print(f"Arestas incidentes no vértice 'A': {grafoDir.arestas_sobre_vertice('A')}")
