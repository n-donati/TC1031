#ifndef SORT_H
#define SORT_H

#include <vector>
#include "car.h"

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int partition(std::vector<T>& arr, int low, int high, bool (*compare)(const T&, const T&)) {
    T pivot = arr[high];
    int i = low - 1;
   
    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Complejidad temporal peor caso: O(n^2)
// Complejidad espacial: O(log n) 
template<typename T>
void quickSort(std::vector<T>& arr, int low, int high, bool (*compare)(const T&, const T&)) {
    if (low < high) {
        int pi = partition(arr, low, high, compare);
        quickSort(arr, low, pi - 1, compare);
        quickSort(arr, pi + 1, high, compare);
    }
}

inline bool compareByReleaseYear(const Car& a, const Car& b) {
    return a.getReleaseYear() < b.getReleaseYear();
}

inline bool compareByMaxSpeed(const Car& a, const Car& b) {
    return a.getMaxSpeed() < b.getMaxSpeed();
}

inline bool compareByModelName(const Car& a, const Car& b) {
    return a.getModel() < b.getModel();
}

#endif