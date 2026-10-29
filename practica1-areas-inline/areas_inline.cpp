// Práctica 1: Función inline – Cálculo de áreas
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

constexpr double PI = 3.14159265358979;

inline double areaCuadrado(double lado) { return lado * lado; }

inline double areaRectangulo(double base, double altura) { return base * altura; }

inline double areaCirculo(double radio) { return PI * radio * radio; }

double leerMedida(const std::string& nombre) {
    double valor;
    while (true) {
        std::cout << "Ingrese " << nombre << ": ";
        if (std::cin >> valor && valor >= 0) {
            return valor;
        }
        if (std::cin.eof()) {
            std::exit(0);
        }
        std::cout << "Medida inválida: ingrese un número positivo.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(2);
    int opcion = -1;
    while (opcion != 0) {
        std::cout << "\n===== CÁLCULO DE ÁREAS =====\n"
                  << "1. Cuadrado\n"
                  << "2. Rectángulo\n"
                  << "3. Círculo\n"
                  << "0. Salir\n"
                  << "Opción: ";
        if (!(std::cin >> opcion)) {
            if (std::cin.eof()) {
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
        }
        switch (opcion) {
            case 1: {
                double lado = leerMedida("el lado");
                std::cout << "Área del cuadrado: " << areaCuadrado(lado) << '\n';
                break;
            }
            case 2: {
                double base = leerMedida("la base");
                double altura = leerMedida("la altura");
                std::cout << "Área del rectángulo: " << areaRectangulo(base, altura) << '\n';
                break;
            }
            case 3: {
                double radio = leerMedida("el radio");
                std::cout << "Área del círculo: " << areaCirculo(radio) << '\n';
                break;
            }
            case 0:
                std::cout << "Programa finalizado.\n";
                break;
            default:
                std::cout << "Opción no válida. Elija un número del 0 al 3.\n";
        }
    }
    return 0;
}
