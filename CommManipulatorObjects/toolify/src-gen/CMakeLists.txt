CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT("CommManipulatorObjectsJSON" VERSION 1.0)

FIND_PACKAGE(nlohmann_json PATHS $ENV{SMART_ROOT_ACE} PATH_SUFFIXES modules QUIET)

IF(TARGET nlohmann_json::nlohmann_json)
	SET(CMAKE_CXX_STANDARD 14)
	
	FILE(GLOB JSON_SRCS ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/*.cc)
	FILE(GLOB JSON_HDRS ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/*.hh)
	# find depndency CommManipulatorObjectsJSON
	FIND_PACKAGE(CommBasicObjectsJSON PATHS $ENV{SMART_ROOT_ACE}/modules)
	
	ADD_LIBRARY(${PROJECT_NAME} SHARED ${JSON_SRCS})
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} CommManipulatorObjects nlohmann_json::nlohmann_json)
	# link depndency CommBasicObjects
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} CommBasicObjectsJSON)
	TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<INSTALL_INTERFACE:include>
	)
	
	ADD_DEPENDENCIES(autoinstall ${PROJECT_NAME})
	
	CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}Config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake @ONLY)
	INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION modules)
	
	IF(DEFINED ${PROJECT_NAME}_VERSION)
		SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES VERSION ${${PROJECT_NAME}_VERSION} SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR})
		INCLUDE(CMakePackageConfigHelpers)
		write_basic_package_version_file(${PROJECT_NAME}ConfigVersion.cmake COMPATIBILITY SameMajorVersion)
		IF(EXISTS ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake)
			INSTALL(FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake DESTINATION modules)
			SMART_TRACE_GENERATED_FILE(${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake)
		ENDIF(EXISTS ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake)
	ENDIF(DEFINED ${PROJECT_NAME}_VERSION)
	
	INSTALL(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Targets DESTINATION lib)
	EXPORT(EXPORT ${PROJECT_NAME}Targets)
	INSTALL(EXPORT ${PROJECT_NAME}Targets DESTINATION modules)
	INSTALL(FILES ${JSON_HDRS} DESTINATION include/${PROJECT_NAME})
ENDIF(TARGET nlohmann_json::nlohmann_json)
