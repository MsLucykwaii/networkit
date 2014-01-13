/*
 * DynamicsGTest.cpp
 *
 *  Created on: 24.12.2013
 *      Author: cls
 */

#include "DynamicsGTest.h"

#include "../DGSStreamParser.h"

namespace NetworKit {

TEST_F(DynamicsGTest, testDGSStreamParser) {
	DGSStreamParser parser("input/example2.dgs");
	auto stream = parser.getStream();
	for (auto event : stream) {
		std::cout << event.toString() << " ";
	}
	std::cout << std::endl;
}


TEST_F(DynamicsGTest, tryDGSStreamParserOnRealGraph) {
	std::string path;
	std::cout << "enter .dgs file path: ";
	std::cin >> path;
	DGSStreamParser parser(path);
	auto stream = parser.getStream();
	for (auto event : stream) {
		std::cout << event.toString() << " ";
	}
	std::cout << std::endl;
}

} /* namespace NetworKit */
