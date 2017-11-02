# OpenCVSample
A sample project structure for C++ OpenCV based libraries

## Building the project

First you need to clone the project using git

```
git clone git@github.com:jbarbadillo/OpenCVSample.git 
```

Install OpenCV and CMake. For building the project use CMake commands

```
cd build
cmake ..
make
```

## Understanding the library and samples

The library CutDetector is the core of the project. Provides a method for detecting cuts in images. 
The use of the library is shown in the sample called sample_circular_cut.

Image data is captured from file and passed to the library. First the constructor initializes some required values. Then the library function
detectCuts performs the vision algorithms and returns the results.