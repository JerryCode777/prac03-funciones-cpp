#ifndef DESCUENTO_H
#define DESCUENTO_H

// Responsable: Fernando
// Funciones inline: van en el .h porque el compilador necesita ver el cuerpo
// en cada lugar donde se llaman para poder reemplazar la llamada.

inline double calcularDescuento(double precio, double porcentaje) {
    if (porcentaje < 0.0 || porcentaje > 100.0) {
        return 0.0;
    }
    return precio * porcentaje / 100.0;
}

inline double precioConDescuento(double precio, double porcentaje) {
    return precio - calcularDescuento(precio, porcentaje);
}

#endif
