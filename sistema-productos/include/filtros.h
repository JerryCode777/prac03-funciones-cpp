#ifndef FILTROS_H
#define FILTROS_H

#include <vector>

#include "producto.h"

// Responsable: Fernando
// Operaciones sobre el catálogo implementadas con funciones lambda.

// Devuelve los productos cuyo precio está entre min y max (inclusive).
std::vector<Producto> filtrarPorPrecio(const std::vector<Producto>& productos, double min, double max);

// Ordena los productos de menor a mayor precio.
void ordenarPorPrecio(std::vector<Producto>& productos);

#endif
