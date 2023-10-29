#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int Cambio(const std::vector<int>& V, int M, int tam, int matriz[4][10], std::vector<int>& vector){
	int infinito = std::numeric_limits<int>::max();

	for(int j = 0; j < M + 1; j++)
                matriz[0][j] = infinito;

        for(int i = 0; i < tam + 1; i++)
                matriz[i][0] = 0;

	for(int i = 1; i < tam + 1; i++){
		for(int j = 1; j < M + 1; j++){
			if(V[i - 1] > j)
				matriz[i][j] = matriz[i - 1][j];
			if(V[i - 1] <= j)
				matriz[i][j] = std::min(matriz[i - 1][j], 1 + matriz[i][j - V[i - 1]]);
		}
	}
        int i = tam;
	int j = M;
	
	while(j > 0){
	if(i > 1 && matriz[i][j] == matriz[i - 1][j])
		i--;
	else{
		vector[i - 1]++;
		j -= V[i - 1];
	}
	}
	return matriz[tam][M];
}

int main(){
	int M = 9;
	int tam = 3;
	int matriz[4][10];
	std::vector<int> V{1, 4, 6};
	std::vector<int> vector{0, 0, 0};

	int resultado = Cambio(V, M, tam, matriz, vector);

	for(int i = 1; i < tam + 1; i++){
                for(int j = 1; j < M + 1; j++){
                        std::cout << matriz[i][j] << " ";
                }
                std::cout << std::endl;
        }
	std::cout << "Resultado: " << resultado << std::endl;

	for(int i = 0; i < 3; i++)
		std::cout << vector[i] << " monedas de " << V[i] << std::endl;
}



