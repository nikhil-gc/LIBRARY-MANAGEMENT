// library management system

#include <bits/stdc++.h>

using namespace std;
// CREATING A STUDENT CLASS
class student{
    public:
    int student_id;
    set<int> req_books;
    student(int student_id){
        this->student_id = student_id;
        req_books.clear();
    }
};
// CREATING A BOOK CLASS
class book{
    public:
    int book_id;
    int num_of_copies;
    vector<int> students;
    book(int book_id, int num_of_copies){
        this->book_id = book_id;
        this->num_of_copies = num_of_copies;
    }
};
// CREATING A LIBRARY CLASS
class library{
    public:
    map<int,student*> rno_to_student;
    map<int,book*> bid_to_book;
    library(){
        this->rno_to_student.clear();
        this->bid_to_book.clear();
    }
    // ADDING NEW STUDENT INTO THE LIBRARY
    void add_new_student(){
        cout<<"Enter Your Student id "<<endl;
        int student_id;
        cin>>student_id;
        if(rno_to_student.find(student_id)!=rno_to_student.end()){
            cout<<"student already exists";
            return;
        }
        student* s = new student(student_id);
        rno_to_student[student_id] = s;
        cout<<"account successfully created with id "<<student_id<<endl;
    }
    // ADDING NEW BOOK INTO THE LIBRARY
    void add_new_book(){
        int book_id, num_of_copies;
        cout<<"Enter the book id"<<endl;
        cin>>book_id;
        if(bid_to_book.find(book_id)!=bid_to_book.end()){
            cout<<"book already exists"<<endl;
            return;
        }
        cout<<"Enter Number of copies"<<endl;
        cin>>num_of_copies;
        book* b = new book(book_id,num_of_copies);
        bid_to_book[book_id] = b;
        cout<<"book successfully added to the library"<<endl;
    }
    // REQUESTING A BOOK FROM THE LIBRARY
    void request_a_book(){
        int sid,bid;
        cout<<"Enter Your student id "<<endl;
        cin>>sid;
        cout<<"Enter your book id "<<endl;
        cin>>bid;
        if(rno_to_student.find(sid)==rno_to_student.end()){
            cout<<"Student doest exist ! please create a new account "<<endl;
            return;
        }
        if(bid_to_book.find(bid)==bid_to_book.end()){
            cout<<"Requested book doesnt exist "<<endl;
            return;
        }
        student *s = rno_to_student[sid];
        if(s->req_books.size()==3){
            cout<<"You took the maximum books(3), please return the old books to request a new book";
            return;
        }
        book *b = bid_to_book[bid];
        if(b->num_of_copies == 0){
            cout<<"No copies are available for requested book "<<endl;
            return;
        }
        s->req_books.insert(bid);
        b->num_of_copies--;
        cout<<"The student with id "<<sid<<" successfully borrowed the book with id "<<bid<<endl;
    }
    // RETURNING THE BOOK TO THE LIBRARY
    void return_a_book(){
        int sid,bid;
        cout<<"Enter Your student id "<<endl;
        cin>>sid;
        cout<<"Enter your book id "<<endl;
        cin>>bid;
        if(rno_to_student.find(sid)==rno_to_student.end()){
            cout<<"Student doest exist ! please create a new account "<<endl;
            return;
        }
        if(bid_to_book.find(bid)==bid_to_book.end()){
            cout<<"book doesnt exist "<<endl;
            return;
        }
        student *s = rno_to_student[sid];
        book *b = bid_to_book[bid];
        if(s->req_books.find(bid)==s->req_books.end()){
            cout<<"You did'nt have the book with the given book-id, please enter valid book id "<<endl;
            return;
        }
        s->req_books.erase(bid);
        b->num_of_copies++;
        cout<<"The student with id "<<sid<<" successfully returned the book with id "<<bid<<endl;
    }
    // PRINTING THE ACCOUNT DETAILS OF THE LIBRARY ACCOUNT HOLDER
    void print_account_details(){
        cout<<"Enter your student id "<<endl;
        int sid;
        cin>>sid;
        if(rno_to_student.find(sid)==rno_to_student.end()){
            cout<<"Student doest exist ! please create a new account "<<endl;
            return;
        }
        student* s = rno_to_student[sid];
        if(s->req_books.size()==0){
            cout<<"The student doesnt hold any books"<<endl;
        }else{
            cout<<"The book ids of the books took by the student"<<endl;
            for(auto it : s->req_books){
                cout<<"book id -> "<<it<<endl;
            }
        }
    }
};

int main()
{
    library *lib = new library();  
    cout<<"\t\t\t------- Library Management System --------"<<endl;
    while(1){
      cout<<endl;
      cout<<"--------------------------------"<<endl;
      cout<<"Enter 1 to create new account "<<endl;
      cout<<"Enter 2 to add new book into library "<<endl;
      cout<<"Enter 3 to request new book"<<endl;
      cout<<"Enter 4 to return a book"<<endl;
      cout<<"Enter 5 to show the account details "<<endl;
      cout<<"Enter 0 to exit"<<endl<<endl;
      int input;
      cin>>input;
      switch(input){
          case 1:
          lib->add_new_student();
          break;
          case 2:
          lib->add_new_book();
          break;
          case 3:
          lib->request_a_book();
          break;
          case 4:
          lib->return_a_book();
          break;
          case 5:
          lib->print_account_details();
          break;
          default:
          return 0;
      }
    }
    return 0;
}
