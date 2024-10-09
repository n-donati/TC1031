# Proyecto de Ordenamiento Para Concesionaria de Porsche

Este programa gestiona y ordena información sobre modelos de coches Porsche utilizando un Árbol Binario de Búsqueda (BST).

> [!IMPORTANT]
>
> ## Linux
>
> # g++ main.cpp -o app
>
> ## Windows
>
> # g++ main.cpp -o app.exe
>
> ## macOS
>
> # g++ main.cpp -o app

## Características principales

1. Carga de datos desde un archivo CSV.
2. Ordenamiento de modelos por:
   - Fecha de lanzamiento
   - Velocidad máxima
   - Nombre del modelo
3. Búsqueda eficiente de modelos específicos.
4. Visualización de resultados ordenados.

## Implementación

- Utiliza un Árbol Binario de Búsqueda (BST) para almacenar y gestionar eficientemente los datos de los coches.
- Emplea QuickSort para ordenar.
- Implementa lectura de archivos CSV para cargar datos iniciales.

## Análisis de complejidad

- Inserción en BST: O(log n) en promedio, O(n) en el peor caso.
- Búsqueda en BST: O(log n) en promedio, O(n) en el peor caso.
- QuickSort para ordenamientos adicionales: O(n log n) en promedio.
- Recorrido inorden del BST: O(n).
- Complejidad general del programa: O(n log n), determinada por el algoritmo de ordenamiento QuickSort para criterios específicos.
