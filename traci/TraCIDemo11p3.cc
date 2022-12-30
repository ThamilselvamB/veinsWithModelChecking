//
// Copyright (C) 2006-2011 Christoph Sommer <christoph.sommer@uibk.ac.at>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "veins/modules/application/traci/TraCIDemo11p3.h"

#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"


using namespace veins;

Define_Module(veins::TraCIDemo11p3);
//bool hasStoppedVC=false;
//int subscribedServiceId;
//int currentOfferedServiceId = 7;
//int wsaInterval = 5;
//double beaconInterval = 0.1;
int counter = 0;

void TraCIDemo11p3::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
//    if (stage == 0) {
//        sentMessage = false;
//        lastDroveAt = simTime();
//        currentSubscribedServiceId = -1;
//    }



//    DemoBaseApplLayer::initialize(stage);
        if (stage == 0) {
            // Initializing members and pointers of your application goes here
            EV << "Initializing " << par("appName").stringValue() << std::endl;
            EV << "Initializing is going on  "  ;
            mobility = TraCIMobilityAccess().get(getParentModule());
            //mobility1 = TraCIMobilityAccess().get(getParentModule());
            traciVehicle = mobility->getVehicleCommandInterface();
            //traciLaneAreaDetector = mobility1->getLaneAreaDetectorCommandInterface();
            //EV << "traciVehicle:"<<traciVehicle->getSpeed()<<std::endl;




//            manager = TraCIScenarioManagerAccess().get();
//
//            traci = manager->getCommandInterface();
//            laneId = "areaDet1";
//            trafficId = "traffic1";
//
//            EV << "traciLaneAreaDetector:"<<traci->laneAreaDetector(laneId).getLastStepVehicleNumber()<<std::endl;
//            EV<< "Traffic Light"<<traci->trafficlight(trafficId).setProgram("0");
            //findHost()->subscribe(mobilityStateChangedSignal, this);
 //           subscribedServiceId = -1;
            currentOfferedServiceId = 7;
            wsaInterval = 50;
            beaconInterval = 100.0;
           // counter++;
//            counterSent = 0;
//            counterReceived = 0;
        }
        else if (stage == 1) {
            int idDebug = getId();
            EV<< idDebug<< std::endl;


            manager = TraCIScenarioManagerAccess().get();
            traci = manager->getCommandInterface();
            laneId = "areaDet1W1";
            trafficId = "B4";
            initMsg = new cMessage("Traffic light init",77);
            phaseMsg = new cMessage("phase msg",88);
            //EV << "traciLaneAreaDetector:"<<traci->laneAreaDetector(laneId).getLastStepVehicleNumber()<<std::endl;

            traci->trafficlight(trafficId).setProgram("0");
            scheduleAt(simTime()+1,initMsg);
//            counterSent++;
            // Initializing members that require initialized other modules goes here
            if (getId() == 21){
            // this is the head vehicle
            EV<< "This is the head vehicle ---------- start Service"<<endl;
            startService(Channel::sch2, currentOfferedServiceId, "Platoon Lead Vehicle Service");
//            EV<< "Traffic Light"<<traci->trafficlight(trafficId).setProgram("0");
            //scheduleAt()
            //scheduleAt(computeAsynchronousSendingTime(beaconInterval, ChannelType::control),sendBeaconEvt);
            }
        }


}

void TraCIDemo11p3::onBSM(DemoSafetyMessage* bsm)
{

EV<< "I am receiving the BSM message in TraciDemo....... "<<std::endl;
//if(bsm->getKind()==21){
//    if(!phaseMsg->isScheduled()){
//        traci->trafficlight(trafficId).setProgram("1");
//        scheduleAt(simTime()+4,initMsg);
//    }
//}


}

void TraCIDemo11p3::onWSA(DemoServiceAdvertisment* wsa)
{
    EV<< "I am receiving the onWSA message....... "<<std::endl;
//    if (currentSubscribedServiceId == -1) {
//        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
//        currentSubscribedServiceId = wsa->getPsid();
//        if (currentOfferedServiceId != wsa->getPsid()) {
//            stopService();
//            startService(static_cast<Channel>(wsa->getTargetChannel()), wsa->getPsid(), "Mirrored Traffic Service");
//        }
//    }
}

void TraCIDemo11p3::onWSM(BaseFrame1609_4* frame)
{

    EV<< "I am receiving the WSM message....... "<<std::endl;

    /***
    TraCIDemo11pMessage* wsm = check_and_cast<TraCIDemo11pMessage*>(frame);

    findHost()->getDisplayString().setTagArg("i", 1, "green");

    if (mobility->getRoadId()[0] != ':') traciVehicle->changeRoute(wsm->getDemoData(), 9999);
    if (!sentMessage) {
        sentMessage = true;
        // repeat the received traffic update once in 2 seconds plus some random delay
        wsm->setSenderAddress(myId);
        wsm->setSerial(3);
        scheduleAt(simTime() + 2 + uniform(0.01, 0.2), wsm->dup());
    }

    ***/
}

void TraCIDemo11p3::showNow(int i){
//    EV<<"I am now printing showNow()"<< counterSent<<"    " <<counterReceived<<endl;
    int src [] = {1, 2}; /*This i value in K_i(Q_j)*/
    int dest [] = {2, 1}; /*This j value in K_i(Q_j)*/
    int threshold [] = {60, 70}; /*required threshold in current instance at destination*/
    int curr_flow [] = {80, 90}; /*number of vehicles in current instance at destination*/
    float randum [] = {0.1, 0.1};/*probability of sucessful packet arrival at destination*/

    int apListSize = (std::end(src) - std::begin(src));

    bool *apList = new bool(apListSize);

    apList = EvaluateEpisetmicQuery(apListSize, src, dest, threshold, curr_flow, randum);



    bool isQuerySatisfied = true;

       for (int i=0; i<apListSize; i++)
       {
        if(apList[i] == false)
            {
          isQuerySatisfied = false;
          break;
        }
       }
       EV<<"Query Is : "<<isQuerySatisfied<<endl;
}



bool TraCIDemo11p3::Check_Atomic_Proposition(int  src, int dest, int threshold, int curr_flow, float randum)
{

  srand((unsigned)time(NULL));


  /* Transistion Function of Message Transmission*/

  for(int i=0; i<2; i++)
  {
     float genRand = (float) rand()/RAND_MAX;

     //std::cout<<"random generated number at iteration "<<i<<" : "<<genRand<<endl;

     if(genRand > randum)
     {
        return false;    /*if there is a packet drop then return Ki(Qj) is false*/
     }
  }

   if(curr_flow > threshold)
   {
    return true;
   }
   else
   {
       return false;
   }
}


bool* TraCIDemo11p3::EvaluateEpisetmicQuery(int arrSize, int src [], int dest [],  int threshold [], int curr_flow [], float randum [])
{

     static bool *AP = new bool(arrSize); /* list of atomic propositions*/

     for(int i=0; i<arrSize; i++)
     {
            bool isValid = Check_Atomic_Proposition(src[i],dest[i], threshold[i], curr_flow[i], randum[i]);
            AP[i] = isValid;
     }

     return AP;
}

void TraCIDemo11p3::handleSelfMsg(cMessage* msg)
{
//    static int counterSent = 0;
//    static int counterReceived = 0;
//    counterReceived = counterReceived + 1;
//    //counter = counter + 1;
    EV<<"Simulation Time:" <<simTime()<<endl;
//    std::cout<< "I am receiving the handleSelfMsg message yes Ramesh ....... "<<counter<<"   "<<std::endl;
//    EV << "traciVehicle:"<<traciVehicle->getSpeed()<<std::endl;
//    EV << "traciLaneAreaDetector:"<<traci->laneAreaDetector(detectors1[0][0]).getLastStepVehicleNumber()<<std::endl;
//    EV << "traciLaneAreaDetector:"<<traci->laneAreaDetector(detectors1[0][1]).getLastStepVehicleNumber()<<std::endl;
//    DemoBaseApplLayer::handleSelfMsg(msg);
//
////    showNow(10);
//    switch(msg->getKind()){
//
//    case 77:
//        EV <<"I have received 77 message"<<endl;
//        manager = TraCIScenarioManagerAccess().get();
//        traci = manager->getCommandInterface();
//        switch(myId)
//        {
//        case 21:
//            trafficId = "219";
//            traci->trafficlight(trafficId).setProgram("0");
//            break;
//        case 10:
//                    trafficId = "219";
//                    traci->trafficlight(trafficId).setProgram("1");
//                    break;
//
//        default:
//            assert(0);
//            break;
//
//        }
//        break;
//     case 88:
//                            trafficId = "219";
//                            traci->trafficlight(trafficId).setProgram("1");
//                            break;
//
//                default:
//                    assert(0);
//                    break;
//
//    }
//
//    EV<< "I am receiving the handleSelfMsg message....... "<<std::endl;
////    /***
//    if (TraCIDemo11pMessage* wsm = dynamic_cast<TraCIDemo11pMessage*>(msg)) {
//        EV <<"I am in if condition of handleSelfMsg "<< std::endl;
//        // send this message on the service channel until the counter is 3 or higher.
//        // this code only runs when channel switching is enabled
//        sendDown(wsm->dup());
//        wsm->setSerial(wsm->getSerial() + 1);
//        if (wsm->getSerial() >= 3) {
//            // stop service advertisements
//            stopService();
//            delete (wsm);
//        }
//        else {
//            scheduleAt(simTime() + 1, wsm);
//        }
//    }
//    else {
//        EV <<"I am in else condition of handleSelfMsg "<< std::endl;
//        DemoBaseApplLayer::handleSelfMsg(msg);
//    }

//    ***/
}

void TraCIDemo11p3::handlePositionUpdate(cObject* obj)
{
    DemoBaseApplLayer::handlePositionUpdate(obj);


    /***
    // stopped for for at least 10s?
    if (mobility->getSpeed() < 1) {
        if (simTime() - lastDroveAt >= 10 && sentMessage == false) {
            findHost()->getDisplayString().setTagArg("i", 1, "red");
            sentMessage = true;

            TraCIDemo11pMessage* wsm = new TraCIDemo11pMessage();
            populateWSM(wsm);
            wsm->setDemoData(mobility->getRoadId().c_str());

            // host is standing still due to crash
            if (dataOnSch) {
                startService(Channel::sch2, 42, "Traffic Information Service");
                // started service and server advertising, schedule message to self to send later
                scheduleAt(computeAsynchronousSendingTime(1, ChannelType::service), wsm);
            }
            else {
                // send right away on CCH, because channel switching is disabled
                sendDown(wsm);
            }
        }
    }
    else {
        lastDroveAt = simTime();
    }
    ***/
//    if ( this->getId() == 21 ){
//    const simtime_t t = simTime();
//    if ( t == 10 ) {
//    traciVehicle->setSpeedMode(0x1f);
//    traciVehicle->setSpeed(0);
//    }
//    else if ( t == 20 ) {
//    traciVehicle->setSpeedMode(0x1f);
//    traciVehicle->setSpeed(20);
//    }
//    }
}


