// #include "../../src/slowmokit/methods/neighbors/bernoulli_nb.hpp"
// #include "../../src/slowmokit/core.hpp"

// signed main(){
//     std::vector<std::vector<int>> x_train{
//         {0,0,0},
//         {1,0,0},
//         {1,0,1},
//         {1,0,0},
//         {0,1,1},
//         {1,0,0},
//         {1,1,0},
//         {0,1,1},
//         {1,0,1},
//         {1,1,1}
//     };
//     std::vector<int> y_train{0,0,1,1,0,0,1,1,1,0};
//     std::vector<int> x_test{1,0,0};
//     BernoulliNB<int> bernoulli;
//     std::cout<<bernoulli.predict(x_train,y_train,x_test);
//     return 0;
// }