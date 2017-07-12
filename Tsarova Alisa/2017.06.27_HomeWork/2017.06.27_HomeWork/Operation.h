#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

class Operation
{
protected:
	std::string m_name;

public:
	Operation()
	{
		m_name = nullptr;
	}

	Operation(std::string name) : m_name(name)
	{
	}

	std::string GetName() const
	{
		return m_name;
	}

	virtual void Execute() = 0;
};

class SummOperation : public Operation
{
public:
	SummOperation() : Operation("Summ operation")
	{
	}
	
	void Execute()
	{
		double leftOperand;
		std::cout << "Please enter left operand: ";
		std::cin >> leftOperand;

		double rigthOperand;
		std::cout << "Please enter right operand: ";
		std::cin >> rigthOperand;

		std::cout << leftOperand << " + " << rigthOperand << " = " << leftOperand + rigthOperand << std::endl;
	}
};

class DifferenceOperation : public Operation
{
public:
	DifferenceOperation() : Operation("Difference operation")
	{
	}
	
	void Execute()
	{
		double leftOperand;
		std::cout << "Please enter left operand: ";
		std::cin >> leftOperand;

		double rigthOperand;
		std::cout << "Please enter right operand: ";
		std::cin >> rigthOperand;

		std::cout << leftOperand << " - " << rigthOperand << " = " << leftOperand - rigthOperand << std::endl;
	}
};

class MultiplyOperation : public Operation
{
public:
	MultiplyOperation() : Operation("Multiply operation")
	{
	}

	void Execute()
	{
		double leftOperand;
		std::cout << "Please enter left operand: ";
		std::cin >> leftOperand;

		double rigthOperand;
		std::cout << "Please enter right operand: ";
		std::cin >> rigthOperand;

		std::cout << leftOperand << " * " << rigthOperand << " = " << leftOperand * rigthOperand << std::endl;
	}
};

class DivedeOperation : public Operation
{
public:
	class Exception
	{
	};

	DivedeOperation() : Operation("Divide operation")
	{
	}

	void Execute()
	{
		double leftOperand;
		std::cout << "Please enter left operand: ";
		std::cin >> leftOperand;

		double rigthOperand;
		std::cout << "Please enter right operand: ";
		std::cin >> rigthOperand;

		if (rigthOperand == 0)
		{
			throw Exception();
		}

		std::cout << leftOperand << " / " << rigthOperand << " = " << leftOperand / rigthOperand << std::endl;
	}
};

class ExponentOperation : public Operation
{
	const double m_e = 2.71828;
public:
	ExponentOperation() : Operation("Exponent operation")
	{
	}

	void Execute()
	{
		double degree;
		std::cout << "Please enter degree: ";
		std::cin >> degree;

		std::cout << m_e << " in degree " << degree << " = " << pow(m_e, degree) << std::endl;
	}
};

class SinusOperation : public Operation
{
public:
	SinusOperation() : Operation("Sinus operation")
	{
	}

	void Execute()
	{
		double operand;
		std::cout << "Please enter operand: ";
		std::cin >> operand;

		std::cout << "sin(" << operand << ") = " << sin(operand) << std::endl;
	}
};

class CosineOperation : public Operation
{
public:
	CosineOperation() : Operation("Cosine operation")
	{
	}

	void Execute()
	{
		double operand;
		std::cout << "Please enter operand: ";
		std::cin >> operand;

		std::cout << "cos(" << operand << ") = " << cos(operand) << std::endl;
	}
};

class Calculator
{
	std::vector<Operation*> m_operations;
public:
	Calculator(Operation* operation)
	{
		m_operations.push_back(new SummOperation());
		m_operations.push_back(new DifferenceOperation());
		m_operations.push_back(new MultiplyOperation());
		m_operations.push_back(new DivedeOperation());
		m_operations.push_back(new ExponentOperation());
		m_operations.push_back(new SinusOperation());
		m_operations.push_back(new CosineOperation());
	}

	~Calculator()
	{
		std::vector<Operation*>::iterator it = m_operations.begin();
		while (it != m_operations.end())
		{
			delete *it;
			it++;
		}
	}

	void ShowMenu()
	{
		std::cout << "Please, choose the operation: " << std::endl;
		std::vector<Operation*>::iterator it;
		it = m_operations.begin();
		int i = 1;
		while (it != m_operations.end())
		{
			std::cout << i << '.' << (*it)->GetName() << std::endl;
			it++;
			i++;
		}
		std::cout << i << ".Exit" << std::endl;
	}

	void ExecuteOperation(int position)
	{
		m_operations[position]->Execute();
	}

	int GetCountOperations() const
	{
		return m_operations.size();
	}
};