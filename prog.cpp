#include<iostream>
#include<sstream>
#include<fstream>
#include<string.h>
//#include<conio.h>
using namespace std;

class Login{ 
	protected:		
		char username[100];
		char password[50];
		char sec_answer_1[50];
		unsigned int access;
	public:
		void Register();
		void login(char user_n[], char pass[]);
		void Export();
		void Read();
		void Login_Output();
		void Login_SecQues();
		void Enter_NewPass(char new_pass[],char check_new_pass[]);
		
};

void Login :: Register()
{
	ofstream fout("login_data.txt",ios::trunc);
	cout<<"Enter username(mail): ";
	cin>>username;
	cout<<"Enter your preferred password: ";
	cin>>password;
	cout<<endl;
	cout<<"Answer the security question >>> ";
	cout<<"Which is your favourite game: ";
	cin>>sec_answer_1;
	cout<<"Press 1. Member 2.Admin: ";
	cin>>access;
	fout<<username<<" "<<password<<" "<<access<<" "<<sec_answer_1<<" "<<endl;
	fout.close();
}

void Login::Read()
{
	ifstream fin("login_data.txt",ios::in);
	while(fin>>username>>password>>access)
	{
		cout<<"Username - "<<username<<"\n"<<"Password - "<<password<<"\n"<<"role - "<<access<<"\n"<<endl;
	}
	fin.close();
}

void Login::login(char user_n[], char pass[])
{
	int f_pass;
	int again;
	ifstream fin("login_data.txt",ios::in);
	while(fin>>username>>password>>access>>sec_answer_1)
	{
	        if(strcmp(user_n,this->username)==0 && strcmp(pass,this->password)==0)
		    {
			Login_Output();
		    }
		else
		{
		    cout<<endl;
		    cout<<"Wrong Username OR PASSWORD"<<endl;
		    cout<<"1. Try Again"<<endl;
		    cout<<"2. Forgot PASSWORD"<<endl;
		    cout<<"Enter choice: ";
		    cin>>f_pass;
		    cout<<endl;
		    if (f_pass==1)
		    {	        
	           	again = 1;
	           	break;
	           	//login(username,password);
		    }
		    
		    else if(f_pass==2)
		    {
		        char answer_1[50];
		        //Login_SecQues();
		        cout<<"Which is your favourite game: ";
			cin>>answer_1;
		    	if(strcmp(answer_1,sec_answer_1)==0)
		    	{   
		    	    ofstream fout("login_data.txt",ios::trunc);
		    	    //strcpy(sec_answer_1,answer_1);
		    	    char new_pass[50];
			    char check_new_pass[50];
		    	    Enter_NewPass(new_pass,check_new_pass);
		    	    if(strcmp(check_new_pass,new_pass)==0)
		    	       {
			    	    strcpy(password,new_pass);
			    	    fout<<username<<" "<<password<<" "<<access<<" "<<answer_1<<endl;
				    fout.close();
				    Login_Output();
		    	       }
		    	    else
		    	       {    
		    	    	    Enter_NewPass(new_pass,check_new_pass);
		    	    	    Login_Output();
		    	       }
		    	}
		    	else
		    	{
		    		cout<<"\n\n\n\n\n\nSORRY"<<endl;
		    		cout<<"Wrong Answer --XXXXXXXXXXXXXXXXX\n\n\n\n";
		    		cout<<endl;
		    		break;
		    	}
	     	      }
    	            }
	  }
	fin.close();
	if (again==1)
	{
	char Username[50];
        char Password[50];
        cout<<" Username : "; cin>>Username;
   	cout<<" Password : "; cin>>Password;
	login(Username,Password);
	}
}

//void Login :: Login_SecQues(){}


void Login::Enter_NewPass(char new_pass[],char check_new_pass[])
{
	cout<<"Enter new PASSWORD: ";
	cin>>new_pass;
	cout<<"ReEnter new PASSWORD: ";
	cin>>check_new_pass;

}



void Login :: Login_Output()
{
    if(access==1)
		{
			cout<<"Welcome Back "<<username<<endl;
		}
    else if(access==2)
		{
			cout<<"Another day at work, isn't it "<<username<<endl;
		}
}




void Login::Export()
{
	ifstream fin("login_data.txt",ios::in);
	ofstream fout("Login_data.csv",ios::out);
	fout<<"USERNAME"<<","<<"PASSWORD"<<","<<"ROLE(1=Member 2=Admin)"<<endl;
	while(fin>>username>>password>>access)
	{
		if(access==1)
			fout<<username<<","<<password<<","<<"Member"<<endl;
		else if(access==2)
			fout<<username<<","<<password<<","<<"Admin"<<endl;
	}
	fin.close();
	fout.close();
}

int main()
{
	Login l1;
    while(1)
    {
	    //system("cls");
	    char username[100],password[50];
	    unsigned int ch;
	    cout<<endl;
	    cout<<" ********  Welcome to Car Rental System *********";
	    cout<<"\n 1. Login \n 2. Register \n 3. Read \n 4.Export \n 5. Exit"<<endl;
	    cout<<"Enter choice: ";
	    cin>>ch;
	    switch(ch)
	    {
	        case 1:
	           		cout<<" Username : "; cin>>username;
	           		cout<<" Password : "; cin>>password;
	           		l1.login(username,password);
	        	break;
	        case 2:
	                l1.Register();
	        	break;
	        case 3:
	        		l1.Read();
	        	break;
	        case 4:
	        		l1.Export();
	        		cout<<"File has been made in the folder"<<endl;
	        	break;
	        case 5:
	            exit(1);
	    }
	    cout<<endl;
	    cout<<"Press anything to proceed: ";
	    //getc();
  }
}
