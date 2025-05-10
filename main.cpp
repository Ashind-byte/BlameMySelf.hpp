#include "BlameMyself.hpp"
#include <unordered_set>



int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage: HeaderGen <filename> <config-file>\n";
        return 1;
    }

    std::cout << "Welcome to the standard library header includer!\n";

    std::string file_name = argv[1];
    std::string configFileName = argv[2];
    CLI::CliApp app;
    auto includes = app.loadIncludesFromFile(configFileName);
    if (includes.empty()) {
        std::cerr << "No valid includes found or failed to load the configuration file." << std::endl;
        return 1;
    }

    if (file_name.length() >= 3)
    {
        CLI::FileCreation f{file_name};
        int _header_choice;
        std::cout << "Do you want to add any headers? Type 1 for YES and 2 for NO: ";
        std::cin >> _header_choice;

        if (_header_choice == 1)
        {
            int add_more_choice = 1;
            std::string item_name;
            std::unordered_set<std::string> headerList;

            while (add_more_choice == 1)
            {
                std::cout << "Enter a standard library item to add to your header file: ";
                std::cin >> item_name;
                if (includes.find(item_name) == includes.end())
                {
                    std::cout << "Invalid header item. Please try again.\n";
                    continue;
                }

                headerList.insert(item_name);

                std::cout << "Would you like to add more? Type 1 for YES and 2 for NO: ";
                std::cin >> add_more_choice;
            }

            f.createHeaderFile(headerList, includes); 
        }
        else
        {
            std::cout << "No headers added. Exiting without creating a file.\n";
        }
    }
    else
    {
        std::cerr << "Filename must be at least 3 characters long.\n";
        return 1;
    }

    return 0;
}