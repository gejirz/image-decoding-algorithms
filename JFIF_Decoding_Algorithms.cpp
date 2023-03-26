#include <cmath>
#include <array>
#include <pybind11.h>
#include <stl.h>

double IDCT_matrix[8][8];
int raw_matrix[8][8];
static std::array<std::array<unsigned char, 8>, 8> out_matrix;
int i, j, u, v;
double c1, c2, c3;

std::array<std::array<unsigned char, 8>, 8> do_InverseDCT(std::vector<std::vector<int>> raw_matrix_vect){
	for (i = 0; i < 8; ++i){ // initializing the vectors
			for (j = 0; j < 8; ++j){
				raw_matrix[i][j] = raw_matrix_vect[i][j];
				IDCT_matrix[i][j] = 0.0;
		}
	}
	c1 = 0.7071; // approx. pow(2, -0.5)
	c2 = 0.7071;
	for (i = 0; i < 8; ++i){ // IDCT
		for (j = 0; j<8; ++j){
			if (j == 0) c2 = 0.7071;
			else c2 = 1.0;
			for (u = 0; u<8; ++u){
				for (v = 0; v<8; ++v) //3.1416 is approx. pi
					IDCT_matrix[u][v] += 0.25 * c1 * c2 * raw_matrix[i][j] * cos(((2 * u + 1) * i * 3.1416) / 16) * cos(((2 * v + 1) * j * 3.1416) / 16);
			}
		}
		c1 = 1;
	}
	for (i = 0; i < 8; ++i){ // clamping algorithm
		for (j = 0; j < 8; ++j){
			c3 = IDCT_matrix[i][j];
			if (c3 > 127) out_matrix[i][j] = 255;
			else if (c3 < -128) out_matrix[i][j] = 0;
			else{
				c3 += 128;
				if (c3 > int(c3) + 0.5) out_matrix[i][j] = int(c3) + 1;
				else out_matrix[i][j] = int(c3);
			}
		}
	}
	return out_matrix;
}

PYBIND11_MODULE(JFIF_Decoder_Algorithms, m){
	m.def("do_InverseDCT", &do_InverseDCT, "do IDCT Transformation for JFIF image decoding. IT`S AN ALGORITHM, ISN`T CUSTOMIZABLE");
}
