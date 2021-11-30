#ifndef BUSCOPLUGIN_H
#define BUSCOPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class BUSCOPlugin : public Plugin
{
public: 
 std::string toString() {return "BUSCO";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;

};

#endif
