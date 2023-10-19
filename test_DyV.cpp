#include "DyV.h"
#include <vector>
#include <chrono>

int main(){
	std::vector<int> a{2, 6, 1, 9, 3, 5, 8};
	std::vector<double> b{5.6, 3.6, 6.2, 8.6, 3.2, 6.4};
	std::vector<int> c{7, 5, 2, 4, 3};

	try{
	std::cout << "Busqueda Binaria (int) = " << BusquedaBinaria(9, a, 0, 6) << std::endl;
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try{	
       	std::cout << "Busqueda Binaria (float) = " << BusquedaBinaria(4.6, b, 0, 5) << std::endl;
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try{	
	std::cout << "Busqueda Binaria_INV (int) = " << BusquedaBinaria_INV(7, c, 0, 4) << std::endl;   
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}

	auto start = std::chrono::system_clock::now();
	QuickSort(a, 0, 6);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;

	std::cout << "QuickSort (int) => [";
	for(int i = 0; i < 7; i++){
		std::cout << a[i];
		if(i < 6)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Time (int): " << duration.count() << "s" << std::endl;

	auto inicio = std::chrono::system_clock::now();
        QuickSort(b, 0, 5);
        auto fin = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> duracion = fin - inicio;

	std::cout << "QuickSort (float) => [";
	for(int i = 0; i < 6; i++){
		std::cout <<  b[i];
       		if(i < 5)
		       std::cout << ", ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Time (float): " << duracion.count() << "s" << std::endl;
}
