// NAMA		: FARHAN ARDIA NASHWAN
// NRP		: 5025221308
// Jurusan	: TEKNIK INFORMATIKA

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

float mencari_V0(float Vt, float speed_loss)
{
	float V0 = Vt - speed_loss;
  	return V0;
}

float speed_dgn_loss(float x)
{
	float loss;
	if (x >= 2 && x <= 11) {
		loss = 1;
	} else if (x >= 14 && x <= 23) {
		loss = 3;
	} else if (x >= 26 && x <= 30) {
		loss = 5;
	}
	else {
		loss = 0;
	}
    return loss;
}

int main() {
	float input, loss, V0;
	int jarak;

  	std::cin >> input;
	loss = speed_dgn_loss(input);
	V0 = mencari_V0(input, loss);

	jarak = V0*V0 * sin(2*SUDUT*3.14/180) / GRAVITASI;
	double tangensial = sqrt(jarak*GRAVITASI / sin(2*SUDUT*3.14/180)) + loss;

  	std::cout << jarak << " " << tangensial << std::endl;
    return 0;
}