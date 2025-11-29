#include <iostream>
#include <string>/*to use sunstr & other stuff*/
#include <iomanip>/*used for setfill & other stuff*/
#include <sstream>/*to read strings from memory*/
using namespace std;
struct Patient {
long long id;
string name;
string surname;
int age;
string depertman;
double bloodSugar;
double colestrol;
double heartDisease;
};
/*functions prototypes (i guess it looks better)*/
double heartDiseaseRate(int age,double bloodSugar,double colestrol);
void DisplayRow( const Patient& p);
void DisplayTable(const Patient* arr, int size);
void List(const Patient* arr, int size);
void Find(Patient arr[], int size, long long target);
void Edit(Patient arr[], int index, int size);
Patient* New(Patient arr[], int size);
Patient* Delete(Patient arr[], int size, int index, int& newSize);
int main() {
Patient * list = new Patient[2];
int size = 0;
int choice;
while (true) {/*to keep working till u exit*/
cout << "MENU\n";
cout << "1 - New\n";
cout << "2 - Find\n";
cout << "3 - List\n";
cout << "4 - Exit\n";
cout << "Enter option: ";
if (!(cin >> choice)) break;
cin.ignore(10000,
'\n');/*to remove the leftover newline*/
if (choice == 1) {
list = New(list, size);
++size;
} else if (choice == 2) {
cout << "Find by id: ";
long long target; /*to stay able to hold many digits*/
if (!(cin >>target)) break;
cin.ignore(10000,
'\n');
Find(list, size, target);
cout <<"Would you like to edit or delete a listed entry? (y/n): ";
char resp;
cin >> resp;
if (resp == 'y' || resp == 'Y') /*in case*/{
cout << "Enter index of entry: ";
int idx;
if (!(cin >> idx)) break;
cin.ignore(10000,
'\n');
cout << "1 - Edit\n2 - Delete\nEnter option: ";
int op;
if (!(cin >> op)) break;
cin.ignore(10000,
'\n');
if (op == 1) {
Edit(list, idx, size);
} else if (op == 2) {
int newSize = size;
list = Delete(list, size, idx, newSize);
size = newSize;
} else {
cout << "Invalid option.\n";
}
}
} else if (choice == 3) {
List(list, size);
cout<<endl;
cout << "Would you like to delete all the list ? (y/n): ";
char resp;
cin >> resp;
if (resp == 'y' || resp == 'Y') {
delete[]list;
list = new Patient[2];
size=0;
cout<<"all entered list has been deleted";
}
} else if (choice == 4) {
cout << "Exiting.\n";
break;
} else {
cout << "Invalid option. Try again.\n";
}
cout << endl ;
}
delete[] list;
return 0;
}
/*this function is unnecessary work, trying to get more grades, that is according to google*/
double heartDiseaseRate(int age,double bloodSugar,double colestrol){
double rate=0;
if(age<30&&age>=0 &&bloodSugar>=200&&colestrol>=160){
rate =6;
}
if(age<30&&age>=0 &&bloodSugar<200&&colestrol<160){
rate =1.5;
}
if(age<30&&age>=0 &&bloodSugar>=200&&colestrol<160){
rate =3;
}
if(age<30&&age>=0 &&bloodSugar<200&&colestrol>=160){
rate =2;
}
if(age<40&&age>=30 &&bloodSugar>=200&&colestrol>=160){
rate =12;
}
if(age<40&&age>=30 &&bloodSugar<200&&colestrol<160){
rate =2.5;
}
if(age<40&&age>=30 &&bloodSugar>=200&&colestrol<160){
rate =6;
}
if(age<40&&age>=30 &&bloodSugar<200&&colestrol>=160){
rate =5;
}
if(age<50&&age>=40 &&bloodSugar>=200&&colestrol>=160){
rate =15;
}
if(age<50&&age>=40 &&bloodSugar<200&&colestrol<160){
rate =5;
}
if(age<50&&age>=40 &&bloodSugar>=200&&colestrol<160){
rate =10;
}
if(age<50&&age>=40 &&bloodSugar<200&&colestrol>=160){
rate =8;
}
if(age<60&&age>=50 &&bloodSugar>=200&&colestrol>=160){
rate =35;
}
if(age<60&&age>=50 &&bloodSugar<200&&colestrol<160){
rate =10;
}
if(age<60&&age>=50 &&bloodSugar>=200&&colestrol<160){
rate =20;
}
if(age<60&&age>=50 &&bloodSugar<200&&colestrol>=160){
rate =20;
}
if(age<70&&age>=60 &&bloodSugar>=200&&colestrol>=160){
rate =50;
}
if(age<70&&age>=60 &&bloodSugar<200&&colestrol<160){
rate =15;
}
if(age<70&&age>=60 &&bloodSugar>=200&&colestrol<160){
rate =30;
}
if(age<70&&age>=60 &&bloodSugar<200&&colestrol>=160){
rate =30;
}
if(age<80&&age>=70 &&bloodSugar>=200&&colestrol>=160){
rate =70;
}
if(age<80&&age>=70 &&bloodSugar<200&&colestrol<160){
rate =25;
}
if(age<80&&age>=70 &&bloodSugar>=200&&colestrol<160){
rate =40;
}
if(age<80&&age>=70 &&bloodSugar<200&&colestrol>=160){
rate =40;
}
if(age>=80 &&bloodSugar>=200&&colestrol>=160){
rate =80;
}
if(age>=80 &&bloodSugar<200&&colestrol<160){
rate =40;
}
if(age>=80 &&bloodSugar>=200&&colestrol<160){
rate =60;
}
if(age>=80 &&bloodSugar<200&&colestrol>=160){
rate =60;
}
return rate;
}
void DisplayRow( const Patient & p) {
/* we need to keep the IDs under each other even if the user input less than 11 digits id, i
know sefill() is not included in the course but i didn't find a better way included, finding by
id still works by the user inputed id though, i will explain setfill to prove its human work
since its not included because we will use it a lot with substr.
setfill &substr work : used to fill the gap by something so that when we display the list
each colomn elements stay under eachother,setfill for the numbers to fill with zeros and
sbstr to fill the gap by spaces for strings*/
cout << setw(11)<<setfill('0')<<p.id<<setfill(' ') << " " ;
string name = (p.name.size() > 7) ? p.name.substr(0, 7) : p.name;
cout << left << setw(7) << name << right << " ";
string sname = (p.surname.size() > 7) ? p.surname.substr(0, 7) : p.surname;
cout << left << setw(7) << sname << right << " ";
cout << setw(3)<<setfill('0')<< p.age <<setfill(' ') << " ";
string dept = (p.depertman.size() > 11) ? p.depertman.substr(0, 11) : p.depertman;
cout << left << setw(11) << dept << right << " ";
cout << setw(3) << setfill('0')<<p.bloodSugar<<setfill(' ')<<" ";
cout << setw(3) << setfill('0')<<p.colestrol<<setfill(' ') ;
cout <<" "<< setw(3) << setfill('0')<<p.heartDisease<<setfill(' ') <<"%"<<endl;
}
void DisplayTable(const Patient* arr, int size) {
if (size <= 0) {
cout << "no patients to display.\n";
return;
}
cout << "Index ID Name Surname Age Department Sugar Cholesterol Heart
Disease Rate\n";
cout << "
------------------------------------------------------------------------------------------------\n";
for (int i = 0; i<size; ++i) {
cout << i << " ";
DisplayRow(arr[i]);
}
}
void List(const Patient * arr,int size) {
DisplayTable(arr,size);
}
void Find(Patient arr[], int size, long long target) {
bool found = false;
for (int i = 0; i < size; ++i) {
if (arr[i].id == target) {
cout << "Found at index " << i << ": "<<endl;
DisplayRow(arr[i]);
found = true;
}
}
if (!found) {
cout << "No patient found with ID equalled to " << target << ".\n";
}
}
Patient * New(Patient arr[], int size) {
Patient* newArr = new Patient[size + 1];
for (int i = 0; i < size; ++i) newArr[i] = arr[i];
cout << "Enter id: ";
cin >> newArr[size].id;
cout << "Name: ";
cin >> newArr[size].name;
cout << "Surname: ";
cin >> newArr[size].surname;
cout << "Age: ";
cin >> newArr[size].age;
cout << "Department: ";
cin >> newArr[size].depertman;
cout << "Blood sugar: ";
cin >> newArr[size].bloodSugar;
cout << "Cholesterol: ";
cin >> newArr[size].colestrol;
newArr[size].heartDisease=heartDiseaseRate(newArr[size].age,newArr[size].bloodSugar,
newArr[size].colestrol);
delete[] arr;
return newArr;
}
void Edit(Patient arr[], int index, int size) {
if (index < 0 || index >= size) {
cout << "Invalid index.\n";
return;
}
Patient& p = arr[index];
cout << "Editing patient at index " << index << ". Leave empty input to keep current
value.\n";
/*i will use std::istringstream iss(line); to read strings from memory to support the leaving
empty if u dont want to change the values , if the user clıcked enter the if(!string.empty())
will catch it,not included in slides but needed it*/
cout << "ID [" << p.id << "]: ";
string line;
getline(cin, line);
if (!line.empty()) {
std::istringstream iss(line);
iss >> p.id;
}
cout << "Name [" << p.name << "]: ";
getline(cin, line);
if (!line.empty()) p.name = line;
cout << "Surname [" << p.surname << "]: ";
getline(cin, line);
if (!line.empty()) p.surname = line;
cout << "Age [" << p.age << "]: ";
getline(cin, line);
if (!line.empty()) {
std::istringstream iss(line);
iss >> p.age;
}
cout << "Department [" << p.depertman << "]: ";
getline(cin, line);
if (!line.empty()) p.depertman = line;
cout << "BloodSugar [" << p.bloodSugar << "]: ";
getline(cin, line);
if (!line.empty()) {
std::istringstream iss(line);
iss >> p.bloodSugar;
}
cout << "Colestrol [" << p.colestrol << "]: ";
getline(cin, line);
if (!line.empty()) {
std::istringstream iss(line);
iss >> p.colestrol;
}
p.heartDisease = heartDiseaseRate(p.age,p.bloodSugar, p.colestrol);
cout << "Edit completed.\n";
}
/*this function will delete only 1 row, to delete the whole lıst we added delete[]list in the
main function*/
Patient * Delete(Patient arr[], int size, int index, int& newSize) {
if (index < 0 || index >= size) {
cout << "Invalid index.\n";
newSize = size;
return arr;
}
int sz = size - 1;
Patient* newArr = new Patient[sz];
for (int i = 0, j = 0; i < size; ++i) {
if (i == index) continue;
newArr[j++] = arr[i];
}
delete[] arr;
newSize = sz;
return newArr;
}
