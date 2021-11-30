#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BUSCOPlugin.h"

void BUSCOPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   if (key.size() != 0)
   parameters[key] = value;
   else
	   break;
 }

}

void BUSCOPlugin::run() {
}


void BUSCOPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 std::string outdirname = file.substr(file.find_last_of("/")+1);
 std::string outpath = file.substr(0, file.find_last_of("/"));
myCommand += "busco -i "+std::string(PluginManager::prefix())+"/"+parameters["fastafile"]+" -m "+parameters["mode"]+" -f -o "+outdirname+"; mv "+outdirname+" "+outpath+"; cp "+file+"/*.txt "+file+"/../";
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<BUSCOPlugin> BUSCOPluginProxy = PluginProxy<BUSCOPlugin>("BUSCO", PluginManager::getInstance());
