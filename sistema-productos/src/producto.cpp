#include "producto.h"

#include <iostream>

// Responsable: Gabriel
// TODO:
//   - Getters: devolver el atributo correspondiente (codigo_, nombre_, precio_, cantidad_).
//   - mostrarDatos() const: imprimir código, nombre, precio (2 decimales) y stock, uno por línea.
//     Probar que, si dentro de una función const se escribe  precio_ = 0;  el compilador da error
//     y luego borrar esa línea.
//   - setPrecio: si precio < 0 devolver false sin cambiar nada; si no, asignarlo y devolver true.
//   - compararPrecios (friend): comparar a.precio_ con b.precio_ directamente, sin usar getPrecio().

namespace {
const std::string kPendiente = "[pendiente]";
}

const std::string& Producto::getCodigo() const { return kPendiente; }

const std::string& Producto::getNombre() const { return kPendiente; }

double Producto::getPrecio() const { return 0.0; }

int Producto::getCantidad() const { return 0; }

void Producto::mostrarDatos() const { std::cout << "[pendiente: mostrarDatos]\n"; }

bool Producto::setPrecio([[maybe_unused]] double precio) { return false; }

int compararPrecios([[maybe_unused]] const Producto& a, [[maybe_unused]] const Producto& b) { return 0; }
