#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <sstream>
#include <string>

#include "cola.h"


/**
 * Clase Compra.
 */
class Compra {
public:
    Compra(int tid, int cantidad, int costo);
    int getID() const;
    int getCantidad() const;
    int getCosto() const;
    int disponibles() const;
    bool vender(int cantidad);
    
private:
    int tid;
    int costo;
    int cantidad;
    int vendidas;
    friend std::ostream& operator<<(std::ostream &, const Compra &);
};


Compra::Compra(int tid, int cantidad, int costo)
: tid(tid), cantidad(cantidad), costo(costo) {
    // implementar
}


int Compra::getID() const {
    return tid;
}


int Compra::getCantidad() const {
    return cantidad;
}


int Compra::getCosto() const {
    return costo;
}


int Compra::disponibles() const {
    // implementar
    return 0;
}


bool Compra::vender(int cant) {
    // implementar
    return true;
}


std::ostream& operator<<(std::ostream &strm, const Compra &c) {
  return strm << "Compra. Día: " << std::to_string(c.tid)
    << "; Cantidad: " << std::to_string(c.cantidad)
    << "; Costo: $" << std::to_string(c.costo)
    << "; Disponibles: " << std::to_string(c.disponibles());
}




/**
 * Clase Venta.
 */
class Venta {
public:
    Venta(int tid, int cantidad, int costoCompra, int costoVenta);
    int getID() const;
    int getCantidad() const;
    int getCosto() const;
    int getGanancia() const;

private:
    int tid;
    int cantidad;
    int costo;
    int ganancia;
    friend std::ostream& operator<<(std::ostream&, const Venta&);
};


Venta::Venta(int tid, int cantidad, int costoCompra, int costoVenta)
: tid(tid), cantidad(cantidad), costo(costoVenta) {
    // implementar
}


int Venta::getID() const {
    return tid;
}


int Venta::getCosto() const {
    return costo;
}


int Venta::getCantidad() const {
    return cantidad;
}


int Venta::getGanancia() const {
    return ganancia;
}


std::ostream& operator<<(std::ostream &strm, const Venta &v) {
    std::string venta = "Venta. Transacción: " + std::to_string(v.tid)
                        + "; Acciones: " + std::to_string(v.cantidad)
                        + "; Costo: $" + std::to_string(v.costo)
                        + "; Ganancia: ";
    if (v.ganancia < 0)
        venta += "-$" + std::to_string(v.ganancia * -1);
    else
        venta += "$" + std::to_string(v.ganancia);
  return strm << venta;
}



/**
 * Clase SistemaCV.
 */
class SistemaCV {
public:
    SistemaCV();
    Compra comprar(int tid, int cantidad, int costo);
    Cola<Venta> vender(int tid, int cantidad, int costo);
    int getAcciones();
    int getGanancia();
    int getAccionesVendidas();

private:
    Cola<Compra> compras;
    Cola<Venta> ventas;
    int acciones;
    int ganancia;
    int vendidas;
    friend std::ostream& operator<<(std::ostream &strm, const SistemaCV &s);
};


SistemaCV::SistemaCV() {
    // implementar
}


Compra SistemaCV::comprar(int tid, int cantidad, int costo) {
    // implementar
    return new Compra(0,0,0);
}



Cola<Venta> SistemaCV::vender(int tid, int cantidad, int costo) {
    Cola<Venta> gana;
    // implementar
    return gana;
}
    

int SistemaCV::getAcciones() {
    return acciones;
}


int SistemaCV::getGanancia() {
    return ganancia;
}


int SistemaCV::getAccionesVendidas() {
    return vendidas;
}


std::ostream& operator<<(std::ostream &strm, const SistemaCV &s) {
    std::string sistema = "Acciones en el sistema: \n";
    if (s.compras.esVacia())
        sistema += "\tNo hay acciones en el sistema.\n";
    else {
        std::stringstream ss;
        ss << s.compras;
        sistema += ss.str() + "\n\n";
    }
    sistema += "Acciones vendidas: \n";
    if (s.ventas.esVacia())
        sistema += "\tNo se han vendido acciones.\n";
    else {
        std::stringstream ss;
        ss << s.ventas;
        sistema += ss.str() + "\n";
    }
    return strm << sistema;
}


#endif // SISTEMA_H
