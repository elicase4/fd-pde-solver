#pragma once
#include "mesh/mesh.hpp"

namespace pde {
	namespace diffop {
		
		template<typename Derived>
		class DiffOp {
			void apply(const double* u, double* Au) const{
				static_cast<const Derived*>(this)->apply(u, Au);
			}

			int stencilRadius() const{
				return static_cast<const Derived*>(this)->stencilRadius();
			}
		};

	}
}
