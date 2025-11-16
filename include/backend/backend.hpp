#pragma once

#include "pde/diffop/diffop.hpp"

namespace backend{
	
	template<int stencil_rad, int DIM>
	class Backend {
		
		public:
			virtual ~Backend() = default;

			virtual void applyOperator(const pde::diffop::DiffOp<stencil_rad, DIM>& op, double* u, double* Au) = 0;
			
			virtual void updateSolution(const pde::diffop::DiffOp<stencil_rad, DIM>& op, double* u, const double* rhs) = 0;
			
			virtual void computeResidual(const pde::diffop::DiffOp<stencil_rad, DIM>& op, const double* u, const double* rhs, double* r) = 0;
	};

}
