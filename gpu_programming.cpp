#include <iostream>
#include <math.h>

void add(int N, float* x, float* y){
	for (unsigned int i = 0 ; i < N ; i++){
		y[i] = x[i] + y[i];
	}
}

int main(void) {
	int N = 1 << 20;
	std::cout << "array size: " << N << std::endl;
	float* x = new float[N];
	float* y = new float[N];

	for (unsigned int i = 0; i < N ; i++){
		x[i] = 1.0f;
		y[i] = 2.0f;
	}
	add (N, x, y);
	std::cout << "Done: " << y[100] << std::endl;
	delete [] x; 
	delete [] y;

	return 0;
}