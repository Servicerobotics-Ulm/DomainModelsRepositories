#include "FestoMPSVisualDockingCoordinationServiceDetectioneventEventHandler.hh"

std::string FestoMPSVisualDockingCoordinationServiceDetectioneventEventHandler::handleEvent(const CommTrackingObjects::CommDetectedMarkerEventResult &r) throw() {
	//convert the event result commObject to string representation outString (to TCL)
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();

    int numberOfTags;
    std::stringstream eventState;


    CommTrackingObjects::CommDetectedMarkerList list = r.getMarkers();

    numberOfTags = list.getMarkersSize();


    eventState << "( ";
    for (int i = 0; i < numberOfTags; i++)
    {
    		CommTrackingObjects::CommDetectedMarker marker = list.getMarkersElemAtPos(i);
            CommBasicObjects::CommPose3d pose = list.get_tag_pose_in_world_frame_by_index(i);
            eventState << "( " << marker.getId()<<" "<< pose.get_x(1.0)<<" "<< pose.get_y(1.0)<<" "<< pose.get_z(1.0)<<" "<< pose.get_azimuth()<<" " << pose.get_elevation()<<" "<<pose.get_roll()<<" )";
    }
    eventState << " )";

    return eventState.str();

}

CommTrackingObjects::CommDetectedMarkerEventParameter FestoMPSVisualDockingCoordinationServiceDetectioneventEventHandler::activateEventParam(const std::string& parameterString){
	CommTrackingObjects::CommDetectedMarkerEventParameter param;
	
	//fill the event activation (parameter) commObject with the data provided via the inString (from TCL)
	//e.g. param.setLisp(inString);
	return param;
}
