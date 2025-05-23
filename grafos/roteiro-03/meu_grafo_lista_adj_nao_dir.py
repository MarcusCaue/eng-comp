from bibgrafo.grafo_lista_adj_nao_dir import GrafoListaAdjacenciaNaoDirecionado
from bibgrafo.grafo_errors import *
from types import NoneType

class MeuGrafo(GrafoListaAdjacenciaNaoDirecionado):

    def ha_ciclo(self):
        # Não é possível formar um ciclo em um grafo que não tenha pelo menos 3 vértices e 3 arestas
        if len(self.vertices) < 3 or len(self.arestas) < 3:
            return False
        
        vertices_visitados = []
        for v in self.get_rotulos_vertices(): # Tentando montar um ciclo partindo de cada vértice do grafo
            if v not in vertices_visitados:
                vertices_visitados.append(v)    
                ciclo = self.monta_ciclo([], v, vertices_visitados)

                if ciclo != list() and ciclo[0] == ciclo[-1]:
                    return ciclo
        
        return False

        """
        - Para que haja um ciclo, é preciso de no mínimo 3 vértices 
        - Todo vértice que tem somente uma aresta não possui um ciclo partindo dele e ele não pode estar no meio do caminho.
            - É o caso de 'J' e 'Z'
        
        - Um vértice cujas arestas são todas paralelas a um mesmo vértice não possui ciclo e não pode estar no meio do caminho
            - É o caso de 'E' e 'P'

        T a7 C a6 M a8 T
        T a8 M a6 C a7 T

        T a8 M a6 C a2 E a3 C a7 T (ERRO, 'C' se repete)
        T a8 M a6 C a4 P a5 C a7 T (ERRO, 'C' se repete)

        
        - Preciso saber de alguma forma, na função recursiva, quais foram os vértices visitados
        - Preciso criar uma função que monta o ciclo a partir de um vértice de referência (esse pode ser recursivo)

        """
        
    def monta_ciclo(self, ciclo: list, vertice: str, vertices_visitados: list):
        # Se o vértice é de grau 1 então não tem como ir para outro vértice por outra aresta
        # Se todas as arestas do vértice incidem no mesmo vértice então não tem como ir para outro vértice por uma aresta não paralela
        if self.grau(vertice) == 1 or self.arestas_incidem_mesmo_vertice(vertice): 
            return ciclo
        
        # Se o ciclo já está pronto, então deve ser retornado
        if len(ciclo) > 6 and ciclo[0] == ciclo[-1]:
            return ciclo
        
        if len(ciclo) == 0:
            ciclo.append(vertice)
        else:
            aresta = self.get_aresta_entre(vertice, ciclo[-1])
            ciclo += [aresta.rotulo, vertice]

        vizinhos = self.vertices_adjacentes(vertice)

        for v in vizinhos:
            if v not in vertices_visitados:
                vertices_visitados.append(v)
                self.monta_ciclo(ciclo, v, vertices_visitados)

            elif len(ciclo) > 3 and v == ciclo[0] and ciclo[0] != ciclo[-1]:
                aresta = self.get_aresta_entre(vertice, v)
                ciclo += [aresta.rotulo, v]
                return ciclo 
        
        return ciclo

    def caminho(self, comprimento: int, v: str):
        if self.contem_vertice_nao_adjacente() or self.ha_laco():
            return False
        
        # E quando caminho é um ciclo?
        caminho = list()

        return self.monta_caminho_iterativo(v, comprimento)

        # return self.monta_caminho(v, comprimento, 0, MeuGrafo())
        

    def monta_caminho_iterativo(self, V: str, comp: int):
        if not self.existe_rotulo_vertice(V): 
            raise VerticeInvalidoError
        
        # Lista com as rotas que ele pode seguir
        rotas = self.arestas_sobre_vertice(V)

        caminho = [V]
        for r in rotas:
            outraPonta = self.outra_ponta(r, V)

            if comp == 1: # Quando o comprimento é 1
                caminho += [ r, outraPonta ]
                return caminho
            
            # Desconsiderando vértices que apontam para o mesmo vértice
            if self.arestas_incidem_mesmo_vertice(outraPonta):
                continue

            # Se ele passou pelos testes anteriores, então esta rota pode ser viável
            copia_caminho = caminho.copy()

            # Como faço para seguir uma determinada rota?


        pass


















    def monta_caminho(self, V: str, comp_ref: int, comp_atual: int, arvore_dfs: GrafoListaAdjacenciaNaoDirecionado):
        if not self.existe_rotulo_vertice(V): 
            raise VerticeInvalidoError
        
        if comp_atual == comp_ref:
            return arvore_dfs
        
        if len(arvore_dfs.vertices) == 0:
            arvore_dfs.adiciona_vertice(V)

        









        
        for rot in self.arestas_sobre_vertice(V):
            a = self.arestas[rot]
            outraPonta = (a.v1 if a.v1.rotulo != V else a.v2).rotulo

            if len(arvore_dfs.arestas) == comp_ref:
                return arvore_dfs

            if not arvore_dfs.existe_rotulo_vertice(outraPonta):
                if self.grau(outraPonta) != 1 and self.arestas_incidem_mesmo_vertice(outraPonta):
                    pass
                else:
                    comp_atual += 1
                    arvore_dfs.adiciona_vertice(outraPonta)
                    arvore_dfs.adiciona_aresta(a)
                    self.monta_caminho(outraPonta, comp_ref, comp_atual, arvore_dfs) 
     
        return arvore_dfs

    def dfs(self, V: str = '', arvore_dfs: GrafoListaAdjacenciaNaoDirecionado = None):
        # Verificando a existência do vértice no grafo
        if not self.existe_rotulo_vertice(V): 
            raise VerticeInvalidoError
        
        # Verificando se o grafo contém um vértice com nenhum outro adjacente a ele
        if self.contem_vertice_nao_adjacente() or self.ha_laco():
            return MeuGrafo()

        # Criando a árvore DFS quando ela não existe, isto é, na chamada não-recursiva da função
        if type(arvore_dfs) == NoneType:
            arvore_dfs = MeuGrafo()
        
        # Sempre que a função é chamada e passou pelas verificações, então o vértice do momento pode entrar na árvore DFS
        arvore_dfs.adiciona_vertice(V)

        # Retorna um conjunto de strings contendo os rótulos das arestas incidentes sobre o vértice
        conexoesDiretas = self.arestas_sobre_vertice(V)
        
        for rot in conexoesDiretas:
            a = self.arestas[rot]

            # Pegando o vértice oposto
            outraPonta = a.v1 if a.v1.rotulo != V else a.v2

            # Quando o vértice oposto não está na árvore
            if not arvore_dfs.existe_rotulo_vertice(outraPonta.rotulo):
                self.dfs(outraPonta.rotulo, arvore_dfs) # Aprofundamento
                arvore_dfs.adiciona_aresta(a)
     
        return arvore_dfs
        
    def bfs(self, V: str = ''):
        """
        Não consegui implementar a função por conta própria, então busquei um código pronto e o adaptei para funcionar com a biblioteca.
        Fonte do código base: https://youtu.be/mFb8WwI98b0?si=buxbZQZkRczjCRLj
        Autora: Hemili Beatriz Alves Trindade
        """

        # Verificando a existência do vértice no grafo
        if not self.existe_rotulo_vertice(V): 
            raise VerticeInvalidoError
        
        # Verificando se o grafo contém um vértice com nenhum outro adjacente a ele
        if self.contem_vertice_nao_adjacente() or self.ha_laco():
            return MeuGrafo()
        
        arvore_bfs = MeuGrafo()

        # Marcando todos os vértices do grafo como não visitados
        verticesNaoVisitados = dict()
        for v in self.vertices:
            verticesNaoVisitados[v.rotulo] = False
            arvore_bfs.adiciona_vertice(v.rotulo)

        # Fila de visitas, inserindo o nó raiz como o primeiro a ser visitado
        filaVisitas = [V]
        verticesNaoVisitados[V] = True # Marcando o nó raiz como visitado
        
        # Percorrendo a fila
        while len(filaVisitas) != 0:

            # Removendo o vértice que está sendo visitado
            visitado = filaVisitas.pop(0)

            adjacentesVisitado = self.vertices_adjacentes(visitado)
            arestasVizinhos = self.arestas_sobre_vertice(visitado)

            for v in adjacentesVisitado:
                # Visitando os vizinhos e adicionando os seus vizinhos na fila de visitas
                if verticesNaoVisitados[v] == False:
                    filaVisitas.append(v)
                    verticesNaoVisitados[v] = True

                    for rot in arestasVizinhos:
                        a = self.get_aresta(rot)
                        pontas = [ a.v1.rotulo, a.v2.rotulo ]

                        if (v in pontas and visitado in pontas):
                            arvore_bfs.adiciona_aresta(self.get_aresta(rot))

        return arvore_bfs

    def arestas_incidem_mesmo_vertice(self, V: str):
        arestas = self.arestas_sobre_vertice(V)
        pontas = []
        for rot in arestas:
            a = self.arestas[rot]
            if len(pontas) == 0:
                pontas.append(a.v1.rotulo)
                pontas.append(a.v2.rotulo)
            
            if a.v1.rotulo not in pontas or a.v2.rotulo not in pontas:
                return False
        
        return True

    def contem_vertice_nao_adjacente(self):
        """
        Verifica se um grafo contém pelo menos um vértice sem outros vértices adjacentes.
        :return: um valor booleano indicando se o grafo contém ou não um vértice adjacente a nenhum outro.
        """
        for v in self.vertices:
            if self.grau(v.rotulo) == 0:
                return True
        
        return False
        
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

    def vertices_adjacentes(self, V: str) -> set:
        arestasIncidentes = self.arestas_sobre_vertice(V)
        verticesAdj = set()
            
        for rot in arestasIncidentes:
            a = self.arestas[rot]
            outraPonta = a.v1 if a.v1.rotulo != V else a.v2
            verticesAdj.add(outraPonta.rotulo)
        
        return verticesAdj

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

    def get_rotulos_vertices(self):
        return [ v.rotulo for v in self.vertices ]

    def get_aresta_entre(self, ponta1: str, ponta2: str):
        """ Retorna o uma aresta que conecta os dois vértices passados como parâmetro """
        arestas = self.arestas

        for rot in arestas:
            a = arestas[rot]
            pontas = sorted([ a.v1.rotulo, a.v2.rotulo ])
            if pontas == sorted([ ponta1, ponta2 ]):
                return a
        
        raise ArestaInvalidaError

    def outra_ponta(self, rot_aresta: str, v: str):
        if not self.existe_rotulo_vertice(v):
            raise VerticeInvalidoError
        elif not self.existe_rotulo_aresta(rot_aresta):
            raise ArestaInvalidaError
        elif not self.arestas[rot_aresta].eh_ponta(self.get_vertice(v)):
            raise ArestaInvalidaError
        
        aresta = self.arestas[rot_aresta]
        outraPonta = (aresta.v1 if aresta.v1.rotulo != v else aresta.v2).rotulo

        return outraPonta