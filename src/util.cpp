/***************************************************************************     
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved                        
 **************************************************************************/     
 /* @file src/util.cpp                                                            
 * @author zhangruiqing01(zhangruiqing01@baidu.com)                              
 * @date 2015/10/24 02:12:34                                                     
 * @version $Revision$-                                                          
 * @brief*/                                                                     

#include "util.h"                                                                
#include <stdio.h>                                                               
#include <errno.h>                                                               
#include "Python.h"             
#include <iostream>
#define MAX_LENGTH 2048 
using namespace std;

void init_log(const char* argv){                                                 
//    if (!getenv("GLOG_logtostderr")) {                                           
          google::LogToStderr();                                                 
//    }                                                                            
    google::InstallFailureSignalHandler();                                       
    google::InitGoogleLogging(argv);                                             
    LOG(INFO) << "Create Log successfully";                                      
}                                                                                

char* exe_command(const char* cmd){                                              
    FILE* fres;                                                                  
    if ((fres = popen(cmd, "r")) != NULL){                                       
        char* buf_res = (char*) malloc(MAX_LENGTH);                              
        int n = fread(buf_res,1,MAX_LENGTH , fres);
        buf_res[n] = '\0';                                     
        //buf_res                                                                
        fprintf(stderr, "------------\nEXE RESULT: %s\n------------\n", buf_res);
        //cout<<buf_res<<endl;
        pclose(fres);                                                            
        return buf_res;                                                          
    }                                                                            
    else{                                                                        
        LOG(FATAL) << "Failed to execute '" << cmd << "'";                       
    }                                                                            
}     

void exe_py(                                                        
        const std::string module_name,                              
        const std::string func_name,                                
        const std::vector<std::string>& args){                      
    std::string args_str = "";                                      
    for(auto& arg : args){                                          
        args_str += arg + ",";                                      
    }                                                               

    std::string cmd = "LD_LIBRARY_PATH=" +                          
        std::string(PYTHON_LIB_PATH) + ":" + "$LD_LIBRARY_PATH " +  
        std::string(PYTHON_BIN_PATH) +                              
        " -c 'import sys\n" +                                       
        "sys.path.append(\"pyfiles\")\n" +                          
        "import " + module_name + "\n" +                            
        "ret = " + module_name + "." + func_name + "([" +           
        args_str + "])'";                                           
    LOG(INFO) << "exec command: "<< cmd;                            
    char* res = exe_command(cmd.c_str());                           
}
