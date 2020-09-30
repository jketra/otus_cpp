#ifndef _MSC_VER
	#define BOOST_TEST_DYN_LINK
#endif

#define BOOST_TEST_MODULE ProjectVersionTests

#include "version.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(ProjectVersionTests)

	BOOST_AUTO_TEST_CASE(PatchNumber)
	{
	    BOOST_CHECK(hw0::getProjectVersion() > 0);
	}

}
