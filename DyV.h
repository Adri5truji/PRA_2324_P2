#include <iostream>
#include <vector>
#include <algorithm>

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

int PartitionIni(std::vector<T>& V, int ini, int fin){
        T x = V[ini];
        int i = fin;
        for(int j = fin; j > ini; j--){
              if(V[j] > x){
		    std::swap(V[i], V[j]);
		    i--;
	}
	}
	std::swap(V[i], V[ini]);      
	return i;
}

template<typename T>

int PartitionFin(std::vector<T>& V, int ini, int fin){
        T x = V[fin];
	int i = ini;
        for(int j = ini; j < fin; j++){
              if(V[j] <= x){
		    std::swap(V[i], V[j]);
		    i++;
        }
        }
	std::swap(V[i], V[fin]);
        return i;
}

template<typename T>

int PartitionMedio(std::vector<T>& V, int ini, int fin){
	int medio = (fin + 1 + ini)/2;
	T x = V[medio];
        int i = ini;
        for(int j = ini; j <= fin; j++){
              if(V[j] < x){
		    std::swap(V[i], V[j]);
		    i++;
        }
        }
	std::swap(V[i], V[medio]);

        return i;
}


template<typename T>

void QuickSortIni(std::vector<T>& V, int ini, int fin){
        if(ini < fin){
                 int pivot = PartitionIni(V, ini, fin);
		 QuickSortIni(V, ini, pivot - 1);
                 QuickSortIni(V, pivot + 1, fin);
	}
}

template<typename T>

void QuickSortFin(std::vector<T>& V, int ini, int fin){
        if(ini < fin){
                 int pivot = PartitionFin(V, ini, fin);
                 QuickSortFin(V, ini, pivot - 1);
                 QuickSortFin(V, pivot + 1, fin);
        }
}

template<typename T>

void QuickSortMedio(std::vector<T>& V, int ini, int fin){
        if(ini < fin){
                 int pivot = PartitionMedio(V, ini, fin);
                 QuickSortMedio(V, ini, pivot - 1);
                 QuickSortMedio(V, pivot + 1, fin);
        }
}


