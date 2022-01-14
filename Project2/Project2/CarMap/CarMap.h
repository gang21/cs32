//
//  CarMap.h
//  Map
//
//  Created by Gabriella Ang on 1/13/22.
//

#ifndef CarMap_h
#define CarMap_h

#include <stdio.h>
#include "Map.h"

using namespace std;


class CarMap
{
  public:
    CarMap();
    bool addCar(string license);
    double miles(string license) const;
    bool drive(string license, double distance);
    int fleetSize() const;
    void print() const;

  private:
    Map cars;
};
#endif /* CarMap_h */
