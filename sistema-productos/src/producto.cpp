// Implementación de la clase Producto.
// Las funciones marcadas con const solo consultan el objeto: el compilador no permite
// modificar ningún atributo dentro de ellas.
#include "producto.h"

#include <iomanip>
#include <iostream>

// Responsable: Gabriel
// Getters const: devuelven los atributos privados sin modificarlos. Los textos se
// devuelven por referencia constante para no copiarlos.
const std::string& Producto::getCodigo() const { return codigo_; }

const std::string& Producto::getNombre() const { return nombre_; }

double Producto::getPrecio() const { return precio_; }

int Producto::getCantidad() const { return cantidad_; }

// Función const: muestra el producto sin modificarlo. Si aquí se escribiera
// precio_ = 0; el compilador daría un error.
void Producto::mostrarDatos() const {
    // Se guarda el formato de cout para restaurarlo al final y no afectar otras salidas.
    const auto formato = std::cout.flags();
    const auto precision = std::cout.precision();
    std::cout << "Código: " << codigo_ << '\n'
              << "Nombre: " << nombre_ << '\n'
              << "Precio: S/ " << std::fixed << std::setprecision(2) << precio_ << '\n'
              << "Stock: " << cantidad_ << '\n';
    std::cout.flags(formato);
    std::cout.precision(precision);
}

// No es const porque modifica el objeto; por eso no se puede llamar sobre un Producto
// constante. Rechaza los precios negativos.
bool Producto::setPrecio(double precio) {
    if (precio < 0) {
        return false;
    }
    precio_ = precio;
    return true;
}

// compararPrecios no es miembro de la clase, pero es friend: puede leer precio_ sin
// usar getters. Devuelve 1 si a es más caro, -1 si lo es b y 0 si cuestan lo mismo.
int compararPrecios(const Producto& a, const Producto& b) {
    if (a.precio_ > b.precio_) {
        return 1;
    }
    if (a.precio_ < b.precio_) {
        return -1;
    }
    return 0;
}
