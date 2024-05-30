# Cesar Alejandro Velazquez Mercado
# 372329

# Juego de la Serpiente

## Menú Principal

Al comenzar el juego, se muestra el menú principal con las siguientes opciones:
- **Jugar**
- **Ranking**
- **Ajustes**
- **Salir**

## Pantalla de Ranking

En la pantalla de ranking se muestran los 3 puntajes más altos de partidas anteriores.

## Opción de Cambio de Fondo

Dentro del juego se implementó una opción para favorecer si el usuario se encuentra en una localización más oscura, cambiando el fondo a negro.

## Pantalla Inicial del Juego

En la pantalla inicial del juego se muestra un mensaje que dice “Flecha Abajo para Iniciar”.

## Pantalla del Juego

Mientras se está jugando, se muestra el puntaje y la serpiente siguiendo el objetivo, que son las papas que se muestran en un lugar aleatorio del mapa.

## Pantalla de Fin del Juego

Pantalla que se muestra al perder.

## Definición de Posiciones y Direcciones

En esta parte del código se definen dos cosas: la primera son las posiciones y direcciones en una cuadrícula bidimensional y la segunda es el cuerpo de la serpiente asignándole la posición y velocidad.

```c
typedef struct
{
    int x;
    int y;
} Vector2Int;

typedef struct
{
    Vector2Int position;
    Vector2Int velocity;
} SnakeSegment;
