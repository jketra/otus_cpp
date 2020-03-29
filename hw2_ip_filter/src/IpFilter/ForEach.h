#pragma once

#include "ProcessDirection.h"

#include <functional>
#include <algorithm>

namespace bl
{

template<class Iterator>
class ForEach
{
	using ValueType = typename Iterator::value_type;

public:
	ForEach(std::function<void(const ValueType&)> function) :
		_function(function)
	{}

	template<ProcessDirection processingDirection_ = ProcessDirection::ASC>
	void process(Iterator begin, Iterator end) const;

	template<>
	void process<ProcessDirection::ASC>(Iterator begin, Iterator end) const {
		std::for_each(begin, end, _function);
	}

	template<>
	void process<ProcessDirection::DESC>(Iterator begin, Iterator end) const {
		std::for_each(std::reverse_iterator<Iterator>{ end }, std::reverse_iterator<Iterator>{ begin },
			_function);
	}

private:
	std::function<void(const ValueType&)> _function;
};

}
