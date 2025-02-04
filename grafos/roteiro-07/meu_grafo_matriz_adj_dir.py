from json.encoder import INFINITY
from bibgrafo.grafo_matriz_adj_dir import *
from bibgrafo.grafo_errors import *
from copy import deepcopy

class MeuGrafo(GrafoMatrizAdjacenciaDirecionado):


    def bellman_ford(self, v_src="", v_dest=""):
        """
        Também retorna uma lista com os vértices e os pesos dos menores caminhos até eles
        """
        def grafo_viavel():
            # Grafo vazio ou sem arestas
            if self == MeuGrafo() or len(self.matriz) == 0:
                return False

            # Verifica a existência dos vértices no grafo
            if not self.existe_rotulo_vertice(v_src) or not self.existe_rotulo_vertice(v_dest):
                raise VerticeInvalidoError

            matrizAlcancabilidade = self.warshall()

            index_src = self.indice_do_vertice(self.get_vertice(v_src))
            index_dest = self.indice_do_vertice(self.get_vertice(v_dest))

            # Verificando se é possível alcançar o destino a partir da origem
            if matrizAlcancabilidade[index_src][index_dest] == 0:
                return False
            
            return True

        if not grafo_viavel():
            return []

        NULL = 0

        weights_min_ways = [[0] + [ INFINITY for _ in range(len(self.vertices) - 1) ]]
        menores_caminhos = [ NULL for _ in range(len(self.vertices)) ]

        for _ in range(len(self.vertices) - 1):
            if len(weights_min_ways) > 1 and weights_min_ways[-1] == weights_min_ways[-2]:
                break

            min_ways_i = weights_min_ways[-1].copy()

            for v in self.vertices:
                index_v = self.indice_do_vertice(v)

                if (min_ways_i[index_v] == INFINITY):
                    continue

                arestas_saida = self.get_arestas_saida(v)
                for a in arestas_saida:
                    outra_ponta = self.outra_ponta_aresta(a.rotulo, v.rotulo)
                    index_outra_ponta = self.indice_do_vertice(self.get_vertice(outra_ponta))

                    novo_peso = min_ways_i[index_v] + a.peso

                    if novo_peso < min_ways_i[index_outra_ponta]:
                        min_ways_i[index_outra_ponta] = novo_peso
                        menores_caminhos[index_outra_ponta] = {"peso": novo_peso, "antecessor": v.rotulo, "aresta": a.rotulo}
            
            weights_min_ways.append(min_ways_i)
        
        caminho = []
        w = v_dest
        while w != v_src:
            for i, m in enumerate(menores_caminhos):
                vertice = self.vertices[i].rotulo

                if w == vertice:
                    if w == v_src:
                        break

                    caminho.insert(0, w)
                    caminho.insert(0, m['aresta'])
                    w = m['antecessor']

        caminho.insert(0, v_src)
    
        return caminho


    def get_arestas_saida(self, v: Vertice) -> list[ArestaDirecionada]:
        arestas_saida = self.matriz[self.indice_do_vertice(v)]
        retorno = []

        for a in arestas_saida:
            if a != dict():
                retorno.append(*list(a.values()))
                
        return retorno

    def dijkstra(self, v_src="", v_dest="") -> list[str]:

        def grafo_viavel():
            # Grafo vazio ou sem arestas
            if self == MeuGrafo() or len(self.matriz) == 0:
                return False

            # Verifica a existência dos vértices no grafo
            if not self.existe_rotulo_vertice(v_src) or not self.existe_rotulo_vertice(v_dest):
                raise VerticeInvalidoError

            matrizAlcancabilidade = self.warshall()

            index_src = self.indice_do_vertice(self.get_vertice(v_src))
            index_dest = self.indice_do_vertice(self.get_vertice(v_dest))

            # Verificando se é possível alcançar o destino a partir da origem
            if matrizAlcancabilidade[index_src][index_dest] == 0:
                return False
            
            return True

        def get_index_menor_beta(betas: list, gamas: list):

            betas_vertices_nao_visitados = []
            for i in range(len(gamas)):
                b = betas[i]
                g = gamas[i]

                if g == 0:
                    betas_vertices_nao_visitados.append({ "index": i, "valor": b })
        
            menor = betas_vertices_nao_visitados[0]["valor"]
            index = betas_vertices_nao_visitados[0]["index"]
            for i in range(1, len(betas_vertices_nao_visitados)):
                b = betas_vertices_nao_visitados[i]["valor"]
                if b < menor:
                    menor = b
                    index = betas_vertices_nao_visitados[i]["index"]
            
            return index

        if not grafo_viavel():
            return []

        # Setup #
        NULL = 0

        quant_vertices = len(self.vertices)
        # Pesos dos menores caminhos
        betas    = [INFINITY for _ in range(quant_vertices)]
        # Vértices predecessores
        pis      = [NULL for _ in range(quant_vertices)]
        # Vértices visitados (0/1)
        gamas = [0 for _ in range(quant_vertices)]

        # Início
        w = v_src
        v = v_dest

        while w != v:
            index_w = self.indice_do_vertice(self.get_vertice(w))
            gamas[index_w] = 1

            if w == v_src:
                betas[index_w] = 0
            
            arestas_saida = self.matriz[index_w]
            for a in arestas_saida:
                if a != dict():
                    arco = list(a.values())[0]
                    outra_ponta = self.outra_ponta_aresta(arco.rotulo, w)
                    index_outra_ponta = self.indice_do_vertice(self.get_vertice(outra_ponta))

                    novo_beta = arco.peso + betas[index_w]

                    if novo_beta < betas[index_outra_ponta]:
                        betas[index_outra_ponta] = novo_beta
                        pis[index_outra_ponta] = { "vertice": w, "aresta": arco.rotulo }
            
            index_menor_beta = get_index_menor_beta(betas, gamas)
            w = self.vertices[index_menor_beta].rotulo

        # Montando o caminho
        caminho = []
        w = v_src
        while v != w:
            caminho.insert(0, v)
            index_v = self.indice_do_vertice(self.get_vertice(v))
            caminho.insert(0, pis[index_v]["aresta"])
            v = pis[index_v]["vertice"]
        
        caminho.insert(0, w)

        return caminho

    def outra_ponta_aresta(self, rotulo="", ponta_rot="") -> str:
        aresta = self.get_aresta(rotulo)
        if aresta.v1.rotulo == ponta_rot:
            return aresta.v2.rotulo
        else:
            return aresta.v1.rotulo

    def get_aresta(self, rotulo="") -> ArestaDirecionada:
        for a in self.get_todas_arestas():
            if rotulo == a.rotulo:
                return a

        raise ArestaInvalidaError

    def get_todas_arestas(self) -> list[ArestaDirecionada]:
        arestas = list()

        for linha in range(len(self.matriz)):
            for coluna in range(len(self.matriz)):
                arestas_dict = self.matriz[linha][coluna]
                if arestas_dict != dict():
                    valores = arestas_dict.values()
                    for v in valores:
                        arestas.append(v)
        
        return arestas

    def vertices_nao_adjacentes(self) -> set[str]:
        '''
        Provê uma lista de vértices não adjacentes no grafo. A lista terá o seguinte formato: [X-Z, X-W, ...]
        Onde X, Z e W são vértices no grafo que não tem uma aresta entre eles.
        :return: Uma lista com os pares de vértices não adjacentes
        '''
        vertices_nao_adj = set()

        for i in range(len(self.vertices)): 
            for j in range(len(self.matriz)):
                dict_arestas = self.matriz[i][j]
                if dict_arestas == dict():
                    vertices = f"{self.vertices[i]}-{self.vertices[j]}"
                    
                    if i != j:
                        vertices_nao_adj.add(vertices)
        
        return vertices_nao_adj

    def ha_laco(self) -> bool:
        '''
        Verifica se existe algum laço no grafo.
        :return: Um valor booleano que indica se existe algum laço.
        '''
        for i in range(len(self.vertices)):
            arestas = self.matriz[i][i]
            if arestas != dict():
                return True
        
        return False

    def grau_entrada(self, V='') -> int:
        '''
        Provê o grau de entrada do vértice passado como parâmetro, ou seja, a quantidade de as arestas cujo vértice de origem não é 'V'
        :param V: O rótulo do vértice a ser analisado
        :return: Um valor inteiro que indica o grau do vértice
        :raises: VerticeInvalidoException se o vértice não existe no grafo
        '''
        if not self.existe_rotulo_vertice(V):
            raise VerticeInvalidoError

        index_vertice = self.indice_do_vertice(self.get_vertice(V))

        grau = 0
        for linha in range(len(self.vertices)):
            arestas_entrada = self.matriz[linha][index_vertice]
            grau += len(arestas_entrada.keys())
        
        return grau

    def grau_saida(self, V='') -> int:
        '''
        Provê o grau de saída do vértice passado como parâmetro, isto é, a quantidade de arestas cujo vértice de origem é 'V'
        :param V: O rótulo do vértice a ser analisado
        :return: Um valor inteiro que indica o grau do vértice
        :raises: VerticeInvalidoException se o vértice não existe no grafo
        '''
        if not self.existe_rotulo_vertice(V):
            raise VerticeInvalidoError
        
        index_vertice = self.indice_do_vertice(self.get_vertice(V))
        adjacencias = self.matriz[index_vertice]

        grau = 0

        for a in adjacencias:
            if a != dict():
                grau += len(a.keys())
        
        return grau

    def ha_paralelas(self) -> bool:
        '''
        Verifica se há arestas paralelas no grafo
        :return: Um valor booleano que indica se existem arestas paralelas no grafo.
        '''
        for linha in range(len(self.vertices)):
            for coluna in range(len(self.vertices)):
                arestas = self.matriz[linha][coluna]
                quant_arestas = len(arestas.keys())

                if quant_arestas > 1:
                    return True
                
        return False

    def arestas_sobre_vertice(self, V) -> set[str]:
        '''
        Provê uma lista que contém os rótulos das arestas que incidem sobre o vértice passado como parâmetro
        Deve-se considerar tanto a entrada quanto a saída
        :param V: O vértice a ser analisado
        :return: Uma lista os rótulos das arestas que incidem sobre o vértice
        :raises: VerticeInvalidoException se o vértice não existe no grafo
        '''
        if not self.existe_rotulo_vertice(V):
            raise VerticeInvalidoError
        
        index_vertice = self.indice_do_vertice(self.get_vertice(V))
        arestas_saida = self.matriz[index_vertice]
        rotulos_arestas = set()

        for a in arestas_saida:
            if a != dict():
                rotulos = a.keys()
                for r in rotulos:
                    rotulos_arestas.add(r) 
        
        for linha in range(len(self.vertices)):
            arestas_entrada = self.matriz[linha][index_vertice]
            for r in arestas_entrada.keys():
                rotulos_arestas.add(r)

        return rotulos_arestas

    def eh_completo(self) -> bool:
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

    def warshall(self) -> list[list[int]] :
        '''
        Provê a matriz de alcançabilidade de Warshall do grafo
        :return: Uma lista de listas que representa a matriz de alcançabilidade de Warshall associada ao grafo
        '''

        def arestasToNumbers(grafo: GrafoMatrizAdjacenciaDirecionado):
            matrizNovoGrafo = deepcopy(grafo.matriz)

            for linha in range(len(matrizNovoGrafo)):
                for coluna in range(len(matrizNovoGrafo[linha])):
                    arestas = matrizNovoGrafo[linha][coluna]
                    matrizNovoGrafo[linha][coluna] = 0 if len(arestas.keys()) == 0 else 1

            return matrizNovoGrafo                            

        grafoPreProcessado = arestasToNumbers(self)

        n = len(grafoPreProcessado)

        for linha in range(n):
            for coluna in range(n):
                if grafoPreProcessado[coluna][linha] == 1: # Se há caminho (ou seja, uma ligação)
                    for k in range(n):
                        if grafoPreProcessado[linha][k] == 1 or grafoPreProcessado[coluna][k] == 1:
                            grafoPreProcessado[coluna][k] = 1
        
        return grafoPreProcessado
    
