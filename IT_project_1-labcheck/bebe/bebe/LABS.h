#pragma once
#include <iostream>
#include <string>
class LABS
{
private:
	std::string PATH;
	std::string name;
	//std::string deadline;
	std::string comm;
	bool BS;
	bool report;
	bool code;
	bool IDEF0;
public:
	LABS(std::string PATHconstr, std::string nameconstr, /*std::string deadlineconstr;*/ std::string commconstr, bool BSconstr, bool reportconstr, bool codeconstr, bool IDEF0constr)
	{
		PATH = PATHconstr, name = nameconstr, /*deadline = deadlineconstr,*/ comm = commconstr, BS = BSconstr, report = reportconstr, code = codeconstr, IDEF0 = IDEF0constr;
	}
	LABS() {
		PATH = "PATHconstr", name = "nameconstr", /*deadline = deadlineconstr,*/ comm = "commconstr", BS = false, report = false, code = false, IDEF0 = false;
	}
	const std::string GET_PATH() {
		return PATH;
	}
	const std::string GET_name() {
		return name;
	}
	///const std::string GET_PATH() {
	///return PATH;
	///}
	const std::string GET_comm() {
		return comm;
	}
	const bool GET_BS() {
		return BS;
	}
	const bool GET_report() {
		return report;
	}
	const bool GET_code() {
		return code;
	}
	const bool GET_IDEF0() {
		return IDEF0;
	}
	~LABS() {};
};

