#include <iostream>
#include <vector>

template<typename T>

int BusquedaBinaria(T X, std::vector<T>& V, int ini, int fin){
        if(ini > fin){ 
               	std::cout << "No se encuentra en el array" << std::endl;
		return -1;
	}		
	else{
        int medio = (ini + fin) / 2; 
        if (V[medio] == X)
                 return medio;
	else if(V[medio] > X) 
                 return BusquedaBinaria(X, V, ini, medio - 1);
	else
                 return BusquedaBinaria(X, V, medio + 1, fin);
}
}
