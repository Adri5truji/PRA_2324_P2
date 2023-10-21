#include <iostream>
#include <vector>

int g(int i, int C, const std::vector<int>& p, const std::vector<int>& b, std::vector<std::vector<int>>& matriz){
	if( i == 0 || C == 0)
		return 0;

	if(matriz[i][C] != -1)
		return matriz[i][C];

	if(p[i - 1] > C)
		return g(i - 1, C, p, b, matriz);
	
	else
		return std::max(g(i - 1, C, p, b, matriz), g(i - 1, C - p[i - 1], p, b, matriz) + b[i - 1]);

	return matriz[i][C];
}

int funcion(int M, int tam, const std::vector<int>& p, const std::vector<int>& b){
	std::vector<std::vector<int>> matriz(tam + 1, std::vector<int>(M + 1, - 1));

	for(int i = 0; i < tam + 1; i++){
		for(int j = 0; j < M + 1; j++){
			if( i == 0 || j == 0)
				matriz[i][j] = 0;
	}
	}

	int beneficio = g(tam, M, p, b, matriz);
			
	return beneficio;
}


int main(){
	std::vector<int> p{1, 3, 2, 4};
	std::vector<int> b{10, 20, 15, 20};
	int tam = 4;
	int M = 5;

	int beneficio = funcion(M, tam, p, b);
	
	std::cout << "El beneficio maximo es: " << beneficio << std::endl;
}
		
