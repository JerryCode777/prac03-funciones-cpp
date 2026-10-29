# Conceptos aplicados en el Sistema de Productos

| Requisito de la práctica | Implementación | Archivo | Responsable |
|--------------------------|----------------|---------|-------------|
| Función **inline** para calcular el descuento | `inline double calcularDescuento(double precio, double porcentaje)` y `precioConDescuento` | `include/descuento.h` | Fernando |
| Clase `Producto` con atributos **privados** | `codigo_`, `nombre_`, `precio_`, `cantidad_` en la sección `private` | `include/producto.h` | Gabriel |
| Función **friend** que compare precios | `friend int compararPrecios(const Producto&, const Producto&)` accede a `precio_` sin getters | `src/producto.cpp` | Gabriel |
| Funciones **const** para mostrar datos | `getCodigo() const`, `getNombre() const`, `getPrecio() const`, `getCantidad() const`, `mostrarDatos() const` | `src/producto.cpp` | Gabriel |
| **Lambda** para filtrar por precio | `std::copy_if(..., [min, max](const Producto& p) { ... })` | `src/filtros.cpp` | Fernando |
| Sobrecarga de **`+`** | `friend Producto operator+(const Producto&, const Producto&)`: paquete con precio y cantidad sumados | `src/operadores.cpp` | Diego |
| **Reto:** sobrecarga de **`<<`** | `friend std::ostream& operator<<(std::ostream&, const Producto&)` | `src/operadores.cpp` | Diego |
| Extra: lambda para ordenar | `std::sort(..., [](const Producto& a, const Producto& b) { ... })` | `src/filtros.cpp` | Fernando |

## Por qué cada decisión

- **`inline` en el `.h`:** el compilador necesita ver el cuerpo de la función en cada archivo donde se llama para poder sustituir la llamada; por eso las funciones inline se definen en el encabezado.
- **`compararPrecios` como `friend`:** compara `precio_` directamente, demostrando el acceso a miembros privados sin pertenecer a la clase.
- **`operator+` y `operator<<` como `friend`:** `operator<<` no puede ser miembro de `Producto` porque su operando izquierdo es `std::ostream`; `operator+` como friend trata a ambos operandos de forma simétrica.
- **Parámetros `const Producto&`:** evitan copiar el objeto y garantizan que la función no lo modifica.
- **`setPrecio` no es `const`:** contrasta con las funciones de consulta; un objeto `const` no puede llamarla.
- **Captura `[min, max]` en la lambda:** copia los límites del filtro dentro de la función anónima.
