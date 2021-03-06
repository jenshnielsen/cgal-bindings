// ------------------------------------------------------------------------------
// Copyright (c) 2011 GeometryFactory (FRANCE)
// Distributed under the Boost Software License, Version 1.0. (See accompany-
// ing file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// ------------------------------------------------------------------------------ 

#ifndef SWIG_CGAL_MESH_2_TYPEDEFS_H
#define SWIG_CGAL_MESH_2_TYPEDEFS_H

#include <SWIG_CGAL/Kernel/typedefs.h>
#include <CGAL/Constrained_Delaunay_triangulation_2.h>
#include <CGAL/Delaunay_mesher_2.h>
#include <CGAL/Delaunay_mesh_face_base_2.h>
#include <CGAL/Delaunay_mesh_size_criteria_2.h>
#include <CGAL/Triangulation_conformer_2.h>  

typedef CGAL::Triangulation_vertex_base_2<EPIC_Kernel>                          M2_Vb;
typedef CGAL::Delaunay_mesh_face_base_2<EPIC_Kernel>                            M2_Fb;
typedef CGAL::Triangulation_data_structure_2<M2_Vb, M2_Fb>                      M2_Tds;
typedef CGAL::Constrained_Delaunay_triangulation_2<EPIC_Kernel, M2_Tds>         M2_CDT;

typedef CGAL::Delaunay_mesh_size_criteria_2<M2_CDT>                             DM2_C;
typedef CGAL::Delaunay_mesher_2<M2_CDT,DM2_C>                                   DM2_M;


#endif //SWIG_CGAL_MESH_2_TYPEDEFS_H
