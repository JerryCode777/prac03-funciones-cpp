#include "filtros.h"

#include <algorithm>
#include <iterator>

// Responsable: Fernando

std::vector<Producto> filtrarPorPrecio(const std::vector<Producto>& productos,
                                       double min, double max) {
    std::vector<Producto> resultado;
    std::copy_if(productos.begin(), productos.end(), std::back_inserter(resultado),
                 [min, max](const Producto& p) {
                     return p.getPrecio() >= min && p.getPrecio() <= max;
                 });
    return resultado;
}

void ordenarPorPrecio(std::vector<Producto>& productos) {
    std::sort(productos.begin(), productos.end(),
              [](const Producto& a, const Producto& b) {
                  return a.getPrecio() < b.getPrecio();
              });
}
