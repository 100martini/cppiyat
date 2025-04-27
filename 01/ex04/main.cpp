#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Ghalat: cannot open input file: " << filename << std::endl;
        return;
    }
    
    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Ghalat: cannot create output file: " << outFilename << std::endl;
        inFile.close();
        return;
    }
    
    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        
        outFile << line;
        
        if (!inFile.eof()) {
            outFile << std::endl;
        }
    }
    
    inFile.close();
    outFile.close();
    
    std::cout << "Tbdlat! Output written to " << outFilename << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    if (s1.empty()) {
        std::cerr << "Ghalat: search string cannot be empty" << std::endl;
        return 1;
    }
    
    replaceInFile(filename, s1, s2);
    
    return 0;
}