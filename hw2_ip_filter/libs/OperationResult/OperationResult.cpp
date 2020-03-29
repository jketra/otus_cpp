#pragma once

#include "OperationResult.h"

namespace bl
{

std::ostream& operator<<(std::ostream& out, const OperationResult& or ) {
	return out << or._msg.str() << std::endl;
}

}
