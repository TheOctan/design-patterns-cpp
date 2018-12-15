/*
* C++ Design Patterns: Memento
*
* Memento without violating encapsulation, captures and externalizes an object's internal
* state so that the object can be restored to this state later. The pattern has behavioral
* purpose and applies to the objects.
*
*/

#include<iostream>

/*
* ### When to use ###
*
* a snapshot of an object's state must be saved so that it can be restored to that state later
* a direct interface to obtaining the state would expose implementation details and break the object's encapsulation
*
*/

// stores internal state of the Originator object and protects
// against access by objects other than the originator
class Memento
{
	friend class Number;
public:
	Memento(int value)
	{
		_state = value;
	}
	// ...

private:
	int _state;
	// ...
};

// creates a memento containing a snapshot of its current internal
// state and uses the memento to restore its internal state
class Number
{
public:
	Number(int value)
	{
		_value = value;
	}
	void doubble()
	{
		_value *= 2;
	}
	void half()
	{
		_value /= 2;
	}
	int getValue()
	{
		return _value;
	}
	Memento* createMemento()
	{
		return new Memento(_value);
	}
	void reinstateMemento(Memento* mem)
	{
		_value = mem->_state;
	}

private:
	int _value;
	// ...
};

// is responsible for the memento's safe keeping
class Command
{
	typedef void(Number::*Action)();
public:
	Command(Number* receiver, Action action)
	{
		_receiver = receiver;
		_action = action;
	}
	virtual void execute()
	{
		_mementoList[_numCommands] = _receiver->createMemento();
		_commandList[_numCommands] = this;

		if (_numCommands > _highWater)
			_highWater = _numCommands;

		_numCommands++;
		(_receiver->*_action)();
		
	}
	static void undo()
	{
		if (_numCommands == 0)
		{
			std::cout << "*** Attempt to run off the end!! ***" << std::endl;
			return;
		}

		_commandList[_numCommands - 1]->_receiver->reinstateMemento(_mementoList[_numCommands - 1]);
		_numCommands--;
	}
	static void redo()
	{
		if (_numCommands > _highWater)
		{
			std::cout << "*** Attempt to run off the end!! ***" << std::endl;
			return;
		}

		(_commandList[_numCommands]->_receiver->*(_commandList[_numCommands]->_action))();
		_numCommands++;
	}
	// ...

protected:
	Number* _receiver;
	Action _action;
	// ...

	static Command* _commandList[20];
	static Memento* _mementoList[20];
	static int		_numCommands;
	static int		_highWater;
};

Command*	Command::_commandList[];
Memento*	Command::_mementoList[];
int			Command::_numCommands	= 0;
int			Command::_highWater		= 0;


int main()
{
	int i;
	std::cout << "Integer: ";
	std::cin >> i;

	Number* object = new Number(i);

	Command* commands[3];
	commands[1] = new Command(object, &Number::doubble);
	commands[2] = new Command(object, &Number::half);

	std::cout << "Exit[0], Double[1], Half[2], Undo[3], Redo[4]: ";
	std::cin >> i;

	while (i)
	{
		if (i == 3)
			Command::undo();
		else if (i == 4)
			Command::redo();
		else
			commands[i]->execute();

		std::cout << object->getValue() << std::endl;

		std::cout << "Exit[0], Double[1], Half[2], Undo[3], Redo[4]: ";
		std::cin >> i;
	}

	for (auto obj : commands)
		delete obj;
	delete object;

	return 0;
}
