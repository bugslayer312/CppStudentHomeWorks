#include "Operation.h"

int main()
{
	Operation* operation = new SinusOperation();
	
	Calculator c(operation);

	int position = 0;

	while (position != c.GetCountOperations() + 1)
	{
		c.ShowMenu();
		std::cin >> position;
		if (position < c.GetCountOperations() + 1 && position >= 0)
		{
			c.ExecuteOperation(position - 1);
		}
	}
	return 0;
}