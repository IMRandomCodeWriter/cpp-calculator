#include <fstream>
#include <string>
#include <cmath>
#define pi 3.14159265358979323846
int main(){ std::ofstream file("history.txt", std::ios::app); file << std::to_string(cos(99.0)); file << std::endl; file.close(); return 0; }