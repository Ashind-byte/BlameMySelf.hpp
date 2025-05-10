#include <iostream>
#include <unordered_map>
#include<fstream>
#include<algorithm>
#include<unordered_set>
#include<sstream>


using includeConfMap = std::unordered_map<std::string, std::string>;
namespace CLI
{
    
    class CliApp
    {
        public:
        includeConfMap loadIncludesFromFile(const std::string&);

    };

    class FileCreation{
        std::string basefile_name;
        public:
                FileCreation(std::string&);
                void createHeaderFile(std::unordered_set<std::string> &requiredIncludes, const includeConfMap & includesMap);
                std::string toUpperCase(std::string);
                void createSourceFile(std::string &);
                
    };
}
