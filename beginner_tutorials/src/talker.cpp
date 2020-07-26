#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <ctime>
using namespace std;

#include <ros/ros.h>
#include <std_msgs/Int32.h>


int randNum(){
    int alpha = rand()%1000;
    printf("\nNumero: %d", alpha);
    printf("\n");

    return alpha;
}


int main(int argc, char **argv)
{
    //Inicializa el nodo con nombre [sleeptover_five]
    ros::init(argc, argv, "sleeptover_five");
    
    //inicia el nodo
    ros::NodeHandle nh;
    
    // Crea el publisher y le decimos que tipos de datos va a manejar y el topic al que lo enviamos y la cantidad
    ros::Publisher dataPublisher = nh.advertise<std_msgs::Int32>("rand_number", 10);
    
    // Create a rate
    ros::Rate rate(10);


    // inside the main function of the program
    while (ros::ok())
    {
        std_msgs::Int32 msg;
        msg.data = randNum();
        dataPublisher.publish(msg);
        rate.sleep();
        sleep(10);
    }
}


/*

  do{
       sleep(300);
      cout<<"han pasado 5 minutos..."<<endl;
  }while(true);
  
=====================================================

    int num;        //store random number
 
    randomize();    //call it once to generate random number
    for(i=1;i<=10;i++)
    {
        num=rand()%100; //get random number
        cout << num << "\t";


*/
