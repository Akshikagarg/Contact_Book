#include<iostream>
#include <fstream>             //File handling
#include <sstream>             //Allows a string object to be treated as a stream
#include "MergeSort.cpp"
using namespace std;
#define ll long long


class Contact_Book
{
    private:
        Node *head;
        string name;
        ll x;
     
    public:
        Contact_Book()     //constructor
        {
            head=NULL;
            name="";
            x=0;
        }


        void Structure()
    	{
            int i=1;
            while(i)
            {
	    	cout<<endl<<"***********"<<endl;
	    	cout<<" 1. Add Contact"<<endl;
	    	cout<<" 2. Edit a Contact"<<endl;
	    	cout<<" 3. Delete Contact"<<endl;
	    	cout<<" 4. Search Contact"<<endl;
	    	cout<<" 5. Display All Contacts"<<endl;
	    	cout<<" 6. Delete All Contacts"<<endl;
            cout<<" 7. EXIT"<<endl;
	    	cout<<"***********"<<endl;
		
	    	int Choice;
	    	cout<<" Enter the Choice: ";
	    	cin>>Choice;
	    	
            switch(Choice)
	    		{
	    		    case 1:
	            	{
                        CreateContact();
	            		OfflineSave();
                        break;
                    }
	            	
	            	case 2:
		        	{
		        		EditContacts();
		        		OfflineSave();	
                        break;
                    }    
			        
	            	case 3:
	            	{
	    	        	DeleteContact();
                        OfflineSave();
                        break;
                    }

	            	case 4:
	            	{
	            		Search_op();
                        break;
                    }

	            	case 5:
	            	{     		
	            		Display();
	            		OfflineSave();
                        break;
                    }

	            	case 6:
	            	{
	            		DeleteAllContacts();
	            		OfflineSave();
                        break;
                    }
                    case 7:
                    {
                        cout<<" THANK YOU!";
                        i=0;
                        break;
                    }
                    
                    default:
                    {
                        cout<<" Oops! Invalid choice";
                    }
	
	            }
            }
        }


        void Display()                                     //For displaying contacts
        {
            if(head==NULL) cout<<" CONTACT BOOK IS EMPTY"<<endl<<" THANK YOU"<<endl;
            else
            {
                MergeSort(head);
                Node *temp=head;
                int count=0;                              //to count number of contacts

                cout<<"NAME"<<"\t \t"<<"NUMBER";
                while(temp!=NULL)
                {
                    cout<<endl;
                    cout<<temp->Name<<"\t \t"<<temp->Phone_Number;
                    temp=temp->next;
                    count++;
                }
                cout<<endl<<"TOTAL CONTACTS:"<<count<<endl;
            }
        }


        void CreateContact()                          //For creating new contact
        {
            cout<<" ENTER CONTACT NAME: "; cin>>name;
            cout<<" ENTER PHONE NUMBER: "; cin>>x;
            if(head==NULL)
            {
                Node *New=new Node;
                New->Name=name;
                New->Phone_Number=x;
                New->next=NULL;
                New->prev=NULL;
                head=New;
            }
            else
            {
                Node *New=new Node;
                New->Name=name;
                New->Phone_Number=x;
                New->next=NULL;
                Node *temp=head;
                while(temp->next!=NULL) temp=temp->next;
                New->prev=temp;
                temp->next=New;
            }
            cout<<" CONTACT ADDED SUCCESSFULLY"<<endl;
        }

        Node *Search()
    	{
    		bool check=false;
	    	Node *temp=head;
	    	cout<<"***********"<<endl;
	    	cout<<" Press 1 if you want to Search By Name."<<endl;
	    	cout<<" Press 2 if you want to Search By Number."<<endl;
	    	int choice;
	    	cout<<" Enter the Choice: ";
	    	cin>>choice;
	  
	    	if(choice==1 && temp!=NULL)
	    	{
	    		cout<<" ENTER NAME: "; cin>>name;
		    	while(temp!=NULL)
		    	{
		        	if(temp->Name==name)
		        	{
                        check=true;
		        		return temp;
		        	}
		        	temp=temp->next;
	        	}
	        	if(check==false) return NULL;
	    	}
	    	else if(choice==2)
	    	{
	    		cout<<" ENTER NUMBER: "; cin>>x;
				
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->Phone_Number==x)
		        	{
                        check=true;
		        		return temp;
		        	}
			        temp=temp->next;
	        	}
				if(check==false) return NULL;	
	    	}
            else cout<<"Invalid choice"; return NULL;
	    }


        void Search_op()
        {
            Node *temp=Search();
            if(temp!=NULL)
            {
                cout<<endl<<"***********"<<endl;
                cout<<" Name: "<<temp->Name<<endl;
                cout<<" Phone Number: "<<temp->Phone_Number<<endl;
            }
            else cout<<" CONTACT NOT FOUND";
            cout<<endl;
        }


        void DeleteContact()
    	{ 
            Node *temp=Search();
            if(temp==NULL) cout<<" CONTACT NOT FOUND";
            else
            {
                if(temp==head)
                {
                    Node *t;
                    t=temp;
                    temp=temp->next;
                    delete t;
                    temp->prev=NULL;
                    head=temp;
                }
                else if(temp->next==NULL)
                {
                    temp->prev->next=NULL;
			    	delete temp;
                }
                else{
                    Node *t;
                    t=temp;
                    temp->prev->next=t->next;
                    temp->next->prev=t->prev;
                    delete t;
                }
                cout<<" CONTACT SUCCESSFULLY DELETED";
            }
            cout<<endl;
        }


        void EditContacts()
        {
            Node *temp=Search();
            if(temp==NULL) cout<<" CONTACT NOT FOUND";
            else
            {
                cout<<" Enter New Name: "; cin>>name;
                cout<<" Enter New Number: "; cin>>x;
                temp->Name=name;
                temp->Phone_Number=x;
                cout<<" CONTACT EDITED SUCCESSFULLY";
            }
            cout<<endl;
        }  


        void DeleteAllContacts()
	    {
	    	Node *temp=head;
	    	Node *del;
	    	if(head==NULL)
	    	{
	    		cout<<" CONTACT BOOK IS EMPTY"<<endl;
	    		cout<<"***********"<<endl;
			}
			else
			{
				while(temp!=NULL)
				{
					del=temp;
					temp=temp->next;
					delete del;
				}
				head=NULL;
				cout<<" SUCCESSFULLY DELETED ALL CONTACTS"<<endl;
	    		cout<<"***********"<<endl;
			}
		}


        void OfflineSave()                                                //to save in file
    	{
    		Node *temp=head;
    		ofstream myfile ("Contact book.txt");
            if (myfile.is_open())
            {
            	while(temp!=NULL)
	        	{
	        	    myfile<<temp->Name<<endl;
		        	myfile<<temp->Phone_Number<<endl;
    		    	temp=temp->next;		
	        	}
                myfile.close();
            }
            else
            {
            	cout<<" FILE IS EMPTY!"<<endl;
			}
		}
		
		void reopen()                                                   //to open file
		{
			bool isEmpty;
			ifstream myfile ("Contact Book.txt");
            if (myfile.is_open() & myfile.peek() != EOF)
            {
                int i=0;
                while(getline(myfile,name))
                {	
                    if(i % 2 == 0)
					{
						if(head==NULL)
	                    {
    	                  Node *New= new Node;
                          New->Name=name;
		         
	                      New->next=NULL;
	                      New->prev==NULL;
	                      head=New;
		                }
						else
						{
							Node *New= new Node;
							
							New->Name=name;
							New->next=NULL;
							
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	temp->next=New;
		                	New->prev=temp;		
						} 
                    }
                   else
                    {
                    	Node *temp=head;
                    	if(temp->Phone_Number==0)
                    	{
                    		
                    		 stringstream convert(name);
			       	         convert>>x;
                             temp->Phone_Number=x;
						}
						else
						{
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	
		                	stringstream convert(name);
                            convert>>x;
                            temp->Phone_Number=x;
							
						}
                       
				    }
                    i++;
                }
            	myfile.close();
            }
            else
            {
            	cout<<" FILE IS EMPTY!"<<endl;
			}
		}
};
        



