from bibgrafo.grafo_matriz_adj_nao_dir import GrafoMatrizAdjacenciaNaoDirecionado
from bibgrafo.grafo_errors import *


class MeuGrafo(GrafoMatrizAdjacenciaNaoDirecionado):

    def vertices_nao_adjacentes(self):
        '''
        Provê um conjunto (set) de vértices não adjacentes no grafo.
        O conjunto terá o seguinte formato: {X-Z, X-W, ...}
        Onde X, Z e W são vértices no grafo que não tem uma aresta entre eles.
        :return: Um conjunto (set) com os pares de vértices não adjacentes
        '''
        vertices_nao_adj = set()

        for i in range(len(self.vertices)): 
            for j in range(i+1, len(self.matriz)):
                dict_arestas = self.matriz[i][j]
                if dict_arestas == dict():
                    vertices = f"{self.vertices[i]}-{self.vertices[j]}"
                    
                    if i != j:
                        vertices_nao_adj.add(vertices)
        
        return vertices_nao_adj

    def ha_laco(self):
        '''
        Verifica se existe algum laço no grafo.
        :return: Um valor booleano que indica se existe algum laço.
        '''
        for i in range(len(self.vertices)):
            arestas = self.matriz[i][i]
            if arestas != dict():
                return True
        
        return False

    def grau(self, V=''):
        '''
        Provê o grau do vértice passado como parâmetro
        :param V: O rótulo do vértice a ser analisado
        :return: Um valor inteiro que indica o grau do vértice
        :raises: VerticeInvalidoError se o vértice não existe no grafo
        '''
        if not self.existe_rotulo_vertice(V):
            raise VerticeInvalidoError
    
        index_vertice = self.indice_do_vertice(self.get_vertice(V))
        adjacencias = self.matriz[index_vertice]

        grau = 0
        for cel in adjacencias:
            index_cel = adjacencias.index(cel)
            quant_arestas = len(cel.keys())

            if index_cel == index_vertice:
                grau += quant_arestas * 2
            else:
                grau += quant_arestas
        
        return grau
        
    def ha_paralelas(self):
        '''
        Verifica se há arestas paralelas no grafo
        :return: Um valor booleano que indica se existem arestas paralelas no grafo.
        '''
        for i in range(len(self.vertices)):
            for j in range(i, len(self.vertices)):
                arestas = self.matriz[i][j]
                quant_arestas = len(arestas.keys())

                if quant_arestas > 1:
                    return True
                
        return False

    def arestas_sobre_vertice(self, V):
        '''
        Provê um conjunto (set) que contém os rótulos das arestas que
        incidem sobre o vértice passado como parâmetro
        :param V: O vértice a ser analisado
        :return: Um conjunto com os rótulos das arestas que incidem sobre o vértice
        :raises: VerticeInvalidoError se o vértice não existe no grafo
        '''
        if not self.existe_rotulo_vertice(V):
            raise VerticeInvalidoError
        
        index_vertice = self.indice_do_vertice(self.get_vertice(V))
        adjacencias = self.matriz[index_vertice]
        rotulos_arestas = set()

        for adj in adjacencias:
            if adj != dict():
                rotulos = adj.keys()
                for r in rotulos:
                    rotulos_arestas.add(r) 
        
        return rotulos_arestas

    def eh_completo(self):
        '''
        Verifica se o grafo é completo.
        :return: Um valor booleano que indica se o grafo é completo
        '''
        if self.ha_laco() or self.ha_paralelas():
            return False
        
        quant_vertices = len(self.vertices)
        
        for i in range(quant_vertices):
            quant_adjacencias = 0
            adjacencias = self.matriz[i]

            for adj in adjacencias:
                if adj != dict():
                    quant_adjacencias += 1
            
            if quant_adjacencias != (quant_vertices - 1):
                return False
        
        return True