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

#include "veins/modules/application/traci/TraCIDemoRSU11p.h"

#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"



#include <filesystem>
#include<vector>
using namespace veins;


Define_Module(veins::TraCIDemoRSU11p);
static int countNextQuerySatisfied;
static int countUntilQuerySatisfied;
static int cuqs;
bool stopSimulation = false;
int cur_flow[] = {0,0};
int prev_flow[] = {0,0};
int maxTime = 1400;
int tau_1 = 800;
int tau_2 = 500;
string tf = "M"; // prob 0.9
int tth = 80;
vector<int> th1 ={tth, tth, tth, tth}; // tau_1
vector<int> th2 = {tth, tth, tth, tth}; //tau_2
int messageGap = 10;
int isUntilSatisfied = false;
bool queryStatus = false;
bool curRunSatisfied = false;
int untilTime = 0;
int queryTime = 0;
bool writeOver = false;
//bool isUntilSatisfied = false;
bool checkThreshold = false;
int  cur_trafficLoad[300][2]={};
int arrInc = 0;


vector<bool> TraCIDemoRSU11p::EpistemicLogicChecking(vector<vector<int>> trafInfo, vector<float> randomMsgDrop,char nextOrNot ){

   vector<bool> ap;

    vector<vector<int>> atpQry;
     //vector<vector<int>> vec;
    atpQry = {
            {1,2,3,4},
            {1,1,1,1} // 0 means 1st intersection
    };

    int row = atpQry[1].size();
//    cout<<"row "<<row<<endl;

    for(int i = 0; i<row; i++)
    {

           int dst = atpQry[1][i];
//           cout<<"dst "<<dst<<endl;

            float genRand = (float) rand()/RAND_MAX;

            if(genRand > randomMsgDrop[i])
            {
                ap.push_back(false);
                    //cout<<"here i set:atp[i][j] "<<atp[i][j]<<endl;
            }
            else
            {
                   if(nextOrNot == 'N')
                   {

                           if(trafInfo[0][dst] >= trafInfo[1][dst] )
                           {
                               //cout<<"I am here now"<<endl;
                               //cout<<"N : if "<<dst<<trafInfo[0][dst]<<trafInfo[1][dst]<<endl;
                               ap.push_back(true);
                           }
                           else
                           {
                               //cout<<"here now for false"<<endl;
                               //cout<<"N : else"<<dst<<trafInfo[0][dst]<<trafInfo[1][dst]<<endl;

                               ap.push_back(false);
                           }
                    }
                    else
                    {


                        if(trafInfo[0][dst] <= trafInfo[2][dst] )
                        {
                            //cout<<"Y : if "<<dst<<trafInfo[0][dst]<<trafInfo[1][dst]<<endl;
                            ap.push_back(true);
                        }
                        else
                        {
                            //cout<<"Y : else"<<dst<<trafInfo[0][dst]<<trafInfo[1][dst]<<endl;
                            //cout<<"here now for false"<<endl;
                            ap.push_back(false);
                        }


                    }
            }
    }

    return ap;
}

bool TraCIDemoRSU11p::untilSatisfied(vector<bool> knowAtp, int cur_time, int tau_1){

    bool isQuerySatisfied = true;

    if(isUntilSatisfied == false)
     {
       // if(convTime >= (time_k1 + time_k2))
            // std::cout<<"If At next time step : Current flow : "<<curr_flow[0]<<"  "<<curr_flow[1]<<endl;

        if(cur_time >  tau_1)
            return  isUntilSatisfied;

         //bool isQuerySatisfied = true;

         for(int i=0; i< knowAtp.size();i++)
            {
                  if(knowAtp[i] == false)
                  {
                      //isUntilSatisfied = false;
                      isQuerySatisfied = false;
                        break;
                  }
            }

         if((isQuerySatisfied) and (!isUntilSatisfied))
         {
                  countUntilQuerySatisfied = countUntilQuerySatisfied +1;
                  cuqs = cuqs +1;
                  isUntilSatisfied = true;
                  //curRunSatisfied = true;
                  untilTime = cur_time;
                  //std::cout<<"Satisfied Current flow.."<<curr_flow[0]<<"  "<<curr_flow[1]<<endl;
                  std::cout<<"\n Until Satisfied............"<<countUntilQuerySatisfied<<"......\n Until Satisfied ..............\n Until Satisfied .................."<<cur_time<<endl;
         }
       }

    return isUntilSatisfied;
}

bool TraCIDemoRSU11p::checkNextOperator(vector<vector<int>> trafInfo, int cur_time, int tau_2, int untilTime)
{
    bool allFalse = true;
    vector<bool> atpBool;

    vector<float> randomMsgDrop{1,0.99,0.9,1};

   atpBool = EpistemicLogicChecking(trafInfo,randomMsgDrop,'Y');

   if((untilTime + tau_2) == cur_time)
   {

       for(int j=0;j<atpBool.size();j++)
       {
           //cout<<"I am executing now  "<<atpBool[0][j]<<endl;
           if(atpBool[j] == false)
           {
                allFalse = false;
           }
       }

       if(allFalse and (!stopSimulation))
       {
                    countNextQuerySatisfied = countNextQuerySatisfied + 1;
                    //std::cout<<"\n Query Satisfied..................\n Query Satisfied ..............\n Query Satisfied .................."<<countNextQuerySatisfied<<endl;
                     queryTime = cur_time;
                    stopSimulation  = true;
       }
   }
       return stopSimulation;
}



void TraCIDemoRSU11p::onWSA(DemoServiceAdvertisment* wsa)
{
    // if this RSU receives a WSA for service 42, it will tune to the chan
    if (wsa->getPsid() == 42) {
        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
        EV <<"I am in onWSA inside if loop in TraCIDemoRSU11"<<endl;
    }
    EV <<"I am in onWSA outside if loop in TraCIDemoRSU11"<<endl;
}
void TraCIDemoRSU11p::onBSM(DemoSafetyMessage* bsm)
{

EV<< "I am receiving the BSM message in the RSU part....... "<<std::endl;
}
void TraCIDemoRSU11p::onWSM(BaseFrame1609_4* frame)
{
    TraCIDemo11pMessage* wsm = check_and_cast<TraCIDemo11pMessage*>(frame);

    // this rsu repeats the received traffic update in 2 seconds plus some random delay
    sendDelayedDown(wsm->dup(), 4 + uniform(0.01, 0.2));
    EV <<"I am in onWSM in TraCIDemoRSU11"<<endl;
}

int TraCIDemoRSU11p::getWaitingVehciles(int intersectionID,std::string direction){
    int waitingVehicles = 0;
    std::string* detecArrStr;
    detecArrStr = d.getDetectorData(intersectionID);
    if(direction == "W"){
        for(int i=0;i<3;i++){
            waitingVehicles = waitingVehicles + traci->laneAreaDetector(detecArrStr[i]).getJamLengthVehicle();
        }
    }
    else if(direction == "S"){
        for(int i=3;i<6;i++){
                   waitingVehicles = waitingVehicles + traci->laneAreaDetector(detecArrStr[i]).getJamLengthVehicle();
               }
    }
    else if(direction == "N"){
            for(int i=6;i<9;i++){
                       waitingVehicles = waitingVehicles + traci->laneAreaDetector(detecArrStr[i]).getJamLengthVehicle();
                   }
        }
    else if(direction == "E"){
            for(int i=9;i<12;i++){
                       waitingVehicles = waitingVehicles + traci->laneAreaDetector(detecArrStr[i]).getJamLengthVehicle();
                   }
        }
    else{
        std::cout<<"enter valid flow "<<endl;

    }
 return waitingVehicles;
}

void TraCIDemoRSU11p::runTrafficSignal(string pgmId,int numOfJunctions){
    manager = TraCIScenarioManagerAccess().get();
    traci = manager->getCommandInterface();
    if(numOfJunctions == 2){
        traci->trafficlight("B4").setProgram(pgmId);
        traci->trafficlight("C4").setProgram(pgmId);
    }
    if(numOfJunctions == 3){
        traci->trafficlight("B4").setProgram(pgmId);
        traci->trafficlight("C4").setProgram(pgmId);
        traci->trafficlight("D4").setProgram(pgmId);
       }
    if(numOfJunctions == 4){
            traci->trafficlight("B4").setProgram(pgmId);
            traci->trafficlight("C4").setProgram(pgmId);
            traci->trafficlight("B3").setProgram(pgmId);
            traci->trafficlight("C3").setProgram(pgmId);
           }
}
void TraCIDemoRSU11p::handleSelfMsg(cMessage* msg)
{



    manager = TraCIScenarioManagerAccess().get();
                traci = manager->getCommandInterface();
                laneId = "areaDet1";
                trafficId = "B4";
                int phi11 = 0;
                int phi2 = 0;
                int phi3 = 0;
                int phi4 = 0;

//                showNow(10);
               vector<vector<int>> trafInfo;
               double currTime = simTime().dbl();
               int convTime = (int) currTime;

//    int threshold_1 [] = {24,20};
//    std::cout <<"I am in getting values from another class"<<detecArrOne[0]<<endl;
//    std::cout <<"I am in getting values from another class"<<detecArrOne[1]<<endl;
//    std::cout <<"I am in getting values from another class"<<detecArrTwo[0]<<endl;
//        std::cout <<"I am in getting values from another class"<<detecArrTwo[1]<<endl;
//
////    int prev_flow[] = {phi1,phi2};
//                int vhw = traci->laneAreaDetector(detectors1[0][1]).getJamLengthVehicle();
////     std::cout<<"Halting vehicles:         "<<vhw<<endl;
//    // ----------------------------- GET THE DETECTOR VALUES -------------------------------------------
//
//    int phi1 = traci->laneAreaDetector(detectors1[0][0]).getJamLengthVehicle()+traci->laneAreaDetector(detectors1[0][1]).getJamLengthVehicle()
//            +traci->laneAreaDetector(detectors1[0][2]).getJamLengthVehicle()+traci->laneAreaDetector(detectors1[0][3]).getJamLengthVehicle()
//            +traci->laneAreaDetector(detectors1[0][4]).getJamLengthVehicle() + traci->laneAreaDetector(detectors1[0][5]).getJamLengthVehicle()+traci->laneAreaDetector(detectors1[0][6]).getJamLengthVehicle();
//    std::cout<<"phi 1 from current: "<<phi1<<endl;
//
                vector<int> currentFlow;
    if(convTime >2){
     phi11 = getWaitingVehciles(1,"W")+getWaitingVehciles(1,"E");
     phi2 = getWaitingVehciles(2,"W") + getWaitingVehciles(2,"E");
     phi3 = getWaitingVehciles(5,"W") + getWaitingVehciles(5,"E");
     phi4 = getWaitingVehciles(6,"W") + getWaitingVehciles(6,"E");
    }
//    std::cout<<"phi1: "<<phi11<<endl;
//    std::cout<<"phi2: "<<phi2<<endl;
//    std::cout<<"phi3: "<<phi3<<endl;
//    std::cout<<"phi4: "<<phi4<<endl;
   // std::cout<<"The probability of until query satisfied is:"<<countUntilQuerySatisfied<<"   "<< cuqs<<endl;
    currentFlow.push_back(phi11);
    currentFlow.push_back(phi2);
    currentFlow.push_back(phi3);
    currentFlow.push_back(phi4);
            trafInfo.push_back(currentFlow);

            trafInfo.push_back(th1);
            trafInfo.push_back(th2);
            for(int i=0;i<1;i++){
                cout<<"-----------------------------------"<<endl;
                for(int j=0;j<trafInfo[i].size();j++){

                    cout<<"phi:"<<j+1<<"  "<<trafInfo[i][j]<<endl;

                }
            }
            cur_trafficLoad[arrInc][0] = phi11;
                        cur_trafficLoad[arrInc][1] = phi2;
                        if(arrInc == 300){
                            arrInc = 0;
                        }
                        else{arrInc = arrInc + 1;}


//    std::cout<<"phi 1 from updated: "<<phi11<<endl;
//    int phi2 = traci->laneAreaDetector(detectors1[1][0]).getJamLengthVehicle()+traci->laneAreaDetector(detectors1[1][1]).getJamLengthVehicle()
//            +traci->laneAreaDetector(detectors1[1][2]).getJamLengthVehicle()+traci->laneAreaDetector(detectors1[1][3]).getJamLengthVehicle()
//            +traci->laneAreaDetector(detectors1[1][4]).getJamLengthVehicle()+traci->laneAreaDetector(detectors1[1][5]).getJamLengthVehicle()
//            +traci->laneAreaDetector(detectors1[1][6]).getJamLengthVehicle()+traci->laneAreaDetector(detectors1[1][7]).getJamLengthVehicle()
//            +traci->laneAreaDetector(detectors1[1][8]).getJamLengthVehicle();
//
////    std::cout<<"Detector values phi 1 now:"<<phi1<<endl;
//   // std::cout<<"Detector values phi 2 now:"<<phi2<<endl;
//    for(int i=0;i<2;i++)
//        prev_flow[i] = cur_flow[i];
////    prev_flow = cur_flow;
//    cur_flow[0] = phi1;
//    cur_flow[1] = phi2;
////    std::cout<<"Previous flow: ";
////    for(int i=0;i<2;i++)
////    {
////        std::cout<<prev_flow[i]<<"  ";
////    }
////    std::cout<<endl;
////    std::cout<<"current flow: ";
////    for(int i=0;i<2;i++)
////    {
////        std::cout<<cur_flow[i]<<"  ";
////    }
////       std::cout<<endl;
//   cur_flow[0] = phi1;cur_flow[1] = phi2;
//
//
////    std::cout<<"Current Query Status is:"<<queryStatus<<endl;
//
//    if(stopSimulation == false){
//        //int cf[] = {15,15};
//        //int pf[] ={50,50};
//       // bool queryStatus = showNow(cf,pf);

//
//        if(convTime%2 == 0)
//        {
//            //std::cout<<"Time now:"<<convTime<<endl;
//            std::string pgmId = "2";
//            //std::cout<<"----------------------------------------------------------------------- showNow is called ---------------------------"<<endl;
//            //queryStatus = showNow1(cur_flow,prev_flow, convTime);
//            queryStatus = check_Knowledge_Operator(cur_flow,threshold_1, convTime);
//            if(!curRunSatisfied){
//                //std::cout<<"Program Id ------ 1 ------------"<<endl;
//                traci->trafficlight("cluster_20a_20b_20c_39_39a_40_41_42").setProgram(pgmId);
//                traci->trafficlight("210").setProgram(pgmId);
//                messageGap = 10;
//            }
//            else{
//               // std::cout<<"Program Id  ------ 2 ------------"<<endl;
//                traci->trafficlight("cluster_20a_20b_20c_39_39a_40_41_42").setProgram("1");
//                traci->trafficlight("210").setProgram("1");
//                messageGap = 10;
//            }
//        }
//
//        if(convTime <=20 and convTime >=8 ){
//                    //std::cout<<"Hi -----------------------------------"<<endl;
//                    cSimulation::getActiveSimulation()->setSimulationTimeLimit (maxTime);
//                    //system("python3 chooseRandomRoute.py");
//        }
//
//    }
//
//
////    if(simTime()>380)
////    {
////       //std::cout<<"Time now:"<<simTime()::<<endl;
////
////        std::cout<<"The probability of query satisfied is:"<<countNextQuerySatisfied<<endl;
////    }
//
    if(simTime() > (maxTime - messageGap))
    {
        isUntilSatisfied = false;
      //  isQuerySatisfied = false;
        stopSimulation = false;
        curRunSatisfied = false;
        writeOver = false;
        queryTime = 0;
        untilTime = 0;

        //std::cout<<"The probability of query satisfied is:"<<countNextQuerySatisfied<<endl;
        //std::cout<<cSimulation::getActiveSimulation()::SimTime();
        std::cout<<"------------------------------------------"<<endl;
        std::cout<<"The probability of until query satisfied is:"<<cuqs<<endl;
        std::cout<<"The probability of next query satisfied is:"<<countNextQuerySatisfied<<endl;
        for(int i = 0;i<300;i++){
                             cout<<","<<cur_trafficLoad[i][0] << " "<<cur_trafficLoad[i][1]<<",";
                         }
        std::cout<<"------------------------------------------"<<endl;
    }

    if(simTime() >= (maxTime - messageGap)){
        if(!writeOver){
                cSimulation::getActiveSimulation()->setSimulationTimeLimit (maxTime);
                system("python3 generateRouteRandomGroup.py");
                writeOver = true;
                std::cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
                }

    }


                   int cur_time = convTime;

                   bool nextOpt = false;
                   vector<bool> atpBool;
                   vector<float> randomMsgDrop{0.9,0.9,0.9,0.9};
//                   int cur_time = 40;
//                   int tau_1 = 80;
//                   int tau_2 = 30;
//                   vector<vector<int>> trafInfo1
//                                    {
//                                        {24, 26,28,34},
//                                        {23, 25, 27,33},
//                                        {27, 28, 29,23}
//                                    };
                   atpBool = EpistemicLogicChecking(trafInfo,randomMsgDrop,'N');

//                   cout<<"apt 0: "<<atpBool[0]<<endl;
//                   cout<<"apt 1: "<<atpBool[1]<<endl;

                   isUntilSatisfied = untilSatisfied(atpBool,cur_time,tau_1);
//                   cout<<"isUntilSatisfied: "<<isUntilSatisfied<<endl;

                   if(isUntilSatisfied)
                   {
                       std::cout<<"The probability of until query satisfied is:"<<countUntilQuerySatisfied<<endl;

                       runTrafficSignal(tf,4);
                       cout<<"Traffic Policy is: "<<tf<<endl;
                       nextOpt = checkNextOperator(trafInfo,cur_time,tau_2,untilTime);

//                       cout<<"checkNextOperator: "<<nextOpt<<endl;
                   }
                   else{
                       runTrafficSignal("N",4);
                   }
//                   cout<<"untilTime : "<<untilTime<<endl;
//                   cout<<"query time: "<<queryTime<<endl;


//                   cout<<"checkNextOperator: "<<nextOpt<<endl;
//                   for(int k=0;k<atpBool.size();k++)
//                    {
//                        for(int k1 = 0; k1<atpBool[k].size();k1++)
//                        {
//                           cout<<" "<<atpBool[k][k1];
//                        }
//                        cout<<endl;
//                    }
                   //std::cout << "Hello world!";



    DemoSafetyMessage* bsm = new DemoSafetyMessage();
    int g = getId();
    EV <<"ID now is:"<<g<<endl;
    if(g==15){
            populateWSM(bsm);
            sendDown(bsm);
//            traci->trafficlight(trafficId).setProgram("1");
//            std::cout <<"I have set program to 0 now on traffic light TraCIDemoRSU11"<<endl;
            scheduleAt(simTime() + messageGap, sendBeaconEvt);
            }
    if(g==10){
                populateWSM(bsm);
                sendDown(bsm);
//                traci->trafficlight(trafficId).setProgram("2");
//                std::cout <<"I have set program to 1 now on traffic light TraCIDemoRSU11"<<endl;
                scheduleAt(simTime() + messageGap, sendBeaconEvt);
                }

}
