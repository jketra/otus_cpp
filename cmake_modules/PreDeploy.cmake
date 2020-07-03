set(DEFAULT_DEPLOY_PROJECT "none")

set(DEPLOY_PROJECT "${DEFAULT_DEPLOY_PROJECT}" CACHE STRING "${DEFAULT_DEPLOY_PROJECT}")

set_property(CACHE DEPLOY_PROJECT PROPERTY STRINGS "none" "${CICD}" "${IP_FILTER}" "${PRINT_IP}")

set(DEPLOY_${CICD} OFF)
set(DEPLOY_${IP_FILTER} OFF)
set(DEPLOY_${PRINT_IP} OFF)

if (NOT ${DEPLOY_PROJECT} STREQUAL "none") 
	if(BUILD_${DEPLOY_PROJECT})
		set(DEPLOY_${DEPLOY_PROJECT} ON)
		message(STATUS "Release package will be created for ${DEPLOY_PROJECT} project.")
	else()
		message("Project for deploy (${DEPLOY_PROJECT}) can't be OFF.")
		set(DEPLOY_${DEPLOY_PROJECT} OFF)
		set(DEPLOY_PROJECT "none" CACHE STRING "none")
	endif()
endif()
