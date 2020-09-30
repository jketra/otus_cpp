## Homework 1.1: ci/cd

* To build this project, enable the `BUILD_CICD` option during generation:
```
cmake -DBUILD_CICD=ON
```
* To create a package to install the app from this project, use `DEPLOY_PROJECT`:
```
cmake -DBUILD_CICD=ON -DDEPLOY_PROJECT="CICD"
```
* To read more about building go to the [OTUS c++ homeworks](https://github.com/jketra/otus_cpp#building)
