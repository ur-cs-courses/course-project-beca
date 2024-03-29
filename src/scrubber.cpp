#include "hppfiles/scrubber.hpp"
#include <iostream>

Scrubber::Scrubber(RobotSize robotSize, int robotId) : Robot(RobotType::SCRUBBER, robotSize, robotId) {}

void Scrubber::performTask() { // This should clean the room, but we do not have Room class yet, so this will be changed
    std::cout << "Robot " << robotId << " is scrubbing the floor." << std::endl; // for now just print that it is doing its task
}