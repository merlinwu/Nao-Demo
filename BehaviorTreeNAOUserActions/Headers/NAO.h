#ifndef NAO_H
#define NAO_H

#include <alproxies/almemoryproxy.h>
#include <alproxies/albehaviormanagerproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/almotionproxy.h>

#define RobotAddress "192.168.1.246"
#define RobotPort 9559

namespace NAO
{
    // Possible robot action
    enum RobotAction {None, Sit, Stand, Walk};
}

#endif
