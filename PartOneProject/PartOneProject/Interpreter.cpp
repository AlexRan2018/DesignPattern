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

//˵�������硰�ػ�ͨ�������������������жϳ˿͵���ݣ�����ǡ��عء����ߡ����ݡ��ġ����ˡ� ����Ů������ͯ���Ϳ�����ѳ˳���������Ա�˳�һ�ο� 2 Ԫ��
/*�ķ�����
  <expression> ::= <city>��<person>
  <city> ::= �ع�|����
  <person> ::= ����|��Ů|��ͯ
*/

//������ʽ
class IExpression
{
public:
	virtual ~IExpression() = default;
	virtual bool Interpret(string Information) = 0;
};

//���ս���ʽ
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
		vector<string> StringArr = StringSplit(Information, "��");
		return City->Interpret(StringArr[0]) && Person->Interpret(StringArr[1]);
	}
	
private:
	IExpression* City = nullptr;
	IExpression* Person = nullptr;
};

//�ս�����ʽ��
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
		Cities = { "�ع�", "����" };
		Persons = { "����", "��Ů", "��ͯ" };
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
	Bus->CheckTicket("�عص�����");
	Bus->CheckTicket("�عص�������");
	Bus->CheckTicket("���ݵĸ�Ů");
	Bus->CheckTicket("ɽ���Ķ�ͯ");

	delete Bus;
	return 0;
}
