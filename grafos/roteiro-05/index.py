from bibgrafo.grafo_errors import *
from meu_grafo_matriz_adj_nao_dir import MeuGrafo
from bibgrafo.grafo_builder import GrafoBuilder
from bibgrafo.aresta import Aresta

def criaGrafo():
  grafo = GrafoBuilder().tipo(MeuGrafo()).vertices(5).build()
  grafo.adiciona_aresta(Aresta("a0", grafo.get_vertice("A"), grafo.get_vertice("D")))
  grafo.adiciona_aresta(Aresta("a1", grafo.get_vertice("E"), grafo.get_vertice("D")))
  grafo.adiciona_aresta(Aresta("a2", grafo.get_vertice("A"), grafo.get_vertice("B")))
  grafo.adiciona_aresta(Aresta("a3", grafo.get_vertice("E"), grafo.get_vertice("B")))
  grafo.adiciona_aresta(Aresta("a4", grafo.get_vertice("C"), grafo.get_vertice("A")))
  grafo.adiciona_aresta(Aresta("a5", grafo.get_vertice("C"), grafo.get_vertice("B")))
  grafo.adiciona_aresta(Aresta("a6", grafo.get_vertice("D"), grafo.get_vertice("B")))
  grafo.adiciona_aresta(Aresta("a7", grafo.get_vertice("D"), grafo.get_vertice("A")))
  return grafo

def haCaminho(v1, v2, alvo, grafo: MeuGrafo):
  if not grafo.existe_rotulo_vertice(v1) or \
    not grafo.existe_rotulo_vertice(v2) or \
    not grafo.existe_rotulo_vertice(alvo):
      raise VerticeInvalidoError
  
  v_linha = grafo.indice_do_vertice(grafo.get_vertice(v1))
  v_col = grafo.indice_do_vertice(grafo.get_vertice(v2))

  adjacencia = grafo.matriz[v_linha][v_col]

  if len(adjacencia) > 0:
    return 1
  
  # Percorre por cada vertice
  for i in range(len(grafo.vertices)):
    v = grafo.vertices[i]
    haCaminho(v1, v, grafo)

    
    # Se ha adjacencia com v2
  
  return 0


  


grafo = criaGrafo()
print(grafo)

haCaminho("A", "E", grafo)
