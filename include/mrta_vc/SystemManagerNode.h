/**
 *  SystemManagerNode.h
 *
 *  Version: 0.0.0.0
 *  Created on: 26/03/2016
 *  Modified on: *********
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef SYSTEM_MANAGER_NODE_H_
#define SYSTEM_MANAGER_NODE_H_

#include <ros/ros.h>
#include "unifei/expertinos/mrta_vc/system/AllocationManager.h"


namespace mrta_vc 
{

	class SystemManagerNode : unifei::expertinos::mrta_vc::system::AllocationManager
	{

	public:

		/** Construtors */
		SystemManagerNode(ros::NodeHandle nh);
		/** Destrutor */
		~SystemManagerNode();

		/** métodos publicos relacionados ao gerenciamento do nó */
		void spin();

	private:
	
		/** atributos privados relacionados ao nó */
		ros::NodeHandle nh_;
		ros::Subscriber robot_beacon_sub_;
		ros::Subscriber user_beacon_sub_;
		ros::Timer logged_robots_update_timer_;
		ros::Timer logged_users_update_timer_;
		
		void robotBeaconCallback(const mrta_vc::Agent::ConstPtr& robot_msg);
		void userBeaconCallback(const mrta_vc::Agent::ConstPtr& user_msg);
		void loggedRobotsUpdateTimerCallback(const ros::TimerEvent& event);
		void loggedUsersUpdateTimerCallback(const ros::TimerEvent& event);

	};

}

#endif /* SYSTEM_MANAGER_NODE_H_ */
