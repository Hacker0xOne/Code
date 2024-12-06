#include <iostream>
#include "Admin.h"
#include "AdminLogin.h"
#include "UserInterface.h"
#include "Contact.h"
#include "Users.h"
#include "ContactBook.h"
enum Identity{User=1,Admin,NewAdmin};
int main()
{
	UserInterface UI;
	UI.displayStart();
	while(1)
	{
		int choice=UI.MenuDisplayStart();
		switch(choice)
		{
			case User:
			{
				std::string name;
				std::cout << "\n\nEnter Full name to make an entry into Users.txt: ";
				getline(std::cin >> std::ws, name);
				Users user(name);
				user.checkIn();
				ContactBook cb;
				int flag=0;
				while(1)
				{
					int choice=UI.MenuDisplayUser();
					switch(choice)
					{
						case 1:
						{
						    system("cls");
							cb.listing();
							break;
						}
						case 2:
						{
                            system("cls");
							cb.searching();
							break;
						}
						case 0:
						{
                            system("cls");
							flag=1;
							break;
						}
					}
					if(flag==1) break;
				}
				break;
			}
			case Admin:
			{
				std::string uname,pass;
				std::cout<<"Enter Username & Password\n";
				std::cout<<"Username: "; std::cin>>uname;
				std::cout<<"Password: "; std::cin>>pass;
				AdminLogin AL;
				bool isLoggedIn=AL.checkCredentials(uname,pass);
				if(isLoggedIn)
				{
					
					ContactBook cb;
					int flag=0;
					while(1)
					{
						int choice=UI.MenuDisplayAdmin();
						switch(choice)
						{
							case 1:
							{
                                system("cls");
								cb.adding();
								break;
							}
							case 2:
							{
                                system("cls");
								cb.listing();
								break;
							}
							case 3:
							{
							    system("cls");
								cb.searching();
								break;
							}
							case 4:
							{
							    system("cls");
								cb.editing();
								break;
							}
							case 5:
							{
							    system("cls");
								cb.deleting();
								break;
							}
							case 0:
							{
							    system("cls");
								flag=1;
								break;
							}
						}
						if(flag==1) break;
					}
				}
				else
				{
					std::cout<<"\nIncorrect Username or Password\n";
				}
				break;
			}
			case NewAdmin:
			{
				std::string uname,pass;
				std::cout<<"Enter the username for new Admin: ";
				std::cin>>uname;
				std::cout<<"Enter(Create) the Password: ";
				std::cin>>pass;
				Administrator A(uname,pass);
				A.display_mydetails();
				break;
			}
			case 0:
			{
				std::cout<<"\n\nThank You !!!\n\n";
				exit(0);
			}
		}
	}

}
