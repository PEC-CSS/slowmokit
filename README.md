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
3. Clone the forked repo, using `git clone https://github.com/PEC-CSS/slowmokit.git`.

After this,

You can directly use the execuatable file by running `./create` in the root folder of library, to do the required configurations.

More details [here](./create_model/README.md)

> If it does not work then you need to comfigure everything by your own.

4. Make the model directory you want to implement in the `src/slowmokit/methods/<model type>/<your_model>`.
    - `<model type>` is basically the class of your model, for example `linear_model` or `cluster`.
5. Create two mandatory files using IDE **ONLY**! As this will automatically add the file to `CMakeLists.txt`:
    - `<model>.hpp` : the header file for the model, create the class of model here and include all the stuff required
      for the model here.
        - Include `src/slowmokit.core.hpp` for all the basic functionalities already added.
        - Make sure to add **doc comments above each function signature** (refer other files for the format)
        - Variable and function names should be in **camel case** and class names should be in **pascal case** in **all files**.
    - `<model>.cpp` : implement the functions of the class here.
6. If your IDE does not automatically add the files to Cmake, add them manually in the `CMakeLists.txt`, under
   the `add_libraries`.

> This step is mandatory.

7. Add the header file `<model>.hpp` in `src/slowmokit.hpp` under the documentation block as shown [here](./src/slowmokit/ducks/io/io.hpp). More on [documentation block](https://developer.lsst.io/cpp/api-docs.html#multi-line-documentation-delimiters-should-be-on-their-own-lines).
8. Test the working by building in IDE.

> This step is mandatory

9. Format the files according to the convention. For simplicity, run `./clang-format-all src/` in gitbash(if on widnows) or in terminal(if on linux/macos)

_For this you need to have `clang-format` binaries installed in the machine._

To do that, run the fllowing in the terminal

```bash
# with npm (windows)
npm install -g clang-format
# you have to restart terminal in case of windows

# with homebrew (macos)
brew install clang-format

# linux (Ubuntu)
sudo apt install clang-format
```

> **NOTE:** Do **NOT** use `#include <bits/stdc++.h>` in any file, all the major header files are already included in `core.hpp`.]

### Example

Once the algorithm is ready, run and test it. After testing, push it in the `examples` directory, with proper comments and
instructions. With same directory structure as in `src`.

### Documentation

Push the docs of the model in a `<model>.md` file in same directory structure in `docs` folder.

### Pull Request (PR) format

After code is ready, you can make PR to the main branch. PR will be accepted only if:

-   Code pass the CI tests.
-   Example is pushed.
-   Code has proper comments and instructions.

## GOOD LUCK!
