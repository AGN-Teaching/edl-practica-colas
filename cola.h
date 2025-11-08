#ifndef COLA_H
#define COLA_H

#include <sstream>
#include <string>

/**
 * Clase Nodo para su uso en colas.
 */
template <typename T>
class Nodo {
public:
    Nodo();
    T* elemento;
    Nodo<T> *siguiente;
};


template <typename T>
Nodo<T>::Nodo() {
    siguiente = NULL;
}



/**
 * Clase Cola.
 */
template <typename T>
class Cola {
public:
    Cola<T>();
    ~Cola<T>();
    bool enqueue(T* x);
    bool dequeue();
    T* frente() const;
    bool esVacia() const;
    int getNumElementos() const;
    std::string aTexto() const;

private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
    int numElementos;
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Cola<U>&);
};


/**
 * Constructor.
 */
template <typename T>
Cola<T>::Cola() {
    primero = new Nodo<T>();
    ultimo = primero;
    numElementos = 0;
}


/**
 * Destructor.
 */
template <typename T>
Cola<T>::~Cola() {
    while (!esVacia())
        dequeue();
    delete primero;
}


/**
 * Inserta un elemento.
 */
template <typename T>
bool Cola<T>::enqueue(T* x) {
    // implementar
    return true;
}


/**
 * Elimina el elemento en el frente.
 */
template <typename T>
bool Cola<T>::dequeue() {
    bool exito = false;
    // implementar
    return exito;
}


/**
 * Devuelve el elemento en el frente.
 */
template <typename T>
T* Cola<T>::frente() const {
    T *elem;
    // implementar
    return elem;
}


/**
 * Verifica si es vacia.
 */
template <typename T>
bool Cola<T>::esVacia() const {
    // implementar
    return false;
}


/**
 * Devuelve el número de elementos.
 */
template <typename T>
int Cola<T>::getNumElementos() const {
    return numElementos;
}


template <typename T>
std::ostream& operator<<(std::ostream &strm, const Cola<T> &q) {
    std::string elems = "";
    if (!q.esVacia()) {
        Nodo<T> *p = q.primero->siguiente;
        while (p != NULL) {
            std::stringstream ss;
            ss << *(p->elemento);
            elems += ss.str() + "\n";
            p = p->siguiente;
        }
    }
    elems.pop_back();
    return strm << elems;
}


#endif // COLA_H
