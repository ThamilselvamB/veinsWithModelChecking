from __future__ import absolute_import
from __future__ import print_function

import os
import sys
import optparse
import subprocess
import random
#  "518.38,517.78 501.38,517.78"
# we need to import python modules from the directory
sys.path.append(os.path.join('c:', os.sep, 'usr', 'share', 'sumo', 'tools'))
from sumolib import checkBinary  # import library
import traci
import numpy as np
import array as arr


class Configuration:
    def __init__(self, cases):
        start = 1
        end = 25
        # majorRoad = 1500
        # minorRoad = 750
        # leftTurn = 100
        # crossRoad = 600

        self.cases=cases
        self.tcH = {}
        self.routeH = {}
        self.pH = {}
        if cases == "Case1Low":
            multiplier = 1.0
            caseLow = 800
            route_1_AmpliToVaishnamdevi = caseLow
            route_2AmpliToVaishnamdevi = caseLow
            route_3GandhinagarToShrikaei = caseLow
            route_4GandhinagarToShrikaei = caseLow
            route_5NavaNarodatoZundal = caseLow
            route_6NavaNarodatoZundal = caseLow
            route_7CGRoadtoUshmanpura = caseLow
            route_8CGRoadtoUshmanpura = caseLow
            route_9CGRoadtoUshmanpura = caseLow
            route_10CGRoadtoUshmanpura = caseLow
            route_11CGRoadtoUshmanpura = caseLow
            route_12CGRoadtoUshmanpura = caseLow
            route_13CGRoadtoUshmanpura = caseLow
            route_14CGRoadtoUshmanpura = caseLow
            route_15CGRoadtoUshmanpura = caseLow
            route_16CGRoadtoUshmanpura = caseLow
            route_17CGRoadtoUshmanpura = caseLow
            route_18CGRoadtoUshmanpura = caseLow
            route_19CGRoadtoUshmanpura = caseLow
            route_20CGRoadtoUshmanpura = caseLow
            route_21CGRoadtoUshmanpura = 1
            route_22CGRoadtoUshmanpura = 1
            route_23CGRoadtoUshmanpura = 1
            route_24CGRoadtoUshmanpura = 1
            route_25CGRoadtoUshmanpura = 1
            route_26CGRoadtoUshmanpura = 1

            crossRoad = 300
        if cases == "Case1Mid":
            multiplier = 1.0
            caseMid = 1200
            route_1_AmpliToVaishnamdevi = caseMid
            route_2AmpliToVaishnamdevi = caseMid
            route_3GandhinagarToShrikaei = caseMid
            route_4GandhinagarToShrikaei = caseMid
            route_5NavaNarodatoZundal = caseMid
            route_6NavaNarodatoZundal = caseMid
            route_7CGRoadtoUshmanpura = caseMid
            route_8CGRoadtoUshmanpura = caseMid
            route_9CGRoadtoUshmanpura = caseMid
            route_10CGRoadtoUshmanpura = caseMid
            route_11CGRoadtoUshmanpura = caseMid
            route_12CGRoadtoUshmanpura = caseMid
            route_13CGRoadtoUshmanpura = caseMid
            route_14CGRoadtoUshmanpura = caseMid
            route_15CGRoadtoUshmanpura = caseMid
            route_16CGRoadtoUshmanpura = caseMid
            route_17CGRoadtoUshmanpura = caseMid
            route_18CGRoadtoUshmanpura = caseMid
            route_19CGRoadtoUshmanpura = caseMid
            route_20CGRoadtoUshmanpura = caseMid
            route_21CGRoadtoUshmanpura = 2
            route_22CGRoadtoUshmanpura = 1
            route_23CGRoadtoUshmanpura = 1
            route_24CGRoadtoUshmanpura = 1
            route_25CGRoadtoUshmanpura = 1
            route_26CGRoadtoUshmanpura = 1
        if cases == "Case1High":
            multiplier = 1.0
            caseHigh = 2000
            route_1_AmpliToVaishnamdevi = caseHigh
            route_2AmpliToVaishnamdevi = caseHigh
            route_3GandhinagarToShrikaei = caseHigh
            route_4GandhinagarToShrikaei = caseHigh
            route_5NavaNarodatoZundal = caseHigh
            route_6NavaNarodatoZundal = caseHigh
            route_7CGRoadtoUshmanpura = caseHigh
            route_8CGRoadtoUshmanpura = caseHigh
            route_9CGRoadtoUshmanpura = caseHigh
            route_10CGRoadtoUshmanpura = caseHigh
            route_11CGRoadtoUshmanpura = caseHigh
            route_12CGRoadtoUshmanpura = caseHigh
            route_13CGRoadtoUshmanpura = caseHigh
            route_14CGRoadtoUshmanpura = caseHigh
            route_15CGRoadtoUshmanpura = caseHigh
            route_16CGRoadtoUshmanpura = caseHigh
            route_17CGRoadtoUshmanpura = caseHigh
            route_18CGRoadtoUshmanpura = caseHigh
            route_19CGRoadtoUshmanpura = caseHigh
            route_20CGRoadtoUshmanpura = caseHigh
            route_21CGRoadtoUshmanpura = 1
            route_22CGRoadtoUshmanpura = 1
            route_23CGRoadtoUshmanpura = 1
            route_24CGRoadtoUshmanpura = 1
            route_25CGRoadtoUshmanpura = 1
            route_26CGRoadtoUshmanpura = 1
        if cases == "Case2":
            multiplier = 1.0
            majorRoad = 1600
            minorRoad = 1000
            leftTurn = 100
            crossRoad = 300
        if cases == "Case3":
            multiplier = 1.0
            majorRoad = 850
            minorRoad = 850
            leftTurn = 100
            crossRoad = 300
        if cases == "Case4":
            multiplier = 1.0
            majorRoad = 450
            minorRoad = 750
            leftTurn = 100
            crossRoad = 300

        self.pH1 = np.ones(1)*multiplier * route_1_AmpliToVaishnamdevi / 3600
        self.pH2 = np.ones(1) * multiplier * route_2AmpliToVaishnamdevi / 3600
        self.pH3 = np.ones(1) * multiplier * route_3GandhinagarToShrikaei / 3600
        self.pH4 = np.ones(1) * multiplier * route_4GandhinagarToShrikaei / 3600
        self.pH5 = np.ones(1) * multiplier * route_5NavaNarodatoZundal / 3600
        self.pH6 = np.ones(1) * multiplier * route_6NavaNarodatoZundal / 3600
        self.pH7 = np.ones(1) * multiplier * route_7CGRoadtoUshmanpura / 3600
        self.pH8 = np.ones(1) * multiplier * route_8CGRoadtoUshmanpura / 3600
        self.pH9 = np.ones(1) * multiplier * route_9CGRoadtoUshmanpura / 3600
        self.pH10 = np.ones(1) * multiplier * route_10CGRoadtoUshmanpura / 3600
        self.pH11 = np.ones(1) * multiplier * route_11CGRoadtoUshmanpura / 3600
        self.pH12 = np.ones(1) * multiplier * route_12CGRoadtoUshmanpura / 3600
        self.pH13 = np.ones(1) * multiplier * route_13CGRoadtoUshmanpura / 3600
        self.pH14 = np.ones(1) * multiplier * route_14CGRoadtoUshmanpura / 3600
        self.pH15 = np.ones(1) * multiplier * route_15CGRoadtoUshmanpura / 3600
        self.pH16 = np.ones(1) * multiplier * route_16CGRoadtoUshmanpura / 3600
        self.pH17 = np.ones(1) * multiplier * route_17CGRoadtoUshmanpura / 3600
        self.pH18 = np.ones(1) * multiplier * route_18CGRoadtoUshmanpura / 3600
        self.pH19 = np.ones(1) * multiplier * route_19CGRoadtoUshmanpura / 3600
        self.pH20 = np.ones(1) * multiplier * route_20CGRoadtoUshmanpura / 3600
        self.pH21 = np.ones(1) * multiplier * route_21CGRoadtoUshmanpura / 3600
        self.pH22 = np.ones(1) * multiplier * route_22CGRoadtoUshmanpura / 3600
        self.pH23 = np.ones(1) * multiplier * route_23CGRoadtoUshmanpura / 3600
        self.pH24 = np.ones(1) * multiplier * route_24CGRoadtoUshmanpura / 3600
        self.pH25 = np.ones(1) * multiplier * route_25CGRoadtoUshmanpura / 3600
        self.pH26 = np.ones(1) * multiplier * route_26CGRoadtoUshmanpura / 3600
        self.pH27 = np.ones(1) * multiplier * route_26CGRoadtoUshmanpura / 3600

        self.pH = np.hstack((self.pH1 , self. pH2,self.pH3,self.pH4,self.pH5 , self. pH6,self.pH7,self.pH8,self.pH9 , self. pH10,self.pH11,self.pH12,self.pH13 , self. pH14,self.pH15,self.pH16,
                             self.pH17, self.pH18, self.pH19, self.pH20,self.pH21 , self. pH22,self.pH23,self.pH24,self.pH25 , self. pH26,self.pH27))
        self.routeH = []
        for i in range(start,end):
            self.routeH.append("route_"+str(i) )
        # self.routeH = ["route_1","route_2","route_3","route_4","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1",
        #                "route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1","route_1"]

        # self.directions = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12','13','14','15','16','17','18','19','20','1A', '2A', '3A', '4A', '5A', '6A', '7A', '8A', '9A', '10A', '11A', '12A','13A','14A','15A','16A','17A','18A','19A','20A']
        # self.nrDirections = len(self.directions)
#<route id="route_1" edges="168277061#0 168277061#1 168277061#3 168277061#4 168275829 168275547#1 168275547#2 547236215#0 547236215#2 547236215#4 547236215#5 168278390#0 168278390#1 168278390#2 168278390#3 168278390#4 547560317 168278394 168278393#1 168278393#2 168274448#1 168244316#0 168244316#1 168244316#3 168244316#4 168244316#5 168244316#6 168108873#2"/>

#  Wiedemann  Krauss  IDM   

def generate_routefile(cases, outputfile,randomSeed):
    random.seed(random.randint(0,99))  # make tests reproducible
    N = 200  # number of time steps
    cf1 = Configuration("Case1Low")
    cf2 = Configuration("Case1Mid")
    cf3 = Configuration("Case1High")
    # according to distribution in Ahmadabad city
    pBus = 2. / 100
    pCar = 17. / 100
    p3Wheel = 6. / 100
    p2Wheel = 75. / 100
    pBus1 = 0.2 / 100
    pCar1 = 1.7 / 100
    p3Wheel1 = 0.6 / 100
    p2Wheel1 = 7.5 / 100
    v_Types = ['Bus','Auto','MotorCycle','Car','emergency']
    with open(""+outputfile, "w") as routes:
        totalCars = 0;
        print("""<routes>
<vType id="Bus" accel="0.6" decel="3.5" sigma="0.5" length="10.1" minGap="1.0" maxSpeed="16.67" carFollowModel="Wiedemann" guiShape="bus" width="2.45" latAlignment="left" laneChangeModel="SL2015" lcStrategic="0.5" lcCooperative="0.0"/>
<vType id="Auto" accel="0.7" decel="4.5" sigma="0.5" length="2.6" minGap="0.3" maxSpeed="16" carFollowModel="Wiedemann" guiShape="passenger/sedan" width="1.25" latAlignment="left" laneChangeModel="SL2015" lcStrategic="0.5" lcCooperative="0.0" />
<vType id="MotorCycle" accel="0.9" decel="3.5" sigma="0.5" length="1.85" minGap="0.15"  carFollowModel="Wiedemann" maxSpeed="17" guiShape="motorcycle" width="0.7" latAlignment="left" laneChangeModel="SL2015" lcStrategic="0.5" lcCooperative="0.0"/>
<vType id="Car" accel="0.8" decel="4.5" sigma="0.5" length="3.6" minGap="0.5" maxSpeed="40" carFollowModel="Wiedemann" guiShape="passenger" width="1.5" latAlignment="left" laneChangeModel="SL2015" lcStrategic="0.5" lcCooperative="0.0"/>
<vType id="emergency" accel="2.8" decel="5.5" sigma="0.5" length="3.6" minGap="0.5" maxSpeed="120.6" carFollowModel="Wiedemann" guiShape="emergency" width="1.5" latAlignment="left" laneChangeModel="SL2015" lcStrategic="0.5" lcCooperative="0.0" vClass="emergency" speedFactor="1.9" jmDriveAfterRedTime="300" jmDriveAfterRedSpeed="5.56">
<param key="has.bluelight.device" value="true"/>
<param key="has.fcd.device" value="true"/> 
</vType>
    <route id="route_0" edges="left4A4 A4B4 B4C4 C4D4 D4E4 E4F4 F4right4 " />
    <route id="route_1" edges="right4F4 F4E4 E4D4 D4C4 C4B4 B4A4 A4left4" />
        <route id="route_2" edges=" left3A3 A3B3 B3C3 C3D3 D3E3 E3F3" />
        <route id="route_3" edges="F3E3 E3D3 D3C3 C3B3 B3A3 A3left3" />
        <route id="route_4" edges="top1B5 B5B4 B4B3 B3B2 B2B1 B1B0" /> B4B3_1
        <route id="route_5" edges="B0B1 B1B2 B2B3 B3B4 B4B5 B5top1 " />
        <route id="route_6" edges="top2C5 C5C4 C4C3 C3C2 C2C1 C1C0 " />
        <route id="route_7" edges=" C0C1 C1C2 C2C3 C3C4 C4C5 C5top2" />
        <route id="route_8" edges="left4A4 A4B4 B4C4 C4D4 D4E4 E4F4 F4right4" />
        <route id="route_9" edges="right4F4 F4E4 E4D4 D4C4 C4B4 B4A4 A4left4" />
        <route id="route_10" edges="A4B4 B4B5" />
        <route id="route_11" edges="A4B4 B4B3" />
        <route id="route_12" edges="C4B4 B4B3 " />
        <route id="route_13" edges="C4B4 B4B5" />
        <route id="route_14" edges="B4C4 C4C3" />
        <route id="route_15" edges="B4C4 C4C5" />
        <route id="route_16" edges="C3C4 C4B4" />
        <route id="route_17" edges="C3C4 C4D4" />
        <route id="route_18" edges="D4C4 C4C3" />
        <route id="route_19" edges="D4C4 C4C5" />
        <route id="route_20" edges="B2A2" />
        <route id="route_21" edges="B2A2" />
        <route id="route_22" edges="B2A2" />
        <route id="route_23" edges="B2A2" />

    <route id="route_24" edges="D4C4"/>""",
              file=routes)
        lastVeh = 0
        vehNr = 0  # 3,6,20 ----- 2,10,21 -------- 5,16,22   ----- 7,12,23
        list1 = [3,6,20,2,10,21]
        numVehTypes = arr.array('i', [0, 0, 0, 0])
        for i in range(int(round(N))):
           emergencyRandom = random.sample(list1,1)
           if(i<40):
            cf = cf1;
            #print("configuration selected now cf1: at time",i)
           if(i>=40 and i<60):
            cf = cf2
            #print("configuration selected now cf2: at time",i)
           if(i>=60 and i<80):
            cf = cf1
           if(i>=80 and i<200):
            cf = cf1
           if(i==0):        
                print('<vehicle id="%s_%i" type="emergency" route="%s" depart="%i" />' % (v_Types[4], vehNr, cf.routeH[emergencyRandom[0]], i),file=routes)
                print('<vehicle id="%s_%i" type="Bus" route="%s" depart="%i" />' % (v_Types[0], vehNr, cf.routeH[emergencyRandom[0]], i),file=routes)                
                print('<vehicle id="%s_%i" type="Car" route="%s" depart="%i" />' % (v_Types[3], vehNr, cf.routeH[random.randint(0,19)], i),file=routes)
                vehNr += 1
           else:
            for j in range(len(cf.routeH)):
                # d = cf.routeH[j]
                k = random.uniform(0, 1)
                #print("-------------------------------------------------", k)
                if k < cf.pH[j]:
                    #print("-------------------------- %s <  %s  : True now at %s-----------------------"%( k,cf.pH[j], i))
                    #print("now:",cf.pH)
                    route = cf.routeH[j]
                    # cf.tcH[d] = cf.tcH[d] + 1
                    #k = random.randint(0, 3)
                    probVehType =random.uniform(0, 1)
                    # if k == 0:
                    if probVehType < pBus:
                        print('<vehicle id="%s_%i" type="Bus" route="%s" depart="%i" />' % (v_Types[0], vehNr, route, i),file=routes)
                        vehNr += 1
                        numVehTypes[0] = numVehTypes[0] + 1 
                    elif probVehType < (pBus + p3Wheel):
                        print('<vehicle id="%s_%i" type="Auto" route="%s" depart="%i" />' % (v_Types[1], vehNr, route, i),
                              file=routes)
                        vehNr += 1
                        numVehTypes[1] = numVehTypes[1] + 1 
                    elif probVehType < (pBus + p3Wheel + p2Wheel):
                        print('<vehicle id="%s_%i" type="MotorCycle" route="%s" depart="%i" />' % (v_Types[2], vehNr, route, i),
                              file=routes)
                        vehNr += 1
                        numVehTypes[2] = numVehTypes[2] + 1 
                    else:
                        print('<vehicle id="%s_%i" type="Car" route="%s" depart="%i" />' % (v_Types[3], vehNr, route, i),
                              file=routes)
                        vehNr += 1
                        numVehTypes[3] = numVehTypes[3] + 1 
                    # print('<vehicle id="%s_%i" type="Auto" route="%s" depart="%i" />' % (
                    #     route, vehNr, route, i), file=routes)
                    # vehNr += 1
                    lastVeh = i
                     
        '''              
        for i in range(int(round(N/2)),N):
            if(i>10):
             cf = cf1;
            else:
             cf = cf2;
            if(i==0):
                print('<vehicle id="%s_%i" type="Bus" route="%s" depart="%i" />' % (v_Types[4], vehNr, cf.routeH[random.randint(0, 18)], i),file=routes)
                vehNr += 1
            else:
             for j in range(len(cf.routeH)):
                # d = cf.directions[j]
                if random.uniform(0, 1) < cf.pH[j]:
                    route = cf.routeH[j]
                    # cf.tcH[d] = cf.tcH[d] + 1
                    k = random.randint(0, 3)
                    # if k == 0:
                    if random.uniform(0, 1) < pBus:
                        print('<vehicle id="%s_%i" type="Bus" route="%s" depart="%i" />' % (v_Types[k], vehNr, route, i),file=routes)
                        vehNr += 1
                    if random.uniform(0, 1) < p3Wheel:
                        print('<vehicle id="%s_%i" type="Auto" route="%s" depart="%i" />' % (v_Types[k], vehNr, route, i),
                              file=routes)
                        vehNr += 1
                    if random.uniform(0, 1) < p2Wheel:
                        print('<vehicle id="%s_%i" type="MotorCycle" route="%s" depart="%i" />' % (v_Types[k], vehNr, route, i),
                              file=routes)
                        vehNr += 1
                    if random.uniform(0, 1) < pCar:
                        print('<vehicle id="%s_%i" type="Car" route="%s" depart="%i" />' % (v_Types[k], vehNr, route, i),
                              file=routes)
                        vehNr += 1
                    # print('<vehicle id="%s_%i" type="Auto" route="%s" depart="%i" />' % (
                    #     route, vehNr, route, i), file=routes)
                    # vehNr += 1
                    lastVeh = i         
        
        '''
        print('<!-- totalCars="%i -->' % (vehNr), file=routes)
        print('<!-- CarsPerDirection="%s -->' % (str(cf.tcH)), file=routes)
        print("</routes>", file=routes)
        # print(cf.tcH)
        ans = numVehTypes[0] + numVehTypes[1]+ numVehTypes[2]+ numVehTypes[3] 
        print(numVehTypes, ans)
        print("Total cars Generated:",vehNr)
    routes.close()

def get_options():
    optParser = optparse.OptionParser()
    optParser.add_option("--cases", type="string", dest="cases", default="Case1Mid")
    optParser.add_option("--output", type="string", dest="output", default="gridExp.rou.xml")
    options, args = optParser.parse_args()
    return options


# this is the main entry point of this script
if __name__ == "__main__":
    options = get_options()
    for i in range(1,2):
     filename = "gridExp.rou.xml"
     generate_routefile(options.cases, filename,32)
    # generate_routefileSimple()