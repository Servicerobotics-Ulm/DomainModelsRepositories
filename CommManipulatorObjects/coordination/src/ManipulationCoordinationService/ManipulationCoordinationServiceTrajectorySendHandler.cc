#include "ManipulationCoordinationServiceTrajectorySendHandler.hh"

#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING 100000
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CommManipulatorObjects::CommManipulationTrajectory ManipulationCoordinationServiceTrajectorySendHandler::handleSend(std::string inString){

	CommManipulatorObjects::CommManipulationTrajectory sendCommObject;


	//fill the send commObject with the data provided via the inString (from TCL)

	//fill the send commObject with the data provided via the inString (from TCL)
	static char outString[LISP_STRING];
	char *running;
	char *token;
	double tcp[6]; // x, y, z, azimuth, roll, elevation

	// copy string
	token = running = strdupa (inString.c_str());

	// extract trajectory flag -- angles or pose
	do
	{
		token = strsep (&running, LISP_SEPARATOR);
	} while ((token != NULL) && (strlen(token)==0));

	/////////////////////////////////////////////////////////////////////
	// angles
	if( strcasecmp(token, "ANGLES") == 0 )
	{

		double angle;
		int joint_count;
		double joint_time = 0.2; //default value


		std::vector<CommManipulatorObjects::CommJointManipulationTarget> targets_vector;
		CommManipulatorObjects::CommJointManipulationTarget target;
		target.setMotion_type(CommManipulatorObjects::BasicRobotMotionType::JOINT_SPACE);
		target.setReach_type(CommManipulatorObjects::TargetVelocityTimeFlag::TIME);
		target.setBlending_radius(0.1);

		// extract number of joints
		do
		{
			token = strsep (&running, LISP_SEPARATOR);
		} while ((token != NULL) && (strlen(token)==0));
		joint_count = atoi(token);

		target.resizeJoint_angles(joint_count);

		// iterate over angles
		for(int i=0; i<joint_count; i++)
		{
			do
			{
				token = strsep (&running, LISP_SEPARATOR);
			} while ((token != NULL) && (strlen(token)==0));
			angle = atof(token);
			target.setJoint_anglesElemAtPos(i, angle);
		}

		token = strsep (&running, LISP_SEPARATOR);
		if(!((token != NULL) && (strlen(token)==0))){
			joint_time = atof(token);
		}
		token = strsep (&running, LISP_SEPARATOR);
		if(!((token != NULL) && (strlen(token)==0))){
			joint_time = atof(token);
		}
		//TODO
		std::cout<<"joint_time: "<<joint_time<<std::endl;
		target.setReach_time(joint_time);

		targets_vector.push_back(target);

		sendCommObject.setType(CommManipulatorObjects::ManipulatorTrajectoryFlag::JOINT_ANGLES);
		sendCommObject.setJoint_angles(targets_vector);

	}
	/////////////////////////////////////////////////////////////////////
	// tcp
	else if( strcasecmp(token, "POSE") == 0 )
	{

		std::vector<CommManipulatorObjects::CommCartesianManipulationTarget> targets_vector;

		CommManipulatorObjects::CommCartesianManipulationTarget target;
		target.setMotion_type(CommManipulatorObjects::BasicRobotMotionType::LINEAR);
		target.setReach_type(CommManipulatorObjects::TargetVelocityTimeFlag::TIME);
		target.setReference_frame(CommManipulatorObjects::CartesianManipulationTargetReferenceFrame::MOBILE_BASE);
		target.setReach_time(2.0); //TODO
		target.setBlending_radius(0.02); //TODO

		// iterate over TCP -- x, y, z, azimuth, roll, elevation
		for(int i=0; i<6; i++)
		{
			do
			{
				token = strsep (&running, LISP_SEPARATOR);
			} while ((token != NULL) && (strlen(token)==0));
			tcp[i] = atof(token);
		}

		target.setTcp_pose(CommBasicObjects::CommPose3d (tcp[0], tcp[1], tcp[2], tcp[3], tcp[4], tcp[5], 1.0));

		std::cout<<"Target Pose: "<<target<<std::endl;
		targets_vector.push_back(target);

		sendCommObject.setType(CommManipulatorObjects::ManipulatorTrajectoryFlag::POSE_TCP);
		sendCommObject.setTcp_poses(targets_vector);
	}
	else
	{
		std::cout << "switchManipulator -- unknown parameter - should be POSE or ANGLES\n";
		sprintf(outString,"(error (unknown parameter))");
	}


	return sendCommObject;
}

