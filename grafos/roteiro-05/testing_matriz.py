from meu_grafo_matriz_adj_nao_dir import MeuGrafoNaoDir
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

print(grafoNaoDirecionado)
print(grafoDirecionado)

print(f"(GRAFO NAO DIR) -> vertices_nao_adj(): {grafoNaoDirecionado.vertices_nao_adjacentes()}")
print(f"(GRAFO DIR) -> vertices_nao_adj(): {grafoDirecionado.vertices_nao_adjacentes()}\n")

print(f"(GRAFO NAO DIR) -> ha_laco(): {grafoNaoDirecionado.ha_laco()}")
print(f"(GRAFO DIR) -> ha_laco(): {grafoDirecionado.ha_laco()}\n")

print(f"(GRAFO NAO DIR) -> ha_paralelas(): {grafoNaoDirecionado.ha_paralelas()}")
print(f"(GRAFO DIR) -> ha_paralelas(): {grafoDirecionado.ha_paralelas()}\n")

print(f"(GRAFO NAO DIR) -> arestas_sobre_vertice(): {grafoNaoDirecionado.arestas_sobre_vertice('E')}")
print(f"(GRAFO DIR) -> arestas_sobre_vertice(): {grafoDirecionado.arestas_sobre_vertice('E')}\n")

print(f"(GRAFO NAO DIR) -> eh_completo(): {grafoNaoDirecionado.eh_completo()}")
print(f"(GRAFO DIR) -> eh_completo(): {grafoDirecionado.eh_completo()}\n")

print(f"(GRAFO NAO DIR) -> grau(): {grafoNaoDirecionado.grau('B')}")
print(f"(GRAFO DIR) -> grau_entrada() + grau_saida: {grafoDirecionado.grau_entrada('B') + grafoDirecionado.grau_saida('B')}\n")
