#include "producto.h"

#include <iomanip>
#include <iostream>

// Responsable: Gabriel
const std::string& Producto::getCodigo() const { return codigo_; }

const std::string& Producto::getNombre() const { return nombre_; }

double Producto::getPrecio() const { return precio_; }

int Producto::getCantidad() const { return cantidad_; }

void Producto::mostrarDatos() const {
    const auto formato = std::cout.flags();
    const auto precision = std::cout.precision();
    std::cout << "Código: " << codigo_ << '\n'
              << "Nombre: " << nombre_ << '\n'
              << "Precio: S/ " << std::fixed << std::setprecision(2) << precio_ << '\n'
              << "Stock: " << cantidad_ << '\n';
    std::cout.flags(formato);
    std::cout.precision(precision);
}

bool Producto::setPrecio(double precio) {
    if (precio < 0) {
        return false;
    }
    precio_ = precio;
    return true;
}

// La declaración friend permite consultar los atributos privados directamente.
int compararPrecios(const Producto& a, const Producto& b) {
    if (a.precio_ > b.precio_) {
        return 1;
    }
    if (a.precio_ < b.precio_) {
        return -1;
    }
    return 0;
}
