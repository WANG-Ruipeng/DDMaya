// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2015 Qingnan Zhou <qnzhou@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
//
#ifndef IGL_COPYLEFT_CGAL_EXTRACT_CELLS_SINGLE_COMPONENT_H
#define IGL_COPYLEFT_CGAL_EXTRACT_CELLS_SINGLE_COMPONENT_H

#include "../../igl_inline.h"
#include <Eigen/Core>
#include <vector>

namespace igl {
  namespace copyleft
  {
    namespace cgal
    {
      /// Extract connected 3D space partitioned by mesh (V,F) composed of
      /// **possibly multiple components** (the name of this function is
      /// dubious).
      ///
      /// @param[in] V  #V by 3 array of vertices.
      /// @param[in] F  #F by 3 array of faces.
      /// @param[in] P  #F list of patch indices.
      /// @param[in] uE    #uE by 2 list of vertex_indices, represents undirected edges.
      /// @param[in] uEC  #uE+1 list of cumsums of directed edges sharing each unique edge
      /// @param[in] uEE  #E list of indices into E (see `igl::unique_edge_map`)
      /// @param[out] cells  #P by 2 array of cell indices.  cells(i,0) represents the
      ///    cell index on the positive side of patch i, and cells(i,1)
      ///    represents cell index of the negative side.
      /// @return number of components
      template<
        typename DerivedV,
        typename DerivedF,
        typename DerivedP,
        typename DeriveduE,
        typename DeriveduEC,
        typename DeriveduEE,
        typename DerivedC >
      IGL_INLINE int extract_cells_single_component(
        const Eigen::MatrixBase<DerivedV>& V,
        const Eigen::MatrixBase<DerivedF>& F,
        const Eigen::MatrixBase<DerivedP>& P,
        const Eigen::MatrixBase<DeriveduE>& uE,
        const Eigen::MatrixBase<DeriveduEC>& uEC,
        const Eigen::MatrixBase<DeriveduEE>& uEE,
        Eigen::PlainObjectBase<DerivedC>& cells);
    }
  }
}

#ifndef IGL_STATIC_LIBRARY
#  include "extract_cells_single_component.cpp"
#endif
#endif

