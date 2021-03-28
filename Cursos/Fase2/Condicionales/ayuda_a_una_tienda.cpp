// Ayuda a una tienda
// https://omegaup.com/arena/problem/Ayuda-a-una-Tienda/

#include <iostream>

using namespace std;

int main () {

    // lectura
    float compra = 0.0;
    cin>>compra;
    
    float descuento = 0.0;

    if (compra >= 500.0) {
        // si aplica un descuento, tenemos que calcular de cuanto:
        if (compra > 500.0 && compra <= 1000) {
            descuento = compra * 0.05;
        }
        if (compra > 1000.0 && compra <= 7000) {
            descuento = compra * 0.11;
        }
        if (compra > 7000.0 && compra <= 15000) {
            descuento = compra * 0.18;
        }
        if (compra > 15000) {
            descuento = compra * 0.25;
        }

    } else {
        // no hay descuento
        descuento = 0.0;
    }

    // Aplicar el descuento
    float nuevoPrecio = compra - descuento;

    // imprimir
    cout<<nuevoPrecio;

    return 0;
}