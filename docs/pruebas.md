# Casos de prueba

Cada integrante ejecuta los casos de su parte y verifica que su salida coincida con el **resultado esperado**.

| ID | Parte | Entrada | Resultado esperado | Resultado |
|----|-------|---------|--------------------|-----------|
| P1-01 | Práctica 1 | Cuadrado, lado 4 | Área 16.00 | |
| P1-02 | Práctica 1 | Rectángulo, base 5, altura 3 | Área 15.00 | |
| P1-03 | Práctica 1 | Círculo, radio 2 | Área 12.57 | |
| P1-04 | Práctica 1 | Opción de menú inválida | Mensaje y vuelve al menú | |
| S-01 | operator<< | Opción 1 | Catálogo con formato `[P001] Teclado mecánico \| S/ 150.00 \| stock: 10` | |
| S-02 | const | Opción 2, producto 3 | Detalle del monitor | |
| S-03 | const | Agregar `precio_ = 0;` dentro de `mostrarDatos() const` | Error de compilación (luego se borra) | |
| S-04 | friend | Opción 3, productos 6 y 1 | `Laptop es más caro que Teclado mecánico.` | |
| S-05 | inline | Opción 4, producto 6, 20 % | Descuento S/ 579.80, final S/ 2319.20 | |
| S-06 | lambda | Opción 5, rango 40 a 200 | Teclado, Mouse y Audífonos | |
| S-07 | operator+ | Opción 6, productos 1 y 2 | `[P001+P002] Teclado mecánico + Mouse inalámbrico \| S/ 195.50 \| stock: 35` | |
| S-08 | lambda | Opción 7 | Catálogo de menor a mayor precio | |
| S-09 | setPrecio | Opción 8, precio -5 | `El precio no puede ser negativo.` | |
