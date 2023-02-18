// #include "../../../src/slowmokit/methods/neighbors/gaussian_nb.hpp"

// signed main(){
//     std::vector<std::vector<double>> x_train{
//         {6,180,12},
//         {5.92,190,11},
//         {5.58,170,12},
//         {5.92,165,10},
//         {5,100,6},
//         {5.5,150,8},
//         {5.42,130,7},
//         {5.75,150,9},
//     };
//     std::vector<int> y_train{0,0,0,0,1,1,1,1};
//     std::vector<double> x_test{6,130,8};
//     std::vector<int> classes{0,1};
//     GaussianNB<double> gaussian;
//     std::cout<<gaussian.fitPredict(x_train,y_train,x_test,classes);
//     return 0;
// }