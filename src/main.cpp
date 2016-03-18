/***************************************************************************         
 *-                                                                                  
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved                            
 *-                                                                                  
 **************************************************************************/         
/**                                                                                  
 * @file src/util.cpp                                                                
 * @author zhangruiqing01(zhangruiqing01@baidu.com)                                  
 * @date 2015/10/23 10:41:23                                                         
 * @version $Revision$-                                                              
 * @brief-                                                                           
 *--                                                                                 
 **/                                                                                 

#include <stdio.h>                                                                   
#include <vector>                                                                    
#include <string>                                                                    
#include "util.h"                                                                    
#include <iostream>                                                                  

int main(int argc, char* argv[]){                                                    
    //initial log                                                                    
    init_log(argv[0]);                                                               

    char cmd[100]="echo 'abc'";                                                      
    char* res = exe_command(cmd);                                                    

    std::string arg_v[] = {"1"};                                                     
    std::vector<std::string>py_args(arg_v, arg_v + sizeof(arg_v)/sizeof(arg_v[0]));  
    exe_py("printargs", "pr", py_args);                                              
}
