#include "producto.h"

// Responsable: Diego
// TODO:
//   - operator+: devolver un Producto con
//       codigo   = a.codigo_ + "+" + b.codigo_
//       nombre   = a.nombre_ + " + " + b.nombre_
//       precio   = a.precio_ + b.precio_
//       cantidad = a.cantidad_ + b.cantidad_
//   - operator<<: escribir en `os` el formato  [P001] Teclado mecánico | S/ 150.00 | stock: 10
//     (std::fixed y std::setprecision(2) de <iomanip>) y devolver `os` para poder encadenar.

Producto operator+([[maybe_unused]] const Producto& a, [[maybe_unused]] const Producto& b) {
    return Producto("[pendiente]", "[pendiente: operator+]");
}

std::ostream& operator<<(std::ostream& os, [[maybe_unused]] const Producto& producto) {
    return os << "[pendiente: operator<<]";
}
