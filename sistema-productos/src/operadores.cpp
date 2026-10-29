#include "producto.h"
#include <iomanip>

// Responsable: Diego

// Sobrecarga de operadores de Producto. Ambos son friend porque leen los atributos privados.
//
// operator+ combina dos productos en un paquete: une códigos y nombres, y suma precios y
// cantidades. Recibe referencias const porque no modifica los productos originales.
Producto operator+(const Producto& a, const Producto& b) {
    return Producto(
        a.codigo_ + "+" + b.codigo_,
        a.nombre_ + " + " + b.nombre_,
        a.precio_ + b.precio_,
        a.cantidad_ + b.cantidad_
    );
}

// operator<< no puede ser miembro de Producto, porque su operando izquierdo es el flujo
// (std::cout) y no el producto. Devuelve el flujo para poder encadenar:
// std::cout << p1 << '\n' << p2;
std::ostream& operator<<(std::ostream& os, const Producto& producto) {
    // Guardar el estado actual de los flags de formato de os
    std::ios state(nullptr);
    state.copyfmt(os);

    os << "[" << producto.codigo_ << "] "
       << producto.nombre_ << " | S/ "
       << std::fixed << std::setprecision(2) << producto.precio_
       << " | stock: " << producto.cantidad_;

    // Restaurar el estado anterior de os para no alterar flujos externos
    os.copyfmt(state);

    return os;
}
