#include "ManipulatorCoordinationServiceTrajectorySendHandler.hh"

#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING 100000
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
CommManipulatorObjects::CommManipulatorTrajectory ManipulatorCoordinationServiceTrajectorySendHandler::handleSend(std::string inString){

	CommManipulatorObjects::CommManipulatorTrajectory sendCommObject;

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

			sendCommObject.set_valid_values(CommManipulatorObjects::ManipulatorTrajectoryFlag::JOINT_ANGLES);
			sendCommObject.set_trajectory_size(1);

			// extract number of joints
			do
			{
				token = strsep (&running, LISP_SEPARATOR);
			} while ((token != NULL) && (strlen(token)==0));
			joint_count = atoi(token);
			sendCommObject.set_joint_count(joint_count);

			// iterate over angles
			for(int i=0; i<joint_count; i++)
			{
				do
				{
					token = strsep (&running, LISP_SEPARATOR);
				} while ((token != NULL) && (strlen(token)==0));
				angle = atof(token);
				sendCommObject.set_joint_angle(0, i, angle);
			}

			token = strsep (&running, LISP_SEPARATOR);
							if(!((token != NULL) && (strlen(token)==0))){
									joint_time = atof(token);
							}
							std::cout<<"joint_time: "<<joint_time<<std::endl;
							sendCommObject.set_joint_time(0, joint_time);
		}
		/////////////////////////////////////////////////////////////////////
		// tcp
		else if( strcasecmp(token, "POSE") == 0 )
		{
			sendCommObject.set_valid_values(CommManipulatorObjects::ManipulatorTrajectoryFlag::POSE_TCP);

			// iterate over TCP -- x, y, z, azimuth, roll, elevation
			for(int i=0; i<6; i++)
			{
				do
				{
					token = strsep (&running, LISP_SEPARATOR);
				} while ((token != NULL) && (strlen(token)==0));
				tcp[i] = atof(token);
			}
			sendCommObject.set_pose_TCP_robot(tcp[0], tcp[1], tcp[2], tcp[3], tcp[4], tcp[5], 1);

		}
		else
		{
			std::cout << "switchManipulator -- unknown parameter - should be POSE or ANGLES\n";
			sprintf(outString,"(error (unknown parameter))");
		}

	return sendCommObject;
}

