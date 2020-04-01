#include "OperationResult.h"

namespace bl
{

std::ostream& operator<<(std::ostream& out, const OperationResult& operationResult) {
	return out << operationResult._msg.str() << std::endl;
}

}
