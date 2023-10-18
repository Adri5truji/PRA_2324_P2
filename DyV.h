#include <iostream>
#include <vector>

template<typename T>

int BusquedaBinaria(T X, std::vector<T>& V, int ini, int fin){
        if(ini > fin)
               	throw std::runtime_error("No se encuentra en el array");	

        int medio = (ini + fin) / 2; 
        if (V[medio] == X)
                 return medio;
	else if(V[medio] > X) 
                 return BusquedaBinaria(X, V, ini, medio - 1);
	else
                 return BusquedaBinaria(X, V, medio + 1, fin);
}

template<typename T>

int BusquedaBinaria_INV(T X, std::vector<T>& V, int ini, int fin){
        if(ini > fin)
                throw std::runtime_error("No se encuentra en el array");	

        int medio = (ini + fin) / 2;
        if (V[medio] == X)
                 return medio;
        else if(V[medio] < X)
                 return BusquedaBinaria_INV(X, V, ini, medio - 1);
        else
                 return BusquedaBinaria_INV(X, V, medio + 1, fin);
}

