## Homework 4: print ip
* Task:
	- [x] One template function with different implementations via the SFINAE mechanism for printing conditional ip addresses. Input/output examples:
	```	
	int{1234}                   => "0.0.4.210" (if sizeof(int) == 4)		
	std::string{"trololo"}      => "trololo"	
	std::list, std::vector      => dot separated container contents
	std::make_tuple(0, 1, 2, 3) => "0, 1, 2, 3"
	```
	- [x] Documentation for this project.
	- [x] Publish thml-documantation on github-pages.

* To build this project, enable the `BUILD_PRINT_IP` option during generation:
```
cmake -DBUILD_PRINT_IP=ON
```
* To create a package to install the app from this project, use `DEPLOY_PROJECT`:
```
cmake -DBUILD_PRINT_IP=ON -DDEPLOY_PROJECT="PRINT_IP"
```
* To read more about building go to the [OTUS c++ homeworks](https://github.com/jketra/otus_cpp#building)
