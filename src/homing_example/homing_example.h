#ifndef HOMING_EXAMPLE_H
#define HOMING_EXAMPLE_H

// main XBot2 include
#include <xbot2/xbot2.h>

using namespace XBot;

/**
 * @brief The HomingExample class is a ControlPlugin
 * implementing a simple homing motion.
 */
class HomingExample : public ControlPlugin
{

public:

    // we don't do anything special inside the
    // constructor, so just inherit the base class
    // implementation
    using ControlPlugin::ControlPlugin;

    // initialization method; the plugin won't be run
    // if this returns 'false'
    bool on_initialize() override;

    // callback for the 'Starting' state
    // start_completed() must be called to switch
    // to 'Run' state
    void starting() override;

    // callback for 'Run' state
    void run() override;

private:
    
    void set_control_mode();

    Eigen::VectorXd _q_home, _q_start, _q_ref;
    double _homing_time;
    double _fake_time;

};

#endif // HOMING_EXAMPLE_H
