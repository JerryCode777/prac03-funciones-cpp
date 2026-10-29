#include "producto.h"
#include <iomanip>

// Responsable: Diego

Producto operator+(const Producto& a, const Producto& b) {
    return Producto(
        a.codigo_ + "+" + b.codigo_,
        a.nombre_ + " + " + b.nombre_,
        a.precio_ + b.precio_,
        a.cantidad_ + b.cantidad_
    );
}

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
