#include <KinectFramework.h>


//void KFLocationController::drawController()
//{
//	joystickView.setTo(0);
//	joystickView.setTo(0);
//
//	for(int i=0;i<3;i++)
//		for(int j=0;j<3;j++)
//			cv::rectangle(joystickView,cv::Rect(i*220,j*160,220,160),cv::Scalar(255,155,0));
//	//cv::rectangle(joystickView,cv::Rect(320-50/2,240-50/2,50,50),cv::Scalar(255,155,0));
//	cv::circle(joystickView,cv::Point(320-20/2-xOffset,240-20/2-zOffset),20,cv::Scalar(0,60,60),3);
//
//}
void KFLocationController::processUserGestures()
{
	if(!bothHandsUp){
		cv::Point3f lHand = getJointPos(currentSkelReal, XN_SKEL_LEFT_HAND);
		cv::Point3f rHand = getJointPos(currentSkelReal, XN_SKEL_RIGHT_HAND);
		cv::Point3f neck = getJointPos(currentSkelReal, XN_SKEL_NECK);
		if(lHand.y > neck.y && rHand.y > neck.y){
		bothHandsUp=true;
		}
		//cout <<"left hand is " <<lHand.y <<"\n";
		//cout <<"neck is " << neck.y <<"\n";
	}
	torsoPt = getJointPos(currentSkelReal, XN_SKEL_TORSO);
	if(!startPosition && bothHandsUp){
		initialPosition = torsoPt;
		startPosition=true;
	}

	if(startPosition){
	zMovement = (torsoPt.z - initialPosition.z)/-3;
	xMovement = (torsoPt.x - initialPosition.x)/3;
	}
	//cout << "Torso is : " <<torsoPt.x <<"\n";
	//cout << "initial is : " <<initialPosition.x <<"\n";
	std::ostringstream strs;
	strs << "Offse is: ";
	strs << zOffset;
	strs << " ";
	strs << xOffset;
	strs << " ";
	std::string str = strs.str();

	//std::cout << str << "\n";

}

void KFLocationController::calculateHumanLength(std::map<XnSkeletonJoint, XnSkeletonJointPosition> skel){
	torsoPt = getJointPos(currentSkelReal, XN_SKEL_TORSO);
	//cv::Point3d neckPt = getJointPos(skel, XN_SKEL_NECK);
	//cv::Point3d  shoulderPt = getJointPos(skel, XN_SKEL_RIGHT_SHOULDER);
	//cv::Point3d  handPt = getJointPos(skel, XN_SKEL_RIGHT_HAND); 
	//cv::Point3d  elbowPt = getJointPos(skel, XN_SKEL_RIGHT_ELBOW);

	//neckLength = distApart(neckPt, shoulderPt);    // neck to shoulder length
	//armLength = distApart(handPt, shoulderPt);     // hand to shoulder length
	//lowerArmLength = distApart(handPt, elbowPt);    // hand to elbow length


}

