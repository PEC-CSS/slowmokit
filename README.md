<p align="center">
    <img width="69" src="https://user-images.githubusercontent.com/52048551/206870724-e4c71d93-fbaf-420c-8a64-cfd8ba05d27e.png" alt="slowmoKIT logo">
    <h1 align="center">Slomokit</h1>
</p>


## ML kit in C++.

Library which can be used for machine learning in C++.

### Steps

Following are the steps to start contributing to our beautiful library:

1. Install an IDE, preferably [CLion](https://www.jetbrains.com/clion/download/).
2. Fork this repo.
3. Clone the forked repo, using `git clone https://github.com/Ishwarendra/slowmokit.git`.
4. Make the model directory you want to implement in the `src/slowmokit/methods/<model type>/<your_model>`.
    - `<model type>` is basically the class of your model, for example `linear_model` or `cluster`.
5. Create two mandatory files using IDE **ONLY**! As this will automatically add the file to `CMakeLists.txt`:
    - `<model>.hpp` : the header file for the model, create the class of model here and include all the stuff required
      for the model here.
        - Include `src/slowmokit.core.hpp` for all the basic functionalities already added.
    - `<model>.cpp` : implement the functions of the class here.
6. If your IDE does not automatically add the files to Cmake, add them manually in the `CMakeLists.txt`, under
   the `add_libraries`.
7. Add the header file `<model>.hpp` in `src/slowmokit.hpp` under the documentation block as shown [here](./src/slowmokit/ducks/io/io.hpp). More on [documentation block](https://developer.lsst.io/cpp/api-docs.html#multi-line-documentation-delimiters-should-be-on-their-own-lines).
8. Test the working by building in IDE.


> **NOTE:** Do **NOT** use `#include <bits/stdc++.h>` in any file, all the major header files are already included in `core.hpp`.]

### Example

Once the algorithm is ready, run and test it. After testing, push it in the `examples` directory, with proper comments and
instructions. With same directory structure as in `src`.

### Documentation

Push the docs of the model in a `<model>.md` file in same directory structure in this folder.

### Pull Request (PR) format

After code is ready, you can make PR to the main branch. PR will be accepted only if:

- Code pass the CI tests.
- Example is pushed.
- Code has proper comments and instructions.

## GOOD LUCK!