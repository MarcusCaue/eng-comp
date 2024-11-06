from bibgrafo.grafo_lista_adjacencia import Aresta, Vertice
from meu_grafo import MeuGrafo

def init(grafo: MeuGrafo) -> MeuGrafo:
  grafo = MeuGrafo(
    vertices = [Vertice("J"), Vertice("M"), Vertice("Z"), Vertice("T")],
  )

  grafo.adiciona_vertice("E")
  grafo.adiciona_vertice("P")
  grafo.adiciona_vertice("C")

  grafo.arestas = {
    "a1": Aresta("a1", grafo.get_vertice("J"), grafo.get_vertice("C")),
    "a2": Aresta("a2", grafo.get_vertice("C"), grafo.get_vertice("E")),
    "a3": Aresta("a3", grafo.get_vertice("C"), grafo.get_vertice("E")),
    "a4": Aresta("a4", grafo.get_vertice("C"), grafo.get_vertice("P")),
    "a5": Aresta("a5", grafo.get_vertice("C"), grafo.get_vertice("P")),
    "a6": Aresta("a6", grafo.get_vertice("C"), grafo.get_vertice("M")),
    "a7": Aresta("a7", grafo.get_vertice("C"), grafo.get_vertice("T")),
  }

  grafo.adiciona_aresta("a8", "M", "T")
  grafo.adiciona_aresta("a9", "T", "Z")

  return grafo

def ha_laco_test(grafo: MeuGrafo):
  copia = MeuGrafo(grafo.vertices, grafo.arestas)

  print("Grafo cópia: ")
  print(copia)

  print(f"Tem laço? {copia.ha_laco()}") # Antes da adição do laço
  copia.adiciona_aresta("a10", "J", "J") 
  print(f"Tem laço? {copia.ha_laco()}") # Depois da adição do laço

def grau_vertice_test(grafo: MeuGrafo):
  copia = MeuGrafo(grafo.vertices, grafo.arestas)

  print("Grafo cópia: ")
  print(copia)

  print(f"Grau do vértice O: {copia.grau('O')}") # Vértice inexistente
  print(f"Grau do vértice P: {copia.grau('P')}") # Vértice de grau > 0

  copia.adiciona_vertice("A")
  print(f"Grau do vértice A: {copia.grau('A')}") # Vértice de grau 0

# Setup do Grafo
paraiba = MeuGrafo()
paraiba = init(paraiba)

# Grafo Padrão
# print(paraiba)

# Verificando a existência de laços
# ha_laco_test(paraiba)

# Verificando o grau de um vértice
# grau_vertice_test(paraiba)

paraiba.ha_paralelas()

