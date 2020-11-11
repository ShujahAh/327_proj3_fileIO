/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{

	ifstream myInputfile;
	myInputfile.open(filename.c_str());

	if (!myInputfile.is_open()){
		contents = "";
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	std::string line;
	while (!myInputfile.eof()) {
			getline(myInputfile, line);
			contents.append(line);
	}

	myInputfile.close();
	return SUCCESS;

}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream myOutputfile;
	myOutputfile.open(filename.c_str());

	if (!myOutputfile.is_open()){
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}

	for (int i = 0; i < myEntryVector.size(); i++){
		myOutputfile << myEntryVector.at(i);
		myOutputfile << "\n";
		;
	}

	myOutputfile.close();
	return SUCCESS;
}


