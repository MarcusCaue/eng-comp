import unittest
from bibgrafo.aresta import ArestaDirecionada
from bibgrafo.grafo_errors import VerticeInvalidoError, ArestaInvalidaError
from bibgrafo.grafo_json import GrafoJSON
from bibgrafo.grafo_builder import GrafoBuilder
from meu_grafo_matriz_adj_dir import *
from atividades_grafos import gerar_grafos_teste

class TestGrafo(unittest.TestCase):

    def test_bellman_ford(self):
        #Em um momento oportuno, gostaria de testar a seguinte hipótese: Se um caminho entre dois vértices não passar por um ciclo negativo, mesmo que o grafo o tenha, então o algoritmo ainda soluciona o problema

        # Grafos aleatórios
        grafo_aleat1 = GrafoJSON.json_to_grafo("test_json/grafo_aleat1.json", MeuGrafo())
        grafo_aleat2 = GrafoJSON.json_to_grafo("test_json/grafo_aleat2.json", MeuGrafo())
        grafo_aleat3 = GrafoJSON.json_to_grafo("test_json/grafo_aleat3.json", MeuGrafo())
        
        self.assertEqual(grafo_aleat1.bellman_ford('I', 'B'), ['I', 'a2', 'E', 'a3', 'D', 'a6', 'A', 'a4', 'C', 'a7', 'B'])
        self.assertNotEqual(grafo_aleat1.bellman_ford('I', 'A'), ['I', 'a2', 'E', 'a3', 'D', 'a5', 'C', 'a7', 'B', 'a8', 'A'])
        self.assertEqual(grafo_aleat2.bellman_ford('A', 'E'), ['A', 'a2', 'C', 'c1', 'D', 'd1', 'B', 'b2', 'E'])
        self.assertEqual(grafo_aleat2.bellman_ford('E', 'D'), ['E', 'e2', 'A', 'a2', 'C', 'c1', 'D'])
        self.assertEqual(grafo_aleat3.bellman_ford('S', 'Z'), ['S', 's2', 'Y', 'y2', 'X', 'x1', 'T', 't3', 'Z'])
        self.assertEqual(grafo_aleat3.bellman_ford('Z', 'Y'), ['Z', 'z2', 'S', 's2', 'Y'])
    
        # Grafos com ciclos de peso negativo
        grafo_neg1 = GrafoJSON.json_to_grafo("test_json/grafo_neg1.json", MeuGrafo())
        grafo_neg2 = GrafoJSON.json_to_grafo("test_json/grafo_neg2.json", MeuGrafo())
        grafo_neg3 = GrafoJSON.json_to_grafo("test_json/grafo_neg3.json", MeuGrafo())
        grafo_neg4 = GrafoJSON.json_to_grafo("test_json/grafo_neg4.json", MeuGrafo())

        self.assertEqual(grafo_neg1.bellman_ford('I', 'F'), [])
        self.assertEqual(grafo_neg1.bellman_ford('A', 'C'), [])
        self.assertEqual(grafo_neg2.bellman_ford('A', 'D'), [])
        self.assertEqual(grafo_neg2.bellman_ford('D', 'A'), [])
        self.assertEqual(grafo_neg3.bellman_ford('A', 'E'), [])
        self.assertEqual(grafo_neg3.bellman_ford('C', 'D'), [])
        self.assertEqual(grafo_neg4.bellman_ford('S', 'G'), [])
        self.assertEqual(grafo_neg4.bellman_ford('S', 'F'), [])

        # Grafo vazio
        self.assertEqual(MeuGrafo().bellman_ford(), [])

        # Vértices inexistentes
        with self.assertRaises(VerticeInvalidoError):
            grafo_aleat1.bellman_ford('X', 'J')
        with self.assertRaises(VerticeInvalidoError):
            grafo_aleat2.bellman_ford('W', 'R')
        with self.assertRaises(VerticeInvalidoError):
            grafo_neg4.bellman_ford('Z', 'Y')
        
        # Testando os resultados do algoritmo em relação ao de Dijkstra
        k10 = GrafoBuilder().tipo(MeuGrafo()).vertices(10).arestas(True).build()
    
        self.assertEqual(k10.dijkstra('A', 'C'), k10.bellman_ford('A', 'C'))
        self.assertEqual(self.g_p.dijkstra('J', 'Z'), self.g_p.bellman_ford('J', 'Z'))

        # Outro grafo aleatório
        vertices = ['A', 'B', 'C', 'D', 'E', 'F']
        arestas = [
            ArestaDirecionada('a0', Vertice(vertices[0]), Vertice(vertices[3]), 2),
            ArestaDirecionada('a1', Vertice(vertices[0]), Vertice(vertices[1]), 3), 
            ArestaDirecionada('a2', Vertice(vertices[1]), Vertice(vertices[2]), 1), 
            ArestaDirecionada('a3', Vertice(vertices[2]), Vertice(vertices[4]), 1), 
            ArestaDirecionada('a4', Vertice(vertices[3]), Vertice(vertices[4]), 4), 
            ArestaDirecionada('a5', Vertice(vertices[3]), Vertice(vertices[5]), 5), 
            ArestaDirecionada('a6', Vertice(vertices[4]), Vertice(vertices[5]), 1), 
        ]

        grafo = GrafoBuilder().tipo(MeuGrafo()).vertices(vertices).arestas(arestas).build()
        self.assertEqual(grafo.dijkstra('A', 'F'), grafo.bellman_ford('A', 'F'))
        
    def test_dijkstra(self):
        # Grafos aleatórios
        vertices = ['A', 'B', 'C', 'D', 'E', 'F']
        arestas = [
            ArestaDirecionada('a0', Vertice(vertices[0]), Vertice(vertices[3]), 2),
            ArestaDirecionada('a1', Vertice(vertices[0]), Vertice(vertices[1]), 3), 
            ArestaDirecionada('a2', Vertice(vertices[1]), Vertice(vertices[2]), 1), 
            ArestaDirecionada('a3', Vertice(vertices[2]), Vertice(vertices[4]), 1), 
            ArestaDirecionada('a4', Vertice(vertices[3]), Vertice(vertices[4]), 4), 
            ArestaDirecionada('a5', Vertice(vertices[3]), Vertice(vertices[5]), 5), 
            ArestaDirecionada('a6', Vertice(vertices[4]), Vertice(vertices[5]), 1), 
        ]

        # Grafo aleatório 1
        grafo = GrafoBuilder().tipo(MeuGrafo()).vertices(vertices).arestas(arestas).build()
        self.assertEqual(grafo.dijkstra('A', 'F'), ['A', 'a1', 'B', 'a2', 'C', 'a3', 'E', 'a6', 'F'])

        vertices = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
        arestas = [
            ArestaDirecionada('a0', Vertice(vertices[0]), Vertice(vertices[1]), 1), # A -> B
            ArestaDirecionada('a1', Vertice(vertices[0]), Vertice(vertices[2]), 4), # A -> C
            ArestaDirecionada('a2', Vertice(vertices[1]), Vertice(vertices[3]), 5), # B -> D
            ArestaDirecionada('a3', Vertice(vertices[2]), Vertice(vertices[3]), 1), # C -> D
            ArestaDirecionada('a4', Vertice(vertices[3]), Vertice(vertices[4]), 2), # D -> E
            ArestaDirecionada('a5', Vertice(vertices[3]), Vertice(vertices[5]), 1), # D -> F
            ArestaDirecionada('a6', Vertice(vertices[2]), Vertice(vertices[5]), 3), # C -> F
            ArestaDirecionada('a7', Vertice(vertices[5]), Vertice(vertices[6]), 4), # F -> G
            ArestaDirecionada('a8', Vertice(vertices[4]), Vertice(vertices[6]), 2)  # E -> G
        ]
        
        # Grafo aleatório 2
        grafo = GrafoBuilder().tipo(MeuGrafo()).vertices(vertices).arestas(arestas).build()
        self.assertEqual(grafo.dijkstra('A', 'G'), ['A', 'a1', 'C', 'a3', 'D', 'a4', 'E', 'a8', 'G'])

        # Grafo vazio
        self.assertEqual(MeuGrafo().dijkstra(), [])

        # Vértices inexistentes
        with self.assertRaises(VerticeInvalidoError):
            self.g_p.dijkstra('X', 'J')
        with self.assertRaises(VerticeInvalidoError):
            self.g_p.dijkstra('J', 'W')
        with self.assertRaises(VerticeInvalidoError):
            self.g_p.dijkstra('O', 'Y')

        # Grafos completos
        k3 = GrafoBuilder().tipo(MeuGrafo()).vertices(3).arestas(True).build()
        k4 = GrafoBuilder().tipo(MeuGrafo()).vertices(4).arestas(True).build()
        k7 = GrafoBuilder().tipo(MeuGrafo()).vertices(7).arestas(True).build()
        k10 = GrafoBuilder().tipo(MeuGrafo()).vertices(10).arestas(True).build()
        self.assertEqual(len(k3.dijkstra('A', 'C')), 3)
        self.assertEqual(len(k4.dijkstra('A', 'C')), 3)
        self.assertEqual(len(k7.dijkstra('A', 'C')), 3)
        self.assertEqual(len(k10.dijkstra('A', 'C')), 3)

        # Quando não é possível alcançar, descoberto por Warshall
        # Adicionando vértices desconexos no grafo Aleatorio 2
        grafo.adiciona_vertice("H")
        grafo.adiciona_vertice("I")
        grafo.adiciona_vertice("J")
        grafo.adiciona_vertice("K")

        grafo.adiciona_aresta(ArestaDirecionada("b1", Vertice('H'), Vertice('I'), 4))
        grafo.adiciona_aresta(ArestaDirecionada("b2", Vertice('H'), Vertice('J'), 2))
        grafo.adiciona_aresta(ArestaDirecionada("b3", Vertice('I'), Vertice('J')))
        grafo.adiciona_aresta(ArestaDirecionada("b4", Vertice('J'), Vertice('K'), 2))

        self.assertEqual(grafo.dijkstra('A', 'H'), [])
        self.assertEqual(grafo.dijkstra('K', 'C'), [])
        self.assertEqual(grafo.dijkstra('H', 'K'), ['H', 'b2', 'J', 'b4', 'K'])

    def setUp(self):
        # Grafo da Paraíba
        self.g_p = GrafoJSON.json_to_grafo('test_json/grafo_pb.json', MeuGrafo())

        # Clone do Grafo da Paraíba para ver se o método equals está funcionando
        self.g_p2 = GrafoJSON.json_to_grafo('test_json/grafo_pb2.json', MeuGrafo())

        # Outro clone do Grafo da Paraíba para ver se o método equals está funcionando
        # Esse tem um pequena diferença na primeira aresta
        self.g_p3 = GrafoJSON.json_to_grafo('test_json/grafo_pb3.json', MeuGrafo())

        # Outro clone do Grafo da Paraíba para ver se o método equals está funcionando
        # Esse tem um pequena diferença na segunda aresta
        self.g_p4 = GrafoJSON.json_to_grafo('test_json/grafo_pb4.json', MeuGrafo())

        # Grafo da Paraíba sem arestas paralelas
        self.g_p_sem_paralelas = GrafoJSON.json_to_grafo('test_json/grafo_pb_simples.json', MeuGrafo())

        # Grafos completos
        self.g_c = GrafoBuilder().tipo(MeuGrafo()) \
            .vertices(['J', 'C', 'E', 'P']).arestas(True).build()

        self.g_c2 = GrafoBuilder().tipo(MeuGrafo()) \
            .vertices(3).arestas(True).build()

        self.g_c3 = GrafoBuilder().tipo(MeuGrafo()) \
            .vertices(1).build()


        # Grafos com laco
        self.g_l1 = GrafoJSON.json_to_grafo('test_json/grafo_l1.json', MeuGrafo())

        self.g_l2 = GrafoJSON.json_to_grafo('test_json/grafo_l2.json', MeuGrafo())

        self.g_l3 = GrafoJSON.json_to_grafo('test_json/grafo_l3.json', MeuGrafo())

        self.g_l4 = GrafoBuilder().tipo(MeuGrafo()).vertices([(v:=Vertice('D'))]) \
            .arestas([ArestaDirecionada('a1', v, v)]).build()

        self.g_l5 = GrafoBuilder().tipo(MeuGrafo()).vertices(3) \
            .arestas(3, lacos=1).build()

        # Grafos desconexos
        self.g_d = GrafoBuilder().tipo(MeuGrafo()) \
            .vertices([a:=Vertice('A'), b:=Vertice('B'), Vertice('C'), Vertice('D')]) \
            .arestas([ArestaDirecionada('asd', a, b)]).build()

        self.g_d2 = GrafoBuilder().tipo(MeuGrafo()).vertices(4).build()

        # Grafo com ciclos e laços
        self.g_e = MeuGrafo()
        self.g_e.adiciona_vertice("A")
        self.g_e.adiciona_vertice("B")
        self.g_e.adiciona_vertice("C")
        self.g_e.adiciona_vertice("D")
        self.g_e.adiciona_vertice("E")
        self.g_e.adiciona_aresta('1', 'A', 'B')
        self.g_e.adiciona_aresta('2', 'A', 'C')
        self.g_e.adiciona_aresta('3', 'C', 'A')
        self.g_e.adiciona_aresta('4', 'C', 'B')
        self.g_e.adiciona_aresta('10', 'C', 'B')
        self.g_e.adiciona_aresta('5', 'C', 'D')
        self.g_e.adiciona_aresta('6', 'D', 'D')
        self.g_e.adiciona_aresta('7', 'D', 'B')
        self.g_e.adiciona_aresta('8', 'D', 'E')
        self.g_e.adiciona_aresta('9', 'E', 'A')
        self.g_e.adiciona_aresta('11', 'E', 'B')

    def test_adiciona_aresta(self):
        self.assertTrue(self.g_p.adiciona_aresta('a10', 'J', 'C'))
        a = ArestaDirecionada("zxc", self.g_p.get_vertice("C"), self.g_p.get_vertice("Z"))
        self.assertTrue(self.g_p.adiciona_aresta(a))
        with self.assertRaises(ArestaInvalidaError):
            self.assertTrue(self.g_p.adiciona_aresta(a))
        with self.assertRaises(VerticeInvalidoError):
            self.assertTrue(self.g_p.adiciona_aresta('b1', '', 'C'))
        with self.assertRaises(VerticeInvalidoError):
            self.assertTrue(self.g_p.adiciona_aresta('b1', 'A', 'C'))
        with self.assertRaises(TypeError):
            self.g_p.adiciona_aresta('')
        with self.assertRaises(TypeError):
            self.g_p.adiciona_aresta('aa-bb')
        with self.assertRaises(VerticeInvalidoError):
            self.g_p.adiciona_aresta('x', 'J', 'V')
        with self.assertRaises(ArestaInvalidaError):
            self.g_p.adiciona_aresta('a1', 'J', 'C')

    def test_remove_vertice(self):
        self.assertTrue(self.g_p.remove_vertice("J"))
        with self.assertRaises(VerticeInvalidoError):
            self.g_p.remove_vertice("J")
        with self.assertRaises(VerticeInvalidoError):
            self.g_p.remove_vertice("K")
        self.assertTrue(self.g_p.remove_vertice("C"))
        self.assertTrue(self.g_p.remove_vertice("Z"))

    def test_remove_aresta(self):
        self.assertTrue(self.g_p.remove_aresta("a1"))
        self.assertFalse(self.g_p.remove_aresta("a1"))
        self.assertTrue(self.g_p.remove_aresta("a7"))
        self.assertFalse(self.g_c.remove_aresta("a"))
        self.assertTrue(self.g_c.remove_aresta("a6"))
        self.assertTrue(self.g_c.remove_aresta("a1", "J"))
        self.assertTrue(self.g_c.remove_aresta("a5", "C"))
        with self.assertRaises(VerticeInvalidoError):
            self.g_p.remove_aresta("a2", "X", "C")
        with self.assertRaises(VerticeInvalidoError):
            self.g_p.remove_aresta("a3", "X")
        with self.assertRaises(VerticeInvalidoError):
            self.g_p.remove_aresta("a3", v2="X")

    def test_eq(self):
        self.assertEqual(self.g_p, self.g_p2)
        self.assertNotEqual(self.g_p, self.g_p3)
        self.assertNotEqual(self.g_p, self.g_p_sem_paralelas)
        self.assertNotEqual(self.g_p, self.g_p4)

    def test_vertices_nao_adjacentes(self):
        self.assertEqual(set(self.g_p.vertices_nao_adjacentes()), {'J-E', 'J-P', 'J-M', 'J-T', 'J-Z', 'C-J', 'C-T', 'C-Z', 'C-M', 'C-P', 'E-C', 'E-J', 'E-P',
                                                                   'E-M', 'E-T', 'E-Z', 'P-J', 'P-E', 'P-M', 'P-T', 'P-Z', 'M-J', 'M-E', 'M-P', 'M-Z', 'T-J',
                                                                   'T-M', 'T-E', 'T-P', 'Z-J', 'Z-C', 'Z-E', 'Z-P', 'Z-M', 'Z-T'})


        self.assertEqual(set(self.g_c.vertices_nao_adjacentes()), {'C-J', 'E-C', 'P-C', 'E-J', 'P-E', 'P-J'})
        self.assertEqual(self.g_c3.vertices_nao_adjacentes(), set())
        self.assertEqual(set(self.g_e.vertices_nao_adjacentes()), {'A-D', 'A-E', 'B-A', 'B-C', 'B-D', 'B-E', 'C-E', 'D-C', 'D-A', 'E-D', 'E-C'})

    def test_ha_laco(self):
        self.assertFalse(self.g_p.ha_laco())
        self.assertFalse(self.g_p_sem_paralelas.ha_laco())
        self.assertFalse(self.g_c2.ha_laco())
        self.assertTrue(self.g_l1.ha_laco())
        self.assertTrue(self.g_l2.ha_laco())
        self.assertTrue(self.g_l3.ha_laco())
        self.assertTrue(self.g_l4.ha_laco())
        self.assertTrue(self.g_l5.ha_laco())
        self.assertTrue(self.g_e.ha_laco())

    def test_grau(self):
        # Paraíba
        self.assertEqual(self.g_p.grau_saida('J'), 1)
        self.assertEqual(self.g_p.grau_entrada('J'), 0)
        self.assertEqual(self.g_p.grau_saida('C'), 2)
        self.assertEqual(self.g_p.grau_entrada('C'), 5)
        self.assertEqual(self.g_p.grau_saida('E'), 0)
        self.assertEqual(self.g_p.grau_entrada('E'), 2)
        self.assertEqual(self.g_p.grau_saida('P'), 2)
        self.assertEqual(self.g_p.grau_entrada('P'), 0)
        self.assertEqual(self.g_p.grau_saida('M'), 2)
        self.assertEqual(self.g_p.grau_entrada('M'), 0)
        self.assertEqual(self.g_p.grau_saida('T'), 2)
        self.assertEqual(self.g_p.grau_entrada('T'), 1)
        self.assertEqual(self.g_p.grau_saida('Z'), 0)
        self.assertEqual(self.g_p.grau_entrada('Z'), 1)
        with self.assertRaises(VerticeInvalidoError):
            self.assertEqual(self.g_p.grau_saida('G'), 5)

        self.assertEqual(self.g_d.grau_entrada('A'), 0)
        self.assertEqual(self.g_d.grau_saida('A'), 1)
        self.assertEqual(self.g_d.grau_entrada('C'), 0)
        self.assertEqual(self.g_d.grau_saida('C'), 0)
        self.assertNotEqual(self.g_d.grau_entrada('D'), 2)
        self.assertNotEqual(self.g_d.grau_entrada('D'), 2)
        self.assertEqual(self.g_d2.grau_entrada('A'), 0)
        self.assertNotEqual(self.g_d.grau_saida('D'), 2)

        # Completos
        self.assertEqual(self.g_c.grau_entrada('J'), 0)
        self.assertEqual(self.g_c.grau_saida('J'), 3)
        self.assertEqual(self.g_c.grau_entrada('C'), 1)
        self.assertEqual(self.g_c.grau_saida('C'), 2)
        self.assertEqual(self.g_c.grau_saida('E'), 1)
        self.assertEqual(self.g_c.grau_entrada('E'), 2)
        self.assertEqual(self.g_c.grau_saida('P'), 0)
        self.assertEqual(self.g_c.grau_entrada('P'), 3)

        # Com laço.
        self.assertEqual(self.g_l1.grau_saida('A'), 2)
        self.assertEqual(self.g_l1.grau_entrada('A'), 3)
        self.assertEqual(self.g_l2.grau_entrada('B'), 2)
        self.assertEqual(self.g_l2.grau_saida('B'), 2)
        self.assertEqual(self.g_l4.grau_entrada('D'), 1)
        self.assertEqual(self.g_l4.grau_saida('D'), 1)

    def test_ha_paralelas(self):
        self.assertTrue(self.g_p.ha_paralelas())
        self.assertFalse(self.g_p_sem_paralelas.ha_paralelas())
        self.assertFalse(self.g_c.ha_paralelas())
        self.assertFalse(self.g_c2.ha_paralelas())
        self.assertFalse(self.g_c3.ha_paralelas())
        self.assertTrue(self.g_l1.ha_paralelas())
        self.assertTrue(self.g_e.ha_paralelas())

    def test_arestas_sobre_vertice(self):
        self.assertEqual(set(self.g_p.arestas_sobre_vertice('J')), {'a1'})
        self.assertEqual(set(self.g_p.arestas_sobre_vertice('C')), {'a1', 'a2', 'a3', 'a4', 'a5', 'a6', 'a7'})
        self.assertEqual(set(self.g_p.arestas_sobre_vertice('M')), {'a7', 'a8'})
        self.assertEqual(set(self.g_l2.arestas_sobre_vertice('B')), {'a1', 'a2', 'a3'})
        self.assertEqual(set(self.g_d.arestas_sobre_vertice('C')), set())
        self.assertEqual(set(self.g_d.arestas_sobre_vertice('A')), {'asd'})
        with self.assertRaises(VerticeInvalidoError):
            self.g_p.arestas_sobre_vertice('A')
        self.assertEqual(set(self.g_e.arestas_sobre_vertice('D')), {'5', '6', '7', '8'})

