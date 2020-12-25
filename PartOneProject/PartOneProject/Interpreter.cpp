#pragma once
#include <iostream>
#include <vector>

using namespace std;

//split string
std::vector<std::string> StringSplit(const  std::string& s, const std::string& delim = ",")
{
	std::vector<std::string> elems;
	size_t pos = 0;
	size_t len = s.length();
	size_t delim_len = delim.length();
	if (delim_len == 0) return elems;
	while (pos < len)
	{
		int find_pos = s.find(delim, pos);
		if (find_pos < 0)
		{
			elems.push_back(s.substr(pos, len - pos));
			break;
		}
		elems.push_back(s.substr(pos, find_pos - pos));
		pos = find_pos + delim_len;
	}
	return elems;
}

//说明：假如“韶粵通”公交车读卡器可以判断乘客的身份，如果是“韶关”或者“广州”的“老人” “妇女”“儿童”就可以免费乘车，其他人员乘车一次扣 2 元。
/*文法规则
  <expression> ::= <city>的<person>
  <city> ::= 韶关|广州
  <person> ::= 老人|妇女|儿童
*/

//抽象表达式
class IExpression
{
public:
	virtual ~IExpression() = default;
	virtual bool Interpret(string Information) = 0;
};

//非终结表达式
class AndExpression : public IExpression
{
public:
	AndExpression(IExpression* city, IExpression* person)
		: City(city),
		  Person(person)
	{
	}
	
	bool Interpret(string Information) override
	{
		vector<string> StringArr = StringSplit(Information, "的");
		return City->Interpret(StringArr[0]) && Person->Interpret(StringArr[1]);
	}
	
private:
	IExpression* City = nullptr;
	IExpression* Person = nullptr;
};

//终结符表达式类
class TerminalExpression : public IExpression
{
public:

	explicit TerminalExpression(const vector<string>& InData)
	{
		for (const auto str : InData)
		{
			MyStrSet.push_back(str);
		}
	}

	bool Interpret(string Information) override
	{
		const auto It = find(MyStrSet.begin(), MyStrSet.end(), Information);
		if (It != MyStrSet.end())
		{
			return true;
		}
		return false;
	}

private:
	vector<string> MyStrSet;
};

class Context
{
public:
	Context()
	{
		Cities = { "韶关", "广州" };
		Persons = { "老人", "妇女", "儿童" };
		IExpression* City = new TerminalExpression(Cities);
		IExpression* Person = new TerminalExpression(Persons);
		Expression = new AndExpression(City, Person);
	}

	void CheckTicket(string Info)
	{
		bool isFree = Expression->Interpret(Info);
		if (isFree)
		{
			cout << "You are " << Info << ", free for this trip." << endl;			
		}
		else
		{
			cout <<  Info << ",you paid 2 $ for this trip." << endl;
		}
	}
	
private:
	vector<string> Cities;
	vector<string> Persons;
	IExpression* Expression;
};

int main(int argc, char* argv[])
{
	Context* Bus = new Context;
	Bus->CheckTicket("韶关的老人");
	Bus->CheckTicket("韶关的年轻人");
	Bus->CheckTicket("广州的妇女");
	Bus->CheckTicket("山东的儿童");

	delete Bus;
	return 0;
}
