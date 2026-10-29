#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <ostream>
#include <string>
#include <utility>

// Producto del catálogo con atributos privados.
// Implementación repartida:
//   Gabriel -> src/producto.cpp   (funciones const, setPrecio y la friend compararPrecios)
//   Diego   -> src/operadores.cpp (operator+ y operator<<)
class Producto {
public:
    Producto(std::string codigo = "", std::string nombre = "", double precio = 0.0, int cantidad = 0)
        : codigo_(std::move(codigo)), nombre_(std::move(nombre)), precio_(precio), cantidad_(cantidad) {}

    // Funciones const: consultan el objeto sin modificarlo.
    const std::string& getCodigo() const;
    const std::string& getNombre() const;
    double getPrecio() const;
    int getCantidad() const;
    void mostrarDatos() const;

    // Función no const: modifica el objeto. Si el precio es negativo no lo cambia y devuelve false.
    bool setPrecio(double precio);

    // Función friend: compara precios accediendo directamente a precio_.
    // Devuelve 1 si a es más caro, -1 si b es más caro y 0 si cuestan lo mismo.
    friend int compararPrecios(const Producto& a, const Producto& b);

    // Combina dos productos en un paquete: códigos y nombres unidos con " + ",
    // precio y cantidad sumados.
    friend Producto operator+(const Producto& a, const Producto& b);

    // Muestra el producto en una línea legible, por ejemplo:
    // [P001] Teclado mecánico | S/ 150.00 | stock: 10
    friend std::ostream& operator<<(std::ostream& os, const Producto& producto);

private:
    std::string codigo_;
    std::string nombre_;
    double precio_;
    int cantidad_;
};

#endif
