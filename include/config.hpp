#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

#include <string>
#include <stdint.h>
#include <stdio.h>

namespace sim {

using std::string;

class Config {
public:
    static Config* get_instance();

    // controller gains
    static double& Kp_x() { return get_instance()->_Kp_x; }
    static double& Kp_y() { return get_instance()->_Kp_y; }
    static double& Kp_z() { return get_instance()->_Kp_z; }
    static double& Ki_x() { return get_instance()->_Ki_x; }
    static double& Ki_y() { return get_instance()->_Ki_y; }
    static double& Ki_z() { return get_instance()->_Ki_z; }
    static double& Kd_x() { return get_instance()->_Kd_x; }
    static double& Kd_y() { return get_instance()->_Kd_y; }
    static double& Kd_z() { return get_instance()->_Kd_z; }
    static double& Kp_R() { return get_instance()->_Kp_R; }
    static double& Kp_P() { return get_instance()->_Kp_P; }
    static double& Kp_Y() { return get_instance()->_Kp_Y; }
    static double& Ki_R() { return get_instance()->_Ki_R; }
    static double& Ki_P() { return get_instance()->_Ki_P; }
    static double& Ki_Y() { return get_instance()->_Ki_Y; }
    static double& Kd_R() { return get_instance()->_Kd_R; }
    static double& Kd_P() { return get_instance()->_Kd_P; }
    static double& Kd_Y() { return get_instance()->_Kd_Y; }

private:
    Config();
    Config(Config const&);
    Config& operator = (Config const&);
    static Config *_instance;

    // Controller gains (PID)
    double _Kp_x, _Ki_x, _Kd_x; // x
    double _Kp_y, _Ki_y, _Kd_y; // y
    double _Kp_z, _Ki_z, _Kd_z; // z
    double _Kp_R, _Ki_R, _Kd_R; // roll
    double _Kp_P, _Ki_P, _Kd_P; // pitch
    double _Kp_Y, _Ki_Y, _Kd_Y; // yaw
};

} // namespace sim

#endif
