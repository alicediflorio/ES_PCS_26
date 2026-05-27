#include <iostream>

#include <Eigen/Dense>

#include "gradiente_coniugato.hpp"

int main()
{
	Eigen::MatrixXd A(3,3);
	A << 4, 1, 1,
		 1, 3, 0,
		 1, 0, 2;
	
	
	Eigen::VectorXd b(3);
	b << 1, 2, 3;
	
	
	Eigen::VectorXd x0(3);
	x0 << 0, 0, 0;
	
	// calcolo la soluzione tramite l'algoritmo implementato
	Eigen::VectorXd x_gc = gradiente_coniugato(A, b, x0, 1e-10, 1000);
	
	// calcolo la soluzione esatta ==> ldlt è utilizzato per risolvere sistemi con matrici simmetriche definite positive
	Eigen::VectorXd x_esatta = A.ldlt().solve(b);
	
	std::cout << "Il sistema risolto tramite il gradiente coniugato ha soluzione"<< "\n" << x_gc << "\n";
	std::cout << "La soluzione esatta:\n" << x_esatta << std::endl;
	
	return 0;
}