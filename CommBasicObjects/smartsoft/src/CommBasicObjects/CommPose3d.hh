//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Christian Schlegel (schlegel@hs-ulm.de)
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------

// --------------------------------------------------------------------------
//
//  Copyright (C) 2003 Boris Kluge
//
//        schlegel@hs-ulm.de
//
//        Prof. Dr. Christian Schlegel
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft Basic Communication Classes".
//  It provides basic standardized data types for communication between
//  different components in the mobile robotics context. These classes
//  are designed to be used in conjunction with the SmartSoft Communication
//  Library.
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//  (partly based on work by Christian Schlegel and Pablo d'Angelo)
//
// --------------------------------------------------------------------------


#ifndef COMMBASICOBJECTS_COMMPOSE3D_H_
#define COMMBASICOBJECTS_COMMPOSE3D_H_

#include "CommBasicObjects/CommPose3dCore.hh"

#include "armadillo.hh"  // from utility

namespace CommBasicObjects {
		
class CommPose3d : public CommPose3dCore {
	public:
		// default constructors
		CommPose3d();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommPose3d(const CommBasicObjects::CommPosition3d &position, const CommBasicObjects::CommOrientation3d &orientation);
		
		CommPose3d(const CommPose3dCore &commPose3d);
		CommPose3d(const DATATYPE &commPose3d);
		virtual ~CommPose3d();
		
		// use framework specific getter and setter methods from core (base) class
		using CommPose3dCore::get;
		using CommPose3dCore::set;
		
		//
		// feel free to add customized methods here
		//
		CommPose3d(double x, double y, double z, double azimuth, double elevation,
				double roll, const double unit = 0.001) {
			set_x(x, unit);
			set_y(y, unit);
			set_z(z, unit);
			set_azimuth(azimuth);
			set_elevation(elevation);
			set_roll(roll);
		}

		/**
		 Creates a Pose3d object from a given homogenous matrix (4x4)
		 The translation is in the form of the given unit.
		 */
		CommPose3d(arma::mat &matrix, const double unit = 0.001);

		/**
		 Set the position.
		 */
		inline void set_position(const CommPosition3d &pos) {
			idl_CommPose3d.position = pos.get();
		}
		/**
		 Set the orientation.
		 */
		inline void set_orientation(const CommOrientation3d &ori) {
			idl_CommPose3d.orientation = ori.get();
		}

		/**
		 Get the position.
		 */
		inline CommPosition3d get_position() const {
			return CommPosition3d(idl_CommPose3d.position);
		}

		/**
		 Get the orientation.
		 */
		inline CommOrientation3d get_orientation() const {
			return CommOrientation3d(idl_CommPose3d.orientation);
		}

		/**
		 Get the x coordinate of the position.
		 */
		inline double get_x(const double unit = 0.001) const {
			return idl_CommPose3d.position.x * 0.001 / unit;
		}
		/**
		 Get the y coordinate of the position.
		 */
		inline double get_y(const double unit = 0.001) const {
			return idl_CommPose3d.position.y * 0.001 / unit;
		}
		/**
		 Get the z coordinate of the position.
		 */
		inline double get_z(const double unit = 0.001) const {
			return idl_CommPose3d.position.z * 0.001 / unit;
		}

		/**
		 Set the x coordinate of the position.
		 */
		inline void set_x(double x, const double unit = 0.001) {
			idl_CommPose3d.position.x = x * unit * 1000;
		}
		/**
		 Set the y coordinate of the position.
		 */
		inline void set_y(double y, const double unit = 0.001) {
			idl_CommPose3d.position.y = y * unit * 1000;
		}
		/**
		 Set the z coordinate of the position.
		 */
		inline void set_z(double z, const double unit = 0.001) {
			idl_CommPose3d.position.z = z * unit * 1000;
		}

		/**
		 Get the azimuth in radians.
		 */
		inline double get_azimuth() const {
			return idl_CommPose3d.orientation.azimuth;
		}
		/**
		 Get the elevation in radians.
		 */
		inline double get_elevation() const {
			return idl_CommPose3d.orientation.elevation;
		}
		/**
		 Get the roll in radians.
		 */
		inline double get_roll() const {
			return idl_CommPose3d.orientation.roll;
		}

		/**
		 Set the azimuth in radians.
		 */
		inline void set_azimuth(double a) {
			idl_CommPose3d.orientation.azimuth = a;
		}
		/**
		 Set the elevation in radians.
		 */
		inline void set_elevation(double e) {
			idl_CommPose3d.orientation.elevation = e;
		}
		/**
		 Set the roll in radians.
		 */
		inline void set_roll(double r) {
			idl_CommPose3d.orientation.roll = r;
		}

		/**
		 Returns a homogenous Matrix with azimuth, elevation, roll and the
		 translation in the given unit.
		 */
		arma::mat getHomogeneousMatrix(const double unit = 0.001) const;
};

inline std::ostream &operator<<(std::ostream &os, const CommPose3d &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommBasicObjects */
#endif /* COMMBASICOBJECTS_COMMPOSE3D_H_ */