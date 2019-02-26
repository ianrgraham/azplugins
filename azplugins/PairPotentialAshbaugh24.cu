// Copyright (c) 2016-2018, Panagiotopoulos Group, Princeton University
// This file is part of the azplugins project, released under the Modified BSD License.

// Maintainer: mphoward

#include "PairPotentials.cuh"

namespace azplugins
{
namespace gpu
{

//! Kernel driver for a Ashbaugh-Hatch 48- 24 pair potential
template cudaError_t compute_pair_potential<azplugins::detail::PairEvaluatorAshbaugh24>
     (const pair_args_t& pair_args,
     const typename azplugins::detail::PairEvaluatorAshbaugh24::param_type *d_params);

} // end namespace gpu
} // end namespace azplugins