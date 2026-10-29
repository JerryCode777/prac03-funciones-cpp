#include "filtros.h"

#include <algorithm>
#include <iterator>

// Responsable: Fernando
// TODO:
//   - filtrarPorPrecio: usar std::copy_if con std::back_inserter y una lambda que capture
//     min y max:  [min, max](const Producto& p) { return ...; }
//   - ordenarPorPrecio: usar std::sort con una lambda que compare dos productos por getPrecio().

std::vector<Producto> filtrarPorPrecio([[maybe_unused]] const std::vector<Producto>& productos,
                                       [[maybe_unused]] double min, [[maybe_unused]] double max) {
    return {};
}

void ordenarPorPrecio([[maybe_unused]] std::vector<Producto>& productos) {}
