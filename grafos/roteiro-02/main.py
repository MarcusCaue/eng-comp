from meu_grafo_lista_adj_nao_dir import MeuGrafo
from bibgrafo.grafo_lista_adj_nao_dir import Aresta
from bibgrafo.grafo import Vertice

paraiba = MeuGrafo()

# ======================= INSERINDO VÉRTICES =======================
# Pela biblioteca
paraiba.adiciona_vertice("J") 
paraiba.adiciona_vertice("C")
# Usando métodos de lista
paraiba.vertices.append(Vertice("P"))
paraiba.vertices.extend([Vertice("E")])
# Manipulando diretamente o atributo
paraiba.vertices += [ Vertice("Z"), Vertice("M"), Vertice("T") ]

# print(paraiba)

# ======================= INSERINDO ARESTAS =======================
# Manipulando diretamente o atributo
paraiba.arestas = {
    'a5': Aresta("a5", paraiba.get_vertice("C"), paraiba.get_vertice("P")),
    'a6': Aresta('a6', paraiba.get_vertice('C'), paraiba.get_vertice('M')),
    'a7': Aresta("a7", paraiba.get_vertice("C"), paraiba.get_vertice("T")),
    'a8': Aresta('a8', paraiba.get_vertice('M'), paraiba.get_vertice('T')),
    'a9': Aresta('a9', paraiba.get_vertice('T'), paraiba.get_vertice('Z')),
}
# Pela biblioteca
paraiba.adiciona_aresta(Aresta("a1", paraiba.get_vertice("J"), paraiba.get_vertice("C")))
paraiba.adiciona_aresta(Aresta("a2", paraiba.get_vertice("C"), paraiba.get_vertice("E")))
# Manipulando o dicionário
paraiba.arestas['a3'] = Aresta('a3', paraiba.get_vertice("C"), paraiba.get_vertice("E"))
paraiba.arestas['a4'] = Aresta('a4', paraiba.get_vertice("C"), paraiba.get_vertice("P"))

print(paraiba)

paraibaClone = MeuGrafo()
paraibaClone.vertices = paraiba.vertices
paraibaClone.arestas = paraiba.arestas

print(paraibaClone)

print("Os grafos são iguais?", paraiba == paraibaClone)


# paraiba.arestas = {
#     "a2": paraiba.get_vertice
# }

