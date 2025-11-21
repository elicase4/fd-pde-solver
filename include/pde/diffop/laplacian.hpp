#pragma once

#include "pde/diffop/diffop.hpp"

namespace pde{
	namespace diffop{

		template<int DIM, int stencil_rad>
		class Laplacian : public DiffOp<Laplacian<DIM, stencil_rad>>{
			public:
				Laplacian(const mesh::Mesh<DIM>& mesh_): mesh(mesh_) {};
				
				void applyOperator_inst(const double* u, double* Au) const;
				
				int stencilRadius_inst() const{
					return stencil_rad;
				}

				double computeDirichletCoeff_inst(int axis_idx) const;

			private:
				const mesh::Mesh<DIM>& mesh;
		};

	}
}
