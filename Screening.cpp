#include "Screening.h"

using namespace std;

template<typename T>
std::queue<T> to_queue(const std::string s)
{
	std::queue<T> result;
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, ',')) result.push(boost::lexical_cast<T>(item));
	return result;
}


Screening::Screening(const string &iniFile) {
	boost::property_tree::ptree pt;
	if ( boost::filesystem::exists( iniFile ) )
	{
		std::cout << "Parsing screening ini file" << std::endl;
 	 	boost::property_tree::ini_parser::read_ini(iniFile, pt);

		std::cout << "Number of scenarios: " << pt.size() << std::endl;
		boost::property_tree::ptree::const_iterator end = pt.end();
		for (boost::property_tree::ptree::const_iterator it = pt.begin(); it != end; ++it) {
			this->scenarioMoments.emplace_back(to_queue<float>(it->second.get<std::string>("moments")));
			this->compliances.emplace_back(boost::lexical_cast<float>(it->second.get<std::string>("compliance")));
			this->timeSinceLastColo.emplace_back(boost::lexical_cast<float>(it->second.get<std::string>("timeSinceLastColo")));
			this->scenarioNames.emplace_back(it->first);
		}
	}
}
