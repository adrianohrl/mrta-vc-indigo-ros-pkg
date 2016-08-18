/**
 *  Desk.h
 *
 *  Version: 1.2.2
 *  Created on: 04/04/2016
 *  Modified on: 17/08/2016
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@unifei.edu.br)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "unifei/expertinos/mrta_vc/places/Desk.h"

/**
 *
 */
unifei::expertinos::mrta_vc::places::Desk::Desk(int id, std::string name, unifei::expertinos::mrta_vc::places::Office office, geometry_msgs::Polygon boundary, double x, double y, double theta) : unifei::expertinos::mrta_vc::places::Place(id, name, boundary, x, y, theta), office_(office)
{
}

/**
 *
 */
unifei::expertinos::mrta_vc::places::Desk::Desk(int id, std::string name, unifei::expertinos::mrta_vc::places::Office office, geometry_msgs::Polygon boundary, geometry_msgs::Pose pose_msg) : unifei::expertinos::mrta_vc::places::Place(id, name, boundary, pose_msg), office_(office)
{
}

/**
 *
 */
unifei::expertinos::mrta_vc::places::Desk::Desk(const mas_msgs::Place::ConstPtr& desk_msg) : unifei::expertinos::mrta_vc::places::Place(desk_msg), office_(mas_msgs::Place()) //desk_(desk_msg->parent) 
{
	// verificar se tem o office 
}

/**
 *
 */
unifei::expertinos::mrta_vc::places::Desk::Desk(mas_msgs::Place desk_msg) : unifei::expertinos::mrta_vc::places::Place(desk_msg), office_(mas_msgs::Place()) //desk_(desk_msg.parent) 
{
	// verificar se tem o office
}

/**
 *
 */
unifei::expertinos::mrta_vc::places::Desk::~Desk() 
{
}

/**
 *
 */
int unifei::expertinos::mrta_vc::places::Desk::getType() 
{
	return DESK;
}

/**
 *
 */
unifei::expertinos::mrta_vc::places::Office unifei::expertinos::mrta_vc::places::Desk::getOffice() 
{
	return office_;
}


/**
 *
 */
mas_msgs::Place unifei::expertinos::mrta_vc::places::Desk::toMsg() 
{
	mas_msgs::Place office_msg = Place::toMsg();
	//office_msg.office = office_.toMsg();
	return office_msg;
}

/**
 *
 */
void unifei::expertinos::mrta_vc::places::Desk::operator=(const unifei::expertinos::mrta_vc::places::Desk& desk)
{
	unifei::expertinos::mrta_vc::places::Place::operator=(desk);
	office_ = desk.office_;
}