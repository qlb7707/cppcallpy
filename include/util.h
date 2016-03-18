#ifndef  __UTIL_H_                                                           
#define  __UTIL_H_                                                           

#include "glog/logging.h"                                                    
#include <string>                                                            
#include <vector>                                                            

#define PYTHON_LIB_PATH "/usr/lib/python2.7"                             
#define PYTHON_BIN_PATH "/usr/bin/python2.7"                             

// initial log                                                               
void init_log(const char* argv);                                             

// exe shell command                                                         
char* exe_command(const char* cmd);                                          

// exe python command                                                        
void exe_py(                                                                 
        const std::string module_name,                                       
        const std::string func_name,                                         
        const std::vector<std::string>& args);             
#endif
