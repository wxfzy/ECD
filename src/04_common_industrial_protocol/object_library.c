
struct cip_class_attributes {
    uint
    uint
    
    
};

struct cip_object {
    class_code;
    class_attributes;
    instance_attributes;
    common_services;
    object_specific_services;
    connections;
    behavior;
};

int identity_object;
// 2 max instance
int message_router_object;
int device_net_object;
int assembly_object;
int connection_object;
int connection_manager_object;
int register_object;
int discrete_input_point_object;
int discrete_output_point_object;
int analog_input_point_object;
int analog_output_point_object;
int presence_sensing_object;
int parameter_object;
int paramter_group_object;
int group_object;
int discrete_input_group_object;
int discrete_output_group_object;
int discrete_group_object;
int analog_input_group_object;
int analog_output_group_object;
int analog_group_object;
int position_sensor_object;
int position_controller_supervisor_object;
int position_controller_object;
int block_sequencer_object;
int command_block_object;
int motor_data_object;
int control_supervisor_object;
int acdc_drive_object;
int acknowledge_handler_object;
int overload_object;
int softstart_object;
int selection_object;
int sdevice_supervisor_object;
int sanalog_sensor_object;
int sanalog_actuator_object;
int ssingle_stage_controller_object;
int sgas_calibration_object;
int trip_point_object;
int drive_data_object;
int file_object;
int spartial_pressure_object;
int safety_supervisor_object;
int safety_validator_object;
int safety_discrete_output_point_object;
int safety_discrete_output_group_object;
int safety_discrete_input_point_object;
int safety_discrete_input_group_object;
int safety_dual_channel_output_object;
int ssensor_calibration_object;
int event_log_object;
int motion_axis_object;
int time_sync_object;
int modbus_object;
int controlnet_object;
int controlnet_keeper_object;
int controlnet_scheduling_object;
int connection_configuration_object;
int port_object;
int tcpip_interface_object;
int ethernet_link_object;
int componet_link_object;
int componet_repeater_object;