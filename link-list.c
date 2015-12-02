/*
	linked list: https://en.wikipedia.org/wiki/Linked_list

	use sentinel node: https://en.wikipedia.org/wiki/Sentinel_node
	
	Description-------
	store information with boundary mark record
*/


// file ops
void readListFromFile();
void writeListToFile();

// linked list ops
void saveToList();
void searchFromList();
void * createNode();

void encrypt();
struct bank
{
	char name[30];
	char branchCode[20];

};

struct data
{
	char user[20];
	char password;
	struct bank bk;
	char salt[20];
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}


