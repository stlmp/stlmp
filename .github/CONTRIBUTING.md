
# Contributing

Firstly, thanks for taking the time to contribute! :grin:

## What should I know before getting started?
- C++
- Algorithms (any)

## How Can I Contribute?

### Feature suggestions / bug reports
You can contribute to this project by suggesting features or filing bugs by creating an issue [here](https://github.com/stlmp/stlmp/issues/new).

### Writing code
If you are interested in contributing by writing code, you can do so by implementing the features listed in [the plan](https://github.com/stlmp/stlmp/blob/master/plan.md).  

#### Sample directory structure
```
.
├── src                          # algorithms implementation
│   └── subfolder                # subfolders with grouped files of implementations
│       └── file.cpp             # implementation file
└── test
    └── subfolder                # subfolders with grouped files of implementations
        └── test_file.cpp        # test file for implementation file
```

#### Setup
 - Install C++17
```
$ sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
$ sudo apt-get update -qq
$ sudo apt-get install g++-6
$ sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90
```
 - Run build script
```
$ ./build.sh
```
 - If there are any changes in the code and you need to build again, run the second script.
```
$ ./build_after_cmake.sh
```

#### Sending a pull request
Push to your fork and [submit a pull request](https://github.com/stlmp/stlmp/compare/). Follow the [pull request template](https://github.com/stlmp/stlmp/blob/master/.github/PULL_REQUEST_TEMPLATE.md)  
put source file in src folder according to the existing structure.
- [ ] Add tests for all implementations.
- [ ] Descriptive pull request message
- [ ] Descriptive commit messages
- [ ] write test cases as written in the test folder
- [ ] use a formatter to format your code according to the google standards.
- [ ] folder names should contain underscores '_' instead of spaces
- [ ] please write full and descriptive names for variables
- [ ] remove main function from the code and add the tests in the tests folder by creating a new file in a similar structure and similar name as others.
- [ ] keep your implementation to C++, and write the code in .hpp files
