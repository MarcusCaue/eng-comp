from meu_grafo_matriz_adj_dir import MeuGrafo
from bibgrafo.vertice import Vertice
from bibgrafo.aresta import Aresta, ArestaDirecionada
from copy import deepcopy

def createGraphDir():
  vertices = [ Vertice('A'), Vertice('B'), Vertice('C'), Vertice('D'), Vertice('E') ]
  grafo = MeuGrafo(
    vertices=vertices,
  )

  grafo.adiciona_aresta(ArestaDirecionada('a0', vertices[2], vertices[4]))
  grafo.adiciona_aresta(ArestaDirecionada('a1', vertices[1], vertices[3]))
  grafo.adiciona_aresta(ArestaDirecionada('a2', vertices[4], vertices[3]))
  grafo.adiciona_aresta(ArestaDirecionada('a3', vertices[1], vertices[0]))

  return deepcopy(grafo)

