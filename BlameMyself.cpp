#include "BlameMyself.hpp"

CLI::FileCreation::FileCreation(std::string &file) : basefile_name(file) {}

std::string CLI::FileCreation::toUpperCase(std::string str)
{
    for (char &c : str)
    {
        c = std::toupper(c);
    }
    return str;
}

void CLI::FileCreation::createHeaderFile(std::unordered_set<std::string> &requiredIncludes, const includeConfMap & includesMap)
{
    int choice = 0;
    std::string headerFileName = basefile_name + ".hpp";

    std::ofstream headerFileStream{headerFileName};
    if (!headerFileStream)
    {
        std::cout << "Error: Failed to create header file." << std::endl;
        return;
    }

    std::string headerGuardMacro = "__" + toUpperCase(basefile_name) + "_HPP";
    headerFileStream << "#ifndef " << headerGuardMacro << "\n";
    headerFileStream << "#define " << headerGuardMacro << "\n";

    for (const auto &includeKey : requiredIncludes)
    {
        auto includeIterator = includesMap.find(includeKey);
        if (includeIterator != includesMap.end())
        {
            headerFileStream << includeIterator->second << "\n";
        }
    }

    headerFileStream << "\n#endif\n";
    std::cout << "Header file generated with necessary includes.\n";
    std::cout << "Would you like to add a corresponding source file as well? Type 1 for Yes and 2 for No: ";
    std::cin >> choice;

    if (choice == 1)
    {
        createSourceFile(headerFileName);
    }
    else
    {
        return;
    }
}

void CLI::FileCreation::createSourceFile(std::string &headerFileName)
{
    std::string source = basefile_name + ".cpp";
    std::ofstream sourceFileStream{source};
    if (!sourceFileStream)
    {
        std::cout << "Error: Failed to create source file." << std::endl;
        return;
    }
    sourceFileStream << "#include \"" + headerFileName + "\"\n"; 
    std::cout << "Source file generated with necessary includes.\n";
}



includeConfMap CLI::CliApp::loadIncludesFromFile(const std::string & fileName){
    std::unordered_map<std::string, std::string> includesMap;
    std::ifstream configFile(fileName);

    if (!configFile.is_open()) {
        std::cerr << "Error: Could not open the configuration file: " << fileName << std::endl;
        return includesMap; 
    }

    std::string line;
    while (std::getline(configFile, line)) {
        std::stringstream ss(line);
        std::string key, value;
        if (std::getline(ss, key, '=') && std::getline(ss, value)) {
            key.erase(0, key.find_first_not_of(" \t"));
            key.erase(key.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);
            includesMap[key] = value;
        }
    }

    configFile.close();
    return includesMap;

}