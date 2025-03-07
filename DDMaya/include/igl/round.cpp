// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "round.h"
#include <cmath>


// http://stackoverflow.com/a/485549
template <typename DerivedX >
IGL_INLINE DerivedX igl::round(const DerivedX r)
{
  return (r > 0.0) ? std::floor(r + 0.5) : std::ceil(r - 0.5);
}

template < typename DerivedX, typename DerivedY>
IGL_INLINE void igl::round(
  const Eigen::MatrixBase<DerivedX>& X,
  Eigen::PlainObjectBase<DerivedY>& Y)
{
  Y.resizeLike(X);
  // loop over rows
  for(int i = 0;i<X.rows();i++)
  {
    // loop over cols
    for(int j = 0;j<X.cols();j++)
    {
      Y(i,j) = igl::round(X(i,j));
    }
  }
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template void igl::round<Eigen::Matrix<double, -1, 3, 1, -1, 3>, Eigen::Matrix<double, -1, 3, 1, -1, 3> >(Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 1, -1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 1, -1, 3> >&);
// generated by autoexplicit.sh
template void igl::round<Eigen::Matrix<float, -1, 3, 0, -1, 3>, Eigen::Matrix<float, -1, 3, 0, -1, 3> >(Eigen::MatrixBase<Eigen::Matrix<float, -1, 3, 0, -1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 0, -1, 3> >&);
// generated by autoexplicit.sh
template void igl::round<Eigen::Matrix<float, -1, 3, 1, -1, 3>, Eigen::Matrix<float, -1, 3, 1, -1, 3> >(Eigen::MatrixBase<Eigen::Matrix<float, -1, 3, 1, -1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 1, -1, 3> >&);
// generated by autoexplicit.sh
template void igl::round<Eigen::Matrix<double, -1, -1, 1, -1, -1>, Eigen::Matrix<double, -1, -1, 1, -1, -1> >(Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 1, -1, -1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 1, -1, -1> >&);
template void igl::round<Eigen::Matrix<double, -1, -1, 0, -1, -1>, Eigen::Matrix<double, -1, -1, 0, -1, -1> >(Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> >&);
template void igl::round<Eigen::Matrix<double, -1, 2, 0, -1, 2>, Eigen::Matrix<double, -1, 2, 0, -1, 2> >(Eigen::MatrixBase<Eigen::Matrix<double, -1, 2, 0, -1, 2> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 2, 0, -1, 2> >&);
template void igl::round<Eigen::Matrix<double, -1, 3, 0, -1, 3>, Eigen::Matrix<double, -1, 3, 0, -1, 3> >(Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3> >&);
#endif
