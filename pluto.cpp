#include <iostream>
#include "yaml-cpp/yaml.h"


struct commandLineArgs {
    const char* filePath = "/opt/pluto/scoring.yaml";
    bool silenceOutput = false;
    bool debugOutput = false;
    bool helpOutput = false;
    std::string runType = "";

    void parseArgs (int argc, char *argv[]){
        (argc > 1); for (int i = 1; i < argc; i++){
            std::string argumentValue = std::string(argv[i]);

            if (argumentValue == "--debug" || argumentValue == "-d"){
                debugOutput = true;
            }
            else if ((argumentValue == "--path" || argumentValue == "-p") && i+1 < argc){
                filePath = argv[i+1];
            }
            else if (argumentValue == "--help" || argumentValue == "-h"){
                helpOutput = true;
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
} cmdArgs;


int main (int argc, char *argv[]){
    cmdArgs.parseArgs(argc, argv);
    YAML::Node config = YAML::LoadFile(cmdArgs.filePath);

    std::cout << config["image"]["checks"][0] << std::endl;

    return 0;
}