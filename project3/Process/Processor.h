////////////////////////////////////////////////////////////////////
// Processor.h										              //
// ver 1.0                                                        //
// Dhaval Sonavaria, CSE687 - Object Oriented Design, Spring 2019 //
////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * -------------------
 *Header file created to use the Process function in the Process Package
 * Required Files:
 * ---------------
 * Process.cpp
 *
 *
 * Maintenance History:
 * -------------------
 * ver 1.0 : 13 Feb 2019
 * - first release
 *
 */
#pragma once
#include<string>
class Processor
{public:
	Processor();
	void startProcess(std::string p);
};
inline Processor::Processor() {};
