#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <utility>

/// Custom libraries.
namespace hw_libs {

class OperationResult {
public:
	OperationResult() = delete;
	OperationResult(const OperationResult& other) = delete;

	OperationResult(OperationResult&& other);

	static OperationResult Success();
	static OperationResult Fail();
	static OperationResult Fail(const std::string& message);

	operator bool() const;

	const OperationResult& operator=(OperationResult&& other);

	friend std::ostream& operator<<(std::ostream& out, const OperationResult& operationResult);

	template<class T>
	friend OperationResult& operator<<(OperationResult& operationResult, const T& t);

	template<class T>
	friend OperationResult operator<<(OperationResult&& operationResult, const T& t);

private:
	explicit OperationResult(bool isSuccess);
	explicit OperationResult(const std::string& message);

	bool _isSuccess;
	std::stringstream _message;
};

template<class T>
OperationResult& operator<<(OperationResult& operationResult, const T& t) {
	operationResult._message << t;
	return operationResult;
}

template<class T>
OperationResult operator<<(OperationResult&& operationResult, const T& t) {
	operationResult._message << t;
	return std::move(operationResult);
}

}
