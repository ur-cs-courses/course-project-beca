#ifndef HPPFILES_SYSTEM_HPP
#define HPPFILES_SYSTEM_HPP
#include "robot.hpp"
#include "room.hpp"
#include "mopper.hpp"
#include "scrubber.hpp"
#include <string>
#include "vacuum.hpp" 
#include <vector>
#include <map>
#include <future>
#include <fstream>

using namespace std;
namespace cleaningSys
{
    class cleaningSystem {
        private:
        std::map<int, Robot*> robots;
        std::map<int, Room> rooms;
        vector<future<void>> futures;
        int roomCounter = 0;
        int robotCounter = 0;
        string logFilename;

        public:
        cleaningSystem();
        ~cleaningSystem();
        vector<string> queryRobotStatus(vector<int> listRobots);
        vector<string> queryRobotStatus();//overload function that will query status of ALL robots
        vector<string> queryRoomStatus(vector<int> listRooms);
        vector<string> queryRoomStatus();//overload function that will query status of ALL rooms
        inline int getRoomCount() {return roomCounter;}
        inline int getRobotCount() {return robotCounter;}
        void clean(int room,vector<int> listRobots);
        void repair(vector<int> botIds);
        void recharge(vector<int> botIds);
        void cleanAsync(vector<int> listRobots, int cleaningTime, int roomID);
        void loggerSetup(string filename);
        void log();
        bool validateRobotIDs(vector<int> botIds);
        bool validateRoomIDs(vector<int> roomIds);
        bool validateRoomIDs(int roomID);
    };
}
#endif