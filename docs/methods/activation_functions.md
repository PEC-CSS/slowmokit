# Activation Functions 

Sigmoid-It is computationally expensive, causes vanishing gradient problem and not zero-centred. This method is generally used for binary classification problems.

tanh- The Tanh activation function is a hyperbolic tangent sigmoid function that has a range of -1 to 1. It is often used in deep learning models for its ability to model nonlinear boundaries

tan-1h-The ArcTan function is a sigmoid function to model accelerating and decelerating outputs but with useful output ranges.This activation function maps the input values in the range (−π/2,π/2). Its derivative converges quadratically against 0 for large input values.

ReLU-This The ReLU activation function returns 0 if the input value to the function is less than 0 but for any positive input, the output is the same as the input. It is also continuous but non-differentiable at 0 and at values less than 0 because its derivative is 0 for any negative input.

leakyReLU- With Leaky ReLU there is a small negative slope so instead of that firing at all, for large gradients, our neurons do output some value and that makes our layer much more optimized too.

softmax-The softmax is a more generalised form of the sigmoid. It is used in multi-class classification problems. Similar to sigmoid, it produces values in the range of 0–1 therefore it is used as the final layer in classification models.

binaryStep-The Step activation function is used in the perceptron network. This is usually used in single-layer networks to convert to an output that is binary (0 or 1).These are called Binary Step Function.


The following function definitions are defined for a single variable for making it comprehendible and are implemented for a vector of 'double' values in the original code.
## Parameters

| Name         | Definition                                 | Type         |
|--------------|--------------------------------------------|--------------|
|   x          |      double value on which the function is applied.                                      | `double` |


## Functions

| Name                                   | Definition                                    | Return value  |
|----------------------------------------|-----------------------------------------------|---------------|
|sigmoid(x)|             1 / (1 + e^(-x)) |                    `double` |
|tanh(x)|                (e^x - e^(-x)) / (e^x + e^(-x)) |     `double` |
|arctan(x)|              the inverse of tan(x) |               `double` |
|ReLU(x)|                max(0, x) |                           `double` |
|leakyReLU(x)|           max(αx, x),α=0.1 |                    `double` |
|binaryStep(x)|          0, if x < 0
                         1, if x ≥ 0 |                         `double` |
|softmax(x)|             e^(x_i) / Σ_j e^(x_j)   |             `double` |


## Example

```cpp
int main(){
                      //sigmoid example    
std::vector<double> x = {-1,0,1};
 sigmoid(x);
 for (int i = 0; i < x.size(); i++) {
       std::cout << x[i] << " ";
   }
    return 0;
   
                      //tanh example
std::vector<double> x = {-1,0,1};
 tanh(x);
 for (int i = 0; i < x.size(); i++) {
       std::cout << x[i] << " ";
    }
    return 0;

                      //arctan example
std::vector<double> x = {-1,0,1};
 arctan(x);
 for (int i = 0; i < x.size(); i++) {
        std::cout << x[i] << " ";
   }
   return 0;

                      //ReLU example
std::vector<double> x = {1, 2, 3};
 ReLU(x);
 for (int i = 0; i < x.size(); i++) {
        std::cout << x[i] << " ";
    }
    return 0;

                       //leakyReLU example
std::vector<double> x = {1, 2, 3};
 leakyReLU(x);
 for (int i = 0; i < x.size(); i++) {
       std::cout << x[i] << " ";
    }
    return 0;
    
                       //binaryStep example
std::vector<double> x = {1, 2, 3};
 binaryStep(x);
 for (int i = 0; i < x.size(); i++) {
        std::cout << x[i] << " ";
   }
   return 0;

                        //softmax example
std::vector<double> x = {1, 2, 3};
 softmax(x);
 for (int i = 0; i < x.size(); i++) {
        std::cout << x[i] << " ";
    }
    return 0;

                      //binaryToBipolar example   
std::vector<double> x = {-1,1};
 binaryToBipolar(x);
 for (int i = 0; i < x.size(); i++) {
        std::cout << x[i] << " ";
    }
    return 0;

                      //bipolarToBinary example    
std::vector<double> x = {-1,1};
 bipolarToBinary(x);
 for (int i = 0; i < x.size(); i++) {
        std::cout << x[i] << " ";
    }
    return 0;

}
```