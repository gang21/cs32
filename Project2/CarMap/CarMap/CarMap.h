//
//  CarMap.h
//  CarMap
//
//  Created by Gabriella Ang on 1/13/22.
//

#ifndef CarMap_h
#define CarMap_h
#include "Map.h"

class CarMap
{
  public:
    CarMap();
    bool addCar(std::string license);
    double miles(std::string license) const;
    bool drive(std::string license, double distance);
    int fleetSize() const;
    void print() const;
    
  private:
        // Some of your code goes here.
    };


#endif /* CarMap_h */
