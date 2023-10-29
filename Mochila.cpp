#include <iostream>
#include <vector>
#include <algorithm>

int funcion(int M, int tam, const std::vector<int>& p, const std::vector<int>& b, int matriz[5][6], int vector[4]){
	for(int i = 0; i < tam + 1; i++){
                for(int j = 0; j < M + 1; j++){
                        if(i == 0 || j == 0)
                                matriz[i][j] = 0;
                }
        }

	int beneficio = 0;

	for(int i = 1; i < tam + 1; i++){
		for(int j = 1; j < M + 1; j++){
			if(p[i - 1] > j)
 				matriz[i][j] = matriz[i - 1][j];
			if(p[i - 1] <= j)
				matriz[i][j] = std::max(matriz[i - 1][j], b[i - 1] + matriz[i - 1][j - p[i - 1]]);
			if(matriz[i][j] > beneficio)
				beneficio = matriz[i][j];
		}
	}
	int i = tam;
	int j = M;

	while(j > 0){
		if(i > 1 && matriz[i][j] == matriz[i - 1][j])
			i--;
		else{
			vector[i - 1]++;
			j -= p[i - 1];
		}
	}

	return beneficio;
}

int main(){
	std::vector<int> p{1, 2, 3, 4};
	std::vector<int> b{10, 15, 20, 20};
	int tam = 4;
	int M = 5;
	int matriz[5][6];
	int vector[4];

	int beneficio = funcion(M, tam, p, b, matriz, vector);
	
	for(int i = 0; i < tam + 1; i++){
		for(int j = 0; j < M + 1; j++){
			std::cout << matriz[i][j] << " ";
			if(matriz[i][j] == 0)
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "El beneficio maximo es: " << beneficio << std::endl;
	for(int i = 0; i < 4; i++)
		std::cout << "Elemento " << i + 1 << "(peso " << p[i] << "): " << vector[i] << " " << std::endl;
}
		
