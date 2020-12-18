#include "Quarterback.h"
#include <iostream>

using namespace std;

Quarterback::Quarterback(){
  pass_completes = 0;
  pass_attempts  = 0;
  total_yards = 0;
  touchdowns = 0;
  intercepts = 0;
}

Quarterback::Quarterback(string n, int comp, int att, 
                            int yards, int td, int i){
  name = n;
  pass_completes = comp;
  pass_attempts  = att;
  total_yards = yards;
  touchdowns = td;
  intercepts = i;
}

void Quarterback::setName(string new_name){
  name=new_name;
}

string Quarterback::getName(){
  return name;
}

void Quarterback::setComp(int x){
  pass_completes=x;
}

int Quarterback::getComp(){
  return pass_completes;
}

void Quarterback::setAtt(int x){
  pass_attempts=x;
}

int Quarterback::getAtt(){
  return pass_attempts;
}

void Quarterback::setYards(int x){
  total_yards=x;
}

int Quarterback::getYards(){
  return total_yards;
}

void Quarterback::setTD(int x){
  touchdowns=x;
}

int Quarterback::getTD(){
  return touchdowns;
}

void Quarterback::setPick(int x){
  intercepts=x;
}

int Quarterback::getPick(){
  return intercepts;
}

void Quarterback::PassCompleted(int x){
  pass_completes+=1;
  total_yards = total_yards+x;
  PassAttempted();
}

void Quarterback::PassAttempted(){
  pass_attempts+=1;
}

void Quarterback::Interception(){
  intercepts+=1;
  PassAttempted();
}

Quarterback::Quarterback(string d){
  int j = 0;
  string current="";
  for (int i = 0; i < d.length();i++){
    if (d[i]==','){
      if (j==0){
	name=current;
      }else if(j==1){
	pass_completes=stoi(current);
      }else if (j==2){
	pass_attempts=stoi(current);
      }else if(j==3){
	total_yards=stoi(current);
      }else if(j==4){
	touchdowns=stoi(current);
      }
      j+=1;

      current="";
    }else{
      current+=d[i];
    }
  }
  intercepts=stoi(current);  
}

float Quarterback::PasserRating(){
  double c_per_a = pass_completes/double(pass_attempts);
  double y_per_a = total_yards/double(pass_attempts);
  double t_per_a = touchdowns/double(pass_attempts);
  double i_per_a = intercepts/double(pass_attempts);
  double C = (c_per_a-0.3)*5;
  double Y = (y_per_a -3)*0.25;
  double T = t_per_a*20;
  double I = 2.375 - (i_per_a * 25);
  if (C < 0) {
    C= 0;
  } else if (C>2.375){
    C=2.375;
  }

  if (Y < 0){
    Y= 0;
  } else if (Y>2.375){
    Y=2.375;
  }
  if (T < 0){
    T= 0;
  } else if (T>2.375){
    T=2.375;
  }
  if (T < 0){
    T= 0;
  } else if (T>2.375){
    T=2.375;
  }
  return (C+Y+T+I)/6*100;
}

void Quarterback::Touchdown(int x){
  touchdowns+=1;
  pass_completes +=1;
  total_yards +=x;
  PassAttempted();
}