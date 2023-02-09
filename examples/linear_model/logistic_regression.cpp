// #include "../../src/slowmokit/methods/linear_model/logistic_regression.hpp"
// #include "../../src/slowmokit/core.hpp"

// int main()
// {
//     LogisticRegression<int> logisticregression;
//     std::vector<std::vector<double>> x = {
//         {1,1,1,1},
//         {1,1.87,1.12,0.86},
//         {1,1.09,1.11,0.99},
//         {1,5,4,4.98},
//         {1,4.07,4.76,5.34},
//         {1,5.65,5.23,4.99},
//         {1,9.98,8.87,8.76},
//         {1,9.83,8.90,8.97},
//     };
//     std::vector<std::vector<int>> y = {
//         {1,0,0},
//         {1,0,0},
//         {1,0,0},
//         {0,1,0},
//         {0,1,0},
//         {0,1,0},
//         {0,0,1},
//         {0,0,1},
//     };
//     logisticregression.fit(x,y,0.0001,2000,false,5);
//     std::vector<double> test{1,1,0.64,0.6};
//     std::vector<double> trained = logisticregression.predict(test);
//     for(int i=0;i<trained.size();i++){
//         std::cout<<trained[i]<<std::endl;
//     }
//     return 0;
// }