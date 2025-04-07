#ifndef SFR_HPP
#define SFR_HPP

#include "matrix.hpp"

namespace Utility {

    template <typename T, std::size_t nX, std::size_t nY = 1UL, std::size_t nU = nY>
    struct SFR {
    public:
        template <std::size_t N, std::size_t M>
        using Mtx = Matrix<T, N, M>;

        Mtx<nU, 1UL> get_control(this SFR& self, Mtx<nY, 1UL> const& y_ref, Mtx<nX, 1UL> const& x)
        {
            try {
                auto const u = y_ref - self.K * x;
                return u;
            } catch (std::runtime_error const& error) {
                throw error;
            }
        }

        Mtx<nU, 1UL> operator()(this SFR& self, Mtx<nY, 1UL> const& y_ref, Mtx<nX, 1UL> const& x)
        {
            try {
                return self.get_control(y_ref, x);
            } catch (std::runtime_error const& error) {
                throw error;
            }
        }

        /* state */
        Mtx<nX, 1UL> x = Mtx<nX, 1UL>{};

        /* state model */
        Mtx<nX, nX> A = Mtx<nX, nX>{};
        Mtx<nX, nU> B = Mtx<nX, nU>{};
        Mtx<nY, nX> C = Mtx<nY, nX>{};
        Mtx<1UL, nU> D = Mtx<1UL, nU>{};

        /* state gain */
        Mtx<nY, nX> K = Mtx<nY, nX>{};
    };

}; // namespace Utility

#endif // SFR_HPP