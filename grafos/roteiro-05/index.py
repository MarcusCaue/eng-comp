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

grafoParaiba = GrafoJSON.json_to_grafo('test_json/grafo_pb.json', MeuGrafo())

print(grafoParaiba)
print(grafoParaiba.vertices_nao_adjacentes())
caso_correto = {
  'J-E', 'J-P', 'J-M', 'J-T', 'J-Z', 'C-J', 'C-T', 'C-Z', 'C-M', 'C-P', 'E-C', 'E-J', 'E-P',
  'E-M', 'E-T', 'E-Z', 'P-J', 'P-E', 'P-M', 'P-T', 'P-Z', 'M-J', 'M-E', 'M-P', 'M-Z', 'T-J',
  'T-M', 'T-E', 'T-P', 'Z-J', 'Z-C', 'Z-E', 'Z-P', 'Z-M', 'Z-T'
 }

print (caso_correto)