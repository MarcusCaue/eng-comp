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

        # Verificando se o grafo é completo
        if self.eh_completo():
            return set()
        
        vertices = self.vertices
        arestas = self.arestas

        rotulosVertices = { v.rotulo for v in vertices }
        naoAdjacentesGrafo = set()

        for v in vertices:
            arestasIncidentes = self.arestas_sobre_vertice(v.rotulo)
            verticesAdj = set()
            
            for a in arestasIncidentes:
                if arestas[a].v1 != v:
                    verticesAdj.add(arestas[a].v1.rotulo)
                if arestas[a].v2 != v:
                    verticesAdj.add(arestas[a].v2.rotulo)
            
            naoAdj = rotulosVertices.difference(verticesAdj)

            for vNaoAdj in naoAdj:
                adjacencia = f"{v.rotulo}-{vNaoAdj}"
                
                if adjacencia[::-1] not in naoAdjacentesGrafo and v.rotulo != vNaoAdj:
                    naoAdjacentesGrafo.add(f"{v.rotulo}-{vNaoAdj}")

        return naoAdjacentesGrafo

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
 
    def ha_paralelas(self):
        '''
        Verifica se há arestas paralelas no grafo
        :return: Um valor booleano que indica se existem arestas paralelas no grafo.
        '''
        arestas = self.arestas
        for a in arestas:
            outrasArestas = arestas.copy()
            outrasArestas.pop(a)

            for aX in outrasArestas.values():
                if arestas[a].eh_ponta(aX.v1) and arestas[a].eh_ponta(aX.v2):
                    return True
        
        return False

    def arestas_sobre_vertice(self, V):
        '''
        Provê uma lista que contém os rótulos das arestas que incidem sobre o vértice passado como parâmetro
        :param V: Um string com o rótulo do vértice a ser analisado
        :return: Uma lista com os rótulos das arestas que incidem sobre o vértice
        :raises: VerticeInvalidoException se o vértice não existe no grafo
        '''
        vertice = self.get_vertice(V)
        arestas = self.arestas

        if self.grau(V) == 0:
            return set()
        
        arestasOnVertice = set()
        for a in arestas:
            if arestas[a].eh_ponta(vertice):
                arestasOnVertice.add(a)
    
        return arestasOnVertice

    def eh_completo(self):
        '''
        Verifica se o grafo é completo.
        :return: Um valor booleano que indica se o grafo é completo
        '''

        # Verificando se o grafo não é simples
        if self.ha_laco() or self.ha_paralelas():
            return False
        
        vertices = self.vertices
        referenciaQuantVert = len(vertices) - 1

        for vertice in vertices:
            if self.grau(vertice.rotulo) != referenciaQuantVert:
                return False
        
        return True