from meu_grafo_lista_adj_nao_dir import MeuGrafo
from bibgrafo.grafo_lista_adj_nao_dir import Aresta
from bibgrafo.grafo import Vertice
from bibgrafo.grafo_errors import VerticeInvalidoError

paraiba = MeuGrafo(
  vertices = [Vertice("Z"), Vertice("M"), Vertice("T"), Vertice("J"), Vertice("C"), Vertice("E"), Vertice("P")],
)

paraiba.arestas = {
    'a1': Aresta('a1', paraiba.get_vertice('J'), paraiba.get_vertice('C')),
    'a2': Aresta('a2', paraiba.get_vertice('C'), paraiba.get_vertice('E')),
    'a3': Aresta('a3', paraiba.get_vertice('C'), paraiba.get_vertice('E')),
    'a4': Aresta('a4', paraiba.get_vertice('C'), paraiba.get_vertice('P')),
    'a5': Aresta('a5', paraiba.get_vertice('C'), paraiba.get_vertice('P')),
    'a6': Aresta('a6', paraiba.get_vertice('C'), paraiba.get_vertice('M')),
    'a7': Aresta('a7', paraiba.get_vertice('C'), paraiba.get_vertice('T')),
    'a8': Aresta('a8', paraiba.get_vertice('M'), paraiba.get_vertice('T')),
    'a9': Aresta('a9', paraiba.get_vertice('T'), paraiba.get_vertice('Z')),
}

print(paraiba)

paraiba.dfs("J")


