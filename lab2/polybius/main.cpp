//
// Created by Zuzanna Obajtek on 2018-03-12.
//

#include "Polybius.h"
using namespace std;

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        cout << "Incorrect number of arguments.";
        return 1;
    }
    else {
        ifstream sourceFile(argv[0]);
        if (!sourceFile)
            return 1;
        ofstream outputFile(argv[1], ios_base::in);
        if (!outputFile)
            return 1;

        char c;

        if (*argv[2] == 0) {
            string message;
            while(sourceFile>>message){}
            string crypted = PolybiusCrypt(message);
            outputFile << crypted;
        }
        else if (*argv[2] == 1) {
            string crypted;
            while(sourceFile>>crypted);
            string message = PolybiusDecrypt(crypted);
            outputFile << message;
        }

        sourceFile.close();
        outputFile.close();
    }

}