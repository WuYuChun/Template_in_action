#include <iostream>


template <typename T0, typename T1, typename T2, typename T3, typename T4> 
T2 func(T1 v1, T3 v3, T4 v4);

int main(){

    double sv2;

    sv2 = func<double,int,int>(1,2,3);
    std::cout << "\tsv2: " << sv2 << std::endl;

    sv2 = func<double,int,int>(1,2,3);
    std::cout << "\tsv2: " << sv2 << std::endl;

    sv2 = func<double,int,int>(1,0.1,0.2);
    std::cout << "\tsv2: " << sv2 << std::endl;

    sv2 = func<int,int,double>(0.1,0.1,0.1);
    std::cout << "\tsv2: " << sv2 << std::endl;

}

template <typename T0, typename T1, typename T2, typename T3, typename T4> 
T2 func(T1 v1, T3 v3, T4 v4){
    T0 static sv0 = T0(0);
    T2 static sv2 = T2(0);

    std::cout << "\tsv1: " << v1
              << "\tsv2: " << v3 
              << "\tsv3: " << v4<< std::endl;

    T2 v2 = sv2;

    sv0 -= 1;
    sv2 -= 1;

    return v2;              
}