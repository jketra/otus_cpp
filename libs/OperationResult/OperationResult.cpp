#include "OperationResult.h"

namespace hw_libs
{

OperationResult::OperationResult(OperationResult&& other) :
	_isSuccess(other._isSuccess),
	_message(std::move(other._message))
{}

OperationResult OperationResult::Success() {
	return OperationResult(true);
}

OperationResult OperationResult::Fail()
{
	return OperationResult(false);
}

OperationResult OperationResult::Fail(const std::string& message) {
	return std::move(OperationResult(message));
}

OperationResult::operator bool() const {
	return _isSuccess;
}

const OperationResult& OperationResult::operator=(OperationResult&& other) {
	_isSuccess = other._isSuccess;
	_message = std::move(other._message);
	return *this;
}

OperationResult::OperationResult(bool isSuccess) :
	_isSuccess(isSuccess)
{}

OperationResult::OperationResult(const std::string& message) :
	_isSuccess(false) {
	_message << message;
}

std::ostream& operator<<(std::ostream& out, const OperationResult& operationResult) {
	return out << operationResult._message.str() << std::endl;
}

}
