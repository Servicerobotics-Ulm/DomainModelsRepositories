# CommLocalizationObjectsJsonTransformation
GET_FILENAME_COMPONENT(TOOLIFY_DIR "${PROJECT_SOURCE_DIR}/../toolify" REALPATH)
IF(EXISTS ${TOOLIFY_DIR})
	ADD_SUBDIRECTORY(${TOOLIFY_DIR}/src-gen ${CMAKE_CURRENT_BINARY_DIR}/toolify)
ENDIF(EXISTS ${TOOLIFY_DIR})

# CommLocalizationObjectsOpcUaBackend
GET_FILENAME_COMPONENT(OPC_UA_BACKEND_DIR "${PROJECT_SOURCE_DIR}/../opcua-backend" REALPATH)
IF(EXISTS ${OPC_UA_BACKEND_DIR})
	ADD_SUBDIRECTORY(${OPC_UA_BACKEND_DIR}/src-gen ${CMAKE_CURRENT_BINARY_DIR}/opcua-backend)
ENDIF(EXISTS ${OPC_UA_BACKEND_DIR})

# coordination interfaces extensions
GET_FILENAME_COMPONENT(Coordination_DIR "${PROJECT_SOURCE_DIR}/../coordination" REALPATH)
IF(EXISTS ${Coordination_DIR})
MESSAGE("-- Include CoordinationInterfaces")
INCLUDE("${Coordination_DIR}/src-gen/coordinationInterfaces.cmake")
ENDIF(EXISTS ${Coordination_DIR})

