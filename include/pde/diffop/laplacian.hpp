#pragma once

#include "diffop.hpp"

namespace pde{
	namespace diffop{

		template<int stencil_rad, int DIM>
		class Laplacian : public DiffOp<Laplacian<stencil_rad, DIM>>{
			public:
				Laplacian(const mesh::Mesh<DIM>& mesh_): DiffOp<Laplacian<stencil_rad, DIM>>(mesh_) {};
				
				int stencilRadius() const{
					return stencil_rad;
				}
			private:
				mesh::Mesh<DIM>& mesh;
		};

	}
}
