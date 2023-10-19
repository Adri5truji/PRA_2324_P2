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

template<typename T>

int Partition(std::vector<T>& V, int ini, int fin){
        T x = V[fin];
        int i = ini;
        for(int j = ini; j < fin; j++){
              if(V[j] <= x){
                    T aux = V[i];
                    V[i] = V[j];
                    V[j] = aux;
		    i++;
              }
	      else{
        	T aux = V[i];
		V[i] = V[fin];
		V[fin] = aux;
		}
	}
	return i;
}

template<typename T>

void QuickSort(std::vector<T>& V, int ini, int fin){
        if(ini < fin){
                 int pivot = Partition(V, ini, fin);
		 QuickSort(V, ini, pivot - 1);
                 QuickSort(V, pivot + 1, fin);
	}
}
