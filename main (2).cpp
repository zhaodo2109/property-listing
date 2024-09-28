#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>

/*
Name: Zhao Do
Project: Property Listing Application
Last Date Modified: Dec 10th, 2022
Description: A program that allows users to create listings, record their listings, print and search for their listings.
*/

using namespace std;
//chmod u+x property_listing
//./property_listing
//property listings are recorded. 
vector<string> total_listing;
vector<string> cityVector;
vector<string> stateVector;
vector<string> zipcodeVector;
vector<int> priceVector;
unsigned int numberOfListing = 0;
string databaseFile = "database.txt";

//get street numbers function
string getstreetnums(){
  string sn;
  cout<< "Enter your street numbers: ";
  cin>> sn;
  cin.ignore(); 
  return sn;
}

//get street names function
string getstreetnames(){
  string names;
  cout<<"Enter your street names: ";
  getline(cin,names);
  return names;
}

//get city function
string getcity(string& city){
  cout<<"Enter your city: ";
  getline(cin,city);
  return city;
}

//get states function
string getstate(string& state){
  cout<<"Enter your state: ";
  getline(cin,state);
  return state;
}

//get zipcode function
string getzip(string& zip){
  cout<<"Enter your zip code: ";
  getline(cin,zip);
  return zip;
}

//get number of bedrooms function
string getnumbeds(string& beds){
  cout<<"Enter your number of bedrooms: ";
  getline(cin,beds);
  return beds;
}


//get number of bathrooms function
string getnumbaths(string& baths){
  cout<<"Enter your number of bathrooms: ";
  getline(cin,baths);
  return baths;
}

//choose type of property function
string choosetype(string& type){
  cout<<"What is your property type ? "<<endl;
  cout<<"  1 for Single family house"<<endl;
  cout<<"  2 for Townhouse"<<endl;
  cout<<"  3 for Condo"<<endl;
  
  getline(cin,type);
  return type;
}


// ask for area of the property
string getarea(string& area){
  cout<<"Enter your property area in sqft: ";
  getline(cin,area);
  return area;
}


// ask for the price of the property
string getprices(string& prices){
  cout<<"Enter your listing price: ";
  getline(cin,prices);
  return prices;
}


// check valid input
bool checkarea(string area){
  bool check = true;
  for(unsigned int i=0; i<area.size();i++){
    if(!isdigit(area.at(i))){
      check = false;
    } 
  }
  if(check==false){
    return false;
  }
  else {
    return true;
  }
}

bool checkprice(string price){
  bool check = true;
  for(unsigned int i=0; i<price.size();i++){
    if(!isdigit(price.at(i))){
      check = false;
    } 
  }
  if(check==false){
    return false;
  }
  else {
    return true;
  }
}

bool checktype(string type){
  bool check = true;
  if (!((type=="1")||(type=="2")||(type=="3"))){
    check = false;
  }
  if(check==false){
    return false;
  }
  else {
    return true;
  }
}

bool checknumbaths(string baths){
  bool check = true;
  for(unsigned int i=0; i<baths.size();i++){
    if(!isdigit(baths.at(i))){
      check = false;
    } 
  }
  if(check==false){
    return false;
  }
  else {
    return true;
  }
}

bool checknumbeds(string beds){
  bool check = true;
  for(unsigned int i=0; i<beds.size();i++){
    if(!isdigit(beds.at(i))){
      check = false;
    } 
  }
  if(check==false){
    return false;
  }
  else {
    return true;
  }
}

bool checkzip(string zip){
  bool check = true;
  if((zip.size()>5) || (zip.size()<0)){
    check = false;
  }
  else {
    for(unsigned int i=0; i<zip.size();i++){
      if(!isdigit(zip.at(i))){
        check = false;
      } 
    }
  }
  if(check==false){
    return false;
  }
  else {
    return true;
  }
}

bool checkstate(string state){
  bool check = true;
  if(!((state=="CA")|| (state=="NV") || (state== "AZ") || (state=="OR") || (state== "WA"))){
    check = false;
  }
  if(check==false){
    return false;
  }
  else {
    return true;
  }
}

bool checksn(string sn){
  bool check = true;
  for(unsigned int i=0; i<sn.size();i++){
    if(!isdigit(sn.at(i))){
      check = false;
      //break;
    } 
  }
  if(check==false){
    return false;
  }
  return true;
}

bool checkstreetnames(string names){
  bool check = true;
  for(unsigned int i; i<names.size();i++){
    if(!isalpha(names.at(i))){
      check = false;
    } 
  }
  if(check==false){
    return false;
  }
  return true;
}

bool checkopt(string opt){
  bool check = true;
  if (!((opt=="1")||(opt=="2")||(opt=="3")||(opt=="4"))){
    check = false;
  }
  if(check==false){
    return false;
  }
  else {
    return true;
  }
}

//check menu option
bool checkmenu(string opt){
  bool check = true;
  if (!((opt=="c")||(opt=="C")||(opt=="p")||(opt=="P")||(opt=="r")||(opt=="R")||(opt=="s")||(opt=="S")||(opt=="e")||(opt=="E"))){
    check = false;
  }
  if(check==false){
    return false;
  }
  else {
    return true;
  }
}

bool checkcity(string city){
  bool check = true;
  for(unsigned int i; i<city.size();i++){
    if(!(isalpha(city[i])) || (isspace(city[i]))){
      check = false;
    } 
  }
  if(check==false){
    return false;
  }
    return true;
}

// The application initially prompts the user with a main menu
void menu() {
  cout << "Main Menu. Press:" << endl;
  cout << "\tc/C to create a property listing" << endl;
  cout << "\tp/P to print all property listings" << endl;
  cout << "\ts/S to search all property listings" << endl;
  cout << "\tr/R to record the listings" << endl;
  cout << "\te/E to exit" << endl;
}

int count(int count){
  return count+=1;
}

//Create a property listing
void choices1(string choice){
  string snums;
  string names;
  string city;
  string state;
  string zip;
  string beds;
  string baths;
  string type;
  string area;
  string price;

  string result;
  
  snums = getstreetnums();
  checksn(snums);
    
  
  while(checksn(snums)==false){
    cout<<"Invalid street numbers."<<endl;
    cout<<"Please re-enter valid street numbers."<<endl;
    cout<<endl;
    snums = getstreetnums();
     
    checksn(snums);
  
  }
  names=getstreetnames();
  checkstreetnames(names);
  

  while(checkstreetnames(names)==false){
    cout<<"Invalid street names"<<endl;
    cout<<"Please re-enter valid street names."<<endl;
    cout<<endl;
    names=getstreetnames();
    
    checkstreetnames(names);
  }

  getcity(city);
  checkcity(city);

  while(checkcity(city)==false){
    cout<<"Invalid city"<<endl;
    cout<<"Please re-enter valid city name."<<endl;
    cout<<endl;
    getcity(city);
    checkcity(city);
  }

  getstate(state);
  checkstate(state);

  while(checkstate(state)==false){
    cout<<"Invalid state"<<endl;
    cout<<"Please re-enter valid state."<<endl;
    cout<<endl;
    getstate(state);
    checkstate(state);
  }

  getzip(zip);
  checkzip(zip);

  while(checkzip(zip)==false){
    cout<<"Invalid zip code"<<endl;
    cout<<"Please re-enter valid zip."<<endl;
    cout<<endl;
    getzip(zip);
    checkzip(zip);
  }

  getnumbeds(beds);
  checknumbeds(beds);

  while(checknumbeds(beds)==false){
    cout<<"Invalid number of bedrooms"<<endl;
    cout<<"Please re-enter valid number."<<endl;
    cout<<endl;
    getnumbeds(beds);
    checknumbeds(beds);
  }

  getnumbaths(baths);
  checknumbaths(baths);

  while(checknumbaths(baths)==false){
    cout<<"Invalid number of bathrooms"<<endl;
    cout<<"Please re-enter valid number."<<endl;
    cout<<endl;
    getnumbaths(baths);
    checknumbaths(baths);
  }

  choosetype(type);
  checktype(type);

  while(checktype(type)==false){
    cout<<"Invalid type of property"<<endl;
    cout<<"Please re-enter valid options."<<endl;
    cout<<endl;
    choosetype(type);
    checktype(type);
  }

  if(type=="1"){
    type="Single family house";
  }
  else if (type=="2"){
    type="Townhouse";
  }
  else if (type=="3"){
    type="Condo";
  }

  getarea(area);
  checkarea(area);

  while(checkarea(area)==false){
    cout<<"Invalid area"<<endl;
    cout<<"Please re-enter valid area of your property."<<endl;
    cout<<endl;
    getarea(area);
    checkarea(area);
  }

  getprices(price);
  checkprice(price);

  while(checkprice(price)==false){
    cout<<"Invalid price"<<endl;
    cout<<"Please re-enter valid price for your property."<<endl;
    cout<<endl;
    getprices(area);
    checkprice(area);
  }
  string space = " ";
  string commaSpace = ", ";
  string colonSpace = ": ";
  string bedString = " Bed, ";
  string bathString = " Bath, ";
  string sqftDollar = " sqft, $";
  string newLine = "\n";
  result = snums + space + names + commaSpace + city + commaSpace + state + space + zip +
    commaSpace + beds + bedString + baths + bathString + type + commaSpace + space + area + sqftDollar + 
    price + newLine;
  total_listing.push_back(result);
  cityVector.push_back(city);
  stateVector.push_back(state);
  zipcodeVector.push_back(zip);
  priceVector.push_back(stoi(price));
  
  // cout<<"\nProperty listing is created successfully: \n" << snums<<" "<<names<<", "<<city<<", "<<state<<" "<<zip<<": "<<beds<<" Bed, "<<baths<<" Bath, "<<type<<" "<<area<< " sqft, $"<< price<<endl;
  cout << "\nProperty listing is created successfully: \n" << result;
  numberOfListing++;
  cout<<endl;

  //cout<<"Enter 'M'to go back to Menu"<<endl;
  //menu();
}

//Print all property listings
void choice2() { 
  cout << "\nNumber of properties: " << numberOfListing << endl;
  for (int i = 0; i < total_listing.size(); i++) {
    cout << i + 1 << ": " << total_listing.at(i) << endl;
  }
  cout << endl;
}

//Search all property listings
void choice3() {
  string cityInput;
  string stateInput;
  string zipcodeInput;
  string priceInput;
  string input;
  cout << "Search Menu. Press: \n\t1 to search in a city \n\t2 to search in a state \n\t3 to search in a zipcode \n\t4 to search all properties with prices less than a threshold\n";
  cout<<endl;
  cin>>input;
  checkopt(input);
  while(checkopt(input)==false){
    cout<<"Invalid option. \nPlease try again."<<endl;
    cin>>input;
    checkopt(input);
  }
  if (input=="1") {
    cout << "Enter the city: ";
    cin >> cityInput;
    checkcity(cityInput);
    while (checkcity(cityInput)==false){
      cout<<"Invalid city"<<endl;
      cout<<"Please re-enter valid city name."<<endl;
      cout<<endl;
      cin >> cityInput;
      checkcity(cityInput);
    } 
    cityInput = " " + cityInput; //Stockton (input) # _Stockton (result.at(1))
    // int count = 0;
    // for (int i = 0; i < cityVector.size(); i++) {
    //   if (cityInput == cityVector.at(i)) {
    //     cout << i + 1 << ": " << total_listing.at(i) << endl;
    //     count++;
    //   }
    // }
    // if (count == 0) {
    //     cout << "No listing found!" << endl;
    // }
    int count = 0;
    for (int i = 0; i < total_listing.size(); i++) {
      vector<string> result;
      // Parse a comma-delimited (slice into small pieces by comma)
      stringstream ss(total_listing.at(i));
      while(ss.good()) {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
      }
      if (cityInput == result.at(1)) {
        cout << i + 1 << ": " << total_listing.at(i) << endl;
        count++;
      }
    }
    if (count == 0) {
        cout << "No listing found!" << endl;
    }
  } else if (input=="2") {
    cout << "Enter the state: ";
    cin >> stateInput;
    checkstate(stateInput);
    while (checkstate(stateInput)==false){
      cout<<"Invalid state"<<endl;
      cout<<"Please re-enter valid state name."<<endl;
      cout<<endl;
      cin >> stateInput;
      checkstate(stateInput);
    } 
    // int count = 0;
    // for (int i = 0; i < stateVector.size(); i++) {
    //   if (stateInput == stateVector.at(i)) {
    //     cout << i + 1 << ": " << total_listing.at(i) << endl;
    //     count++;
    //   }
    // }
    int count = 0;
    for (int i = 0; i < total_listing.size(); i++) {
      vector<string> result;
      stringstream ss(total_listing.at(i));
      while(ss.good()) {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
      }
      vector<string> result1;
      stringstream ss2(result.at(2));
      while(ss2.good()) {
        string subs;
        getline(ss2, subs, ' ');
        result1.push_back(subs);
      }
      if (stateInput == result1.at(1)) {
        cout << i + 1 << ": " << total_listing.at(i) << endl;
        count++;
      }
    }
    if (count == 0) {
      cout << "No listing found!" << endl;
    }
  } else if (input=="3") {
    cout << "Enter the zipcode: ";
    int count =0;
    cin >> zipcodeInput;
    checkzip(zipcodeInput);
    while (checkzip(zipcodeInput)==false){
      cout<<"Invalid zipcode"<<endl;
      cout<<"Please re-enter valid zipcode."<<endl;
      cout<<endl;
      cin >> zipcodeInput;
      checkzip(zipcodeInput);
    } 
    //zipcodeInput = " " + zipcodeInput;
    //int count = 0;
    for (int i = 0; i < total_listing.size(); i++) {
      vector<string> result;
      stringstream ss(total_listing.at(i));
      while(ss.good()) {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
      }
      vector<string> result1;
      stringstream ss2(result.at(2));
      while(ss2.good()) {
        string subs;
        getline(ss2, subs, ' ');
        result1.push_back(subs);
      }
      //cout<< " Input" << zipcodeInput<<"vs"<< result1.at(2)<<endl;
      if (zipcodeInput == result1.at(2)) {
        cout << i + 1 << ": " << total_listing.at(i) << endl;
        count++;
      }
    }
    // for (int i = 0; i < zipcodeVector.size(); i++) {
    //   if (zipcodeInput == zipcodeVector.at(i)) {
    //     cout << i + 1 << ": " << total_listing.at(i) << endl;
    //     count++;
    //   } 
    // }
    if (count == 0) {
        cout << "No listing found!" << endl;
    }
  } else if (input=="4") {
    cout << "Enter the maximum price: $";
    int count=0;
    cin >> priceInput;
    checkprice(priceInput);
    while (checkprice(priceInput)==false){
      cout<<"Invalid price"<<endl;
      cout<<"Please re-enter number."<<endl;
      cout<<endl;
      cin >> priceInput;
      checkprice(priceInput);
    } 
    // for (int i = 0; i < priceVector.size(); i++) {
    //   if (priceVector.at(i) < stoi(priceInput)) {
    //     cout << i + 1 << ": " << total_listing.at(i) << endl; 
    //     count++;
    //   } 
    // }
    //int count = 0;
    for (int i = 0; i < total_listing.size(); i++) {
      vector<string> result;
      stringstream ss(total_listing.at(i));
      while(ss.good()) {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
      }
      vector<string> result1;
      stringstream ss2(result.at(7));
      while(ss2.good()) {
        string subs;
        getline(ss2, subs, '$');
        result1.push_back(subs);
      }
      
      //cout<< "Input"<<priceInput<<"vs"<<result1.at(1)<<endl;
      
      if ( stoi(result1.at(1))< stoi(priceInput)) {
          cout << i+1  << ": " << total_listing.at(i) << endl;
          count++;
      }
    }
    if (count == 0) {
        cout << "No listing found!" << endl;
    }
  } 
}

// print all the listings available
void printListing(string fileName) {
  total_listing.clear();
  ifstream myfile;
  myfile.open(fileName);
  string myline;
  if(myfile.is_open()) {
    while (myfile.good()) {
      getline(myfile, myline);
      //cout << myline << "\n";
      total_listing.push_back(myline);
      numberOfListing++;
    }
  } else {
    cout << "Couldn't open file\n";
    return;
  }
  cout << numberOfListing << " property listings are loaded." << endl;
}

// record created listings
void choice4() {
  ofstream outfile;
  outfile.open(databaseFile);
  int i;
  for (i = 0; i < total_listing.size(); i++) {
    outfile << total_listing.at(i) << "\n";
  }
  outfile.close();
  cout << i << " property listings are recorded." << endl;
}

//main function
int main(){
  printListing(databaseFile);
  string quitCmd = "a";
  string choice;
  bool invalid;
  bool open;
  int count1=0;
  
  while((quitCmd!="e") && (quitCmd!="E")){
    menu();
    cin>>choice;
    //cin.ignore();
    checkmenu(choice);

    while (checkmenu(choice)==false){
      cout<<"Invalid option"<<endl;
      cout<<"Please choose again"<<endl;
      cout<<endl;
      menu();
      cin>>choice;
      checkmenu(choice);
    }
    if (choice=="c"||choice=="C"){
      choices1(choice);
    } else if (choice == "p" || choice == "P") {
      choice2();
    } else if (choice == "s" || choice == "S") {
      choice3();
    } else if (choice == "r" || choice == "R") {
      choice4();
    } else if (choice == "e" || choice == "E") {
      break;
    } 
  } 
  
  
  return 0;   
}