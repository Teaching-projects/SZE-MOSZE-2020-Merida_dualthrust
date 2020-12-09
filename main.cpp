#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include "PreparedGame.h"
#include "ObserverTextRenderer.h"
#include "HeroTextRenderer.h"
#include "ObserverSVGRenderer.h"
#include "HeroSVGRenderer.h"


const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments. Only a single scenario file should be provided." },
    { 2 , "The provided scenario file is not accessible." },
    { 3 , "The provided scenario file is invalid." },
    { 4 , "JSON parsing error." }
};

void bad_exit(int exitcode){
    std::cerr 
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

int main(int argc, char** argv){
    if (argc < 2) bad_exit(1);
    if (!std::filesystem::exists(argv[1])) bad_exit(2);

    try { 
        PreparedGame game(argv[1]);
        //Register renderers (one of each)
        std::ofstream observer_stream = std::ofstream("./renderer outputs/observer_text_output.txt");
        std::ofstream hero_stream = std::ofstream("./renderer outputs/hero_text_output.txt");
        game.registerRenderer(new ObserverTextRenderer(observer_stream));
        game.registerRenderer(new HeroTextRenderer(hero_stream));
        game.registerRenderer(new ObserverSVGRenderer("./renderer outputs/observer_output.svg"));
        game.registerRenderer(new HeroSVGRenderer("./renderer outputs/character_output.svg"));

        //If there are two arguments, we passed '-test' to the program
        //In that case, the 'is test' flag is true, we pass it to the run method
       game.run(argc == 3);
    } 
    catch (const JSON::ParseException& e) 
    {
        bad_exit(4);
    }
    return 0;
}
