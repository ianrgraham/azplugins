// Maintainer: mphoward / Everyone is free to add additional objects

#include "hoomd/extern/pybind/include/pybind11/pybind11.h"
namespace py = pybind11;

#include "PairPotentials.h"

#include "hoomd/md/PotentialPair.h"
#ifdef ENABLE_CUDA
#include "hoomd/md/PotentialPairGPU.h"
#endif // ENABLE_CUDA

namespace azplugins
{
namespace detail
{

//! Helper function export the Ashbaugh-Hatch pair potential parameters
/*!
* \sa ashbaugh_params
*/
void export_ashbaugh_params(py::module& m)
    {
    py::class_<ashbaugh_params>(m, "ashbaugh_params")
    .def(py::init<>())
    .def_readwrite("lj1", &ashbaugh_params::lj1)
    .def_readwrite("lj2", &ashbaugh_params::lj2)
    .def_readwrite("lam", &ashbaugh_params::lambda)
    .def_readwrite("rwcasq", &ashbaugh_params::rwcasq)
    .def_readwrite("wca_shift", &ashbaugh_params::wca_shift)
    ;
    m.def("make_ashbaugh_params", &make_ashbaugh_params);
    }

} // end namespace detail
} // end namespace azplugins


PYBIND11_PLUGIN(_azplugins)
    {
    pybind11::module m("_azplugins");

    export_PotentialPair<azplugins::PairPotentialAshbaugh>(m, "PairPotentialAshbaugh");
    #ifdef ENABLE_CUDA
    export_PotentialPairGPU<azplugins::PairPotentialAshbaughGPU, azplugins::PairPotentialAshbaugh>(m, "PairPotentialAshbaughGPU");
    #endif // ENABLE_CUDA
    azplugins::detail::export_ashbaugh_params(m);
    return m.ptr();
    }
