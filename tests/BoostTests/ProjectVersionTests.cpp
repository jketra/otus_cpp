#ifndef _MSC_VER
	#define BOOST_TEST_DYN_LINK
#endif

#define BOOST_TEST_MODULE ProjectVersionTests

#include <boost/test/unit_test.hpp>

#include "version.h"

BOOST_AUTO_TEST_SUITE(ProjectVersionTests)

	BOOST_AUTO_TEST_CASE(PatchNumber)
	{
	    BOOST_CHECK(info::getProjectVersion() > 0);
	}

}
