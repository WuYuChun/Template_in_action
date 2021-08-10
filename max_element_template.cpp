
#include <iostream>

template <typename T>  //类型模板参数
T const & max_element(T const *l, unsigned int sz){
    T const *max_value(l);
    for(unsigned int i = 1; i < sz;++i){  //这里用指针，避免自定义类型 赋值构造导致额外开销，但是在c++11之后，使用移动赋值，不需要考虑
        if(l[i] > *max_value){
            max_value = &(l[i]);
        }
    }
    return *max_value;
}


int main(){
    int l[] = {2,0,1,1,0,8,2,6};
    char cl[] = "August";

    std::cout << max_element(l,8) << std::endl;  // std::cout << max_element<int>(1,8) << std::endl;
    std::cout << max_element(cl,6) << std::endl;

    return 0;

}


/*-----------------这里是通过insight 去看模板函数--------不要放开-------------------------------------


#include <iostream>

template <typename T>
T const & max_element(T const *l, unsigned int sz){
    T const *max_value(l);
    for(unsigned int i = 1; i < sz;++i){
        if(l[i] > *max_value){
            max_value = &(l[i]);
        }
    }
    return *max_value;
}

//First instantiated from: insights.cpp:19 
#ifdef INSIGHTS_USE_TEMPLATE
template<>
const int & max_element<int>(const int * l, unsigned int sz)
{
  const int * max_value = l;
  for(unsigned int i = 1; i < sz; ++i) {
    if(l[i] > *max_value) {
      max_value = &(l[i]);
    } 
    
  }
  
  return *max_value;
}
#endif


// First instantiated from: insights.cpp:20 
#ifdef INSIGHTS_USE_TEMPLATE
template<>
const char & max_element<char>(const char * l, unsigned int sz)
{
  const char * max_value = l;
  for(unsigned int i = 1; i < sz; ++i) {
    if(static_cast<int>(l[i]) > static_cast<int>(*max_value)) {
      max_value = &(l[i]);
    } 
    
  }
  
  return *max_value;
}
#endif



int main()
{
  int l[8] = {2, 0, 1, 1, 0, 8, 2, 6};
  char cl[7] = "August";
  std::cout.operator<<(max_element(l, 8)).operator<<(std::endl);
  std::operator<<(std::cout, max_element(cl, 6)).operator<<(std::endl);
  return 0;
}

*/