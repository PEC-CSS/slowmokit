// #include "../../src/slowmokit/methods/neighbors/bernoulli_nb.hpp"
// #include "../../src/slowmokit/core.hpp"

// signed main(){
//     std::vector<std::vector<int>> xTrain{
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
//     std::vector<int> yTrain{0,0,1,1,0,0,1,1,1,0};
//     std::vector<int> xTest{1,0,0};
//     BernoulliNB<int> bernoulli;
//     bernoulli.fit(xTrain,yTrain);
//     std::cout<<bernoulli.fit_predict(xTest);
//     return 0;
// }