//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

//#include "vehicleControlApp.h"

//vehicleControlApp::vehicleControlApp() {
//    // TODO Auto-generated constructor stub
//
//}
//
//vehicleControlApp::~vehicleControlApp() {
//    // TODO Auto-generated destructor stub
//}

//
// Copyright (C) 2016 David Eckhoff <david.eckhoff@fau.de>
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

#include "veins/modules/application/traci/vehicleControlApp.h"

using namespace veins;

Define_Module(veins::vehicleControlApp);
//bool hasStoppedVC=false;
//int subscribedServiceId;
//int currentOfferedServiceId = 7;
//int wsaInterval = 5;
//double beaconInterval = 0.1;
void vehicleControlApp::initialize(int stage)
{

    DemoBaseApplLayer::initialize(stage);
//    if (stage == 0) {
//        // Initializing members and pointers of your application goes here
//        EV << "Initializing " << par("appName").stringValue() << std::endl;
//        mobility = TraCIMobilityAccess().get(getParentModule());
//        traciVehicle = mobility->getVehicleCommandInterface();
//        //findHost()->subscribe(mobilityStateChangedSignal, this);
//        subscribedServiceId = -1;
//        currentOfferedServiceId = 7;
//        wsaInterval = 5;
//        beaconInterval = 0.1;
//    }
//    else if (stage == 1) {
//        int idDebug = getId();
//        // Initializing members that require initialized other modules goes here
//        if (getId() == 14){
//        // this is the head vehicle
//        startService(Channel::sch2, currentOfferedServiceId, "Platoon Lead Vehicle Service");
//        //scheduleAt()
//        scheduleAt(computeAsynchronousSendingTime(beaconInterval, ChannelType::control),sendBeaconEvt);
//        }
//    }
}

void vehicleControlApp::finish()
{
    DemoBaseApplLayer::finish();
    // statistics recording goes here
}

void vehicleControlApp::onBSM(DemoSafetyMessage* bsm)
{
    // Your application has received a beacon message from another car or RSU
    // code for handling the message goes here

//    if(hasStoppedVC == false){
//        traciVehicle->setSpeedMode(0x1f);
//        traciVehicle->setSpeed(0);
//        hasStoppedVC = true;
//
//    }
//    else{
//        traciVehicle->setSpeedMode(0x1f);
//        traciVehicle->setSpeed(20);
//        hasStoppedVC = false;
//
//    }


}

void vehicleControlApp::onWSM(BaseFrame1609_4* wsm)
{
    // Your application has received a data message from another car or RSU
    // code for handling the message goes here, see TraciDemo11p.cc for examples
}

void vehicleControlApp::onWSA(DemoServiceAdvertisment* wsa)
{
    // Your application has received a service advertisement from another car or RSU
    // code for handling the message goes here, see TraciDemo11p.cc for examples
}

void vehicleControlApp::handleSelfMsg(cMessage* msg)
{
    DemoBaseApplLayer::handleSelfMsg(msg);
    // this method is for self messages (mostly timers)
    // it is important to call the DemoBaseApplLayer function for BSM and WSM transmission
}

void vehicleControlApp::handlePositionUpdate(cObject* obj)
{
    DemoBaseApplLayer::handlePositionUpdate(obj);
    if ( this->getId() == 14 ){
    const simtime_t t = simTime();
    if ( t == 10 ) {
    traciVehicle->setSpeedMode(0x1f);
    traciVehicle->setSpeed(0);
    }
    else if ( t == 20 ) {
    traciVehicle->setSpeedMode(0x1f);
    traciVehicle->setSpeed(20);
    }
    }
    // the vehicle has moved. Code that reacts to new positions goes here.
    // member variables such as currentPosition and currentSpeed are updated in the parent class
}
