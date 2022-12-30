/*
 * dataForSumo.h
 *
 *  Created on: Sep 7, 2022
 *      Author: thamil
 */
#pragma once

#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#ifndef SRC_VEINS_MODULES_APPLICATION_TRACI_DATAFORSUMO_H_
#define SRC_VEINS_MODULES_APPLICATION_TRACI_DATAFORSUMO_H_

class dataForSumo {
public:
//    std::string detectors1[2][9] = {
//                 { "areaDet1W1", "areaDet1W2", "areaDet1W3","areaDet1W4","areaDet1W5","areaDet1E1","areaDet1E2" },
//                 { "areaDet2E1", "areaDet2E2", "areaDet2E3","areaDet2E4","areaDet2W1","areaDet2W2","areaDet2W3","areaDet2W4","areaDet2W5" }
//               };
    std::string valNowStr = "Hi";
    int valNow = 100;

    dataForSumo();
    virtual ~dataForSumo();
    std::string* getDetectorData(int);

};

#endif /* SRC_VEINS_MODULES_APPLICATION_TRACI_DATAFORSUMO_H_ */
