#include "DyV.h"
#include <vector>

int main(){
	std::vector<int> a{1, 2, 6, 9};
	std::vector<double> b{2.6, 3.6, 6.4, 8.6};
	std::vector<int> c{7, 5, 2};

	try{
	std::cout << "Busqueda Binaria (int) = " << BusquedaBinaria(6, a, 0, 3) << std::endl;
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try{	
       	std::cout << "Busqueda Binaria (float) = " << BusquedaBinaria(4.6, b, 0, 3) << std::endl;
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try{	
	std::cout << "Busqueda Binaria_INV (int) = " << BusquedaBinaria_INV(7, c, 0, 2) << std::endl;   
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
}
