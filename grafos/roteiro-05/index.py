from meu_grafo_matriz_adj_dir import MeuGrafo
from bibgrafo.vertice import Vertice
from bibgrafo.aresta import ArestaDirecionada
from bibgrafo.grafo_builder import GrafoBuilder
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
grafoParaiba = GrafoJSON.json_to_grafo('test_json/grafo_pb.json', MeuGrafo())
grafoParaiba.adiciona_aresta(ArestaDirecionada("a10", grafoParaiba.get_vertice('J'), grafoParaiba.get_vertice('C')))
grafoParaiba.adiciona_aresta(ArestaDirecionada("a12", grafoParaiba.get_vertice('J'), grafoParaiba.get_vertice('C')))
grafoParaiba.adiciona_aresta(ArestaDirecionada("a11", grafoParaiba.get_vertice('J'), grafoParaiba.get_vertice('C')))

g_e = MeuGrafo()
g_e.adiciona_vertice("A")
g_e.adiciona_vertice("B")
g_e.adiciona_vertice("C")
g_e.adiciona_vertice("D")
g_e.adiciona_vertice("E")
g_e.adiciona_aresta('1', 'A', 'B')
g_e.adiciona_aresta('2', 'A', 'C')
g_e.adiciona_aresta('3', 'C', 'A')
g_e.adiciona_aresta('4', 'C', 'B')
g_e.adiciona_aresta('10', 'C', 'B')
g_e.adiciona_aresta('5', 'C', 'D')
g_e.adiciona_aresta('6', 'D', 'D')
g_e.adiciona_aresta('7', 'D', 'B')
g_e.adiciona_aresta('8', 'D', 'E')
g_e.adiciona_aresta('9', 'E', 'A')
g_e.adiciona_aresta('11', 'E', 'B')

print(g_e.warshall())

