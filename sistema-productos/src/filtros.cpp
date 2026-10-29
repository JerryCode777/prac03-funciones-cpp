#include "filtros.h"

#include <algorithm>
#include <iterator>

// Responsable: Fernando

// Filtros del catálogo con funciones lambda y algoritmos de <algorithm>.
//
// Devuelve una lista nueva con los productos cuyo precio está entre min y max.
std::vector<Producto> filtrarPorPrecio(const std::vector<Producto>& productos,
                                       double min, double max) {
    std::vector<Producto> resultado;
    // La lambda [min, max] captura los límites por copia. copy_if la llama con cada
    // producto y copia en `resultado` los que devuelven true.
    std::copy_if(productos.begin(), productos.end(), std::back_inserter(resultado),
                 [min, max](const Producto& p) {
                     return p.getPrecio() >= min && p.getPrecio() <= max;
                 });
    return resultado;
}

// Ordena de menor a mayor precio. La lambda le indica a std::sort cuándo un producto
// debe ir antes que otro.
void ordenarPorPrecio(std::vector<Producto>& productos) {
    std::sort(productos.begin(), productos.end(),
              [](const Producto& a, const Producto& b) {
                  return a.getPrecio() < b.getPrecio();
              });
}
