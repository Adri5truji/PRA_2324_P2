#include "DyV.h"
#include <vector>
#include <chrono>
#include <iostream>

int main(){
	int tam = 7;
	int ini = 0;
	std::vector<int> a{1, 2, 3, 5, 7, 8, 9};
	std::vector<double> b{1.6, 3.6, 4.2, 4.6, 5.2, 6.4, 8.5};
	std::vector<char> c{'c', 'd', 'f', 'h', 'j', 'm', 'z'}; 
	std::vector<int> d{1, 14, 20, 35, 43, 51, 60};
	std::vector<int> p{90, 45, 23, 6, 8, 21, 68};
	std::vector<int> p1{90, 45, 23, 6, 8, 21, 68};
	std::vector<int> p2{90, 45, 23, 6, 8, 21, 68};

	try{
	std::cout << "Busqueda Binaria (int) = " << BusquedaBinaria(9, a, ini, tam - 1) << std::endl;
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}

	try{	
       	std::cout << "Busqueda Binaria (float) = " << BusquedaBinaria(4.5, b, ini, tam - 1) << std::endl;
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}

	try{
	std::cout << "Busqueda Binaria (char) = " << BusquedaBinaria('d', c, ini, tam - 1) << std::endl;
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}

	try{	
	std::cout << "Busqueda Binaria_INV (int) = " << BusquedaBinaria_INV(14, d, ini, tam - 1) << std::endl;   
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}

	auto start = std::chrono::system_clock::now();
	QuickSortIni(p, 0, tam - 1);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;

	std::cout << "QuickSort => [";
	for(int i = 0; i < tam; i++){
		std::cout << p[i];
		if(i < tam - 1)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Time (pivot = inicio): " << duration.count() << "s" << std::endl;

	auto inicio = std::chrono::system_clock::now();
        QuickSortFin(p1, 0, tam - 1);
        auto fin = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> duracion = fin - inicio;

	std::cout << "QuickSort => [";
	for(int i = 0; i < tam; i++){
		std::cout <<  p1[i];
       		if(i < tam - 1)
		       std::cout << ", ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Time (pivot = final): " << duracion.count() << "s" << std::endl;
		
	auto s = std::chrono::system_clock::now();
        QuickSortMedio(p2, 0, tam - 1);
        auto f = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> dura = f - s;

        std::cout << "QuickSort => [";
        for(int i = 0; i < tam; i++){
                std::cout <<  p2[i];
                if(i < tam - 1)
                       std::cout << ", ";
        }
        std::cout << "]" << std::endl;
        std::cout << "Time (pivot = medio): " << dura.count() << "s" << std::endl;
}
