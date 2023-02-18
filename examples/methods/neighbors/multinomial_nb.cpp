// #include "../../src/slowmokit/methods/neighbors/multinomial_nb.hpp"
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
//     std::vector<int> yTrain{2,2,2,2,1,2,2,1,2,0};
//     std::vector<int> xTest{0,0,0};
//     std::vector<int> classes{0,1,2};
//     MultinomialNB<int> multinomial;
//     std::cout<<multinomial.predict(xTrain,yTrain,classes,xTest);
//     return 0;
// }