#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "car.h"
#include "sort.h"

template <class T> class BST;

template <class T>
class TreeNode {
private:
    T value;
    TreeNode *left, *right;

    TreeNode<T>* predecesor();

public:
    TreeNode(T);
    TreeNode(T, TreeNode<T>*, TreeNode<T>*);
    void add(T);
    bool find(T) const;
    void remove(T);
    void removeChilds();
    void inorder(std::vector<T>&) const;
    void preorder(std::stringstream&) const;

    friend class BST<T>;
};

template <class T>
TreeNode<T>::TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}

template <class T>
TreeNode<T>::TreeNode(T val, TreeNode<T> *le, TreeNode<T> *ri) : value(val), left(le), right(ri) {}

template <class T>
void TreeNode<T>::add(T val) {
    if (val < value) {
        if (left != nullptr) {
            left->add(val);
        } else {
            left = new TreeNode<T>(val);
        }
    } else {
        if (right != nullptr) {
            right->add(val);
        } else {
            right = new TreeNode<T>(val);
        }
    }
}

template <class T>
bool TreeNode<T>::find(T val) const {
    if (val == value) {
        return true;
    }
    if (val < value) {
        return (left != nullptr) ? left->find(val) : false;
    } else {
        return (right != nullptr) ? right->find(val) : false;
    }
}

template <class T>
TreeNode<T>* TreeNode<T>::predecesor() {
    TreeNode<T> *le, *ri;

    le = left;
    ri = right;

    if (left == nullptr) {
        if (right != nullptr) {
            right = nullptr;
        }
        return ri;
    }

    if (left->right == nullptr) {
        left = left->left;
        le->left = nullptr;
        return le;
    }

    TreeNode<T> *parent, *child;
    parent = left;
    child = left->right;
    while (child->right != nullptr) {
        parent = child;
        child = child->right;
    }
    parent->right = child->left;
    child->left = nullptr;
    return child;
}

template <class T>
void TreeNode<T>::remove(T val) {
    TreeNode<T> *succ, *old;

    if (val < value) {
        if (left != nullptr) {
            if (left->value == val) {
                old = left;
                succ = left->predecesor();
                if (succ != nullptr) {
                    succ->left = old->left;
                    succ->right = old->right;
                }
                left = succ;
                delete old;
            } else {
                left->remove(val);
            }
        }
    } else if (val > value) {
        if (right != nullptr) {
            if (right->value == val) {
                old = right;
                succ = right->predecesor();
                if (succ != nullptr) {
                    succ->left = old->left;
                    succ->right = old->right;
                }
                right = succ;
                delete old;
            } else {
                right->remove(val);
            }
        }
    }
}

template <class T>
void TreeNode<T>::removeChilds() {
    if (left != nullptr) {
        left->removeChilds();
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        right->removeChilds();
        delete right;
        right = nullptr;
    }
}

template <class T>
void TreeNode<T>::preorder(std::stringstream &aux) const {
    aux << value;
    if (left != nullptr) {
        aux << " ";
        left->preorder(aux);
    }
    if (right != nullptr) {
        aux << " ";
        right->preorder(aux);
    }
}

template <class T>
void TreeNode<T>::inorder(std::vector<T>& vec) const {
    if (left != nullptr) {
        left->inorder(vec);
    }
    vec.push_back(value);
    if (right != nullptr) {
        right->inorder(vec);
    }
}

template <class T>
class BST {
private:
    TreeNode<T> *root;

public:
    BST();
    ~BST();
    bool empty() const;
    void add(T);
    bool find(T) const;
    void remove(T);
    void removeAll();
    std::vector<T> inorder() const;
    std::string preorder() const;
    void loadFromCSV(const std::string& filename);
    std::vector<T> getSortedCars(bool (*compare)(const T&, const T&)) const;
};

template <class T>
BST<T>::BST() : root(nullptr) {}

template <class T>
BST<T>::~BST() {
    removeAll();
}

template <class T>
bool BST<T>::empty() const {
    return (root == nullptr);
}

// Complejidad temporal peor caso: O(n)
// Complejidad espacial: O(log n)
template<class T>
void BST<T>::add(T val) {
    if (root == nullptr) {
        root = new TreeNode<T>(val);
    } else {
        root->add(val);
    }
}

// Complejidad temporal peor caso: O(n)
// Complejidad espacial: O(log n)
template <class T>
void BST<T>::remove(T val) {
    if (root != nullptr) {
        if (val == root->value) {
            TreeNode<T> *succ = root->predecesor();
            if (succ != nullptr) {
                succ->left = root->left;
                succ->right = root->right;
            }
            delete root;
            root = succ;
        } else {
            root->remove(val);
        }
    }
}

// Complejidad temporal peor caso: O(n)
// Complejidad espacial: O(n)
template <class T>
void BST<T>::removeAll() {
    if (root != nullptr) {
        root->removeChilds();
    }
    delete root;
    root = nullptr;
}

// Complejidad temporal peor caso: O(n)
// Complejidad espacial: O(log n)
template <class T>
bool BST<T>::find(T val) const {
    if (empty()) {
        return false;
    }
    return root->find(val);
}

// Complejidad temporal peor caso: O(n)
// Complejidad espacial: O(n)
template <class T>
std::string BST<T>::preorder() const {
    std::stringstream aux;

    aux << "[";
    if (!empty()) {
        root->preorder(aux);
    }
    aux << "]";
    return aux.str();
}

// Complejidad temporal peor caso: O(n)
// Complejidad espacial: O(n)
template <class T>
std::vector<T> BST<T>::inorder() const {
    std::vector<T> result;
    if (!empty()) {
        root->inorder(result);
    }
    return result;
}

template <class T>
void BST<T>::loadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string model;
        int year;
        double speed;
        if (std::getline(iss, model, ',') && iss >> year && iss.ignore() && iss >> speed) {
            add(T(model, year, speed));
        }
    }
    file.close();
}

// Complejidad temporal peor caso: O(n^2)
// Complejidad espacial: O(n)
template <class T>
std::vector<T> BST<T>::getSortedCars(bool (*compare)(const T&, const T&)) const {
    std::vector<T> cars = inorder();
    quickSort(cars, 0, cars.size() - 1, compare);
    return cars;
}

#endif