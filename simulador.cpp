#include <iostream>

#include "cola.h"
#include "sistema.h"

using namespace std;


enum Transacción { COMPRA, VENTA };


void comprar(SistemaCV &s, int dia, int tid, int cantidad, int costo) {
    Compra c = s.comprar(tid, cantidad, costo);
    cout << "***** Se compran acciones (Día: " << dia << "):" << endl;
    cout << c << endl << endl;
}



void vender(SistemaCV &s, int dia, int tid, int cantidad, int costo) {
    int ganancia = 0;
    Cola<Venta> v = s.vender(tid, cantidad, costo);
    cout << "***** Se venden acciones (Día: " << dia << "):" << endl;
    cout << v << endl;
    while (!v.esVacia()) {
        ganancia += v.frente()->getGanancia();
        v.dequeue();
    }
    cout << "Ganancia de la transacción: ";
    if (ganancia < 0)
        cout << "-$" << (ganancia * -1) << endl << endl;
    else
        cout << "$" << ganancia << endl << endl;
}


void mostrarEstado(SistemaCV &s) {
    cout << s << endl;
    cout << "GANANCIA TOTAL: ";
    if (s.getGanancia() < 0)
        cout << "-$" << (s.getGanancia() * -1) << endl << endl << endl;
    else
        cout << "$" << s.getGanancia() << endl << endl << endl;
}


int main() {
    int D_MAX = 100;
    Transacción transacción[] = {COMPRA, COMPRA, COMPRA, VENTA, COMPRA, VENTA, COMPRA, COMPRA, VENTA, VENTA, COMPRA, VENTA};
    int dias[] = {3, 10, 15, 20, 48, 50, 66, 73, 82, 88, 92, 99};
    int costo[] = {30, 30, 40, 50, 40, 60, 50, 40, 50, 60, 60, 50};
    int cantidad[] = {20, 40, 200, 100, 100, 200, 50, 200, 200, 100, 40, 50};

    SistemaCV s;
    int d = 0;
    int trans = 1;
    for (int dia = 1; dia <= D_MAX; dia++) {
        if (dia == dias[d]) {
            if (transacción[d] == COMPRA)
                comprar(s, dia, trans, cantidad[d], costo[d]);
            else
                vender(s, dia, trans, cantidad[d], costo[d]);
            mostrarEstado(s);
            trans += 1;
            d += 1;
        }
    }
    cout << "Fin del período." << endl;

    return 0;
}
