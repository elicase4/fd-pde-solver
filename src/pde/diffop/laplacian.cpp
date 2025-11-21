#include "pde/diffop/laplacian.hpp"

template <>
void pde::diffop::Laplacian<2,1>::applyOperator_inst(const double* u, double* Au) const{
	Au[mesh.idx2flat(0,0)] = (1/(mesh.h[0]*mesh.h[0])) * (u[mesh.idx2flat(1,0)] - 2*u[mesh.idx2flat(0,0)] + u[mesh.idx2flat(-1,0)])
						+ (1/(mesh.h[1]*mesh.h[1])) * (u[mesh.idx2flat(0,1)] - 2*u[mesh.idx2flat(0,0)] + u[mesh.idx2flat(0,-1)]);
}

template <>
void pde::diffop::Laplacian<3,1>::applyOperator_inst(const double* u, double* Au) const{
	Au[mesh.idx2flat(0,0,0)] = (1/(mesh.h[0]*mesh.h[0])) * (u[mesh.idx2flat(1,0,0)] - 2*u[mesh.idx2flat(0,0,0)] + u[mesh.idx2flat(-1,0,0)])
						+ (1/(mesh.h[1]*mesh.h[1])) * (u[mesh.idx2flat(0,1,0)] - 2*u[mesh.idx2flat(0,0,0)] + u[mesh.idx2flat(0,-1,0)])
						+ (1/(mesh.h[2]*mesh.h[2])) * (u[mesh.idx2flat(0,0,1)] - 2*u[mesh.idx2flat(0,0,0)] + u[mesh.idx2flat(0,0,-1)]);
}

template <>
double pde::diffop::Laplacian<2,1>::computeDirichletCoeff_inst(int axis_idx) const{
	return (1 / (mesh.h[axis_idx] * mesh.h[axis_idx]));
}

template <>
double pde::diffop::Laplacian<3,1>::computeDirichletCoeff_inst(int axis_idx) const{
	return (1 / (mesh.h[axis_idx] * mesh.h[axis_idx] * mesh.h[axis_idx]));
}

template class pde::diffop::Laplacian<2,1>;
template class pde::diffop::Laplacian<3,1>;
