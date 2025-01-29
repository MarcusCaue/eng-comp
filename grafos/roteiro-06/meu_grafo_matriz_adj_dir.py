from json.encoder import INFINITY
from bibgrafo.grafo_matriz_adj_dir import *
from bibgrafo.grafo_errors import *
from copy import deepcopy

class MeuGrafo(GrafoMatrizAdjacenciaDirecionado):

    # Retorno:
    # [v1, a1, v2, a2, v2, ..., an, vn]
    def dijkstra(self, v_src="", v_dest=""):

        def avalia_grafo():
            # Verifica a existência dos vértices no grafo
            if not self.existe_rotulo_vertice(v_src) or not self.existe_rotulo_vertice(v_dest):
                raise VerticeInvalidoError

            matrizAlcancabilidade = self.warshall()

            index_src = self.indice_do_vertice(self.get_vertice(v_src))
            index_dest = self.indice_do_vertice(self.get_vertice(v_dest))

            # Verificando se é possível alcançar o destino a partir da origem
            if matrizAlcancabilidade[index_src][index_dest] == 0:
                return MeuGrafo()

        def get_index_menor_beta(betas: list, gamas: list):

            betas_vertices_nao_visitados = []
            for i in range(len(gamas)):
                b = betas[i]
                g = gamas[i]

                if g == 0:
                    betas_vertices_nao_visitados.append({
                        "index": i,
                        "valor": b
                    })
        
            menor = betas_vertices_nao_visitados[0]["valor"]
            index = betas_vertices_nao_visitados[0]["index"]
            for i in range(1, len(betas_vertices_nao_visitados)):
                b = betas_vertices_nao_visitados[i]["valor"]
                if b < menor:
                    menor = b
                    index = betas_vertices_nao_visitados[i]["index"]
            
            return index

        def remove_lacos():
            pass

        def remove_paralelas():
            pass
        

        avalia_grafo()

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
                        pis[index_outra_ponta] = w
            
            index_menor_beta = get_index_menor_beta(betas, gamas)
            w = self.vertices[index_menor_beta].rotulo

        caminho = []
        w = v_src
        while v != w:
            caminho.insert(0, v)
            index_v = self.indice_do_vertice(self.get_vertice(v))
            v = pis[index_v]
        
        caminho.insert(0, w)

        return caminho

        
    def outra_ponta_aresta(self, rotulo="", ponta_rot=""):
        aresta = self.get_aresta(rotulo)
        if aresta.v1.rotulo == ponta_rot:
            return aresta.v2.rotulo
        else:
            return aresta.v1.rotulo


    def get_aresta(self, rotulo=""):
        for a in self.get_todas_arestas():
            if rotulo == a.rotulo:
                return a

        raise ArestaInvalidaError

    def get_todas_arestas(self):
        arestas = list()

        for linha in range(len(self.matriz)):
            for coluna in range(len(self.matriz)):
                arestas_dict = self.matriz[linha][coluna]
                if arestas_dict != dict():
                    valores = arestas_dict.values()
                    for v in valores:
                        arestas.append(v)
        
        return arestas

    def vertices_nao_adjacentes(self):
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

    def grau_entrada(self, V=''):
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

    def grau_saida(self, V=''):
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

    def ha_paralelas(self):
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

    def arestas_sobre_vertice(self, V):
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

    def warshall(self):
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
    
