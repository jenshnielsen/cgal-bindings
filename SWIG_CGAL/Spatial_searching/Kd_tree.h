#ifndef SWIG_CGAL_SPATIAL_SEARCHING_KD_TREE_H
#define SWIG_CGAL_SPATIAL_SEARCHING_KD_TREE_H


#include <SWIG_CGAL/Common/Macros.h>
#include <SWIG_CGAL/Common/Input_iterator.h>
#include <SWIG_CGAL/Common/Input_iterator_wrapper.h>
#include <SWIG_CGAL/Common/Output_iterator_wrapper.h>


SWIG_CGAL_DECLARE_ITERATOR_CLASS_2(iterator,Kd_tree_iterator)

template <class Query>
struct Query_iterator_helper{
  typedef typename internal::Converter<Query>::result_type Base;
  typedef std::pair<Input_iterator_wrapper<Query,Base>,Input_iterator_wrapper<Query,Base> > input;
  typedef boost::function_output_iterator< Container_writer<Query,Base> >                                       output;
};

template<class Cpp_base, class Query, class Fuzzy_sphere, class Fuzzy_iso_box>
class Kd_tree_wrapper{
  Cpp_base data;
public:
  #ifndef SWIG
  typedef Cpp_base cpp_base;
  const cpp_base& get_data() const {return data;}
  cpp_base& get_data_ref() {return data;}
  #endif
  typedef Kd_tree_iterator<Cpp_base,Query> Iterator;
  typedef Query Point_d;
//Input iterator
  typedef typename Query_iterator_helper<Query>::input       Point_range; 

//Creation
  Kd_tree_wrapper(){}
  Kd_tree_wrapper(Point_range range):data(range.first,range.second){}
  
//Operations
  SWIG_CGAL_FORWARD_CALL_1(void,insert,Point_d)
  void insert_range(Point_range range){ data.insert(range.first,range.second);}
  Iterator iterator(){return Iterator(data.begin(),data.end());}
  SWIG_CGAL_FORWARD_CALL_0(void,clear)
  SWIG_CGAL_FORWARD_CALL_0(int,size)
  void search(typename Query_iterator_helper<Query>::output out, const Fuzzy_sphere& fsphere) { data.search(out,fsphere.get_data());}
  void search(typename Query_iterator_helper<Query>::output out, const Fuzzy_iso_box& fbox)   { data.search(out,fbox.get_data());}
  
  SWIG_CGAL_FORWARD_CALL_0(void,build)
};


#endif //SWIG_CGAL_SPATIAL_SEARCHING_KD_TREE_H

//Creation
// Kd_tree<Traits, Splitter, UseExtendedNode> tree ( Splitter s=Splitter());
// template <class InputIterator> Kd_tree<Traits, Splitter, UseExtendedNode> tree ( InputIterator first, InputIterator beyond, Splitter s=Splitter());
//Operations
//  SWIG_CGAL_FORWARD_CALL_0(Node_handle,root)
// Kd_tree_rectangle<Traits>  tree.bounding_box ()  
// std::ostream&  tree.statistics ( std::ostream& s)