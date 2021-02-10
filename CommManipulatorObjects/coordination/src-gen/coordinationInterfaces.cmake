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
MESSAGE("-- Include ManipulatorCoordinationService")
ADD_SUBDIRECTORY(${CMAKE_CURRENT_LIST_DIR}/ManipulatorCoordinationService ${CMAKE_CURRENT_BINARY_DIR}/ManipulatorCoordinationService)
MESSAGE("-- Include WelderCoordinationService")
ADD_SUBDIRECTORY(${CMAKE_CURRENT_LIST_DIR}/WelderCoordinationService ${CMAKE_CURRENT_BINARY_DIR}/WelderCoordinationService)
MESSAGE("-- Include VacuumGripperCoordinationService")
ADD_SUBDIRECTORY(${CMAKE_CURRENT_LIST_DIR}/VacuumGripperCoordinationService ${CMAKE_CURRENT_BINARY_DIR}/VacuumGripperCoordinationService)
