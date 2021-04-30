# Cadenas y caracteres en C++

## descripción 

Los caracteres son letras o símbolos que se ocupan en nuestro lenguaje habitualmente, hace referencia a las letras de nuestro alfabeto, signos de puntuación, números, signos matemáticos, etc. 

Las cadenas son el conjunto de caracteres que se utilizan para representar palabras, párrafos o textos.

Podemos ver a las cadenas como vectores del tipo char. Solo que C++ tiene una clase especial llamada “string” para manipular este tipo de información.

## Problemas vistos en clase clase
* [El maestro Toño (Codigo)](elmaestrotono.cpp) | [OmegaUp](https://omegaup.com/arena/problem/El-maestro-Tono-Palabras/) 
* [Sopa de consonantes, vocales y numeros (Codigo)](sopa.cpp) | [OmegaUp](https://omegaup.com/arena/problem/Sopa-consonantes-vocales-y-num/#problems) 

## Código de la teoría de clase
```c++

#include <iostream>
#include <string>
#include <ctype.h>

// O la libreria stdc que incluye en automatico todas las librerias.
#include <bits/stdc++.h>

using namespace std;

int main() {

  // declaración e inicialización de un string
  string cadena;
  string nombre = "JOSE DE JESUS ";

  // podemos asignar y comparar igual que cualquier otra variable:
  cadena = nombre;

  if (cadena == nombre) {
    cout<<"Son la misma"<<endl;
  }

  // si los imprimimos ambos nos van a dar el mismo resultado
  cout<<cadena<<endl;
  cout<<nombre<<endl;

  // podemos acceder a los caractares del iesimo indice mediante los corchetes como si fuera un vector.
  cout<<cadena[5]<<endl;

  // De igual forma podemos contar cuantos caracteres hay en la cadena, de que tamaño es:
  cout<<cadena.size()<<endl;

  // podemos iterar los caracteres de la cadena como si fuera un vector:
  for (int i=0; i<cadena.size(); i++) {
    cout<<cadena[i]<<endl;
  }

  // Podemos tambier si la cadena esta vacia:
  string cadenaVacia;
  cout<<"ESTA VACIA?: "<<cadenaVacia.empty()<<endl; // nos devuelve un true o false.
  cout<<cadenaVacia.size()<<endl; // nos da cero

  // APPEND: Copia el contenido de apellido en la variable nombre, despues de todos los caracteres de nombre.
  string apellido = "GARFIAS LOPEZ";
  nombre.append(apellido); 
  cout<<"NOMBRE COMPLETO: " << nombre<<endl;

  // concatenacion (+): Podemos usar el simbolo + para concatenar cadenas como si fueran numeros que sumamos, lo que hace es juntar las cadenas.
  string nombre_completo = "HOLA: " + nombre + apellido + "BIENVENIDO" ;
  cout<<"concatenacion: "<<nombre_completo<<endl;

  // ERASE  :  Borrar
  // nombre.begin() -> Iterador de inicio ->  como si fuera el indice 0
  // nombre.end() -> Iterador de fin -> como si fuera el indice N-1  
  // funciona con un rango de inicio y fin, donde tenemos que usar los iteradores y +- las posiciones que queramos recorrer la cadena.
  nombre.erase(nombre.begin() + 0, nombre.begin() + (nombre.size()/2));
  // nombre.erase(nombre.begin() + (nombre.size()/2), nombre.end());
  cout<<"ERASE:"<<nombre<<endl;

  // INSERT: Agregar una cadena en una posicion especifica:
  string nombrePersonaje = "NIKOLA  TESLA";
  string matricula = "FA1232322";
  // primer paramatero: la posicion del indice donde va a comenzar a insertar:
  // segundo parametro: el string que se va a insertar.
  nombrePersonaje.insert(7, matricula);
  cout<<nombrePersonaje<<endl;

  // FIND: Preguntar si una subcadena existe dentro de una cadena.
  if (nombrePersonaje.find("TESLA") != string::npos) {
    cout<<"ESTA CONTENIDA EN:"<<nombrePersonaje<<endl;
  } else {
    cout<<"NO ESTA CONTENIDA EN:"<<nombrePersonaje<<endl;
  }

  // Operaciones con caracteres:
  string mayus = "aDJKS4AJDL1KSAJDLKSA0JDLKSJA82KLDJSA2DJLKSA21JDLKAS";
  for (int i=0; i<mayus.size(); i++) {
    if (isdigit(mayus[i])) { // is Digit nos regresa true si es un digito, false en caso contrario
      cout<<"encontre un digito"<<endl;
    }
    if (islower(mayus[i])) { // is lower nos regresa true si es una minuscula, false en caso contrario
      cout<<"encontre una minuscula"<<endl;
    }

    mayus[i] = tolower(mayus[i]);

  }
  cout<<"MINUSCULAS: "<<mayus<<endl;


  // quitar las repeticiones de un caracter en una cadena. 
  string palabra = "aaaaabbbbaaaaabbbaaabbababababa";
  string nuevaPalabra = "";
  for (int i=0; i<palabra.size();i++) {
    if(palabra[i] != 'b') {
      nuevaPalabra += palabra[i];
    }
  }
  cout<<nuevaPalabra<<endl;


  // Conversión de char a int:
  char letra = 'a';
  int letraAscii = (int)letra;

  cout<<"letra: "<<letra<< "  - ASCII: " << letraAscii <<endl;

  // Conversión de int a char:
  for (int i=0; i<=255; i++) {
    cout<<"ascii:"<<i<<"   char: "<<(char)i<<endl;
  }

  // conversión de string a int.
  string numeroString = "1234"; // el numero debe de caber en un INT.
  int numeroDeString = stoi(numeroString);

  // conversion de una cadena binaria a int
  string cadenaBinaria = "111100001100111010";
  int numeroDeBinString = stoi(cadenaBinaria, 0, 2); // numero = 246586

  return 0;
}

```