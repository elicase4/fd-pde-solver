#pragma once
#include <vector>

namespace pde {

	class Grid2D {
		
		inline int idx(int i, int j) const {
			return i*N + j;
		}

		private:
			int N
	};

}
