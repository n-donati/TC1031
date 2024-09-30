# Proyecto de Ordenamiento Para Concesionaria de Porsche
> [!IMPORTANT]
> ## Linux
> # **g++ main.cpp -o app**
>
> ## Windows
> # **g++ main.cpp -o app.exe**
>
> ## macOS
> # **g++ main.cpp -o app**

Este programa gestiona y ordena información sobre modelos de coches Porsche.

## Características principales

1. Carga de datos desde un archivo CSV.
2. Ordenamiento de modelos por:
   - Fecha de lanzamiento
   - Velocidad máxima
   - Nombre del modelo
3. Visualización de resultados ordenados.

## Implementación

- Utiliza QuickSort para un rendimiento óptimo en el ordenamiento de datos.
- Emplea vectores para almacenar y manipular eficientemente la información de los coches.
- Implementa lectura de archivos CSV para cargar datos iniciales.

## Análisis de complejidad

- QuickSort: O(n log n) en promedio, garantizando un rendimiento eficiente incluso con grandes conjuntos de datos.
- Operaciones de vector: O(1) para acceso y O(n) para inserción al final.
- Complejidad general del programa: O(n log n), determinada por el algoritmo de ordenamiento.
