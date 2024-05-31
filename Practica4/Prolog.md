ALUMNO: Cesar Alejandro Velazquez Mercado
MATRÍCULA: 372329

1. Prolog - Home
2. Empezamos en “Home” donde se nos da una pequeña introducción al tutorial, aquí se nos explica que Prolog es un lenguaje de programación lógico y declarativo y un gran ejemplo de un lenguaje de cuarta generación, sumado a esto se nos dice que el tutorial fue hecho para principiantes con un conocimiento previo de programación.
3. Prolog - Introduction
4. Prolog escribe las reglas con cláusulas lógicas donde  cabeza y cuerpo están presentes. Por ejemplo, H es cabeza y B1, B2, B3 son cuerpo.

Para esta imagen vemos que la programación funcional trabaja paso a paso para resolver los problemas, en cambio, la programación lógica trabaja usando su conocimiento base para responder preguntas


Diferencias:

1. Programación Funcional
1. La Programación Funcional sigue la arquitectura de Von-Neumann o utiliza pasos secuenciales.
1. La sintaxis es en realidad la secuencia de declaraciones como (a, s, I).
1. La computación se lleva a cabo ejecutando las declaraciones secuencialmente.
1. La lógica y los controles están mezclados.
1. Programación Lógica
1. La Programación Lógica utiliza un modelo abstracto o trata con objetos y sus relaciones.
1. La sintaxis es básicamente las fórmulas lógicas.
1. Computa deduciendo las cláusulas.
1. Las lógicas y los controles pueden separarse.


1. Prolog - Environment Setup
1. Usaremos la versión 1.4.5 así que entramos a la página para descargarlo http://www.gprolog.org/ y esto es lo que veremos:  Bajamos hasta encontrar los links para descargar   Descargamos y seguimos los pasos:








Y sé descargo.

4\. Prolog - Hello World

1. Comenzamos escribiendo “write('Hello World').” En la plataforma que nos despliega “Hello World”, ahora vamos a ver como correr el Prolog script file, la Prolog consola.
1. Primero desde el programa vamos a File > Change Dir, Y hacemos click en el menú para después seleccionar un folder y presionar OK. esto nos despliega el mensaje: change\_directory('C:/Users/costco/paradigmas/Practica4').
1. Ahora vamos a crear una extensión para el archivo con estas líneas de código:

main :- write('This is sample Prolog program'),

write(' This program is written into hello\_world.pl file').

1. Y lo corremos con [hello\_world]

5\. Progol - Basics

1. Aquí vemos varios ejemplos de las bases de programación lógica como
1. girl(priya).
1. girl(tiyasha).
1. girl(jaya).
1. can\_cook(priya).
1. Ahora tenemos un ejemplo de base de conocimiento
1. girl(priya).
1. yes
1. girl(tiyasha).
1. no

3\. girl(jaya).

1. yes

4\. can\_cook(priya).

1. no

6\. Prolog - Relations

1. En los programas Prolog se especifican las relaciones entre objetos y las propiedades de los objetos un ejemploo de relación es:
1. Relación:
1. Ambos son hombres
1. Ambos tienen el mismo padre
1. Respuesta
1. Padre(Sudip,piyus).
1. Padre(sudip, raj).
1. Hombre(piyus).
1. Hombre(raj).
1. Hermanos(X, Y) :- Padre(Z, X), Padre(Z, Y), Hombre(X), Hombre(Y)
1. Ejemplo práctico
1. 2.            7. Prolog - Data Objects
1. Aquí hablamos de “data objects in prolog” y sus categorías
1. Este es un ejemplo de variables anónimas, se caracterizan  por no tener nombres ejemplo:
1. hates(jim,tom).

hates(pat,bob).

hates(dog,fox).

hates(peter,tom).

1. 8. Prolog - Operators
1. En esta sección veremos ejemplos de diferentes tipos de operadores en Prolog y comparaciones.
1. Operator        Meaning

X > Y        X         is greater than Y

X < Y        X         is less than Y

X >= Y        X is greater than or equal to Y

X =< Y        X is less than or equal to Y

X =:= Y        the X and Y values are equal

X =\= Y        the X and Y values are not equal

1. Ejemplo en la aplicación
1. | ?- 1+2=:=2+1.


yes

| ?- 1+2=2+1.


no

| ?- 1+A=B+2.


A = 2

B = 1


yes

| ?- 5<10.





calc :- X is 100 + 200,write('100 + 200 is '),write(X),nl,

Y is 400 - 150,write('400 - 150 is '),write(Y),nl,

Z is 10 \* 300,write('10 \* 300 is '),write(Z),nl,

A is 100 / 30,write('100 / 30 is '),write(A),nl,

B is 100 // 30,write('100 // 30 is '),write(B),nl,

C is 100 \*\* 2,write('100 \*\* 2 is '),write(C),nl,

D is 100 mod 30,write('100 mod 30 is '),write(D),nl.

`	`| ?- calc.

100 + 200 is 300

400 - 150 is 250

10 \* 300 is 3000

100 / 30 is 3.3333333333333335

100 // 30 is 3

100 \*\* 2 is 10000.0

100 mod 30 is 10


yes





9\. Loop & Decision Making

1. | ?- [loop].

compiling C:/Users/costco/paradigmas/Practica4/loop.pl for byte code...

C:/Users/costco/paradigmas/Practica4/loop.pl compiled, 4 lines read - 773 bytes written, 5 ms


yes

| ?- count\_to\_10(3).

3

4

5

6

7

8

9

10



`	            `2. | ?- [loop2].

compiling C:/Users/costco/paradigmas/Practica4/loop2.pl for byte code...

C:/Users/costco/paradigmas/Practica4/loop2.pl compiled, 8 lines read - 1097 bytes written, 6 ms


yes

| ?- count\_down(12,17).

5


true ? ;

4



`	            `3. Decision Making

1. Las declaraciones de decisión son declaraciones If-Then-Else. Por lo tanto, cuando intentamos coincidir con alguna condición y realizar alguna tarea, utilizamos las declaraciones de toma de decisiones. El uso básico es el siguiente: If <condition> is true, Then <do this>, Else
1. | ?- consult('C:/Users/costco/paradigmas/Practica4/Decision\_Making.pl').

compiling C:/Users/costco/paradigmas/Practica4/Decision\_Making.pl for byte code...

C:/Users/costco/paradigmas/Practica4/Decision\_Making.pl compiled, 9 lines read - 1138 bytes written, 6 ms


(16 ms) yes

| ?- gt(10,100).

X is smaller


yes

| ?- gt(150,100).

X is greater or equal



`	            `2. Prolog - Conjunctions & Disjunctions

1. La conjunción (lógica AND) puede implementarse utilizando el operador coma (,). Entonces, dos predicados separados por coma se unen con una declaración AND.
1. La disyunción (lógica OR) se puede implementar utilizando el operador punto y coma (;). Por lo tanto, dos predicados separados por punto y coma se unen con una declaración OR.






10\. Prolog - Lists

1. Las listas son una estructura que se puede usar en diferentes casos de programación no numérica.
1. Ejemplo: list\_member(X,[X|\_]).

list\_member(X,[\_|TAIL]) :- list\_member(X,TAIL).

1. Resultado:

[list\_basics].

uncaught exception: error(syntax\_error('user\_input:106 (char:3) current operator needs brackets'),read\_term/3)

| ?- compiling D:/TP Prolog/Sample\_Codes/list\_basics.pl for byte code…

list\_member(b,[a,b,c]).

uncaught exception: error(syntax\_error('user\_input:108 (char:2) . or operator expected after expression'),read\_term/3)

| ?-

true ?


1. Concatenation
1. La concatenación de dos listas significa agregar los elementos de la segunda lista después de la primera. Entonces, si las dos listas son [a, b, c] y [1, 2], entonces la lista final será [a, b, c, 1, 2].
1. [list\_basics].

compiling C:/Users/costco/paradigmas/Practica4/list\_basics.pl for byte code...

C:/Users/costco/paradigmas/Practica4/list\_basics.pl compiled, 4 lines read - 871 bytes written, 10 ms

(15 ms) yes

| ?-  list\_concat([1,2],[a,b,c],NewList).


NewList = [1,2,a,b,c]

yes


1. Ejemplo borrar desde lista: list\_delete(X, [X], []).

list\_delete(X,[X|L1], L1).

list\_delete(X, [Y|L2], [Y|L1]) :- list\_delete(X,L2,L1).


1. Añadir dos listas significa combinarlas, o agregar una lista como un elemento. Ahora, si el elemento está presente en la lista, entonces la función de añadir no funcionará. Por lo tanto, crearemos un predicado llamado list\_append(L1, L2, L3). A continuación se presentan algunas observaciones.
1. Ejemplo: list\_member(X,[X|\_]).

list\_member(X,[\_|TAIL]) :- list\_member(X,TAIL).


list\_append(A,T,T) :- list\_member(A,T),!.

list\_append(A,T,[A|T]).

list\_append(a,[e,i,o,u],NewList).


NewList = [a,e,i,o,u]


yes

| ?- list\_append(e,[e,i,o,u],NewList).


NewList = [e,i,o,u]


yes

1. Insertar en la lista: esta función se usa para insertar X en la lista L y el resultado será R
1. list\_delete(X, [X], []).

list\_delete(X,[X|L1], L1).

list\_delete(X, [Y|L2], [Y|L1]) :- list\_delete(X,L2,L1).


list\_insert(X,L,R) :- list\_delete(X,R,L).

1. Resultado: list\_insert(a,[e,i,o,u],NewList).

NewList = [a,e,i,o,u] ? a

NewList = [e,a,i,o,u]

NewList = [e,i,a,o,u]

NewList = [e,i,o,a,u]

NewList = [e,i,o,u,a]

NewList = [e,i,o,u,a]

(15 ms) no

1. Permutation Operation: Esta operación cambiará las posiciones de los elementos de la lista y generará todos los resultados posibles.

list\_delete(X,[X|L1], L1).

list\_delete(X, [Y|L2], [Y|L1]) :-list\_delete(X,L2,L1).

list\_perm([],[]).

list\_perm(L,[X|P]) :-list\_delete(X,L,L1),list\_perm(L1,P).

1. Resultado: list\_perm([a,b,c,d],X).

X = [a,b,c,d] ? a

X = [a,b,d,c]

X = [a,c,b,d]

X = [a,c,d,b]

X = [a,d,b,c]

X = [a,d,c,b]

X = [b,a,c,d]

X = [b,a,d,c]

X = [b,c,a,d]

X = [b,c,d,a]

X = [b,d,a,c]

X = [b,d,c,a]

X = [c,a,b,d]

X = [c,a,d,b]

X = [c,b,a,d]

X = [c,b,d,a]

X = [c,d,a,b]

X = [c,d,b,a]

X = [d,a,b,c]

X = [d,a,c,b]

X = [d,b,a,c]

X = [d,b,c,a]

X = [d,c,a,b]

X = [d,c,b,a]


(31 ms) no

1. Operación de Reversión: Supongamos que tenemos una lista L = [a, b, c, d, e], y queremos revertir los elementos, por lo que la salida será [e, d, c, b, a]. Para hacer esto, crearemos una cláusula, list\_reverse(List, ReversedList). A continuación se presentan algunas observaciones.
1. list\_concat([],L,L).

list\_concat([X1|L1],L2,[X1|L3]) :- list\_concat(L1,L2,L3).


list\_rev([],[]).

list\_rev([Head|Tail],Reversed) :-

list\_rev(Tail, RevTail),list\_concat(RevTail, [Head],Reversed).

1. Resultado: yes

| ?- list\_rev([a,b,c,d,e],NewList).


NewList = [e,d,c,b,a]


yes

| ?- list\_rev([a,b,c,d,e],[e,d,c,b,a]).


yes

11\. Prolog - Recursion and Structures

1. Recursión es una técnica en la que un predicado se utiliza a sí mismo (quizás con otros predicados) para encontrar el valor de verdad.
1. Coincidencia en Prolog: La coincidencia se utiliza para verificar si dos términos dados son iguales (idénticos) o si las variables en ambos términos pueden tener los mismos objetos después de ser instanciadas. Veamos un ejemplo.
1. Árboles Binarios

A continuación se muestra la estructura de un árbol binario utilizando estructuras recursivas:


Árboles Binarios

La definición de la estructura es la siguiente:node(2, node(1,nil,nil), node(6, node(4,node(3,nil,nil), node(5,nil,nil)), node(7,nil,nil)))

12\. Prolog - Backtracking

1. El backtracking es un procedimiento en el que Prolog busca el valor de verdad de diferentes predicados verificando si son correctos o no.
1. Knowledge Base
1. 1. | ?- pay(X,Y).

X = tom

Y = alice ?

(15 ms) yes

| ?- pay(X,Y).

X = tom

Y = alice ? ;

X = tom

Y = lili ? ;

X = bob

Y = alice ? ;

X = bob

Y = lili

1. yes
1. Evitando el Backtracking: desventajas del backtracking. A veces escribimos los mismos predicados más de una vez cuando nuestro programa lo demanda, por ejemplo, para escribir reglas recursivas o para crear algunos sistemas de toma de decisiones. En tales casos, el backtracking no controlado puede causar ineficiencia en un programa. Para resolver esto, utilizaremos el Corte (Cut) en Prolog.
1. f(X,0) :- X < 3.              % Rule 1

f(X,2) :- 3 =< X, X < 6.   % Rule 2

f(X,4) :- 6 =< X.             % Rule 3

1. | ?- trace

.

The debugger will first creep -- showing everything (trace)

yes

{trace}

| ?- f(1,Y), 2<Y.

1. 1 Call: f(1,\_23) ?
1. 2 Call: 1<3 ?
1. 2 Exit: 1<3 ?
1. 1 Exit: f(1,0) ?

3 1 Call: 2<0 ?

3 1 Fail: 2<0 ?

1. 1 Redo: f(1,0) ?
1. 2 Call: 3=<1 ?
1. 2 Fail: 3=<1 ?
1. 2 Call: 6=<1 ?
1. 2 Fail: 6=<1 ?
1. 1 Fail: f(1,\_23) ?

6\.

(46 ms) no

13\. Prolog - Different and Not

1. Aquí definiremos dos predicados: different y not. El predicado different verificará si dos argumentos dados son iguales o no. Si son iguales, devolverá falso; de lo contrario, devolverá verdadero.
1. different(X, X) :- !, fail.

different(X, Y).

1. yes

| ?- different(100,200).

yes

| ?- different(100,100).

no

| ?- different(abc,def).

yes

14\. Prolog - Inputs and Outputs

1. En este capítulo, veremos algunas técnicas para manejar entradas y salidas a través de Prolog. Utilizaremos algunos predicados incorporados para realizar estas tareas y también veremos técnicas de manejo de archivos.
1. El predicado write()
1. Para escribir la salida, podemos usar el predicado write(). Este predicado toma el parámetro como entrada y escribe el contenido en la consola por defecto. write() también puede escribir en archivos. Veamos algunos ejemplos de la función write().
1. | ?- write(56).

56

yes

| ?- write('hello').

hello

yes

| ?- write('hello'),nl,write('world').

hello

world

yes

| ?- write("ABCDE")

.

[65,66,67,68,69]

yes

1. El predicado read(): El predicado read() se utiliza para leer desde la consola. El usuario puede escribir algo en la consola, que puede ser tomado como entrada y procesarlo.
1. cube :-

write('Write a number: '),

read(Number),

process(Number).

process(stop) :- !.

process(Number) :-

C is Number \* Number \* Number,

write('Cube of '),write(Number),write(': '),write(C),nl, cube.

1. Ejemplo:

| ?- cube.

Write a number: 2.

Cube of 2: 8

Write a number: 10.

Cube of 10: 1000

Write a number: 12.

Cube of 12: 1728

Write a number: 8.

Cube of 8: 512

Write a number: stop

.

1. (31 ms) yes

15\. Prolog - Built-In Predicates

1. En Prolog, hemos visto los predicados definidos por el usuario en la mayoría de los casos, pero también hay algunos predicados integrados.Hay tres tipos de predicados integrados como se indica a continuación:
1. Identificación de términos
1. Descomposición de estructuras
1. Recopilación de todas las soluciones
1. Ejemplo:
1. | ?- var(X).

yes

| ?- X = 5, var(X).

no

| ?- var([X]).

no

16\. Tree Data Structure (Case Study)

1. Ahora veremos un estudio de caso en Prolog. Veremos cómo implementar una estructura de datos de árbol usando Prolog y crearemos nuestros propios operadores. Así que empecemos con la planificación.


Supongamos que tenemos un árbol como se muestra a continuación:


Estructura de Datos de Árbol

Tenemos que implementar este árbol usando Prolog. Tenemos algunas operaciones de la siguiente manera:

op(500, xfx, 'is\_parent').

op(500, xfx, 'is\_sibling\_of').

op(500, xfx, 'is\_at\_same\_level').


1. /\* The tree database \*/

:- op(500,xfx,'is\_parent').

a is\_parent b. c is\_parent g. f is\_parent l. j is\_parent q.

a is\_parent c. c is\_parent h. f is\_parent m. j is\_parent r.

a is\_parent d. c is\_parent i. h is\_parent n. j is\_parent s.

b is\_parent e. d is\_parent j. i is\_parent o. m is\_parent t.

b is\_parent f. e is\_parent k. i is\_parent p. n is\_parent u.

n

is\_parent v.

/\* X and Y are siblings i.e. child from the same parent \*/

:- op(500,xfx,'is\_sibling\_of').

X is\_sibling\_of Y :- Z is\_parent X,

Z is\_parent Y,

X \== Y.

leaf\_node(Node) :- \+ is\_parent(Node,Child). % Node grounded

/\* X and Y are on the same level in the tree. \*/

:-op(500,xfx,'is\_at\_same\_level').

X is\_at\_same\_level X .

X is\_at\_same\_level Y :- W is\_parent X,

Z is\_parent Y,

W is\_at\_same\_level Z.

1. | ?- i is\_parent p.

yes

| ?- i is\_parent s.

no

| ?- is\_parent(i,p).

yes

| ?- e is\_sibling\_of f.

true ?

yes

| ?- is\_sibling\_of(e,g).

no

1. Más sobre la Estructura de Datos de Árbol
1. Aquí, veremos algunas operaciones adicionales que se realizarán en la estructura de datos de árbol dada anteriormente.
