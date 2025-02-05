from bibgrafo.grafo_builder import GrafoBuilder
from meu_grafo_matriz_adj_dir import MeuGrafo
from bibgrafo.aresta import ArestaDirecionada
from bibgrafo.vertice import Vertice

grafoAleatorio1 = GrafoBuilder().tipo(MeuGrafo()) \
    .vertices(['I', 'A', 'B', 'C', 'D', 'E']) \
    .arestas([
        ArestaDirecionada('a1', Vertice('I'), Vertice('A'), 10),
        ArestaDirecionada('a2', Vertice('I'), Vertice('E'), 8),
        ArestaDirecionada('a3', Vertice('E'), Vertice('D'), 1),
        ArestaDirecionada('a4', Vertice('A'), Vertice('C'), 2),
        ArestaDirecionada('a5', Vertice('D'), Vertice('C'), -1),
        ArestaDirecionada('a6', Vertice('D'), Vertice('A'), -4),
        ArestaDirecionada('a7', Vertice('C'), Vertice('B'), -2),
        ArestaDirecionada('a8', Vertice('B'), Vertice('A'), 1),
    ]).build()

grafoAleatorio2 = GrafoBuilder().tipo(MeuGrafo()) \
    .vertices(5) \
    .arestas([
        ArestaDirecionada('a1', Vertice('A'), Vertice('B'), 6),
        ArestaDirecionada('a2', Vertice('A'), Vertice('C'), 7),
        ArestaDirecionada('b1', Vertice('B'), Vertice('C'), 8),
        ArestaDirecionada('b2', Vertice('B'), Vertice('E'), -4),
        ArestaDirecionada('b3', Vertice('B'), Vertice('D'), 5),
        ArestaDirecionada('c1', Vertice('C'), Vertice('D'), -3),
        ArestaDirecionada('c2', Vertice('C'), Vertice('E'), 9),
        ArestaDirecionada('d1', Vertice('D'), Vertice('B'), -2),
        ArestaDirecionada('e1', Vertice('E'), Vertice('D'), 7),
        ArestaDirecionada('e2', Vertice('E'), Vertice('A'), 2),
    ]).build()

# Com ciclo negativo
grafoAleatorio3 = GrafoBuilder().tipo(MeuGrafo()) \
    .vertices(['I', 'A', 'B', 'C', 'F']) \
    .arestas([
        ArestaDirecionada('a1', Vertice('I'), Vertice('A'), 1),
        ArestaDirecionada('a2', Vertice('A'), Vertice('B'), -2),
        ArestaDirecionada('a3', Vertice('B'), Vertice('C'), -3),
        ArestaDirecionada('a4', Vertice('C'), Vertice('A'), 4),
        ArestaDirecionada('a5', Vertice('C'), Vertice('F'), 1),
    ]).build()


grafo = GrafoBuilder().tipo(MeuGrafo()) \
    .vertices(['S', 'T', 'X', 'Y', 'Z']) \
    .arestas([
        ArestaDirecionada('s1', Vertice('S'), Vertice('T'), 6),
        ArestaDirecionada('s2', Vertice('S'), Vertice('Y'), 7),
        ArestaDirecionada('t1', Vertice('T'), Vertice('X'), 5),
        ArestaDirecionada('t2', Vertice('T'), Vertice('Y'), 8),
        ArestaDirecionada('t3', Vertice('T'), Vertice('Z'), -4),
        ArestaDirecionada('x1', Vertice('X'), Vertice('T'), -2),
        ArestaDirecionada('y1', Vertice('Y'), Vertice('Z'), 9),
        ArestaDirecionada('y2', Vertice('Y'), Vertice('X'), -3),
        ArestaDirecionada('z1', Vertice('Z'), Vertice('X'), 7),
        ArestaDirecionada('z2', Vertice('Z'), Vertice('S'), 2),
    ]).build()

print(grafo)
print(grafoAleatorio2.bellman_ford('A', 'B'))
