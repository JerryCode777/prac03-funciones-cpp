// Sistema de Productos: integra funciones inline, friend, const, lambda y sobrecarga de operadores.
// Responsable: Jerry (menú e integración)

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "descuento.h"
#include "filtros.h"
#include "producto.h"

namespace {

// Catálogo de ejemplo con el que arranca el sistema.
std::vector<Producto> catalogoInicial() {
    return {
        {"P001", "Teclado mecánico", 150.0, 10},
        {"P002", "Mouse inalámbrico", 45.5, 25},
        {"P003", "Monitor 24 pulgadas", 620.0, 5},
        {"P004", "Audífonos", 89.9, 15},
        {"P005", "Memoria USB 64 GB", 35.0, 40},
        {"P006", "Laptop", 2899.0, 3},
    };
}

std::string leerLinea(const std::string& mensaje) {
    std::cout << mensaje;
    std::string linea;
    if (!std::getline(std::cin, linea)) {
        throw std::runtime_error("entrada finalizada");
    }
    return linea;
}

// Pide un número hasta que sea válido: usa std::stod y verifica que no sobren caracteres.
double leerReal(const std::string& mensaje) {
    while (true) {
        std::string texto = leerLinea(mensaje);
        try {
            std::size_t pos = 0;
            double valor = std::stod(texto, &pos);
            if (pos == texto.size()) {
                return valor;
            }
        } catch (const std::exception&) {
            // se informa abajo
        }
        std::cout << "Debe ingresar un número válido.\n";
    }
}

// Pide el número de un producto (1..N) y devuelve su posición en el vector (0..N-1).
std::size_t elegirProducto(const std::vector<Producto>& catalogo, const std::string& mensaje) {
    const std::string rango = " (1-" + std::to_string(catalogo.size()) + "): ";
    while (true) {
        double numero = leerReal(mensaje + rango);
        if (numero >= 1 && numero <= static_cast<double>(catalogo.size()) && numero == static_cast<int>(numero)) {
            return static_cast<std::size_t>(numero) - 1;
        }
        std::cout << "Número de producto fuera de rango.\n";
    }
}

// Muestra cada producto con el operador << sobrecargado.
void listar(const std::vector<Producto>& productos) {
    if (productos.empty()) {
        std::cout << "No hay productos para mostrar.\n";
        return;
    }
    for (std::size_t i = 0; i < productos.size(); ++i) {
        std::cout << std::setw(2) << i + 1 << ". " << productos[i] << '\n';  // operator<<
    }
}

void verDetalle(const std::vector<Producto>& catalogo) {
    catalogo[elegirProducto(catalogo, "Producto")].mostrarDatos();  // función const
}

// compararPrecios es friend: compara precio_ directamente, sin getters.
void comparar(const std::vector<Producto>& catalogo) {
    const Producto& a = catalogo[elegirProducto(catalogo, "Primer producto")];
    const Producto& b = catalogo[elegirProducto(catalogo, "Segundo producto")];
    int resultado = compararPrecios(a, b);  // función friend
    if (resultado > 0) {
        std::cout << a.getNombre() << " es más caro que " << b.getNombre() << ".\n";
    } else if (resultado < 0) {
        std::cout << b.getNombre() << " es más caro que " << a.getNombre() << ".\n";
    } else {
        std::cout << "Ambos productos cuestan lo mismo.\n";
    }
}

// calcularDescuento y precioConDescuento son funciones inline.
void aplicarDescuento(const std::vector<Producto>& catalogo) {
    const Producto& producto = catalogo[elegirProducto(catalogo, "Producto")];
    double porcentaje = leerReal("Porcentaje de descuento (0-100): ");
    std::cout << std::fixed << std::setprecision(2)
              << "Precio original: S/ " << producto.getPrecio() << '\n'
              << "Descuento:       S/ " << calcularDescuento(producto.getPrecio(), porcentaje) << '\n'  // inline
              << "Precio final:    S/ " << precioConDescuento(producto.getPrecio(), porcentaje) << '\n';
}

// filtrarPorPrecio usa una lambda que captura el rango ingresado.
void filtrar(const std::vector<Producto>& catalogo) {
    double minimo = leerReal("Precio mínimo: S/ ");
    double maximo = leerReal("Precio máximo: S/ ");
    listar(filtrarPorPrecio(catalogo, minimo, maximo));  // lambda
}

// a + b usa el operator+ sobrecargado y devuelve un Producto nuevo: el paquete.
void combinar(const std::vector<Producto>& catalogo) {
    const Producto& a = catalogo[elegirProducto(catalogo, "Primer producto")];
    const Producto& b = catalogo[elegirProducto(catalogo, "Segundo producto")];
    std::cout << "Paquete: " << (a + b) << '\n';  // operator+
}

// Se ordena una copia con std::sort y una lambda; el catálogo original no cambia.
void ordenar(const std::vector<Producto>& catalogo) {
    std::vector<Producto> copia = catalogo;  // el catálogo original no cambia
    ordenarPorPrecio(copia);                 // lambda en std::sort
    listar(copia);
}

// setPrecio no es const: es la única opción que modifica un producto del catálogo.
void cambiarPrecio(std::vector<Producto>& catalogo) {
    Producto& producto = catalogo[elegirProducto(catalogo, "Producto")];
    if (producto.setPrecio(leerReal("Nuevo precio: S/ "))) {  // función no const
        std::cout << "Precio actualizado: " << producto << '\n';
    } else {
        std::cout << "El precio no puede ser negativo.\n";
    }
}

void mostrarMenu() {
    std::cout << "\n======= SISTEMA DE PRODUCTOS =======\n"
              << "1. Listar catálogo            (operator<<)\n"
              << "2. Ver detalle de un producto (const)\n"
              << "3. Comparar precios           (friend)\n"
              << "4. Calcular descuento         (inline)\n"
              << "5. Filtrar por precio         (lambda)\n"
              << "6. Combinar dos productos     (operator+)\n"
              << "7. Ordenar por precio         (lambda)\n"
              << "8. Cambiar precio\n"
              << "0. Salir\n"
              << "Opción: ";
}

}  // namespace

// Menú principal: cada opción aplica uno de los conceptos de la práctica.
int main() {
    std::vector<Producto> catalogo = catalogoInicial();
    try {
        while (true) {
            mostrarMenu();
            std::string opcion;
            if (!std::getline(std::cin, opcion) || opcion == "0") {
                break;
            }
            if (opcion == "1") {
                listar(catalogo);
            } else if (opcion == "2") {
                verDetalle(catalogo);
            } else if (opcion == "3") {
                comparar(catalogo);
            } else if (opcion == "4") {
                aplicarDescuento(catalogo);
            } else if (opcion == "5") {
                filtrar(catalogo);
            } else if (opcion == "6") {
                combinar(catalogo);
            } else if (opcion == "7") {
                ordenar(catalogo);
            } else if (opcion == "8") {
                cambiarPrecio(catalogo);
            } else {
                std::cout << "Opción no válida. Elija un número del 0 al 8.\n";
            }
        }
    } catch (const std::runtime_error&) {
        // la entrada se cerró a mitad de una operación
    }
    std::cout << "\nSistema finalizado.\n";
    return 0;
}
