#pragma once

#include "pde/grid.hpp"

namespace Backend{

	class Base {
		public:
			virtual ~Base() = default;

			virtual void apply_operator(const pde::Grid& grid, double* u, const double* rhs) = 0;
			
			virtual void update_solution(const pde::Grid& grid, double* u, const double* rhs) = 0;
			
			virtual void compute_residual(const pde::Grid& grid, double* u, const double* rhs) = 0;
	};

}
