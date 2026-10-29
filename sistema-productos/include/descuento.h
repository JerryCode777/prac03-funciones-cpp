#ifndef DESCUENTO_H
#define DESCUENTO_H

// Responsable: Fernando
// Funciones inline: van en el .h porque el compilador necesita ver el cuerpo
// en cada lugar donde se llaman para poder reemplazar la llamada.

// TODO: devolver el monto del descuento: precio * porcentaje / 100.
//       Si el porcentaje está fuera de 0..100, devolver 0.
inline double calcularDescuento([[maybe_unused]] double precio, [[maybe_unused]] double porcentaje) {
    return 0.0;
}

// TODO: devolver precio - calcularDescuento(precio, porcentaje).
inline double precioConDescuento([[maybe_unused]] double precio, [[maybe_unused]] double porcentaje) {
    return 0.0;
}

#endif
