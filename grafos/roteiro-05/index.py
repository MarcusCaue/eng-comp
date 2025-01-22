from bibgrafo.grafo_errors import *
from meu_grafo_matriz_adj_nao_dir import MeuGrafoNaoDir
from bibgrafo.grafo_builder import GrafoBuilder
from meu_grafo_matriz_adj_dir import MeuGrafoDir
from bibgrafo.vertice import Vertice
from bibgrafo.aresta import Aresta, ArestaDirecionada
from copy import deepcopy

def createGraphNonDir():
  vertices = [ Vertice('A'), Vertice('B'), Vertice('C'), Vertice('D'), Vertice('E') ]
  grafo = MeuGrafoNaoDir(
    vertices=vertices,
  )

  grafo.adiciona_aresta(Aresta('a0', vertices[4], vertices[0]))
  grafo.adiciona_aresta(Aresta('a1', vertices[1], vertices[0]))
  grafo.adiciona_aresta(Aresta('a2', vertices[1], vertices[2]))
  grafo.adiciona_aresta(Aresta('a3', vertices[4], vertices[3]))

  return deepcopy(grafo)

def createGraphDir():
  vertices = [ Vertice('A'), Vertice('B'), Vertice('C'), Vertice('D'), Vertice('E') ]
  grafo = MeuGrafoDir(
    vertices=vertices,
  )

  grafo.adiciona_aresta(ArestaDirecionada('a0', vertices[2], vertices[4]))
  grafo.adiciona_aresta(ArestaDirecionada('a1', vertices[1], vertices[3]))
  grafo.adiciona_aresta(ArestaDirecionada('a2', vertices[4], vertices[3]))
  grafo.adiciona_aresta(ArestaDirecionada('a3', vertices[1], vertices[0]))

  return deepcopy(grafo)


grafoNaoDirecionado = createGraphNonDir()
grafoDirecionado = createGraphDir()

# print(grafoNaoDirecionado)
print(grafoDirecionado)
# print(grafoDirecionado.matriz, '\n')
# print(grafoDirecionado.matriz[1][0]['a3'], '\n')

print(grafoDirecionado.arestas_sobre_vertice('E'))


""" print(f"(GRAFO NAO DIR) -> vertices_nao_adj(): {grafoNaoDirecionado.vertices_nao_adjacentes()}")
print(f"(GRAFO DIR) -> vertices_nao_adj(): {grafoDirecionado.vertices_nao_adjacentes()}\n")

print(f"(GRAFO NAO DIR) -> ha_laco(): {grafoNaoDirecionado.ha_laco()}")
print(f"(GRAFO DIR) -> ha_laco(): {grafoDirecionado.ha_laco()}\n")

print(f"(GRAFO NAO DIR) -> ha_paralelas(): {grafoNaoDirecionado.ha_paralelas()}")
print(f"(GRAFO DIR) -> ha_paralelas(): {grafoDirecionado.ha_paralelas()}\n")

 """