#include <iostream>

using namespace std;

enum class EQuestType
{
	primer,
	middle,
	High
};

class Request
{
public:
	explicit Request(EQuestType request_type)
		: RequestType(request_type)
	{
	}

	EQuestType request_type() const
	{
		return RequestType;
	}

	void set_request_type(EQuestType request_type)
	{
		RequestType = request_type;
	}

private:
	EQuestType RequestType;
};

class Handler
{
public:
	virtual ~Handler() = default;
	virtual void HandleRequest(Request* InRequest) = 0;
	void SetNext(Handler* InNext)
	{
		Next = InNext;
	}

protected:
	Handler* Next = nullptr;
};

class HandlerPrimer : public Handler
{
public:
	void HandleRequest(Request* InRequest) override
	{
		if (InRequest->request_type() == EQuestType::primer)
		{
			cout << "HandlerPrimer : I will handle this !" << endl;
		}
		else if (Next)
		{
			Next->HandleRequest(InRequest);
		}
		else
		{
			cout << "No one handle this !" << endl;
		}	
	}
};

class HandlerMiddle : public Handler
{
public:
	void HandleRequest(Request* InRequest) override
	{
		if (InRequest->request_type() == EQuestType::middle)
		{
			cout << "HandlerMiddle : I will handle this !" << endl;
		}
		else if (Next)
		{
			Next->HandleRequest(InRequest);
		}
		else
		{
			cout << "No one handle this !" << endl;
		}
	}
};

class HandlerHigh : public Handler
{
	void HandleRequest(Request* InRequest) override
	{
		if (InRequest->request_type() == EQuestType::High)
		{
			cout << "HandlerHigh : I will handle this !" << endl;
		}
		else if (Next)
		{
			Next->HandleRequest(InRequest);
		}
		else
		{
			cout << "No one handle this !" << endl;
		}
	}
};
//
//int main(int argc, char* argv[])
//{
//	Handler* MyPrimer = new HandlerPrimer;
//	Handler* MyMid = new HandlerMiddle;
//	Handler* MyHigh = new HandlerHigh;
//
//	Request* MyRequest1 = new Request(EQuestType::primer);
//	Request* MyRequest2 = new Request(EQuestType::middle);
//	Request* MyRequest3 = new Request(EQuestType::High);
//
//	MyHigh->SetNext(MyPrimer);
//	MyMid->SetNext(MyHigh);
//	MyPrimer->SetNext(MyMid);
//
//	MyPrimer->HandleRequest(MyRequest1);
//	MyPrimer->HandleRequest(MyRequest2);
//	MyPrimer->HandleRequest(MyRequest3);
//
//	delete MyPrimer;
//	delete MyMid;
//	delete MyHigh;
//	
//	delete MyRequest1;
//	delete MyRequest2;
//	delete MyRequest3;	
//	
//	return 0;
//}
