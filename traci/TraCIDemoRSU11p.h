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

#pragma once
#include<vector>
#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include "veins/modules/application/traci/dataForSumo.h"
using namespace std;
namespace veins {

/**
 * Small RSU Demo using 11p
 */
class VEINS_API TraCIDemoRSU11p : public DemoBaseApplLayer {
protected:
    TraCIScenarioManager* manager;
        std::string laneId;
        std::string trafficId;
        cMessage* initMsg;
        cMessage* phaseMsg;
        dataForSumo d;
        int dd= d.valNow;
        std::string detectors3 = d.valNowStr;
        std::string* detecArrOne = d.getDetectorData(1);
        std::string* detecArrTwo = d.getDetectorData(2);
        //extern std::string detectors1[2][9];
        std::string detectors1[2][9] = {
             { "areaDet1W1", "areaDet1W2", "areaDet1W3","areaDet1W4","areaDet1W5","areaDet1E1","areaDet1E2" },
             { "areaDet2E1", "areaDet2E2", "areaDet2E3","areaDet2E4","areaDet2W1","areaDet2W2","areaDet2W3","areaDet2W4","areaDet2W5" }
           };
        std::string detectors2[2][5] = {
                   { "areaDet1W1", "areaDet1W2", "areaDet1W3","areaDet1W4","areaDet1W5" },
                   { "areaDet2E1", "areaDet2E2", "areaDet2E3","areaDet2E4" }
                 };
    void onBSM(DemoSafetyMessage* bsm) override;
    void onWSM(BaseFrame1609_4* wsm) override;
    void onWSA(DemoServiceAdvertisment* wsa) override;
    void handleSelfMsg(cMessage* msg)override;
    bool showNow(int[],int[], int);
    bool showNow1(int[],int[], int);

    bool Check_Atomic_Proposition(int,int,float);
    bool* EvaluateEpisetmicQuery(int,int[],int[],float[]);
    int getWaitingVehciles(int ,std::string );

    vector<bool> EpistemicLogicChecking(vector<vector<int>> ,vector<float> ,char  );
    bool untilSatisfied(vector<bool> ,int , int );
    bool checkNextOperator(vector<vector<int>> , int , int ,int  );
    void runTrafficSignal(string pgmId,int numOfJunctions);

};

} // namespace veins
