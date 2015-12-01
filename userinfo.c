#include <stdlib.h>
#include <stdio.h>

#define FIRSTNAMEBUFFER 10
#define LASTNAMEBUFFER 10
/*
	check for reentrant code

*/
typedef struct userinfo{
	int id;
	char *firstName;
	char *lastName;
} useri;

typedef useri *userinfop;

typedef struct u
{
	userinfop userinfo;
	struct u *next;
} user;


typedef user *userp;

/*store last id insert and need semaphore or mutual exclusion to control it access*/
int semaphoreForId = 0;
int lastId = 1;

userp first = NULL;
userp last = NULL;
userp *userlist = NULL;

/* functions  prototype*/

	/*return user id*/
	int insert(userinfop);
	userp allocUser();
	userinfop allocUserInfo();
	void readAll();
	userp readById(int);
	/*return first user with matched name*/
	userp readByfName();

/* function prototype ends */



int main()
{
	userinfop ui = allocUserInfo();

	printf("Start insert user\n");
	ui->firstName = (char*) malloc(sizeof(char)*FIRSTNAMEBUFFER);
	ui->lastName = (char*) malloc(sizeof(char)*LASTNAMEBUFFER);
	printf("Enter first name: ");
	fgets(ui->firstName,FIRSTNAMEBUFFER,stdin);
	printf("\nEnter last name: ");
	fgets(ui->lastName,LASTNAMEBUFFER, stdin);
	insert(ui);
	insert(ui);

	readAll();
	

}

void readAll()
{
	userp fu = first;
	while (fu != NULL) {
		printf("firsname: %s, lastName: %s\n", fu->userinfo->firstName, fu->userinfo->lastName);
		fu = fu->next;
	}
}

int insert(userinfop userInfo)
{

	userp u = allocUser();
	u->userinfo = userInfo;
	u->next = NULL;
	printf("%s\n",u->userinfo->firstName);
	if (userlist == NULL) {
		first = last = u;
		userlist = &u;
	} else {
		last->next = u;
		last = u;

	}
	//userlist.next = NULL;
	
	return 0;
}

userp allocUser()
{
	userp usMem = (userp) malloc(sizeof(user));

	return usMem;
}

userinfop allocUserInfo()
{
	userinfop usMem = (userinfop) malloc(sizeof(useri));

	return usMem;
}