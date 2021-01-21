 #include <iostream>
using namespace std;
struct node
{
    string file_name;
    int file_num;
    node *prev, *next;
};
node *head, *tail;
void insert()
{
    node *newnode = new node();
    string s;
    int n, a;
    node *ptr;
    cout << "enter the file name and file number:-";cin>>s>>n;
    newnode->file_name = s;
    newnode->file_num = n;
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    }
    else if (head->file_num >= newnode->file_num)
    {
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        head = newnode;
    }
    else
    {
        ptr = head;
        while (ptr->next != head && ptr->next->file_num < newnode->file_num)
        {
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        newnode->prev = ptr;
        newnode->next->prev = newnode;
        ptr->next = newnode;
        if(newnode->next==head){tail=newnode;}
    }
}
void delete_node()
{
    node *ptr = head;
    int n;
    cout << "enter the file-number which u want to delete=";
    cin >> n;
    ptr = head;
    while (ptr->next != head && ptr->file_num != n)
    {
        ptr = ptr->next;
    }
    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
    if(ptr==head){head=head->next;}
    delete (ptr);
    cout<<"file deleted successfully"<<endl;
}
void file_list()
{
    node *temp=head;
    cout<<"------------------LIST OF FILES-------------------------------\n";
    while(temp->next!=head)
    {
        cout<<temp->file_name<<"-"<<temp->file_num<<endl;
        temp=temp->next;
    }
    cout<<temp->file_name<<"-"<<temp->file_num<<endl;
    cout<<"_______________________________________________________________\n";
}
void show_data()
{
    int n = 0, choice = 0;
    cout << "enter the file num:-";
    cin >> n;
    node *ptr = head;
    while (ptr != NULL && ptr->file_num != n)
    {
        ptr = ptr->next;
    }
    cout << ptr->file_name << "-" << ptr->file_num << endl;
    while (choice != 3)
    {
        cout << "1.next file" << endl
             << "2.prev file" << endl
             << "3.exit" << endl <<"enter your choice:"<<endl;
        cin >> choice;
        if (choice == 1)
        {
            ptr = ptr->next;
            cout << ptr->file_name << "-" << ptr->file_num << endl;
        }
        else
        {
            ptr = ptr->prev;
            cout << ptr->file_name << "-" << ptr->file_num << endl;
        }
    }
}
int main()
{

    int choice=0,n,i;
    int s;
    cout<<"------------------------------------------------------------------------------------"<<endl;
    cout<<"-------------------------\t FILE MANAGER \t\t-----------------------------"<<endl;
    cout<<"------------------------------------------------------------------------------------"<<endl;
    while(choice!=4)
    {
        cout<<"\n1.insert_files"<<endl<<"2.delete_files"<<endl<<"3.display_files"<<endl<<"4.exit"<<endl<<endl;
        cout<<"enter your choice:";cin>>choice;
        s=1,i=1,n=0;
        switch(choice)
        {
            case 1:
                cout<<"enter the number of files u want to add:-";cin>>n;
                while(i<=n)
                {
                  insert();
                  i++;
                }
                cout<<"FILE LIST"<<endl;
                file_list();
                cout<<"____________________________________________________________________________\n";
                break;
            case 2:
                file_list();
                while(s!=0)
                {
                    delete_node();
                    cout<<"0.exit"<<endl<<"1.to delete one more file"<<endl;cin>>s;
                }
                cout<<"_____________________________________________________________________________\n";
                break;
            case 3:
               file_list();
                show_data();
                cout<<"______________________________________________________________________________\n";
                break;
            case 4:
                break;
        }
    }
}

