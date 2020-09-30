## Homework 1.2: ip filter

* To build this project, enable the `BUILD_IP_FILTER` option during generation:
```
cmake -DBUILD_IP_FILTER=ON
```
* To create a package to install the app from this project, use `DEPLOY_PROJECT`:
```
cmake -DBUILD_IP_FILTER=ON -DDEPLOY_PROJECT="IP_FILTER"
```
* To read more about building go to the [OTUS c++ homeworks](https://github.com/jketra/otus_cpp#building)
