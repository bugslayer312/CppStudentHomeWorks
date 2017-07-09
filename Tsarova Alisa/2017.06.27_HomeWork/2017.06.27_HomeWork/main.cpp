#include "Operation.h"

int main()
{
	Operation* operation = new SinusOperation();
	
	Calculator c(operation);

	int position = 0;

	while (position != 8)
	{
		c.ShowMenu();
		std::cin >> position;
		if (position < 8 && position >= 0)
		{
			c.ExecuteOperation(position - 1);
		}
	}
	return 0;
}