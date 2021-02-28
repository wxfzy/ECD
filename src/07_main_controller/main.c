#include <stdio.h>

#include "../01_sockets/_sockets_controller.h"
#include "../02_serializer/_serial_controller.h"
#include "../03_ethernet_ip/_eip_controller.h"
#include "../04_common_industrial_protocol/_cip_controller.h"
#include "../05_system/_system_controller.h"
#include "../06_api/_api_controller.h"

int main(){

    while(1){

        if(api_controller() == -1){
            perror("Error during api branch");
        }

        if(system_controller() == -1){
            perror("Error during system branch");
        }

        if(cip_controller() == -1){
            perror("Error during cip branch");
        }

        if(eip_controller() == -1){
            perror("Error during eip branch");
        }

        if(serial_controller() == -1){
            perror("Error during serial branch");
        }

        if(socket_controller() == -1){
            perror("Error during socket branch");
        }
    }
}
