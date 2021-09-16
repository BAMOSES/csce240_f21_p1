// Author: Blaise Moses
// Email: bamoses@email.sc.edu
// Section #: 003
// Copyright 2021 Blaise Moses
// Modified from template code @coleca24 GitHub
#ifndef LOGIN_H_
#define LOGIN_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::string;

const int COLS = 4;
const int ROWS = 5;

// TODO(commit 1): Commit #1 functions
void printUsers(const string data[ROWS][COLS]);
bool readUsers(string fh, string data[ROWS][COLS]);
char displayOptions();
bool validateOption(char option);
void executeOption(char option, string data[ROWS][COLS], string);
int searchForUser(string name, const string data[ROWS][COLS]);

// TODO(commit 2): Commit #2 functions
int findAllUsers(string title, const string data[ROWS][COLS]);
bool deleteUser(string name, string data[ROWS][COLS], string fh);
string generatePassword();
string generateEmail(string name);
int checkEmpty(const string data[ROWS][COLS]);
void addUser(int index, string name, string title,
             string data[ROWS][COLS], string fh);

void printUsers(const string data[ROWS][COLS]) {
  int i=0, j=0;
  while(i<5){
    while(j<4){
     std::cout << data[i][j] << "\t";
     j++;
    }
    std::cout << std::endl;
    i++;
  }
}
bool readUsers(string fh, string data[ROWS][COLS]) {
 int row=0, column=0;
 string line=" ",token=" ";
 std::ifstream in(fh);
 if(in.is_open()){
  std::stringstream readfile(fh);
  while(row < 5){
    std::getline(readfile, line);
    std::stringstream readline(line);
    while( column< 4){
    std::getline(readline, token, ',');
    data[row][column]=token;
     column++;
    }
   row++;
  }
  return true;
 }
 else return false;
}
char displayOptions() {
char option=' ';
bool validCheck=false;
int breaker= 0;
while(breaker<1){
std::cout << "Please choose one fo the follwing options: " << std::endl;
std::cout << "P(or p): Print Data"<<std::endl;
std::cout << "S(or s):Search data by name"<<std::endl;
std::cout << "F(or f): Find all in data with a certain job title"<<std::endl;
std::cout << "A(or a): Add a new user"<<std::endl;
std::cout << "D(or d): Delete an existing user "<<std::endl;
std::cout << "E(or e): End session "<<std::endl;
std::cin >> option;
validCheck=validateOption(option);
if(validCheck=true){ 
  breaker++;
}
else std::cout<<"invalid input, try again."<<std::endl;
}
return option;
} 
bool validateOption(char option){
  bool validation='false';
  switch(option){
    case 'P':
    case 'p':
    validation=true;
    break;
    case 'S':
    case 's':
    validation=true;
    break;
    case 'F':
    case 'f':
     validation=true;
    break;
    case 'A':
    case 'a':
     validation=true;
    break;
    case 'D':
    case 'd':
    validation=true;
    break;
    case 'E':
    case 'e':
     validation=true;
    break;
    default:
    break;
  }
  if(validation=true){
    return true;
  }
  else{
    return false;
  }
}
void executeOption(char option, string data[ROWS][COLS], string) {
  string firstname=" ",lastname=" ",name="";
  int counter;
  switch(option){
    case 'P':
    case 'p':
    printUsers(data);
    break;
    case 'S':
    case 's':
    std::cout<<"First Name: "<<std::endl;
    std::cin >> firstname;
    std::cout<<"Last Name: "<<std::endl;
    std::cin >> lastname;
    name=firstname+" "+lastname;
    counter = searchForUser(name,data);
    std::cout<<"The user was found at index "+counter<<std::endl;
    int i=0;
    while(i<4){
      std::cout<<data[counter][i];
      i++;
    }
    std::cout<<std::endl;
    break;
    case 'F':
    case 'f':
    std::cout<<"findAllUsers()"<<std::endl;
    break;
    case 'A':
    case 'a':
    std::cout<<"addUser()"<<std::endl;
    break;
    case 'D':
    case 'd':
    std::cout<<"deleteUser()"<<std::endl;
    break;
    case 'E':
    case 'e':
    std::cout<<"Goodbye!"<<std::endl;
    break;
    default:
    break;
  
  return;
}
}
int searchForUser(string name, const string data[ROWS][COLS]){
  int i=0;
  int index=9;
    while(i<5){
      if(name == data[i][1]){
        return i;
      }
    i++;
    }
  return -1;
  }
int findAllUsers(string title, const string data[ROWS][COLS]) {
  return -1;
}
bool deleteUser(string name, string data[ROWS][COLS], string fh) {
  return false;
}
string generatePassword() {
  return "";
}
string generateEmail(string name) {
  return "";
}
int checkEmpty(const string data[ROWS][COLS]) {
  return -1;
}
void addUser(int index, string name, string title,
             string data[ROWS][COLS], string fh) {
  return;
}

#endif  // LOGIN_H_
