#pragma once
#include "pde/mesh/mesh.hpp"

namespace pde {
	namespace diffop {
		
		template<typename Derived>
		class DiffOp {
			public:
				void applyOperator(const double* u, double* Au) const{
					static_cast<const Derived*>(this)->applyOperator_inst(u, Au);
				}

				int stencilRadius() const{
					return static_cast<const Derived*>(this)->stencilRadius_inst();
				}

				double computeDirichletCoeff(int axis_idx) const{
					return static_cast<const Derived*>(this)->computeDirichletCoeff_inst(axis_idx);
				}
		};

	}
}
