from meu_grafo_matriz_adj_dir import MeuGrafo
from bibgrafo.vertice import Vertice
from bibgrafo.aresta import ArestaDirecionada
from copy import deepcopy
from bibgrafo.grafo_json import GrafoJSON

def createGraphDir():
  vertices = [ Vertice('A'), Vertice('B'), Vertice('C'), Vertice('D'), Vertice('E') ]
  grafo = MeuGrafo(
    vertices=vertices,
  )

  grafo.adiciona_aresta(ArestaDirecionada('a0', vertices[2], vertices[4]))
  grafo.adiciona_aresta(ArestaDirecionada('a1', vertices[1], vertices[3]))
  grafo.adiciona_aresta(ArestaDirecionada('a2', vertices[4], vertices[3]))
  grafo.adiciona_aresta(ArestaDirecionada('a3', vertices[1], vertices[0]))
  grafo.adiciona_aresta(ArestaDirecionada('a4', vertices[0], vertices[2]))

  return deepcopy(grafo)

grafo = createGraphDir()

print(grafo)
