#--------------------------------------------------------------------------
# Code generated by the SmartSoft MDSD Toolchain
# The SmartSoft Toolchain has been developed by:
#  
# Service Robotics Research Center
# University of Applied Sciences Ulm
# Prittwitzstr. 10
# 89075 Ulm (Germany)
#
# Information about the SmartSoft MDSD Toolchain is available at:
# www.servicerobotik-ulm.de
#
# This file is generated once. Modify this file to your needs. 
# If you want the toolchain to re-generate this file, please 
# delete it before running the code generator.
#--------------------------------------------------------------------------

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
MESSAGE("-- Include ConveyerBeltCoordinationService")
ADD_SUBDIRECTORY(${CMAKE_CURRENT_LIST_DIR}/ConveyerBeltCoordinationService ${CMAKE_CURRENT_BINARY_DIR}/ConveyerBeltCoordinationService)
MESSAGE("-- Include FestoMPSDockingCoordinationService")
ADD_SUBDIRECTORY(${CMAKE_CURRENT_LIST_DIR}/FestoMPSDockingCoordinationService ${CMAKE_CURRENT_BINARY_DIR}/FestoMPSDockingCoordinationService)
MESSAGE("-- Include FestMPSVisualDockingCoordinationService")
ADD_SUBDIRECTORY(${CMAKE_CURRENT_LIST_DIR}/FestMPSVisualDockingCoordinationService ${CMAKE_CURRENT_BINARY_DIR}/FestMPSVisualDockingCoordinationService)
MESSAGE("-- Include RobotToRobotDockingCoordinationService")
ADD_SUBDIRECTORY(${CMAKE_CURRENT_LIST_DIR}/RobotToRobotDockingCoordinationService ${CMAKE_CURRENT_BINARY_DIR}/RobotToRobotDockingCoordinationService)
MESSAGE("-- Include MasterRPCBridgeCoordinationService")
ADD_SUBDIRECTORY(${CMAKE_CURRENT_LIST_DIR}/MasterRPCBridgeCoordinationService ${CMAKE_CURRENT_BINARY_DIR}/MasterRPCBridgeCoordinationService)
