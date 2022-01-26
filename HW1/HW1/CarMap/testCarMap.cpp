////
////  testCarMap.cpp
////  Map
////
////  Created by Gabriella Ang on 1/13/22.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <cassert>
//#include "CarMap.h"
//
//
//
//int main() {
//    CarMap jeeps;
//    assert(jeeps.fleetSize() == 0);
//    jeeps.addCar("lstrk");
//    jeeps.addCar("");
//    jeeps.addCar("123");
//    assert(!jeeps.addCar("lstrk"));
//    assert(jeeps.addCar("lStrk"));
//    jeeps.addCar("yass");
//    jeeps.addCar("zoom zoom");
//    jeeps.addCar("kachow");
//    assert(jeeps.fleetSize() == 7);
//    assert(jeeps.miles("lstrk") == 0);
//    jeeps.drive("lstrk", 100.2);
//    assert(jeeps.miles("lstrk") == 100.2);
//    jeeps.drive("kachow", -20);
//    assert(jeeps.miles("kachow") == 0);
//    jeeps.drive("123", 2145);
//    assert(jeeps.miles("123") == 2145);
//    jeeps.drive("", 23);
//    assert(jeeps.miles("") == 23);
//    jeeps.drive("zoom zoom", 649.45);
//    assert(jeeps.miles("zoom zoom") == 649.45);
//    jeeps.print();
//
//    cerr << "all tests suceeded" << endl;
//}
