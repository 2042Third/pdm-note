//
// Created by 18604 on 10/4/2021.
//
#include "pdm-sync.h"
#include "../cMain.h"
#include <string.h>

void pdm_sync::set_usr(char *a){
    std::string bf = a;
    usr_act = new pdm_network(bf);
}


int pdm_sync::usr_sync(std::string a){
    usr_act->upload_sync_multi(a);
    return 1;
}

int pdm_sync::usr_get(std::string a){
    usr_act->download_sync(a);
    return 1;
}

int pdm_sync::usr_set(){
    return (usr_act == nullptr) ? 0 : 1;
}
