#pragma once

#include <string>
#include <iostream>
#include <sstream>

namespace bl
{

class OperationResult {
public:
	OperationResult() = delete;

	OperationResult(OperationResult&& other) :
		_isSuccess(other._isSuccess),
		_msg(std::move(other._msg))
	{}

	static OperationResult Success() {
		return OperationResult(true);
	}

	static OperationResult Fail(const std::string& message = "") {
		return OperationResult(false, message);
	}

	operator bool() const {
		return _isSuccess;
	}

	template<typename T>
	OperationResult&  operator<<(const T& str) {
		_msg << str;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const OperationResult& operationResult);

private:
	explicit OperationResult(bool isSuccess, const std::string& message = "") :
		_isSuccess(isSuccess),
		_msg(message)
	{}

	bool _isSuccess;
	std::stringstream _msg;
};

}
