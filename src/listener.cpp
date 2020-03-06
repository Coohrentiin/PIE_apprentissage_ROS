// %Tag(FULLTEXT)%
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>   // std::cout
#include <string>     // std::string, std::stof

struct consigne_roues
{
    float rotationDroite;
    float rotationGauche;
};


struct consigne_roues calculVitesse(float angle){
    float rayon=0.05; //rayon de la roue en mètres
    float espace_roues=0.2; //espace entre les deux roues
    float pi=3.141592;
    struct consigne_roues newConsigne;
    float n=espace_roues*angle/(4*pi*rayon);
    newConsigne.rotationDroite=n;
    newConsigne.rotationGauche=-n;
    return newConsigne;
}

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  float pi= 3.141592;
  float angle=std::stof(msg->data.c_str());
  struct consigne_roues newCons= calculVitesse(angle);
  ROS_INFO("la valeur recu est: %.2f rad, soit : %.2f° \n        rotation roue droite: %.2f, gauche %.2f ", angle, 180*angle/pi, newCons.rotationDroite, newCons.rotationGauche);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::spin();
  return 0;
}
// %EndTag(FULLTEXT)%