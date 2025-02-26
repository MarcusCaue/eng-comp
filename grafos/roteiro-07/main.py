from bibgrafo.grafo_builder import GrafoBuilder
from meu_grafo_matriz_adj_dir import MeuGrafo
from bibgrafo.aresta import ArestaDirecionada
from bibgrafo.vertice import Vertice
from bibgrafo.grafo_json import GrafoJSON

grafo_aleat1 = GrafoBuilder().tipo(MeuGrafo()) \
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

grafo_aleat2 = GrafoBuilder().tipo(MeuGrafo()) \
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

grafo_aleat3 = GrafoBuilder().tipo(MeuGrafo()) \
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

# Com ciclo negativo
grafo_neg1 = GrafoBuilder().tipo(MeuGrafo()) \
    .vertices(['I', 'A', 'B', 'C', 'F']) \
    .arestas([
        ArestaDirecionada('a1', Vertice('I'), Vertice('A'), 1),
        ArestaDirecionada('a2', Vertice('A'), Vertice('B'), -2),
        ArestaDirecionada('a3', Vertice('B'), Vertice('C'), -3),
        ArestaDirecionada('a4', Vertice('C'), Vertice('A'), 4),
        ArestaDirecionada('a5', Vertice('C'), Vertice('F'), 1),
    ]).build()

grafo_neg2 = GrafoBuilder().tipo(MeuGrafo()) \
    .vertices(4) \
    .arestas([
        ArestaDirecionada('a1', Vertice('A'), Vertice('B'), 2),
        ArestaDirecionada('a2', Vertice('B'), Vertice('C'), -1),
        ArestaDirecionada('a3', Vertice('B'), Vertice('D'), 3),
        ArestaDirecionada('a4', Vertice('C'), Vertice('D'), -1),
        ArestaDirecionada('a5', Vertice('C'), Vertice('A'), -3),
    ]).build()

grafo_neg3 = GrafoBuilder().tipo(MeuGrafo()) \
    .vertices(5) \
    .arestas([
        ArestaDirecionada('a1', Vertice('A'), Vertice('B'), 5),
        ArestaDirecionada('a2', Vertice('A'), Vertice('C'), 4),
        ArestaDirecionada('b1', Vertice('B'), Vertice('C'), -3),
        ArestaDirecionada('c1', Vertice('C'), Vertice('D'), -1),
        ArestaDirecionada('c2', Vertice('C'), Vertice('E'), 1),
        ArestaDirecionada('d1', Vertice('D'), Vertice('B'), 6),
        ArestaDirecionada('d2', Vertice('D'), Vertice('E'), -5),
        ArestaDirecionada('e1', Vertice('E'), Vertice('A'), 2),
    ]).build()

grafo_neg4 = GrafoBuilder().tipo(MeuGrafo()) \
    .vertices(['S', 'A', 'B', 'C', 'D', 'E', 'F', 'G']) \
    .arestas([
        ArestaDirecionada('s1', Vertice('S'), Vertice('A'), 3),
        ArestaDirecionada('s2', Vertice('S'), Vertice('C'), 5),
        ArestaDirecionada('s3', Vertice('S'), Vertice('E'), 2),
        ArestaDirecionada('a1', Vertice('A'), Vertice('B'), -4),
        ArestaDirecionada('b1', Vertice('B'), Vertice('G'), 4),
        ArestaDirecionada('c1', Vertice('C'), Vertice('D'), 6),
        ArestaDirecionada('d1', Vertice('D'), Vertice('C'), -3),
        ArestaDirecionada('d2', Vertice('D'), Vertice('G'), 8),
        ArestaDirecionada('e1', Vertice('E'), Vertice('F'), 3),
        ArestaDirecionada('f1', Vertice('F'), Vertice('E'), -6),
        ArestaDirecionada('f2', Vertice('F'), Vertice('G'), 7),
    ]).build()

grafos = [
    {"nome": "grafo_aleat1", "valor": grafo_aleat1},
    {"nome": "grafo_aleat2", "valor": grafo_aleat2},
    {"nome": "grafo_aleat3", "valor": grafo_aleat3},

    {"nome": "grafo_neg1", "valor": grafo_neg1},
    {"nome": "grafo_neg2", "valor": grafo_neg2},
    {"nome": "grafo_neg3", "valor": grafo_neg3},
    {"nome": "grafo_neg4", "valor": grafo_neg4}
]

for g in grafos:
    GrafoJSON.grafo_to_json(g["valor"], f'test_json/{g["nome"]}.json')
