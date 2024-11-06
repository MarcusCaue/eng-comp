from bibgrafo.grafo_lista_adjacencia import GrafoListaAdjacencia, Aresta, Vertice
from bibgrafo.grafo_errors import *

class MeuGrafo(GrafoListaAdjacencia):

    def vertices_nao_adjacentes(self):
        '''
        Provê um conjunto de vértices não adjacentes no grafo.
        O conjunto terá o seguinte formato: {X-Z, X-W, ...}
        Onde X, Z e W são vértices no grafo que não tem uma aresta entre eles.
        :return: Um objeto do tipo set que contém os pares de vértices não adjacentes
        '''

        """ verticesNaoAdj = set()
        vertices = self.vertices
        arestas = self.arestas

        for v in vertices:   
            for a in arestas:
                if a.ehPonta(v):
                    
                           
            verticesNaoAdj.add(f"{str(v)[0]}-{str(v)[0]}")
        
        print(verticesNaoAdj) """

        pass # Apague essa instrução e inicie seu código aqui

    # Tá PRONTO e está TESTADO
    def ha_laco(self):
        '''
        Verifica se existe algum laço no grafo.
        :return: Um valor booleano que indica se existe algum laço.
        '''
        arestas = self.arestas

        for rot in arestas:
            if (arestas[rot].v1 == arestas[rot].v2):
                return True
        
        return False
    
    # Tá PRONTO e está TESTADO
    def grau(self, V=''):
        '''
        Provê o grau do vértice passado como parâmetro
        :param V: O rótulo do vértice a ser analisado
        :return: Um valor inteiro que indica o grau do vértice
        :raises: VerticeInvalidoError se o vértice não existe no grafo
        '''
        vertice = self.get_vertice(V)
        arestas = self.arestas

        grau = 0
        for a in arestas.values():
            if a.eh_ponta(vertice):
                if a.v1 == a.v2: # Quando for laço
                    grau += 2
                else:
                    grau += 1
        
        return grau
              
    # Continuar a partir daqui
    def ha_paralelas(self):
        '''
        Verifica se há arestas paralelas no grafo
        :return: Um valor booleano que indica se existem arestas paralelas no grafo.
        '''
        arestas = self.arestas.copy()

        for a1 in arestas:
            print(f"Aresta '{a1}' em análise: \nOutras arestas: ")
            arestas.pop(a1)
            for a2 in arestas:
                print(a2, end=" ")






        pass

    def arestas_sobre_vertice(self, V):
        '''
        Provê uma lista que contém os rótulos das arestas que incidem sobre o vértice passado como parâmetro
        :param V: Um string com o rótulo do vértice a ser analisado
        :return: Uma lista os rótulos das arestas que incidem sobre o vértice
        :raises: VerticeInvalidoException se o vértice não existe no grafo
        '''
        pass

    def eh_completo(self):
        '''
        Verifica se o grafo é completo.
        :return: Um valor booleano que indica se o grafo é completo
        '''
        pass