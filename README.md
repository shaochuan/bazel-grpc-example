Bazel gRPC Example
======================

Minimal example of using Bazel to build a C++ gRPC server with a Python gRPC client.

Build & Run
======================

gRPC C++ library needs to be built with C++14. Thus, make sure you had
```
export BAZEL_CXXOPTS="-std=c++14"
```
in your `.bashrc`.

    $ blaze run //calculator:calculator_server
    ```Server listening on 0.0.0.0:50051```

In another terminal:
    $ blaze run //calculator:calculator_client
    ```Adding 1 + 2 + 3 = 6```
