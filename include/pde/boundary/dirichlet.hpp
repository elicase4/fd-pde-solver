#pragma once

#include <array>
#include <functional>
#include <stdexcept>

#include "pde/mesh/mesh.hpp"

namespace pde {
	namespace boundary {
		
		template<int DIM>
		class Dirichlet {
			public:
				Dirichlet(const pde::mesh::Mesh<DIM>& mesh_, double* buffer_base_) : mesh(mesh_), buffer_base(buffer_base_) {};

				void set(pde::mesh::BoundaryFace face, std::function<double(const std::array<double, DIM>&)> f){
					bc_funcs[(int) face] = f;
				}

				void eval(double* u) const{
					std::ptrdiff_t flat = u - buffer_base;
					std::array<int,DIM> idx = mesh.flat2idx(static_cast<std::size_t>(flat));
					pde::mesh::BoundaryFace face = mesh.get_boundary_face(idx[0], idx[1], idx[2]);
					if(face == pde::mesh::BoundaryFace::None){
						throw std::runtime_error("Boundary function evaluation used on interior node.");
					}
					auto coord = mesh.idx2coord(idx[0], idx[1], idx[2]);
					u[0] = bc_funcs[(int) face](coord);
				}

			private:
				const pde::mesh::Mesh<DIM>& mesh;
				double* buffer_base = nullptr;
				std::array<std::function<double(const std::array<double,DIM>&)>, 2*DIM> bc_funcs{};
		};
	}
}
