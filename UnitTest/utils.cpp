#include "utils.h"

bool isPowerOfTwo(int val)
{
	double temp = log2(val);
	return temp == static_cast<int> (temp) ? true : false;
}


int nextPowerOfTwo(int val)
{
	double temp = log2(val);
	return pow(2,static_cast<int> (temp) + 1);
}
uint64_t w = 0, s = 0xb5ad4eceda1ce2a9; // qualifying seed
uint32_t getRandSeed(uint64_t _seed)
{
	static uint64_t seed; 
	if (_seed != 1) {
		seed = _seed;
	}
	else {
		seed = pow(seed, 2);
		/*std::string seedDigits = std::to_string(seed);
		if (seedDigits.size() % 2 == 0) {
			seedDigits = seedDigits.substr(seedDigits.size() / 2 - 3, seedDigits.size() / 2 + 2);
		}
		else {
			seedDigits = seedDigits.substr(seedDigits.size() / 2 - 2, seedDigits.size() / 2 + 2);
		}
		seed = std::stoi(seedDigits);*/
		w += s;
		seed += w;

	}
	return seed = (seed >>32) | (seed <<32);
}

void seedRand(int seedValue)
{
	getRandSeed(seedValue);
}

