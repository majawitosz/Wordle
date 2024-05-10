//
// Created by Maja on 5/9/2024.
//

#include "ArgumentsHandleLogic.h"
void ArgumentsHandleLogic::setRepresentationScheme(ArgumentsData &data, char methodOfRepresentation){
    switch (methodOfRepresentation) {
        case 'v':
            data.methodOfRepresentation = ArgumentsData::vectorLinear;
            break;
        case 'b':
            data.methodOfRepresentation = ArgumentsData::vectorBinary;
            break;
        case 's':
            data.methodOfRepresentation = ArgumentsData::set;
            break;
        case 'u':
            data.methodOfRepresentation = ArgumentsData::unorderedSet;
            break;
        default:
            break;
    }
}

void ArgumentsHandleLogic::handleArguments(const std::vector<std::string> &arguments){



    aData.result = false;
    if(arguments.size()%2 !=0 || arguments.size() < 2 ) {
        aData.message = "Wrong number of parameters";
        throw aData;
    }
    else {
        for (int i=0; i<arguments.size(); i++) {
            if(arguments[i] == "-p"){
                this->foundFirst = true;

                if(i != arguments.size()-1){
                    if(arguments[i+1][0] != 'v' && arguments[i+1][0] != 'b' && arguments[i+1][0] != 's' && arguments[i+1][0] != 'u'){
                        aData.message = "No data system as parsed";
                        throw aData;
                    }
                    else{
                        setRepresentationScheme(aData,arguments[i+1][0]);
                    }
                }
                else{
                    aData.message = "You can not pass arguments that way";
                    throw aData;
                }
            }
            if(arguments[i] == "-d"){
                this->foundSecond = true;
                aData.methodOfRepresentation = ArgumentsData::set;
                if(i != arguments.size()-1){
                    std::ifstream file;
                    file.open(arguments[i+1]);
                    if(!file){
                        aData.message = "Can not open a file";
                        throw aData;
                    }
                    else{
                        aData.filePath =arguments[i+1];
                    }
                }
                else{
                    aData.message = "You can not pass arguments that way";
                    throw aData;
                }
            }
        }
        if(this->foundFirst && this->foundSecond){
            aData.result = true;
            aData.message = "Arguments loaded correctly, game will start with custom file system";
            throw aData;
        }
        else if(!this->foundFirst && this->foundSecond){
            aData.result = true;
            aData.message = "Arguments loaded correctly, game will start with default file system";
            throw aData;
        }
        else{
            aData.message = "Not all required parameters passed";
            throw aData;
        }
    }
}