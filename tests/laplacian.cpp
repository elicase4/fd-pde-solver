#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "pde/mesh/mesh.hpp"
#include "pde/diffop/laplacian.hpp"

void check2DCase(int N){
	
	using Mesh2 = pde::mesh::Mesh<2>;

    Mesh2 mesh(
        {N, N},
        {-1.0,-1.0},
        {1.0,1.0}
    );

    const std::size_t n = mesh.size();
    std::vector<double> u(n);
    std::vector<double> f(n);
    std::vector<double> Lu(n);

    // test function u(x,y) = sin(pi*x) sin(pi*y)
    for (int i=0; i<mesh.N[0]; i++){
		for (int j=0; j<mesh.N[1]; j++) {
			auto c = mesh.coord(i,j);
			double x = c[0], y = c[1];
			u[mesh.idx(i,j)] = (-1 / (2 * M_PI * M_PI)) * std::sin(M_PI*x)*std::sin(M_PI*y);
			f[mesh.idx(i,j)] = std::sin(M_PI*x)*std::sin(M_PI*y);
		}
    }

    pde::diffop::Laplacian<1,2> lap(mesh);
    for (int i=1; i<mesh.N[0]-1; i++){
		for (int j=1; j<mesh.N[1]-1; j++) {
			lap.apply(&u[mesh.idx(i,j)], &Lu[mesh.idx(i,j)]);
		}
    }

    std::cout << "grid output:\n";
    std::cout << std::setw(8) << "i"
              << std::setw(8) << "j"
              << std::setw(20) << "Numerical Laplacian"
              << std::setw(20) << "Exact Laplacian"
              << "\n";
    for (int i=1; i<mesh.N[0]-1; i+=8) {
		for (int j=1; j<mesh.N[0]-1; j+=8) {
			std::size_t id = mesh.idx(i,j);

			// Print values aligned
			std::cout << std::setw(8) << i
					  << std::setw(8) << j
					  << std::setw(20) << std::fixed << std::setprecision(6) << Lu[id]
					  << std::setw(20) << std::fixed << std::setprecision(6) << f[id]
					  << "\n";
		}
    }
}

int main() {
	const int N = 100;
	check2DCase(N);
	
	return 0;
}    
