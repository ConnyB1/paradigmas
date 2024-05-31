## A Tour of Standard ML

### 00-01-setup.md
Para instalarlo use este [video](https://www.youtube.com/watch?v=BC6y1g5gr0A&t=39s).

### 01-00-values.md
Al compilar `values.sml` obtenemos estos resultados:
Hello!
val i = <hidden> : int
val j = 10 : real
val k = 10 : int
val i' = 11 : int
val i = 10 : int
val iEqK = true : bool


### 01-01-let-expr.md
Standard ML define una expresión 'let' que permite realizar declaraciones con alcance limitado. Fuera de estas expresiones, sus definiciones quedan sin vincular. El resultado de evaluar una expresión 'let', por ejemplo `letexpr`, es la última expresión contenida entre `in ... end`.

### 01-02-basic-data-types.md
Standard ML tiene seis tipos de datos integrados: `unit`, `bool`, `int`, `real`, `string`, y `char`.

### 01-03-data-structures.md
Standard ML tiene tres estructuras de datos integradas. Los campos de los registros se acceden mediante `#field record`. Los registros no son mapas asociativos; sus etiquetas solo pueden ser nombres alfanuméricos o números mayores que 0.

### 01-04-functions.md
Las funciones en Standard ML se declaran usando `fn` y se pueden nombrar con `val`. Todas las funciones toman un argumento y son currificadas.

### 01-05-fun.md
En Standard ML, se puede usar `fun` para declarar funciones de manera más sencilla en lugar de `fn`. Los argumentos de las funciones pueden tener tipos declarados, pero no es necesario ya que SML los infiere.

Las funciones pueden aceptar y devolver tuplas, permitiendo múltiples argumentos y resultados. Aunque todas las funciones deben aceptar y producir al menos un valor, pueden usar `unit` (`()`) si no se necesita un valor específico.

Para referirse a operadores como `+`, se utiliza la palabra clave `op`.

### 01-07-mod-sigs.md
Recopilamos el archivo `mod-sigs.sml` y obtenemos la siguiente estructura:
structure Math : sig
val e : real
end



### 01-10-new-data-types.md
Los alias de tipos se definen con la palabra clave `type`, mientras que los nuevos tipos de datos se declaran con la palabra clave `datatype`.

Por ejemplo, `major_arcana_card` define un tipo que es un par de un nombre y un número.

Los tipos de datos pueden tener múltiples casos exclusivos. Por ejemplo, `card_suit` define un tipo con cuatro valores, y `card_value` define un tipo con catorce valores.

### 01-11-recursive-datatypes.md
Se definen los tipos `list` y `tree`, junto con algunos valores de ejemplo.

### 02-00-pattern-matching.md
Se muestra la definición de la función `map` junto con un valor de ejemplo.

### 02-01-exhaustive.md
Se muestra una función `inexhaustive` que emite una advertencia de coincidencia no exhaustiva.

### 02-02-deconstr.md
Se muestra la deconstrucción de un valor de tupla y la definición de un tipo de dato `dog`.

### 02-03-pattern-fun.md
Se muestra un ejemplo de uso de patrones en una función.

### 02-04-cond-expr.md
Se muestran ejemplos de expresiones condicionales.

### 02-05-recursion.md
Se definen funciones recursivas y se muestran ejemplos de uso.

### 02-06-hofs.md
Se muestra el uso de funciones de orden superior.

### 02-07-inf.md
No se muestra salida ya que el programa no produce ninguna.

### 02-08-chaining.md
Se muestra una cadena de llamadas a funciones.

### 02-09-mutable-refs.md
Se muestra el uso de referencias mutables.

### 02-10-while.md
Se muestra un bucle `while` que cuenta del 1 al 10.

### 03-01-spawn.md
Se muestra la creación de hilos y su ejecución.

### 03-02-chan.md
Se muestra el uso de canales para comunicación entre hilos.

### 03-03-select.md
Se muestra el uso de selección de canales con CML.

### 03-04-mailboxes.md
Se muestra el envío y recepción de valores a través de buzones.

### 03-05-ivars.md
Muestra el uso de I-Vars, pero hay un error debido a una estructura no enlazada.

### 03-06-mvars.md
No se imprime nada directamente, pero se espera que se produzca una excepción `Put` al intentar establecer dos veces el mismo valor en la variable de sincronización.
