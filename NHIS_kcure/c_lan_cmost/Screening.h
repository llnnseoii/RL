#pragma once

#include <vector>
#include <queue>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/lexical_cast.hpp>

#include <boost/filesystem.hpp>

#include <iostream>


using namespace std;


class Screening
{
public:

	Screening(const string &);

	vector<queue<float>> scenarioMoments;
	vector<float> compliances;
	vector<float> timeSinceLastColo;
	vector<string> scenarioNames;


private:



};

