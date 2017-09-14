#include<iostream>

using namespace std;

bool Bisiesto(int ANIO)
{
  if(ANIO /4 ==0 and ANIO/100!=0 and  ANIO/400==0)
    {
       return 1;
    }
   return 0;
}

int diasXmes(int tmp_mes, int anio)
{
   int B;
   //february
   if(tmp_mes==2)
  {
    if(Bisiesto(anio)==1){B=29;}
    else B=28;
  }
  else if(tmp_mes<=7)
  {
     if(tmp_mes==1) B=31;
     else if(tmp_mes/2==0) B=30;
     else B=31;
  }
  else{
     if(tmp_mes/2==0) B=31;
     else B=30;
  }
  return B;
}

//diamesanio(date old)- dia1mes1anio1(date actual)
void TIME(int dia,int mes, int anio, int dia1, int mes1, int anio1)
{
  int B;
  int tmp_mes=mes-1;
  int cant_anios,cant_meses,cant_dias;
  
  B=diasXmes(mes,anio);

  if((anio>anio1) or (anio==anio1 and mes>mes1) or (anio==anio1 and mes==mes1 and dia>dia1))
    cout<<"primera fecha anterior a la actual"<<endl;
  else
  {
    if(mes<=mes1){
       cant_anios=anio1-anio;
       if(dia<=dia1){
          cant_meses=mes1-mes;
          cant_dias=dia1-dia;
        }
       else{
         if(mes1-mes) {cant_anios=cant_anios-1;}
         cant_meses=(mes1-mes-1+12)/12;
	 cant_dias=(B-dia)+(dia1-1);//B-(dia-dia1);
       }
     }
    else {cant_anios=anio1-anio-1;}
    
    if(dia>dia1){
       cant_meses=mes1-mes-1+12;
       cant_dias=(B-dia)+(dia1-1);
     }
    else{
       cant_meses=mes1-mes+12;
       cant_dias=dia1-dia;
     }
  cant_meses=cant_meses%12;
  cout<<"cant_anios: "<<cant_anios<<endl;
  cout<<"cant_meses: "<<cant_meses<<endl;
  cout<<"cant_dias: "<<cant_dias<<endl;

    int tmp_dias=366; 
    int new_dias=0;
    for(int time=anio+1;time<anio1;time++){
        if(Bisiesto(time)==1){
           // tmp_horas=366;
            new_dias+=tmp_dias;
          }
        else if(Bisiesto(time)==0){
	   // tmp_horas=8760;
 	    new_dias+=(tmp_dias-1);
 	 }
     }
 cout<<"wwww: "<<new_dias<<endl; 
        for(int m=mes;m<12;m++){
           new_dias+=diasXmes(m,anio);
         }
//        for(int m1=mes1;m1>=1;m1--){
//            new_dias+=diasXmes(m1,anio1);  
//         }	

     
     new_dias=new_dias+cant_dias;
     //HORAS
     int horas;
     horas=(new_dias*24);
     //MIN
     int min;
     min=(new_dias*1440);
     //SECONDS
     int seconds;
     seconds=(new_dias*86400);
     cout<<"diass T:"<<new_dias<<endl;
     cout<<"horas: "<<horas<<endl;
     cout<<"minutos: "<<min<<endl;
     cout<<"segundos: "<<seconds<<endl;
  }
}

int main()
{
 int dia,mes,anio;
 int dia1,mes1,anio1;
 cout<<"Primera fecha: ";
 cin>>dia;cout<<" - ";cin>>mes; cout<<" - "; cin>>anio; cout<<endl;
 cout<<"Segunda fecha: ";
 cin>>dia1; cout<<" - "; cin>>mes1; cout<<" - "; cin>>anio1; cout<<endl;
 TIME(dia,mes,anio, dia1,mes1,anio1);
}

