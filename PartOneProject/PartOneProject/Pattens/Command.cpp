#include <iostream>
#include <list>
#include <queue>
#include <Windows.h>

using namespace std;

enum class EButtonType
{
	Button_X,
	Button_Y,
	Button_A,
	Button_B
};

namespace CommandPattenCaseA
{
	class ICharacter
	{
	public:
		virtual ~ICharacter() = default;
		virtual void Jump() = 0; 
		virtual void Attack() = 0; 
		virtual void Fire() = 0;
	};

	class Player : public ICharacter
	{
	public:
		void Jump() override { cout << "Player is Jumping!" << endl; }
		void Attack() override { cout << "Player is Attacking!" << endl; }
		void Fire() override { cout << "Player is Firing!" << endl; }
	};

	class AIPlayer :public ICharacter
	{
	public:
		void Jump() override { cout << "AI is Jumping!" << endl; }
		void Attack() override { cout << "AI is Attacking!" << endl; }
		void Fire() override { cout << "AIP is Firing!" << endl; }
	};

	class Command
	{
	public:
		virtual ~Command() = default;
		virtual void Execute(ICharacter* InCharacter) = 0;
	};	
	
	class JumpCommand : public Command
	{
	public:
		void Execute(ICharacter* InCharacter) override { InCharacter->Jump(); }
	};

	class AttackCommand : public Command
	{
	public:
		void Execute(ICharacter* InCharacter) override { InCharacter->Attack(); }
	};

	class FireCommand : public Command
	{
	public:
		void Execute(ICharacter* InCharacter) override { InCharacter->Fire(); }
	};

	class EmptyCommand : public Command
	{
	public:
		void Execute(ICharacter* InCharacter) override {}
	};

	class InputHandler
	{
	public:
		Command* HandleInput()
		{
			if (IsPressed(EButtonType::Button_X))
			{
				return CommandX;
			}
			if (IsPressed(EButtonType::Button_Y))
			{
				return CommandY;
			}
			if (IsPressed(EButtonType::Button_A))
			{
				return CommandA;
			}
			if (IsPressed(EButtonType::Button_B))
			{
				return CommandB;
			}
		}

		bool IsPressed(EButtonType InType)
		{
			return true;
		}


		void set_command_x(Command* command_x)
		{
			CommandX = command_x;
		}

		void set_command_y(Command* command_y)
		{
			CommandY = command_y;
		}

		void set_command_a(Command* command_a)
		{
			CommandA = command_a;
		}

		void set_command_b(Command* command_b)
		{
			CommandB = command_b;
		}

	private:
		Command* CommandX;
		Command* CommandY;
		Command* CommandA;
		Command* CommandB;
	};
}

//using namespace CommandPattenCaseA;
//
//int main(int argc, char* argv[])
//{
//	ICharacter* MyPlayer = new Player;
//	ICharacter* MyAIPlayer = new AIPlayer;
//
//	Command* Jump = new JumpCommand;
//	Command* Fire = new FireCommand;
//	Command* Attack = new AttackCommand;
//
//	Command* Nothing = new EmptyCommand;
//
//	InputHandler* Handler = new InputHandler;
//
//	Handler->set_command_x(Jump);
//	Handler->set_command_y(Fire);
//	Handler->set_command_a(Attack);
//	Handler->set_command_b(Nothing);
//
//	Handler->IsPressed(EButtonType::Button_A);
//	Command* MyCommand = Handler->HandleInput();
//	MyCommand->Execute(MyAIPlayer);
//	MyCommand->Execute(MyPlayer);
//
//	return 0;
//}


namespace CommandPattenCaseB
{
	class Command
	{
	public:
		virtual ~Command() = default;
		virtual void Execute() = 0;
		virtual void Undo() = 0;
		virtual void Redo() = 0;
	};

	class Unit
	{
	public:
		Unit(int x, int y)
			: X(x),
			  Y(y)
		{
		}

		virtual void MoveTo(int x, int y) { X = x; Y = y; };

		int x() const
		{
			return X;
		}
		
		int y() const
		{
			return Y;
		}
		
	private:
		int X;
		int Y;
	};
	
	class MoveUnitCommand : public Command
	{
	public:

		MoveUnitCommand(Unit* my_unit, int x, int y, bool is_undo_command, bool is_redo_command)
			: MyUnit(my_unit),
			  X(x),
			  Y(y),
			  isUndoCommand(is_undo_command),
			  isRedoCommand(is_redo_command)
		{
			isUndoRedo = false;
			Current = nullptr;
		}

		virtual void Execute() override
		{
			if (isUndoRedo)
			{
				bool isStartDelete = false;
				for (list<MoveUnitCommand*>::iterator it = CommandList.begin(); it != CommandList.end(); ++it)
				{
					if (isStartDelete)
					{
						CommandList.remove(*it);
					}
					else if (*it == Current)						
					{
						isStartDelete = true;
					}
				}
			}

			MyUnit->MoveTo(X, Y);

			Current = new MoveUnitCommand(MyUnit, MyUnit->x(), MyUnit->y(),false,false);

			CommandList.push_back(Current);
		}

		virtual void Undo() override
		{
			for (list<MoveUnitCommand*>::iterator it = CommandList.begin(); it != CommandList.end(); ++it)
			{
				if ((*it) == Current)
				{
					auto LastIt = --it;
					if (LastIt != CommandList.begin())
					{
						(*LastIt)->Execute();
						Current = *LastIt;
						isUndoRedo = true;
					}
					return;
				}
			}
		}

		void Redo() override
		{
			for (list<MoveUnitCommand*>::iterator it = CommandList.begin(); it != CommandList.end(); ++it)
			{
				if ((*it) == Current)
				{
					auto NextIt = ++it;
					if (NextIt != CommandList.begin())
					{
						(*NextIt)->Execute();
						isUndoRedo = true;
					}
					return;
				}
			}
		}
		
	private:
		Unit* MyUnit;
		int X, Y;
		int XBefore, YBefore;
		MoveUnitCommand* Current;
		list<MoveUnitCommand*> CommandList;
		bool isUndoRedo;
		bool isUndoCommand;
		bool isRedoCommand;
	};

	class InputHandler
	{
	public:
		~InputHandler(){delete SelectedUnit;}
		
		Unit* GetSelectedUnit()
		{			
			return SelectedUnit;
		}
		
		void SetSelectedUnit(Unit* InUnit)
		{
			SelectedUnit = InUnit;
		}
		
		void PressButton(EButtonType InType)
		{
			Type = InType;
		}

		Command* HandleInput()
		{
			Unit* unit = GetSelectedUnit();

			if (Type == EButtonType::Button_A)
			{
				//向上移动一个单位
				int DestY = unit->y() - 1;
				return new MoveUnitCommand(unit, unit->x(), DestY, false, false);
			}

			if (Type == EButtonType::Button_B)
			{
				//向下移动一个单位
				int DestY = unit->y() + 1;
				return new MoveUnitCommand(unit, unit->x(), DestY, false, false);
			}
			
			//其他移动......


			//Button_Y 触发undo
			if (Type == EButtonType::Button_Y)
			{
				//Undo
				return new MoveUnitCommand(unit, unit->x(), unit->y(), true, false);
			}
			//Button_Y 触发redo
			if (Type == EButtonType::Button_X)
			{
				//Undo
				return new MoveUnitCommand(unit, unit->x(), unit->y(), false, true);
			}

			return nullptr;
		}

	private:
		Unit* SelectedUnit = nullptr;
		EButtonType Type;
	};
	
}

using namespace CommandPattenCaseB;

//int main(int argc, char* argv[])
//{
//	InputHandler* MyHandler = new InputHandler;
//	Unit* MyUnit = new Unit(10,10);
//	cout << MyUnit->x() << "  " << MyUnit->y() << endl;
//	
//	MyHandler->SetSelectedUnit(MyUnit);
//	//往上走了一步
//	MyHandler->PressButton(EButtonType::Button_A);
//	MyHandler->HandleInput()->Execute();	
//	cout << MyUnit->x() <<"  "<< MyUnit->y() << endl;
//
//	//往上又走了一步
//	MyHandler->PressButton(EButtonType::Button_A);
//	MyHandler->HandleInput()->Execute();
//	cout << MyUnit->x() << "  " << MyUnit->y() << endl;
//
//	//Undo
//	MyHandler->PressButton(EButtonType::Button_Y);
//	MyHandler->HandleInput()->Execute();
//	cout << MyUnit->x() << "  " << MyUnit->y() << endl;
//
//	//Redo
//	MyHandler->PressButton(EButtonType::Button_X);
//	MyHandler->HandleInput()->Execute();
//	cout << MyUnit->x() << "  " << MyUnit->y() << endl;
//	
//	return 0;
//}
