#include <config.hpp>

namespace sim {

Config *Config::_instance = NULL;

Config::Config() :
#ifdef TEST_SIM
    _Kp_x(10),  _Ki_x(0.0), _Kd_x(10),
    _Kp_y(10),  _Ki_y(0.0), _Kd_y(10),
    _Kp_z(80),  _Ki_z(0.0), _Kd_z(35),
    _Kp_R(200), _Ki_R(0.0), _Kd_R(0.1),
    _Kp_P(200), _Ki_P(0.0), _Kd_P(0.1),
    _Kp_Y(200), _Ki_Y(0.0), _Kd_Y(0.1)
#else
    _Kp_x(0.0), _Ki_x(0.0), _Kd_x(0.0),
    _Kp_y(0.0), _Ki_y(0.0), _Kd_y(0.0),
    _Kp_z(0.0), _Ki_z(0.0), _Kd_z(0.0),
    _Kp_R(0.0), _Ki_R(0.0), _Kd_R(0.0),
    _Kp_P(0.0), _Ki_P(0.0), _Kd_P(0.0),
    _Kp_Y(0.0), _Ki_Y(0.0), _Kd_Y(0.0)
#endif
{}

Config* Config::get_instance() {
    if (_instance == NULL)
        _instance = get_instance(); // Generate only one instance of the class
    return _instance;
}

} // namespace sim
