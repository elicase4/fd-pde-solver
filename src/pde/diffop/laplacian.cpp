#include "pde/diffop/laplacian.hpp"

template <>
void pde::diffop::Laplacian<1,2>::apply(const double* u, double* Au) const{
	Au[pde::mesh::Mesh<2>::idx(0,0)] = (1/(h[0]*h[0])) * (u[pde::mesh::Mesh<2>::idx(1,0)] - 2*u[pde::mesh::Mesh<2>::idx(0,0)] + u[pde::mesh::Mesh<2>::idx(-1,0)])
							+ (1/(h[1]*h[1])) * (u[pde::mesh::Mesh<2>::idx(0,1)] - 2*u[pde::mesh::Mesh<2>::idx(0,0)] + u[pde::mesh::Mesh<2>::idx(0,-1)]);
}

template <>
void pde::diffop::Laplacian<1,3>::apply(const double* u, double* Au) const{
	Au[pde::mesh::Mesh<3>::idx(0,0,0)] = (1/(h[0]*h[0])) * (u[pde::mesh::Mesh<3>::idx(1,0,0)] - 2*u[pde::mesh::Mesh<3>::idx(0,0,0)] + u[pde::mesh::Mesh<3>::idx(-1,0,0)])
							+ (1/(h[1]*h[1])) * (u[pde::mesh::Mesh<3>::idx(0,1,0)] - 2*u[pde::mesh::Mesh<3>::idx(0,0,0)] + u[pde::mesh::Mesh<3>::idx(0,-1,0)])
							+ (1/(h[2]*h[2])) * (u[pde::mesh::Mesh<3>::idx(0,0,1)] - 2*u[pde::mesh::Mesh<3>::idx(0,0,0)] + u[pde::mesh::Mesh<3>::idx(0,0,-1)]);
}

template class pde::diffop::Laplacian<1,2>;
template class pde::diffop::Laplacian<1,3>;
