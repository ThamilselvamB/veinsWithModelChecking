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
            route_1_AmpliToVaishnamdevi = 200
            route_2AmpliToVaishnamdevi = 200
            route_3GandhinagarToShrikaei = 100
            route_4GandhinagarToShrikaei = 100
            route_5NavaNarodatoZundal = 100
            route_6NavaNarodatoZundal = 100
            route_7CGRoadtoUshmanpura = 100
            route_8CGRoadtoUshmanpura = 100
            route_9CGRoadtoUshmanpura = 100
            route_10CGRoadtoUshmanpura = 100
            route_11CGRoadtoUshmanpura = 1
            route_12CGRoadtoUshmanpura = 1
            route_13CGRoadtoUshmanpura = 1
            route_14CGRoadtoUshmanpura = 1
            route_15CGRoadtoUshmanpura = 1
            route_16CGRoadtoUshmanpura = 1
            route_17CGRoadtoUshmanpura = 1
            route_18CGRoadtoUshmanpura = 1
            route_19CGRoadtoUshmanpura = 1
            route_20CGRoadtoUshmanpura = 1
            route_21CGRoadtoUshmanpura = 1
            route_22CGRoadtoUshmanpura = 1
            route_23CGRoadtoUshmanpura = 1
            route_24CGRoadtoUshmanpura = 1
            route_25CGRoadtoUshmanpura = 1
            route_26CGRoadtoUshmanpura = 1

            crossRoad = 300
        if cases == "Case1Mid":
            multiplier = 1.0
            route_1_AmpliToVaishnamdevi = 999
            route_2AmpliToVaishnamdevi = 999
            route_3GandhinagarToShrikaei = 200
            route_4GandhinagarToShrikaei = 200
            route_5NavaNarodatoZundal = 200
            route_6NavaNarodatoZundal = 200
            route_7CGRoadtoUshmanpura = 200
            route_8CGRoadtoUshmanpura = 200
            route_9CGRoadtoUshmanpura = 200
            route_10CGRoadtoUshmanpura = 150
            route_11CGRoadtoUshmanpura = 1
            route_12CGRoadtoUshmanpura = 1
            route_13CGRoadtoUshmanpura = 1
            route_14CGRoadtoUshmanpura = 1
            route_15CGRoadtoUshmanpura = 1
            route_16CGRoadtoUshmanpura = 1
            route_17CGRoadtoUshmanpura = 1
            route_18CGRoadtoUshmanpura = 1
            route_19CGRoadtoUshmanpura = 1
            route_20CGRoadtoUshmanpura = 1
            route_21CGRoadtoUshmanpura = 1
            route_22CGRoadtoUshmanpura = 1
            route_23CGRoadtoUshmanpura = 1
            route_24CGRoadtoUshmanpura = 1
            route_25CGRoadtoUshmanpura = 1
            route_26CGRoadtoUshmanpura = 1
        if cases == "Case1High":
            multiplier = 1.0
            route_1_AmpliToVaishnamdevi = 3000
            route_2AmpliToVaishnamdevi = 3000
            route_3GandhinagarToShrikaei = 400
            route_4GandhinagarToShrikaei = 400
            route_5NavaNarodatoZundal = 400
            route_6NavaNarodatoZundal = 400
            route_7CGRoadtoUshmanpura = 400
            route_8CGRoadtoUshmanpura = 500
            route_9CGRoadtoUshmanpura = 400
            route_10CGRoadtoUshmanpura = 400
            route_11CGRoadtoUshmanpura = 1
            route_12CGRoadtoUshmanpura = 1
            route_13CGRoadtoUshmanpura = 1
            route_14CGRoadtoUshmanpura = 1
            route_15CGRoadtoUshmanpura = 1
            route_16CGRoadtoUshmanpura = 1
            route_17CGRoadtoUshmanpura = 1
            route_18CGRoadtoUshmanpura = 1
            route_19CGRoadtoUshmanpura = 1
            route_20CGRoadtoUshmanpura = 1
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
    N = 800  # number of time steps
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
	<route id="route_0" edges="78[0] 56a 56b 78[1][1]" />
	<route id="route_1" edges="78[0] 56a 56b 78[1][1] 189[0] 189[1][0]+20000 189[1][1] 188 87[0] 20001+87[1][0] 87[1][1] m90 89[0] 20002+89[1][0] 89[1][1] 91 186 109[0] 109[1][0]+20003 109[1][1] 116 46 134 134b -gneE0" />
        <route id="route_2" edges="gneE0 133 31 115 110 185 92 90 m91 88 187 190 77[0] 77[1][1] " />
        <route id="route_3" edges="78[0] 56a 56b 79 68 11 84" />
        <route id="route_4" edges="78[0] 56a 56b 21a 21b " /> 
        <route id="route_5" edges="75 77[0] 79 68 11 84 " />
        <route id="route_6" edges="75 77[0] 21a 21b" />
        <route id="route_7" edges="gneE0 133 31 201 201c 204a[0] " />
        <route id="route_8" edges="gneE0 133 31 113 209" />
        <route id="route_9" edges="119 116 46 113 209" />
        <route id="route_10" edges="119 116 46 201 201c 204a[0]" />
        <route id="route_11" edges="59" />
        <route id="route_12" edges="59" />
        <route id="route_13" edges="59" />
        <route id="route_14" edges="59" />
        <route id="route_15" edges="59" />
        <route id="route_16" edges="59" />
        <route id="route_17" edges="59" />
        <route id="route_18" edges="59" />
        <route id="route_19" edges="59" />
        <route id="route_20" edges="59" />
        <route id="route_21" edges="59" />
        <route id="route_22" edges="59" />
        <route id="route_23" edges="59" />

	<route id="route_24" edges="59"/>""",
              file=routes)
        lastVeh = 0
        vehNr = 0  # 3,6,20 ----- 2,10,21 -------- 5,16,22   ----- 7,12,23
        list1 = [3,6,20,2,10,21]
        for i in range(int(round(N))):
           emergencyRandom = random.sample(list1,1)
           if(i<50):
            cf = cf2;
            #print("configuration selected now cf1: at time",i)
           if(i>=50 and i<450):
            cf = cf1
            #print("configuration selected now cf2: at time",i)
           if(i>=450 and i<500):
            cf = cf3
           if(i>=500 and i<800):
            cf = cf1
           if(i==0):
                
                
                print('<vehicle id="%s_%i" type="emergency" route="%s" depart="%i" />' % (v_Types[4], vehNr, cf.routeH[emergencyRandom[0]], i),file=routes)
                print('<vehicle id="%s_%i" type="Bus" route="%s" depart="%i" />' % (v_Types[0], vehNr, cf.routeH[emergencyRandom[0]], i),file=routes)                
                print('<vehicle id="%s_%i" type="Car" route="%s" depart="%i" />' % (v_Types[3], vehNr, cf.routeH[random.randint(0,19)], i),file=routes)
                vehNr += 1
           else:
            for j in range(len(cf.routeH)):
                # d = cf.directions[j]
                k = random.uniform(0, 1)
                #print("-------------------------------------------------", k)
                if k < cf.pH[j]:
                    #print("-------------------------- %s <  %s  : True now at %s-----------------------"%( k,cf.pH[j], i))
                    #print("now:",cf.pH)
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
        print("Total cars Generated:",vehNr)
    routes.close()

def get_options():
    optParser = optparse.OptionParser()
    optParser.add_option("--cases", type="string", dest="cases", default="Case1Mid")
    optParser.add_option("--output", type="string", dest="output", default="cross.rou.xml")
    options, args = optParser.parse_args()
    return options


# this is the main entry point of this script
if __name__ == "__main__":
    options = get_options()
    for i in range(1,21):
     filename = "cross_"+str(i)+".rou.xml"
     generate_routefile(options.cases, filename,32)
    # generate_routefileSimple()
