# Proyecto de Ordenamiento Para Concesionaria de Porsche

Este programa gestiona y ordena información sobre modelos de coches Porsche utilizando un Árbol Binario de Búsqueda (BST).

> [!NOTE]
> `g++ main.cpp -o app`

## Características principales

1. Carga de datos desde un archivo CSV:

   - Lee información de modelos Porsche desde un archivo CSV.
   - Parsea cada línea para extraer modelo, año de lanzamiento y velocidad máxima.

2. Ordenamiento de modelos por múltiples criterios:

   - Fecha de lanzamiento: Ordena los coches del más antiguo al más reciente.
   - Velocidad máxima: Organiza los modelos del más lento al más rápido.
   - Nombre del modelo: Ordena alfabéticamente los nombres de los modelos.

3. Búsqueda eficiente de modelos específicos:

   - Permite al usuario buscar un modelo concreto por su nombre.
   - Utiliza la estructura del BST para optimizar la búsqueda.

4. Visualización de resultados ordenados:
   - Muestra los resultados de manera organizada en la consola.
   - Presenta la información relevante de cada modelo (nombre, año, velocidad).

## Implementación

- Árbol Binario de Búsqueda (BST):

  - Utiliza un BST para almacenar y gestionar los datos de los coches.
  - La clave del BST es el nombre del modelo, permitiendo un ordenamiento natural por nombre.
  - Implementa operaciones de inserción, búsqueda y recorrido inorden.

- QuickSort para ordenamientos adicionales:

  - Aplica QuickSort para ordenar por fecha de lanzamiento y velocidad máxima.
  - Utiliza funciones de comparación personalizadas para cada criterio de ordenamiento.

- Lectura de archivos CSV:

  - Implementa un parser de CSV para leer los datos iniciales.
  - Maneja excepciones para asegurar una carga de datos robusta.

## Análisis de complejidad

- Construcción del BST (basado en el nombre del coche):

  - Promedio: O(n log n), donde cada inserción es O(log n) y se realizan n inserciones.
  - Peor caso: O(n²), ocurre cuando los nombres de los modelos están ordenados, resultando en un árbol degenerado.

- Búsqueda en BST:

  - Promedio: O(log n), aprovecha la estructura balanceada del árbol.
  - Peor caso: O(n), ocurre en un árbol degenerado.

- QuickSort para ordenamientos adicionales:

  - Promedio: O(n log n), eficiente para la mayoría de los casos.
  - Peor caso: O(n²).

- Recorrido inorden del BST:

  - O(n), visita cada nodo exactamente una vez.

- Operaciones adicionales:
  - Lectura del archivo CSV: O(n), donde n es el número de líneas en el archivo.
  - Creación del vector para QuickSort: O(n), copia cada elemento del BST al vector.

### Complejidad por caso:

1. Ordenar por fecha de lanzamiento:

   - Complejidad: O(n log n)
   - Desglose: O(n) para crear el vector + O(n log n) para QuickSort

2. Ordenar por velocidad máxima:

   - Complejidad: O(n log n)
   - Desglose: O(n) para crear el vector + O(n log n) para QuickSort

3. Ordenar por nombre del modelo:

   - Complejidad: O(n log n)
   - Desglose: O(n) para el recorrido inorden

4. Buscar un modelo específico:

   - Complejidad: O(log n) en promedio, O(n) en el peor caso
   - Desglose: O(log n) para la búsqueda en el BST

La complejidad general del programa está dominada por la construcción inicial del BST y las operaciones de ordenamiento, resultando en una complejidad de O(n log n) para la mayoría de los casos prácticos.


> [!IMPORTANT]
> ## Correciones
>
> Sep 30:
> 	- Cambio de los archivos a headers, para que haya un solo .cpp.
> 	- Comentarios explicando complejidad de cada función
>
> Oct 2:
> 	- Junta con Benji, arreglo del sort por default.
>	- Arreglo de signo para sort.
>
> Oct 14:
>	- Arreglo de manejo de vectores para el sorting de modelos por velocidad y año.
> 
> Nov 26:
>  - Hacer mas claro el guardar archivo
