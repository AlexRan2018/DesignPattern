#include <iostream>
#include <string>

using namespace std;

//put an animal in fridge

class Animal
{
public:
	Animal(const string& name, float weight)
		: Name(name),
		  Weight(weight)
	{
	}

	string name() const
	{
		return Name;
	}

	void set_name(const string& name)
	{
		Name = name;
	}

	float weight() const
	{
		return Weight;
	}

	void set_weight(float weight)
	{
		Weight = weight;
	}

protected:
	string Name;
	float Weight;
};


class PutAnimalInFridgeOperatorTemplate
{
public:
	virtual ~PutAnimalInFridgeOperatorTemplate() = default;
	
	void PutStream(Animal* InAnimal)
	{
		OpenFridge();
		PutAnimalIn(InAnimal);
		CloseFridge();
		NoticeOtherAnimals();
	}

protected:
	virtual void OpenFridge() = 0;
	virtual void PutAnimalIn(Animal* InAnimal) = 0;
	virtual void CloseFridge() = 0;
	virtual void NoticeOtherAnimals() = 0;
};

class PutElephantOperator : public PutAnimalInFridgeOperatorTemplate
{
protected:
	void OpenFridge() override
	{
		cout << "Elephant fridge is open!" << endl;
	}
	
	void PutAnimalIn(Animal* InAnimal) override
	{
		cout << InAnimal->name() << " is put in fridge." << endl
			<< "its weight is " << std::to_string(InAnimal->weight()) << endl;
	}
	
	void CloseFridge() override
	{
		cout << "Elephant fridge is closed!" << endl;
	}
	
	void NoticeOtherAnimals() override
	{
		cout << "Elephant is hidden!" << endl;
	}
};

class PutMonkeyOperator : public PutAnimalInFridgeOperatorTemplate
{
protected:
	void OpenFridge() override
	{
		cout << "Monkey fridge is open!" << endl;
	}

	void PutAnimalIn(Animal* InAnimal) override
	{
		cout << InAnimal->name() << " is put in fridge." << endl
			<< "its weight is " << std::to_string(InAnimal->weight()) << endl;
	}

	void CloseFridge() override
	{
		cout << "Monkey fridge is closed!" << endl;
	}

	void NoticeOtherAnimals() override
	{
		cout << "Monkey is hidden!" << endl;
	}
};

//int main(int argc, char* argv[])
//{
//	Animal* Elephant = new Animal("Elephant", 500);
//	Animal* Monkey = new Animal("Monkey", 10);
//
//	PutAnimalInFridgeOperatorTemplate* PutElephant = new PutElephantOperator;
//	PutAnimalInFridgeOperatorTemplate* PutMonkey = new PutMonkeyOperator;
//
//	PutElephant->PutStream(Elephant);
//	cout << "========================" << endl;
//	PutMonkey->PutStream(Monkey);
//
//	delete Elephant;
//	delete Monkey;
//	delete PutElephant;
//	delete PutMonkey;
//	return 0;
//}
