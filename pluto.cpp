#include <iostream>
#include "yaml-cpp/yaml.h"


struct commandLineArgs {
    const char* dirPath = "/opt/pluto";
    bool silenceOutput = false;
    std::string runType = "";

    void parseArgs (int argc, char* argv[]){
        if (argc > 1){
        for (int i = 1; i < argc; i++){
            std::string argumentValue = std::string(argv[i]);

            if (argumentValue == "--debug" || argumentValue == "-d"){
                
            }
            else if ((argumentValue == "--dir" || argumentValue == "-p") && i+1 < argc){
                dirPath = argv[i+1];
            }
            else if (argumentValue == "--help" || argumentValue == "-h"){
                
            }
            else if (argumentValue == "--quiet" || argumentValue == "-q"){
                silenceOutput = true;
            }
            else if (argumentValue == "check" || argumentValue == "s"){
                runType = "check";
            }
            else if (argumentValue == "score" || argumentValue == "c"){
                runType = "score";
            }
            else if (argumentValue == "readme" || argumentValue == "rd"){
                runType = "readme";
            }
            else if (argumentValue == "encrypt" || argumentValue == "e"){
                runType = "encrypt";
            }
            else if (argumentValue == "prompt" || argumentValue == "p"){
                runType = "prompt";
            }
            else if (argumentValue == "info" || argumentValue == "i"){
                runType = "info";
            }
            else if (argumentValue == "version" || argumentValue == "v"){
                runType = "version";
            }
            else if (argumentValue == "release" || argumentValue == "r"){
                runType = "release";
            }
        }
    }
    }
} cmdArgs;


int main (int argc, char *argv[]){
    cmdArgs.parseArgs(argc, argv);
    YAML::Node config = YAML::LoadFile(std::string(cmdArgs.dirPath) + "/scoring.yaml");

    std::cout << config["image"]["checks"][0] << std::endl;
    std::cout << cmdArgs.silenceOutput << std::endl;

    return 0;
}
