#pragma once

#include <iostream>

#include "Eigen/Dense"

Eigen::VectorXd gradiente_coniugato(
	const Eigen::MatrixXd& A,  
	const Eigen::VectorXd& b, 
	const Eigen::VectorXd& x0,
	double tol,
	int max_iter)
	
{	
	// inizializzo la soluzione x0
	Eigen::VectorXd x = x0;
	
	// inizializzo il residuo res (res0 = b - A * x0)
	Eigen::VectorXd res = b - A * x;
	
	// inizializzo la direzione di discesa p (p0 = res0)
	Eigen::VectorXd p = res;

	int k = 0;
	
	// condizione di arresto basata sul numero massimo di iterazioni e sulla tolleranza
	while (k < max_iter && res.norm() > tol) {
		
		// calcolo Ap una sola volta in modo da usarlo successivamente
		Eigen::VectorXd Ap = A * p;
	
		// alpha_k = ((p.transpose() * res) / (p.transpose() * A * p)).value() ==> con Eigen si può utilizzare .dot()) per fare il prodotto scalare
		const double alpha_k = p.dot(res) / (p.dot(Ap));
	
		// aggiorno la soluzione x (x_k+1 = x_k + alpha_k * p_k)
		x = x + alpha_k * p;
	
		// aggiorno il residuo res (r_k+1 = b - A * x_k+1)
		res = b - A * x;
	
		// beta = (p.transpose() * A * res) / (p.transpose() * Ap);
		double beta = p.dot(A * res) / (p.dot(Ap));
	
		// aggiorno la direzione di discesa p (p_k+1 = r_k+1 - beta_k * p_k)
		p = res - beta * p;
	
		k++;
	}
	std::cout << "L'algoritmo è arrivato a convergenza in " << k << " iterzaioni" << std::endl;
	
	return x;
}