#include "pde/mesh/mesh.hpp"

template <>
inline std::size_t pde::mesh::Mesh<2>::idx(int i, int j) const {
	return (std::size_t(i*N[1]) + std::size_t(j));
}

template <>
inline std::size_t pde::mesh::Mesh<3>::idx(int i, int j, int k) const {
	return (std::size_t(i*N[1]) + std::size_t(j) + std::size_t(k*N[0]*N[1]));
}

template <>
inline bool pde::mesh::Mesh<2>::in_bounds(int i, int j) const {
	return ((i >= 0 && i < N[0]) && (j >= 0 && j < N[1]));
}

template <>
inline bool pde::mesh::Mesh<3>::in_bounds(int i, int j, int k) const {
	return ((i >= 0 && i < N[0]) && (j >= 0 && j < N[1]) && (k >= 0 && k < N[2]));
}

template <>
inline std::array<double,2> pde::mesh::Mesh<2>::coord(int i, int j) const {
	std::array<double,2> out {};
	out[0] = xmin[0] + (i + 1)*h[0];
	out[1] = xmin[1] + (j + 1)*h[1];
	return out;
}

template <>
inline std::array<double,3> pde::mesh::Mesh<3>::coord(int i, int j, int k) const {
	std::array<double,3> out {};
	out[0] = xmin[0] + (i + 1)*h[0];
	out[1] = xmin[1] + (j + 1)*h[1];
	out[2] = xmin[2] + (k + 1)*h[2];
	return out;
}

template <>
std::size_t pde::mesh::Mesh<2>::size() const {
	return std::size_t(N[0] * N[1]);
}

template <>
std::size_t pde::mesh::Mesh<3>::size() const {
	return std::size_t(N[0] * N[1] * N[2]);
}

template class pde::mesh::Mesh<2>;
template class pde::mesh::Mesh<3>;
