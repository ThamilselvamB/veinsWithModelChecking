/*
 * dataForSumo.cpp
 *
 *  Created on: Sep 7, 2022
 *      Author: thamil
 */

#include <veins/modules/application/traci/dataForSumo.h>
std::string detIntOneEW[7] = {"areaDet1W1", "areaDet1W2", "areaDet1W3","areaDet1W4","areaDet1W5","areaDet1E1","areaDet1E2"};
std::string detIntTwoEW[9] = {"areaDet2E1", "areaDet2E2", "areaDet2E3","areaDet2E4","areaDet2W1","areaDet2W2","areaDet2W3","areaDet2W4","areaDet2W5"};


std::string InDecData_1[12] = {"A4B4_0", "A4B4_1", "A4B4_2", "B3B4_0", "B3B4_1", "B3B4_2", "B5B4_0", "B5B4_1", "B5B4_2", "C4B4_0", "C4B4_1", "C4B4_2"};
std::string InDecData_2[12] = {"B4C4_0", "B4C4_1", "B4C4_2", "C3C4_0", "C3C4_1", "C3C4_2", "C5C4_0", "C5C4_1", "C5C4_2", "D4C4_0", "D4C4_1", "D4C4_2"};
std::string InDecData_3[12] = {"C4D4_0", "C4D4_1", "C4D4_2", "D3D4_0", "D3D4_1", "D3D4_2", "D5D4_0", "D5D4_1", "D5D4_2", "E4D4_0", "E4D4_1", "E4D4_2"};
std::string InDecData_4[12] = {"D4E4_0", "D4E4_1", "D4E4_2", "E3E4_0", "E3E4_1", "E3E4_2", "E5E4_0", "E5E4_1", "E5E4_2", "F4E4_0", "F4E4_1", "F4E4_2"};

std::string InDecData_5[12] = {"A3B3_0", "A3B3_1", "A3B3_2", "B2B3_0", "B2B3_1", "B2B3_2", "B4B3_0", "B4B3_1", "B4B3_2", "C3B3_0", "C3B3_1", "C3B3_2"};
std::string InDecData_6[12] = {"B3C3_0", "B3C3_1", "B3C3_2", "C2C3_0", "C2C3_1", "C2C3_2", "C4C3_0", "C4C3_1", "C4C3_2", "D3C3_0", "D3C3_1", "D3C3_2"};
std::string InDecData_7[12] = {"C3D3_0", "C3D3_1", "C3D3_2", "D2D3_0", "D2D3_1", "D2D3_2", "D4D3_0", "D4D3_1", "D4D3_2", "E3D3_0", "E3D3_1", "E3D3_2"};
std::string InDecData_8[12] = {"D3E3_0", "D3E3_1", "D3E3_2", "E2E3_0", "E2E3_1", "E2E3_2", "E4E3_0", "E4E3_1", "E4E3_2", "F3E3_0", "F3E3_1", "F3E3_2"};

std::string InDecData_9[12] = {"A2B2_0", "A2B2_1", "A2B2_2", "B1B2_0", "B1B2_1", "B1B2_2", "B3B2_0", "B3B2_1", "B3B2_2", "C2B2_0", "C2B2_1", "C2B2_2"};
std::string InDecData_10[12] = {"B2C2_0", "B2C2_1", "B2C2_2", "C1C2_0", "C1C2_1", "C1C2_2", "C3C2_0", "C3C2_1", "C3C2_2", "D2C2_0", "D2C2_1", "D2C2_2"};
std::string InDecData_11[12] = {"C2D2_0", "C2D2_1", "C2D2_2", "D1D2_0", "D1D2_1", "D1D2_2", "D3D2_0", "D3D2_1", "D3D2_2", "E2D2_0", "E2D2_1", "E2D2_2"};
std::string InDecData_12[12] = {"D2E2_0", "D2E2_1", "D2E2_2", "E1E2_0", "E1E2_1", "E1E2_2", "E3E2_0", "E3E2_1", "E3E2_2", "F2E2_0", "F2E2_1", "F2E2_2"};

std::string InDecData_13[12] = {"A1B1_0", "A1B1_1", "A1B1_2", "B0B1_0", "B0B1_1", "B0B1_2", "B2B1_0", "B2B1_1", "B2B1_2", "C1B1_0", "C1B1_1", "C1B1_2"};
std::string InDecData_14[12] = {"B1C1_0", "B1C1_1", "B1C1_2", "C0C1_0", "C0C1_1", "C0C1_2", "C2C1_0", "C2C1_1", "C2C1_2", "D1C1_0", "D1C1_1", "D1C1_2"};
std::string InDecData_15[12] = {"C1D1_0", "C1D1_1", "C1D1_2", "D0D1_0", "D0D1_1", "D0D1_2", "D2D1_0", "D2D1_1", "D2D1_2", "E1D1_0", "E1D1_1", "E1D1_2"};
std::string InDecData_16[12] = {"D1E1_0", "D1E1_1", "D1E1_2", "E0E1_0", "E0E1_1", "E0E1_2", "E2E1_0", "E2E1_1", "E2E1_2", "F1E1_0", "F1E1_1", "F1E1_2"};

dataForSumo::dataForSumo() {
    // TODO Auto-generated constructor stub

}

dataForSumo::~dataForSumo() {
    // TODO Auto-generated destructor stub
}
std::string* dataForSumo::getDetectorData(int chooseNum){
    std::string *arrayStr;
    switch(chooseNum){
    case 1:
        arrayStr = InDecData_1;
        break;
    case 2:
        arrayStr = InDecData_2;
        break;
    case 3:
        arrayStr = InDecData_3;
        break;
    case 4:
        arrayStr = InDecData_4;
        break;
    case 5:
        arrayStr = InDecData_5;
        break;
    case 6:
        arrayStr = InDecData_6;
        break;
    case 7:
        arrayStr = InDecData_7;
        break;
    case 8:
        arrayStr = InDecData_8;
        break;
    case 9:
        arrayStr = InDecData_9;
        break;
    case 10:
        arrayStr = InDecData_10;
        break;
    case 11:
        arrayStr = InDecData_11;
        break;
    case 12:
        arrayStr = InDecData_12;
        break;
    case 13:
        arrayStr = InDecData_13;
        break;
    case 14:
        arrayStr = InDecData_14;
        break;
    case 15:
        arrayStr = InDecData_15;
        break;
    case 16:
        arrayStr = InDecData_16;
        break;

    default:
        std::cout<<"Not valid detectors"<<endl;

    }

    return arrayStr;
}



