// https://omegaup.com/arena/problem/omi-2019-areas-metropolitanas/
// Solucion parcial de 72 puntos con busqueda binaria.
// No funciona para la subtarea 6, ya que en ese caso la relacion de crecimiento no es lineal.
#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;
typedef vector<vector<i64>> Matriz;

struct Migracion {
    int x;
    int y;
    i64 cantidad;
    int tiempo;
};

bool operator<(const Migracion& a, const Migracion& b) {
    return a.tiempo < b.tiempo;
}

// Calcular las sumas acumuladas en la regiones de la matriz,
// de tal forma que la posicion i, j representa la suma de todas
// las celdas comprendidas en el rango de 0,0 hasta i, j.
void calcularSumas(Matriz& matriz) {
    int filas = matriz.size() - 1;
    int columnas = matriz[0].size() - 1;
    // Acumular las sumas de las regiones internas
    for (int i = 1; i <= filas; ++i) {
        for (int j = 1; j <= columnas; ++j) {
            matriz[i][j] += matriz[i - 1][j] + matriz[i][j - 1] - matriz[i - 1][j - 1];
        }
    }
    // NOTA: Dado que los indices comienzan en 1, se simplifica mucho el codigo. Si no fuera asi
    // seria necesario calcular primero las sumas de la primera fila y luego la primera columna.
    // De esa forma, se evitaria lidiar con indices fuera del rango
}

// Obtener la suma de la region comprendida entre el rango
// de la esquine superior izquierda (x1, y1) hasta la esquina
// inferior derecha (x2, y2).
// Utiliza la matriz de precalculos.
i64 obtenerSumaDeRegion(int x1, int y1, int x2, int y2, const Matriz& matriz) {
    return matriz[x2][y2] - matriz[x1 - 1][y2]  - matriz[x2][y1 - 1] + matriz[x1 - 1][y1 - 1];
}

bool existeAreaSuperiorALimite(int tiempo, i64 limite, int tamRegion, Matriz ciudad, const vector<Migracion>& migraciones) {
    // Simular todas las migraciones hasta el tiempo indicado.
    for (auto& migracion : migraciones) {
        if (migracion.tiempo > tiempo) {
            break;
        }
        ciudad[migracion.x][migracion.y] += migracion.cantidad;
    }

    // Precalcular la suma de todas las regiones en la ciudad.
    calcularSumas(ciudad);

    // Verificar si existe alguna region del tamaño especificado con poblacion superior al limite.
    for (int i = 1; i <= ciudad.size() - tamRegion; ++i) {
        for (int j = 1; j <= ciudad[i].size() - tamRegion; ++j) {
            i64 sumaRegion = obtenerSumaDeRegion(i, j, i + tamRegion - 1, j + tamRegion - 1, ciudad);
            if (sumaRegion > limite) {
                return true;
            }
        }
    }
    return false;
}

int buscarTiempoParaSuperarLimite(i64 limite, int tamRegion, const Matriz& ciudad, const vector<Migracion>& migraciones) {
    int numMigraciones = migraciones.size();
    int inicio = 0;
    int fin = numMigraciones > 0 ? migraciones[numMigraciones - 1].tiempo : 0;
    while (inicio < fin) {
        int mitad = inicio + (fin - inicio) / 2;
        if (existeAreaSuperiorALimite(mitad, limite, tamRegion, ciudad, migraciones)) {
            fin = mitad;
        }
        else {
            inicio = mitad + 1;
        }
    }

    // Verificar si el valor encontrado corresponde a un area superior, de lo contrario
    // no existe ninguna.
    if (existeAreaSuperiorALimite(inicio, limite, tamRegion, ciudad, migraciones)) {
        return inicio;
    }
    return -1;
}

int main() {
    int n, m;
    int k;
    i64 limite;
    cin >> n >> m >> k >> limite;

    // Agregar 1 espacio adicional porque los indices empiezan en 1.
    // Inicializar en 0 es muy importante para los calculos mas adelante.
    Matriz ciudad(n + 1, vector<i64>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> ciudad[i][j];
        }
    }

    // Leer y ordenar las migraciones con base en el tiempo que suceden de forma ascendente.
    int cantidadMigraciones;
    cin >> cantidadMigraciones;
    vector<Migracion> migraciones(cantidadMigraciones);
    for (auto& migracion : migraciones) {
        cin >> migracion.x >> migracion.y >> migracion.cantidad >> migracion.tiempo;
    }
    sort(migraciones.begin(), migraciones.end());

    cout << buscarTiempoParaSuperarLimite(limite, k, ciudad, migraciones);


    return 0;
}