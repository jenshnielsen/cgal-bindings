SET (LIBSTOLINKWITH CGAL_Kernel_cpp)

# Modules
ADD_SWIG_CGAL_JAVA_MODULE   ( HalfedgeDS ${LIBSTOLINKWITH} )
ADD_SWIG_CGAL_PYTHON_MODULE ( HalfedgeDS ${LIBSTOLINKWITH} )
ADD_SWIG_CGAL_RUBY_MODULE   ( HalfedgeDS ${LIBSTOLINKWITH} )
