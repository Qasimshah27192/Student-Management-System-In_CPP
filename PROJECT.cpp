#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct node      // all node(data's members)
{
	int roll_no;
	string name;
	string gender;
	int marks;
	string courses;
	int CGPA;
	
	struct node *next_add;    // pointer variable for next address
};
	node *head=NULL, *curr=NULL;

class LinkedList   // creating class
{

	
	public:
 	 
 	   //Insertion Funtion 
 	   
	int insertnode(int r_n, string n, string g, int t_m, string c, int cgpa)
 	{
 		node *tmp=new node;				// creating new node
 		
 		tmp->roll_no= r_n;
 		tmp->name= n;
 		tmp->gender= g;
 		tmp->marks= t_m;
 		tmp->courses= c;
 		tmp->CGPA= cgpa;
 		
 		tmp->next_add = NULL;
 		
 		if(head !=NULL)						// checking if coming roll_no is already exist or not
 		{
 		     node *tmp2 = head;			

    	while (tmp2 != NULL)				
      	{
			if (tmp2->roll_no == r_n)
	  		{
	    		cout << "ALready exist" << endl;
	    		return 1;
	  		}
			else
	  		{
	    		tmp2 = tmp2->next_add;
	  		}
      	}
 		                                     // to insert if the roll num is not exist
		curr = head;
 		while(curr->next_add != NULL)
 		{
 			curr = curr->next_add;
		}
		curr->next_add = tmp;
		
		}
 		else
 		{
 			head = tmp;
 			
		}
		/// writing data in the file
		// File Hndling For Insertion
		
		 ofstream os ("linked.txt", ios::out | ios::app);
    os << "Roll: " << tmp->roll_no << endl;
    os << "Name: " <<  tmp->name << endl;
    os << "Gen: " << tmp->gender << endl;
    os << "Mar: " << tmp->marks << endl;
    os << "Cour: " << tmp->courses << endl;
	os << "Cgp: " <<tmp->CGPA << endl<<endl;
	
    os.close ();
 	cout<<"values inserted"<<endl<<endl;	
 		return 0;
	}
	
	  //Display Function
	
	void Display()
	{
	    int count=1;
	    
		node *tmp;
		tmp=head;
	  if(tmp!=NULL)
	  {
		while(tmp!=NULL)
		{
			cout<<"Student Details are:"<<endl<<endl;
			cout<<count<<endl;
			cout<<"Roll_No: "<<tmp->roll_no<<endl;
			cout<<"Name: "<<tmp->name<<endl;
			cout<<"Gender: "<<tmp->gender<<endl;
			cout<<"Marks: "<<tmp->marks<<endl;
			cout<<"Courses: "<<tmp->courses<<endl;
			cout<<"CGPA: "<<tmp->CGPA<<endl;
			
			tmp=tmp->next_add;
						count++;

		}
	  }
	  else
	  {
	      cout<<"List is empty"<<endl;
	  }
		
	}
	  
	  // Delelte Function At First Position
	  
	  void del_first() 
    {
        node *tmp = head;
        if(head==NULL)
        {
            cout<<"no such roll number"<<endl;
        }    
        else
        {
            head=head->next_add;
            free(tmp);
        }
    }

   // Delete Function At Specific Function
    
	int del_roll(int rol_no)
    {
         node *temp = head;
        node *next_node=NULL;
        int i=1;
        while(i<rol_no-1)
        {
          if(temp->next_add==NULL)
          {
          cout<<"Not Found";
          return 0;
          }
          else
          {
              
              temp = temp->next_add;
              i++;
          }
        }
        next_node = temp->next_add;
         temp->next_add= next_node->next_add;
        free(next_node);
         return 0;
    }
    
      //Search Function
    
    int search_roll(int rol)
    {
        node *tmp=head;
    
        while(tmp!= NULL)
        {
            if(tmp->roll_no == rol)
            {
                cout<<"Found"<<endl;
                return 1;
            }
            else
            {
                tmp = tmp->next_add;
            }
        }
        
        cout<<"Not Found"<<endl;
        return 0;
    }
    
    //update function
 	
void update_Record(int rol1, string n1, string g1, int m1, string c1, int cgpaa1)
 {
     node *tmp=head;
     
     if(head==NULL)
     {
         cout<<"Record not found" <<endl;
     }
     while(tmp!=NULL)
    
     {
         if(tmp->roll_no == rol1)
         {
        	
 		tmp->name= n1;
 		tmp->gender= g1;
 		tmp->marks= m1;
 		tmp->courses= c1;
 		tmp->CGPA= cgpaa1;
            cout<<"Record Updated"<<endl;
         }
         if(tmp->next_add!=NULL)
         {
            
             tmp=tmp->next_add;
         }
         else
         {
             break;
         }
     }
    
 }
 
   //Pass or Fail Function
 
 int Pass_Fail(int rol)
    {
        node *tmp=head;
    
        while(tmp!= NULL)
        {
            if(tmp->roll_no == rol)
            {
                cout<<"Student Found"<<endl;
                
                cout<<"Now we will check Either this student Pass or Fail"<<endl;
                cout<<"His/Her Marks are: "<<tmp->marks<<endl;
                if(tmp->marks >= 40)
                {
                    cout<<"Congratulations!! Student is PASS"<<endl;
                }
                else
                {
                    cout<<"Unfortunately, Student is FAIL"<<endl;
                }
                return 1;
            }
            else
            {
                tmp = tmp->next_add;
            }
        }
        
        cout<<"Not Found"<<endl;
        return 0;
    }
 // getting topper information
 void Topper()
 {
     int max;
     node *tmp=head;
     max=head->marks;
      if(tmp!=NULL)
	  {
		while(tmp!=NULL)
		
		{
		    if(max < tmp->marks )
		    {
		        max=tmp->marks;
		    }
			tmp=tmp->next_add;

		}
				        cout<<"Topper Found"<<endl<<endl;
		                cout<<max<<endl;
		
	  }
	  else
	  {
	      cout<<"List is empty"<<endl;
	  }
 }
 
};	
   
     //Main Function

int main()

{
	system("color 4e");      //For Colour change

    string username,password;
    cout<<"Enter username :"<<endl;
    cin>>username;
    cout<<"Enter password :"<<endl;
    cin>>password;
    cout<<endl;
    cout<<"This Project Is Made By "<<endl<<endl;
    cout<<"\tMuhammad Zumar Haseeb "<<endl<<"\t&"<<endl;
    cout<<"\tSyed Qasim Ibrar "<<endl<<endl<<endl;
    
    if(username=="1" && password=="1")
    {
    
    
	int r,mar,cgpaa;
	string nam,gndr,cours;
	
	
	LinkedList obj;
	
	int choice,choicey;
	do
	{
	cout<<"\t    **        "<<endl;
	cout<<"\t   Welcome to Student Management System   "<<endl;
	cout<<"\t    **        "<<endl<<endl;
	
	
	cout<<"Press 1 for Insertion any Record"<<endl;
	cout<<"Press 2 for Display by File"<<endl;
	cout<<"Press 3 for Delete any Record"<<endl;
	cout<<"Press 4 for Search any Record"<<endl;
	cout<<"Press 5 for Update any Record"<<endl;
	cout<<"Press 6 for Check Specific Student Fail or Pass"<<endl;
	cout<<"Press 7 for Price of Topper Student"<<endl;
	cout<<"press 8 for Exit"<<endl;
	cout<<"Press 9 for Display by List"<<endl<<endl;
	
	
	cout<<"Enter Your Choice: ";
	cin>>choice;
	while (!choice)
    {
      cin.clear();
      cin.ignore();
      cout<<"Enter Correct Type/Format: "<<endl;
      cin >> choice;
    }
	
		
	switch(choice)
	{
		case 1:
		
			cout<<"Enter Roll_NO: ";
			cin>>r;
			 while(r == 0 || r <= -1 )
            {
                cout<< "invalid Roll_NO"<<endl;
                	cout<<"Enter Roll_NO again: ";
			cin >> r;
            }
          
	
			  cin.ignore();
			  
			cout<<"Enter name: ";
            getline(cin,nam);
            
			cout<<"Enter gender: ";
			cin >> gndr;
            
            while( gndr != "m" && gndr != "male" && gndr != "f" && gndr != "female" )
            {
                cout<< "invalid gender"<<endl;
                	cout<<"Enter gender again: ";
			cin >> gndr;
            }
           
			cout<<"Enter Marks: ";
			cin>>mar;
			while (!mar)
            {
                cin.clear();
                cin.ignore();
                cout<<"Enter Correct Type/Format: "<<endl;
                cin >> mar;
            }
			  
			cout<<"Enter course: ";
			cin >> cours;
			
            while( cours == "1" || cours == "2" || cours == "3" || cours == "4"  )
            {
                cout<< "invalid gender"<<endl;
                	cout<<"Enter gender again: ";
			cin >> cours;
            }
          
			cout<<"Enter CGPA: ";
			cin>>cgpaa;
			while (!cgpaa)
    {
      cin.clear();
      cin.ignore();
      cout<<"Enter Correct Type/Format: "<<endl;
      cin >> cgpaa;
    }

			obj.insertnode(r, nam, gndr, mar, cours, cgpaa);
		
		break;
		
		case 2:
		{
		      char str;
	      ifstream is;
	      is.open ("linked.txt");
	      
	      while (is)
		{
		  is.get (str);
		  cout << str;
		}
		
		//obj.Display();
		}
			break;
		
		case 3:
		{
		   	cout<<"Enter Student Position: ";
			cin>>r;
			while (!r)
    		{
      			cin.clear();
      			cin.ignore();
      			cout<<"Enter Correct Type/Format: "<<endl;
      			cin >> r;
    		}

    
			if(r==1)
			{
			    obj.del_first();
			}
			else
			{
			obj.del_roll(r);
			}
			cout<<"deletion done"<<endl;
			
			ofstream fout("linked.txt", ios::trunc);
			node* tmp = head;
			system("pause");
			while (tmp != NULL)
			{
				fout << "\nRoll_no: " << tmp->roll_no <<endl << "Name: " << tmp->name <<endl << "Gender: " << tmp->gender <<endl << "Marks: " << tmp->marks <<endl << "Course: " << tmp->courses <<endl <<"CGPA:  "<<tmp->CGPA<<endl<<endl;
				tmp = tmp->next_add;
			}

			fout.close();
		}
		break;
		
		
		case 4:
		    
		    cout<<"Enter Roll_NO: ";
			cin>>r;
			while (!r)
    		{
      			cin.clear();
      			cin.ignore();
      			cout<<"Enter Correct Type/Format: "<<endl;
      			cin >> r;
    		}
			obj.search_roll(r);
			cout<<"Searching Done"<<endl;
			break;
			
		case 5:

			cout<<"Enter Roll_NO: ";
			cin>>r;
			  cin.ignore();
			cout<<"Enter name: ";
            getline(cin,nam);
			cout<<"Enter gender: ";
            getline(cin,gndr);
			cout<<"Enter Marks: ";
			cin>>mar;
			  cin.ignore();
			cout<<"Enter course: ";
            getline(cin,cours);
			cout<<"Enter CGPA: ";
			cin>>cgpaa;

			obj.update_Record(r, nam, gndr, mar, cours, cgpaa);
            break;
            
        case 6:
            
            cout<<"Enter Roll_NO: ";
			cin>>r;
            obj.Pass_Fail(r);
            
            break;
            
        case 7:
        
            obj.Topper();
            
          
            
            break;
        case 8: 
		
		return 0;
		
		    
		    
		case 9:
		
		obj.Display();
		
		break;
		
        default:
		 cout<<"Invalid Choice, Please Enter Right Chocie"<<endl;
			break;
		
	}
	
	
	
	cout<<"If you want to perform any other function: Press 0";
	cout<<"\tOtherwise Press Any Integer to exit "<<endl ;
	cin>>choice;

	}
	while(choice==0);
    }
    else
    {
        cout<<"Inavlid Username or password";
    }
	
}