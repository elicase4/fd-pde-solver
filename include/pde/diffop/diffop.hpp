#pragma once
#include "pde/mesh/mesh.hpp"

namespace pde {
	namespace diffop {
		
		template<typename Derived>
		class DiffOp {
			public:
				void apply(const double* u, double* Au) const{
					static_cast<const Derived*>(this)->apply_inst(u, Au);
				}

				int stencilRadius() const{
					return static_cast<const Derived*>(this)->stencilRadius_inst();
				}
		};

	}
}
