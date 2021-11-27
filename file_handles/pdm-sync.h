//
// Created by 18604 on 10/4/2021.
//

#ifndef PDM_PDM_SYNC_H
#define PDM_PDM_SYNC_H

#include <wx/artprov.h>
#include <wx/filename.h>
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include <pdm-network.h>


class pdm_sync {

public:
    void set_usr(char * a);
    void set_usr(std::string a);
    int usr_set();
    int usr_sync(std::string a);
    int usr_get(std::string a="");
    int usr_get(std::string a, std::string b);
private:
    pdm_network *usr_act = nullptr;
};


#endif //PDM_PDM_SYNC_H
