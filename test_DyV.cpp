#include "DyV.h"
#include <vector>

int main(){
	std::vector<int> vec{4, 2, 6, 9};
	std::vector<double> vecc{2.6, 8.6, 3.4, 5.6};
	std::vector<int> vecs{4, 6, 2};

	std::cout << "Busqueda Binaria (int) = " << BusquedaBinaria(6, vec, 0, 3) << std::endl;		
       	std::cout << "Busqueda Binaria (float) = " << BusquedaBinaria(4.6, vecc, 0, 3) << std::endl;	
	std::cout << "Busqueda Binaria (short) = " << BusquedaBinaria(2, vecs, 0, 2) << std::endl;   
}
